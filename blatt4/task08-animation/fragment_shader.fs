#version 330 core
out vec4      frag_color;
uniform float time;

const vec4 clr0 = vec4(228.0 / 255.0, 26.0 / 255.0, 28.0 / 255.0, 1.0);
const vec4 clr1 = vec4(55.0 / 255.0, 126.0 / 255.0, 184.0 / 255.0, 1.0);
const vec4 clr2 = vec4(77.0 / 255.0, 175.0 / 255.0, 74.0 / 255.0, 1.0);
const vec4 clr3 = vec4(152.0 / 255.0, 78.0 / 255.0, 163.0 / 255.0, 1.0);
const vec4 clr4 = vec4(255.0 / 255.0, 127.0 / 255.0, 0.0 / 255.0, 1.0);

// ---


float line(vec2 p, vec2 a,vec2 b) {
    vec2 v = p - a;
    vec2 w = b - a;
    float lambda = dot(v, w) / dot(w, w);
    lambda=clamp(lambda,0,1);
    return length(lambda*w-v);
}

void
main() {
  frag_color = vec4(1);
  vec2 uv = gl_FragCoord.xy / vec2(800,600);

  vec2 a = vec2(0.25, 0.1);    // Bottom left corner
  vec2 b = vec2(0.75, 0.1);    // Bottom right corner
  vec2 c = vec2(0.75, 0.60);    // Top right corner
  vec2 d = vec2(0.25, 0.60);    // Top left corner
  vec2 e = vec2(0.5, 0.9);

  float t = mod(time, 8.0);

  vec4 color = vec4(1.0);

  if (t >= 0.0) {
    if(line(uv, a, b) < 0.01) {
        color.rgb = vec3(0.0, 0.0, 1.0);
    }
  }
  if (t >= 1.0){
    if(line(uv, b, c) < 0.01) {
      color.rgb = vec3(0.0, 0.0, 1.0);
    }
  }
  if (t >= 2.0){
    if(line(uv, c, a) < 0.01) {
      color.rgb = vec3(0.0, 0.0, 1.0);
    }
  }
  if (t >= 3.0){
    if(line(uv, a, d) < 0.01) {
      color.rgb = vec3(0.0, 0.0, 1.0);
    }
  }
  if (t >= 4.0){
    if(line(uv, d, c) < 0.01) {
      color.rgb = vec3(0.0, 0.0, 1.0);
    }
  }
  if (t >= 5.0){
    if(line(uv, c, e) < 0.01) {
      color.rgb = vec3(0.0, 0.0, 1.0);
    }
  }
  if (t >= 6.0){
    if(line(uv, e, d) < 0.01) {
      color.rgb = vec3(0.0, 0.0, 1.0);
    }
  }
  if (t >= 7.0){
    if(line(uv, d, b) < 0.01) {
      color.rgb = vec3(0.0, 0.0, 1.0);
    }
  }

  frag_color = color;
}
