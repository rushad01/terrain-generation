#include "renderer.h"

int main() {
  Renderer *renderer = new Renderer();
  renderer->run();
  delete renderer;

  return 0;
}