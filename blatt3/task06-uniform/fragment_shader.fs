// ToDo: adapt the shaders so that
// - the colormode can be changed
// - the triangle resizes

#version 330 core
out vec4 frag_color;
in vec3 our_color;
uniform int swizz;
void main() {
  switch (swizz) {
  case 1:
    frag_color = vec4(our_color.xzy, 1.0f);
    break;
  case 2:
    frag_color = vec4(our_color.yxz, 1.0f);
    break;
  case 3:
    frag_color = vec4(our_color.yzx, 1.0f);
    break;
  case 4:
    frag_color = vec4(our_color.zxy, 1.0f);
    break;
  case 5:
    frag_color = vec4(our_color.zyx, 1.0f);
    break;
  default:
    frag_color = vec4(our_color.xyz, 1.0f);
    break;
  }
}