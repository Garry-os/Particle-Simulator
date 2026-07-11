#include "renderer.h"

Renderer::Renderer()
    :width(0), height(0) {}

Renderer::~Renderer() {
    CloseWindow();
}

void Renderer::create_window(int width, int height, const std::string& title) {
    this->width = width;
    this->height = height;

    InitWindow(width, height, title.c_str());
}

void Renderer::set_fps(int fps) {
    SetTargetFPS(fps);
}
