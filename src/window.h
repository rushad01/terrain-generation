#ifndef WINDOW_H
#define WINDOW_H
#include "GLFW/glfw3.h"
#include <string>

class Window {
public:
  Window() = default;
  Window(int width, int height, std::string title);
  GLFWwindow *getWindow();
  ~Window();

private:
  int m_width{0};
  int m_height{0};
  GLFWwindow *m_window;

private:
  void imguiInit();
  void OpenGLInformation();
};

#endif