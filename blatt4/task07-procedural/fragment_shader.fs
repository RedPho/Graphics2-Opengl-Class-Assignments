#version 330 core
out vec4      frag_color;
uniform float time;
uniform int render_mode;

const vec4 clr0 = vec4(228.0/255.0,  26.0/255.0,  28.0/255.0,1.0);
const vec4 clr1 = vec4( 55.0/255.0, 126.0/255.0, 184.0/255.0,1.0);
const vec4 clr2 = vec4( 77.0/255.0, 175.0/255.0,  74.0/255.0,1.0);
const vec4 clr3 = vec4(152.0/255.0,  78.0/255.0, 163.0/255.0,1.0);
const vec4 clr4 = vec4(255.0/255.0, 127.0/255.0,   0.0/255.0,1.0);

// ---
void renderCircle() {
  frag_color = clr1;
  vec4 color=vec4(1);
  vec2 uv = gl_FragCoord.xy;
  vec2 midCirc=vec2(400,300);
  if(length(uv-midCirc)<=150) {
    color.rgb=vec3(0.3,0.3,1.0);
  }
  frag_color = color;
}

// ---
void renderDiamond() {
  frag_color = clr2;
  vec4 color=vec4(1);
  vec2 uv = gl_FragCoord.xy;
  vec2 mid=vec2(400,300);
  if(abs(mid.x - uv.x)+abs(mid.y-uv.y)<=150) {
    color.rgb=vec3(0.3,0.3,1.0);
  }
  frag_color = color;
}

// ---
void renderCheckerboard() {
  frag_color = clr3;
  vec4 color = vec4(1);
  vec2 uv = gl_FragCoord.xy;
  int x_id = int(floor(uv.x / 50.0));
  int y_id = int(floor(uv.y / 50.0));
  if ((x_id + y_id) % 2 == 0) {
    color.rgb = vec3(0.3, 0.3, 1.0);
  }
  frag_color = color;
}

// ---
void renderPattern1() {
  frag_color = clr4;
  vec4 color=vec4(1);
  vec2 uv = gl_FragCoord.xy;

  vec2 uv_mod = mod(uv-50, 100);
  if (length(uv_mod - 50) < 20) {
      color.rgb = vec3(0.3, 0.3, 1.0);
  }

  uv_mod = mod(uv-75, 100);
  if (abs(uv_mod.x - 75) + abs(uv_mod.y - 75) < 20) {
      color.rgb = vec3(1.0, 0.3, 0.3);
  }

  frag_color = color;
}

// ---
void renderPattern2() {
  frag_color = clr0;
  vec4 color = vec4(1);
  vec2 uv = gl_FragCoord.xy / vec2(800,600);
  vec2 center = vec2(0.5, 0.5);

  float dist = distance(uv, center);

  color.rgb = vec3(0.5 + 0.5 * sin(dist * 12.0),
                   0.5 + 0.5 * sin(dist * 37.0),
                   0.5 + 0.5 * sin(dist * 53.0));
  frag_color = color;
}

void
main() {
  int mode_count = 5;
  if (render_mode % mode_count == 0)
    renderCircle();
  if (render_mode % mode_count == 1)
    renderDiamond();
  if (render_mode % mode_count == 2)
    renderCheckerboard();
  if (render_mode % mode_count == 3)
    renderPattern1();
  if (render_mode % mode_count == 4)
    renderPattern2();
}
