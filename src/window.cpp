#include "window.h"
#include <cstdlib>
#include <iostream>

#include "glad/glad.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

Window::Window(int width, int height, std::string title)
    : m_width{width}, m_height{height} {
  if (!glfwInit()) {
    std::cerr << "Error Initializing glfw.\n";
    exit(1);
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Required on Mac

  m_window = glfwCreateWindow(m_width, m_height, title.c_str(), NULL, NULL);
  if (m_window == NULL) {
    std::cerr << "Error creating window.\n";
    exit(1);
  }
  glfwMakeContextCurrent(m_window);
  glfwSwapInterval(1); // Enable vsync

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize OpenGL context" << std::endl;
    exit(1);
  }
  OpenGLInformation();

  imguiInit();
}

GLFWwindow *Window::getWindow() { return m_window; }

void Window::imguiInit() {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();
  // ImGui::StyleColorsClassic();

  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL(m_window, true);
  ImGui_ImplOpenGL3_Init("#version 420");
}

void Window::OpenGLInformation() {
  const GLubyte *vendor = glGetString(GL_VENDOR); // Returns the vendor
  const GLubyte *renderer =
      glGetString(GL_RENDERER); // Returns a hint to the model

  std::cout << "Vendor: " << (char *)vendor << "\n"
            << "Renderer: " << (char *)renderer << "\n"
            << "OpenGL Version: " << (char *)glGetString(GL_VERSION) << "\n"
            << "Shading Language Version: "
            << (char *)glGetString(GL_SHADING_LANGUAGE_VERSION) << "\n";
}

Window::~Window() {
  // Cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
  glfwDestroyWindow(m_window);
  glfwTerminate();
}