#include <iostream>   // used for console output

// ToDo: include necessary headers for OpenGL (GLEW, GLFW)
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int
main(void) {
  std::cout << "Task01 - Initialize a Render Window" << std::endl;

  // ToDo step 1
  // - initialize GLFW
  // - exit if initialization fails
  if (!glfwInit()) {
    std::cout << "GLFW initialization failed!";
    glfwTerminate();
    return -1;
  }

  // ToDo step 2
  // - set the properties of GLFW
  // - us OpenGL version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  // - use the core profile, i.e. no backwards compatibility
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  // ToDo step 3
  // - create a window
  // - 800 x 600 pixels
  GLFWwindow* window = glfwCreateWindow(800, 600, "My First Window", NULL, NULL);
  // - exit if window creation fails
  if (!window) {
      std::cout << "Window creation failed!";
      glfwTerminate();
      return -1;
  }

  // ToDo step 4
  // - read the buffer size (window dimensions)
  int buffer_width = -1;
  int buffer_height = -1;
  glfwGetFramebufferSize(window, &buffer_width, &buffer_height);
  // - set the render context to the current window
  glfwMakeContextCurrent(window);

  // ToDo step 5
  // - setup GLEW
  // - allow GLEW to use experimental functions
  glewExperimental = GL_TRUE;
  // - clean up and exit if this fails
  GLenum errCode = glewInit();
  if (errCode != GLEW_OK) {

      std::cout << "GLEW initialization failed!" << glewGetErrorString(errCode) << "\n";
      // Here, I was getting the error: No GLX display
      // Little research and found out that glew api is not fully compatible with wayland (I use KDE desktop env. with wayland window manager.) So I just changed to X11, it worked.

      glfwDestroyWindow(window);
      glfwTerminate();
      return -1;
  }

  // ToDo step 6
  // - set up the viewport with the buffer size
  glViewport(0, 0, buffer_width, buffer_height);

  // ToDo step 7
  // - run a loop in which you clear the viewport
  // - set the clear color to a value of your choice
  // - swap front an back buffer to show the result
  while (!glfwWindowShouldClose(window)) {
      glfwPollEvents();
      glClearColor(150.0f / 255.0f, 0.0f / 255.0f, 150.0f / 255.0f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
      glfwSwapBuffers(window);
  }

  // ToDo step 8
  // - clean everything up
  // - exit the program
  glfwTerminate();

  return 0;
}
