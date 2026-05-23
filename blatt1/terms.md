# OpenGL
OpenGL ist eine Sammlung von funktion Standarts, die von Drivers implementiert werden. Diese Funktionen sind für die Manipulation von Images. Also man nutzt OpenGL für Graphics Programming ist keine Implementierung, weil sie je nach Hardware variert. Es ist ein low level Graphics API.


# GLFW

Es ist eine Library für die Handlung von Window, Events und Input.

# GLEW

Es ist eine Cross-Platform OpenGL Extension loading Library. Man kann mit GLEW kontrollieren, ob einen Extension von den target Device, unterstutzt ist.
Beispiele:
if (GLEW_ARB_vertex_program)
{
  /* It is safe to use the ARB_vertex_program extension here. */
  glGenProgramsARB(...);
}

//////

if (GLEW_VERSION_1_3)
{
  /* Yay! OpenGL 1.3 is supported! */
}

//////

if (glewIsSupported("GL_VERSION_1_4  GL_ARB_point_sprite"))
{
  /* Great, we have OpenGL 1.4 + point sprites. */
}
