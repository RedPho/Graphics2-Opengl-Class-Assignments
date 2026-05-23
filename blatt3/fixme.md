# Aufgabe - Fix Me!

- ToDo: Fix the code!


## Code 1:
vertex shader outputs the vertex_color attribute but doesn't have out command before that, and fragment shader needs in command.  
```
#version 330 core
layout (location = 0) in vec3 pos;
out vec4 vertex_color; // added this
void main() {
  gl_Position = vec4(pos, 1.0);
  vertex_color = vec4(0.5, 0.0, 0.0, 1.0);
}
```

```
#version 330 core
in vec4 vertex_color; // added this
out vec4 frag_color;
void main() {
  frag_color = vertex_color;
}
```

## Code 2:

pos is given as vec2 so it does not have z attribute. I changed it to vec3
```
#version 330 core
layout (location = 0) in vec3 pos; // it was vec2.
void main() {
  gl_Position = vec4(pos.y, pos.x, pos.z, 1.0);
}
```

```
#version 330 core
out vec4 frag_color;
void main() {
  frag_color = vec4(0.0f, 0.0f, 0.0f, 1.0f);
}
```

## Code 3:

uniform my_color needs to be declared in the fragment shader too.
```
#version 330 core
layout (location = 0) in vec3 pos;
uniform vec4 my_color;
void main() {
  gl_Position = vec4(pos.xyz, 1.0);
}
```

```
#version 330 core
out vec4 frag_color;
uniform vec4 my_color; // added this.
void main() {
  frag_color = my_color;
}
```

bearbeitet von Mehmet Duman und Mehmet Emin Daşdan
