# OpenGL - Two Colors

```c++
const char* vertex_shader_source =
    "#version 330 core \n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n" // Added this to so the vertex shader can pass the color info to the fragment shader
    "out vec3 ourColor;\n" // Pass color to fragment shader
    "void main(){\n"
    " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    " ourColor = aColor;\n" // Added this
    "}\0";
```
```c++
const char* fragment_shader_source =
    "#version 330 core\n"
    "in vec3 ourColor;\n" // Added this to take the ourColor as input
    "out vec4 frag_color;\n"
    "void main() {\n"
    " frag_color = vec4(ourColor, 1.0f);\n" // Use the ourColor value
    "}\0";
```

in vertices array added color values to each vertice:
```c++
float vertices[] = {
    //coordinates        //color values
    -0.7f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,
    0.0f, -0.8f, 0.0f,  0.4f, 0.0f, 0.4f,
    0.7f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,

    -0.7f, 0.01f, 0.0f,  1.0f, 0.0f, 0.0f,
    0.0f, 0.2f, 0.0f,  0.4f, 0.0f, 0.4f,
    0.7f, 0.01f, 0.0f,  1.0f, 0.0f, 0.0f,

    -0.7f, 0.02f, 0.0f,  1.0f, 0.0f, 0.0f,
    -0.3f, 0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
    0.0f, 0.21f, 0.0f,  0.4f, 0.0f, 0.4f,

    -0.7f, 0.03f, 0.0f,  1.0f, 0.0f, 0.0f,
    -0.55f, 0.51f, 0.0f,  0.4f, 0.0f, 0.4f,
    -0.3f, 0.51f, 0.0f,  1.0f, 0.0f, 0.0f,

    0.7f, 0.02f, 0.0f,  1.0f, 0.0f, 0.0f,
    0.3f, 0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
    0.0f, 0.21f, 0.0f,  0.4f, 0.0f, 0.4f,

    0.7f, 0.03f, 0.0f,  1.0f, 0.0f, 0.0f,
    0.55f, 0.51f, 0.0f,  0.4f, 0.0f, 0.4f,
    0.3f, 0.51f, 0.0f,  1.0f, 0.0f, 0.0f,
};
```


// position attribute
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr); //every position attribute start has 6 float length distance
glEnableVertexAttribArray(0);

// color attribute
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float))); //every color attribute start has 6 float distance and has 3 float values offset(position values before color)


glEnableVertexAttribArray(0); //coordinate attribute location 0
glEnableVertexAttribArray(1); //color attribute location 1
