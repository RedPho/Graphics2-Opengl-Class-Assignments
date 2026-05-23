#include <array>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// ------------------------------------------------------------------------ //
/* forward declarations*/
// clang-format off
struct Scene;
void createShaderProgram(Scene&);
void createTriangleScene(Scene&);
void renderLoop(Scene const&);
// clang-format on

// ------------------------------------------------------------------------ //
/* Scene keeps global app information. An instance of Scene is sent to
   initialziation functions and to the render loop.*/
struct Scene {
  // --- window stuff
  std::string const title = "INF515 - Triangles";
  GLFWwindow *window = nullptr;
  int width = 800;  // window width
  int height = 600; // window height
  // --- scene stuff
  GLuint shader_program = -1; // shader program object
  GLuint VAO = -1;            // shader array object
  GLuint VBO = -1;            // vertex buffer object
};

// ------------------------------------------------------------------------ //
/** Initialize the GL framework. */
bool initGLFW() {
  if (!glfwInit()) {
    std::cout << "GLFW initilization failed!" << std::endl;
    return false;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL min version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // OpenGL max version
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  return true;
}

// ------------------------------------------------------------------------ //
bool initGLFWWindow(Scene &s) {
  // --- create window
  s.window = glfwCreateWindow(s.width, s.width, s.title.c_str(), NULL, NULL);
  if (!s.window) {
    std::cout << "Window creation failed!" << std::endl;
    return false;
  }
  glfwGetFramebufferSize(s.window, &s.width, &s.height);
  glfwMakeContextCurrent(s.window);
  return true;
}

// ------------------------------------------------------------------------ //
bool initGLEW() {
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    std::cout << "GLEW initialization failed!";
    return false;
  }
  return true;
}

// ------------------------------------------------------------------------ //
int main(void) {
  Scene scene;
  // --- Scene GLFW & GLEW
  if (!initGLFW() || !initGLFWWindow(scene) || !initGLEW()) {
    glfwDestroyWindow(scene.window);
    glfwTerminate();
    return -1;
  };
  glViewport(0, 0, scene.width, scene.height);
  // --- prepare scene
  createShaderProgram(scene);
  createTriangleScene(scene);
  // --- start render loop
  renderLoop(scene);
  //--- clean up before close
  glfwTerminate();
  return 0;
}

// ToDo step 1: define vertex shader
// ToDo step 2: define fragment shader
// ------------------------------------------------------------------------ //
void createShaderProgram(Scene &scene) {
  // ToDo step 3: create & compile vertex shader object
  const char* vertex_shader_source =
          "#version 330 core \n"
          "layout (location = 0) in vec3 aPos;\n"
          "void main(){\n"
          " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
          "}\0";
  unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex_shader, 1, &vertex_shader_source, nullptr);
  glCompileShader(vertex_shader);

  // ToDo step 4: create & compile fragment shader object
  const char* fragment_shader_source =
          "#version 330 core\n"
          "out vec4 frag_color;\n"
          "void main() {\n"
          " frag_color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
          "}\0";
  unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment_shader, 1, &fragment_shader_source, nullptr);
  glCompileShader(fragment_shader);

  // ToDo step 5: create shader program object
  scene.shader_program = glCreateProgram();

  // ToDo step 6: attach shaders & link shader program
  glAttachShader(scene.shader_program, vertex_shader);
  glAttachShader(scene.shader_program, fragment_shader);
  glLinkProgram(scene.shader_program);

  // ToDo step 7: clean up unnecessary shader stuff
  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);
}

// ------------------------------------------------------------------------ //
void createTriangleScene(Scene &scene) {
  // ToDo step 8: create vertex data for triangles
  float vertices[] = {
          -0.7f, 0.0f, 0.0f,
          0.0f, -0.8f, 0.0f,
          0.7f, 0.0f, 0.0f,

          -0.7f, 0.01f, 0.0f,
          0.0f, 0.2f, 0.0f,
          0.7f, 0.01f, 0.0f,

          -0.7f, 0.02f, 0.0f,
          -0.3f, 0.5f, 0.0f,
          0.0f, 0.21f, 0.0f,

          -0.7f, 0.03f, 0.0f,
          -0.55f, 0.51f, 0.0f,
          -0.3f, 0.51f, 0.0f,

          0.7f, 0.02f, 0.0f,
          0.3f, 0.5f, 0.0f,
          0.0f, 0.21f, 0.0f,

          0.7f, 0.03f, 0.0f,
          0.55f, 0.51f, 0.0f,
          0.3f, 0.51f, 0.0f,
  };

  // ToDo step 9: create VAO and VBO -- store IDs in scene variable
  glGenVertexArrays(1, &scene.VAO);
  glGenBuffers(1, &scene.VBO);

  // ToDo step 10: bind VAO and VBO
  glBindVertexArray(scene.VAO);
  glBindBuffer(GL_ARRAY_BUFFER, scene.VBO);

  // ToDo step 11: send vertex data to VBO
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // ToDo step 12: tell OpenGL how to interpret the vertex data
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

  // ToDo step 13: enable vertex attribute array (index is likely to be 0)
  glEnableVertexAttribArray(0);

  // ToDo step 14: unbind VBO and VAO (in that order)
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

// ------------------------------------------------------------------------ //
void renderLoop(Scene const &scene) {
  while (!glfwWindowShouldClose(scene.window)) {
    glfwPollEvents();
    glClearColor(0.192f, 0.510f, 0.741f, 1.000f);
    glClear(GL_COLOR_BUFFER_BIT);

    // ToDo step 15: select shader program object (id stored in scene)
    glUseProgram(scene.shader_program);

    // ToDo step 16: bind VAO from (id stored in scene)
    glBindVertexArray(scene.VAO);

    // ToDo step 17: select draw method
    glDrawArrays(GL_TRIANGLES, 0, 18);

    glfwSwapBuffers(scene.window);
  }
}