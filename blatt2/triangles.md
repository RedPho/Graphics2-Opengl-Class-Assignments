# OpenGL - Triangles

I changed the vertex array like:

```c++
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
```

and then changed the second parameter of the glDrawArrays(GL_TRIANGLES, 0, 3) call, it is the number of vertices I want to render. So I made it glDrawArrays(GL_TRIANGLES, 0, 18), because I have 6 triangles.
