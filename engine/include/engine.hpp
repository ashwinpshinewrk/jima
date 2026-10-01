#pragma once


#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <expected>
#include <string_view>

class Engine {
  public:
    std::expected<void, int> init(int width, int height, std::string_view);
    void shutdown();
    void update();
    bool shouldClose() const;
    Engine();
    ~Engine();
};
