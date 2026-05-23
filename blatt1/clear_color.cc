#include <iostream>   // used for console output

// ToDo: include necessary headers for OpenGL (GLEW, GLFW)
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// For linear interpolation based on time elapsed
#include <chrono>

int
main(void) {
  std::cout << "Task02 - Change Clear Color" << std::endl;

  // ToDo step 1 - 6
  // - repeat steps from task01-window

    if (!glfwInit()) {
        std::cout << "GLFW initialization failed!";
        glfwTerminate();
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "My First Window", NULL, NULL);
    if (!window) {
        std::cout << "Window creation failed!";
        glfwTerminate();
        return -1;
    }

    int buffer_width = -1;
    int buffer_height = -1;
    glfwGetFramebufferSize(window, &buffer_width, &buffer_height);

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    GLenum errCode = glewInit();
    if (errCode != GLEW_OK) {

        std::cout << "GLEW initialization failed!" << glewGetErrorString(errCode) << "\n";
        // Here, I was getting the error: No GLX display
        // Little research and found out that glew api is not fully compatible with wayland (I use KDE desktop env. with wayland window manager.) So I just changed to X11, it worked.

        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }
    glViewport(0, 0, buffer_width, buffer_height);


    // ToDo step 7
  // - perform a smooth color change of the clear color in the render loop
  // - e.g. select a nice color palette from ColorBrewer and perform a linear
  //   interpolation between the colors

    float purple1[] = {215.0f,210.0f,230.0f};
    float purple2[] = {175.0f,189.0f,213.0f};
    float purple3[] = {127.0f,118.0f,183.0f};

    float* firstColor = purple1;
    float* secondColor = purple2;


    auto start = std::chrono::steady_clock::now();
    auto now = start;
    long durationInMs;
    float r;
    float g;
    float b;
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        now = std::chrono::steady_clock::now();
        durationInMs = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
        std::cout << durationInMs << "\n";
        std::cout.flush();
        // 3 secs to change color fully. (3000ms)
        r = firstColor[0]+( (float) durationInMs / 3000.0f )*(secondColor[0]-firstColor[0]);
        g = firstColor[1]+( (float) durationInMs / 3000.0f )*(secondColor[1]-firstColor[1]);
        b = firstColor[2]+( (float) durationInMs / 3000.0f )*(secondColor[2]-firstColor[2]);
        glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        if (durationInMs > 3000) {//restart the timer and set the new colors
            start = std::chrono::steady_clock::now();
            if (firstColor == purple1) {
                firstColor = purple2;
                secondColor = purple3;
            } else if (firstColor == purple2) {
                firstColor = purple3;
                secondColor = purple1;
            } else {
                firstColor = purple1;
                secondColor = purple2;
            }
        }
    }


    // ToDo step 8
  // - repeat step from task01-window
    glfwTerminate();


  return 0;
}
