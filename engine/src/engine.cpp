#include "engine.hpp"

static GLFWwindow *g_window = nullptr;

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

Engine::Engine() {}
Engine::~Engine() {}

std::expected<void, int> Engine::init(int width, int height,
                                      std::string_view title) {
    if (!glfwInit())
        return std::unexpected(-1);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    g_window = glfwCreateWindow(width, height, title.data(), NULL, NULL);

    if (!g_window) {
        glfwTerminate();
    }
    glfwSetFramebufferSizeCallback(g_window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return std::unexpected(-1);
    }
    return {};
}

void Engine::update() {
    if (glfwGetKey(g_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(g_window, true);

    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(g_window);
    glfwPollEvents();
}

bool Engine::shouldClose() const { return glfwWindowShouldClose(g_window); }

void Engine::shutdown() { glfwTerminate(); }
