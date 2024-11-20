#ifndef RENDERER_H
#define RENDERER_H

#include "window.h"

class Renderer {
public:
  Renderer();
  ~Renderer();
  void run(); // For looping opengl draw call using vertex ,fragment shader and
              // necessary data

private:
  // Vertex Array Object,Vertex Data for Terrain
  // Texture
  // Shader
  // Window Context
  Window window;

private:
  void draw();
};

#endif