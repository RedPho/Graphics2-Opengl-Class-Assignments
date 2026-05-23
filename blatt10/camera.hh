#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
public:
  // ToDo: implement this class
  glm::vec3 camera_pos = glm::vec3(0.0, 2.5, 5.0);
  glm::vec3 camera_front = glm::vec3(0.0, 0.0, -1.0);
  glm::vec3 camera_up = glm::vec3(0.0, 1.0, 0.0);
  glm::mat4 getViewMatrix() const;
};