#include "camera.hh"

// ToDo: implement this class

glm::mat4
Camera::getViewMatrix() const {

  glm::mat4 view = glm::lookAt(camera_pos,    // Camera position
                               camera_front + camera_pos,    // Look-at point
                               camera_up);   // Up vector
  return view;
}
