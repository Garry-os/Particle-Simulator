#pragma once
#include <string>
#include <raylib.h>

class Renderer {
public:
    Renderer();
    ~Renderer();

    void create_window(int width, int height, const std::string& title);
    void set_fps(int fps);

    inline bool window_should_close() const { return WindowShouldClose(); }

    inline void begin() const { BeginDrawing(); }
    inline void end() const { EndDrawing(); }

    inline void clear_bg(Color color) const { ClearBackground(color); }

    inline void draw_rect(float x, float y, float width, float height, Color color) const {
        DrawRectangle((int)x, (int)y, (int)width, (int)height, color);
    }
    inline void draw_circle(float cx, float cy, float radius, Color color) const {
        DrawCircle((int)cx, (int)cy, radius, color);
    }

private:
    int width, height;
};
