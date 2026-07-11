#pragma once
#include "matrix.h"
#include "particle.h"
#include "random.h"

class ParticlesManager {
public:
    ParticlesManager()
        :rules(4, 4) {}
    ~ParticlesManager() = default;

    void add_particle(float x, float y, ParticleType type);
    void add_rule(ParticleType effection, ParticleType reaction, float force);
    void add_random_rules();

    void update(const Renderer& renderer, float deltaTime, float speed);

private:
    Matrix2D rules;
    RandomGenerator random;
    std::vector<Particle> particles;
};
