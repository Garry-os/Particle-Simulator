#include "particle.h"
#include <raylib.h>

Color particles_colors[] = {
    BLUE,
    RED,
    GREEN,
    WHITE
};
constexpr float particle_size = 4;

void Particle::accelerate(float deltaTime, float ax, float ay) {
    vx += ax * deltaTime;
    vy += ay * deltaTime;
}

void Particle::update(float deltaTime) {
    x += vx * deltaTime;
    y += vy * deltaTime;

    int window_width = GetScreenWidth();
    int window_height = GetScreenHeight();

    // Bound checking
    if (x <= 0.0f) {
        x = 0.1f;
        vx *= -1.0f;
    }
    else if (x >= static_cast<float>(window_width)) {
        x = static_cast<float>(window_width) - 0.001f;
        vx *= -1.0f;
    }

    if (y <= 0.0f) {
        y = 0.1f;
        vy *= -1.0f;
    }
    else if (y >= static_cast<float>(window_height)) {
        y = static_cast<float>(window_height) - 0.001f;
        vy *= -1.0f;
    }

    // Friction
    vx *= 0.98f;
    vy *= 0.98f;
}

void Particle::draw(const Renderer& renderer) {
    // renderer.draw_rect(x, y, particle_size, particle_size, particles_colors[static_cast<int>(type)]);
    renderer.draw_circle(x, y, particle_size, particles_colors[static_cast<size_t>(type)]);
}
