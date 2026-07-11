#pragma once
#include "renderer.h"
#include <raylib.h>

enum class ParticleType : int {
    Blue = 0,
    Red,
    Green,
    White
};

extern Color particles_colors[];

struct Particle {
    Particle(float x, float y, ParticleType type)
        :x(x), y(y), type(type) {}

    void accelerate(float deltaTime, float ax, float ay);
    void update(float deltaTime);
    void draw(const Renderer& renderer);

    float x, y;
    float vx, vy;
    ParticleType type;
};
