#include "particles_manager.h"

constexpr float r_repel = 20.0f;
constexpr float r_max = 80.0f;
constexpr float r_power = 5.0f;

void ParticlesManager::add_particle(float x, float y, ParticleType type) {
    particles.emplace_back((Particle){ x, y, type });
}

void ParticlesManager::add_rule(ParticleType effection, ParticleType reaction, float force) {
    int effectionIndex = static_cast<size_t>(effection);
    int reactionIndex = static_cast<size_t>(reaction);

    rules[effectionIndex, reactionIndex] = force;
}

void ParticlesManager::add_random_rules() {
    for (int col = 0; col < rules.get_column(); col++) {
        for (int row = 0; row < rules.get_row(); row++) {
            rules[row, col] = random.value(-1.0f, 1.0f);
        }
    }
}

void ParticlesManager::update(const Renderer& renderer, float deltaTime, float speed) {
    for (auto& particle : particles) {
        for (auto& particle1 : particles) {
            if (&particle == &particle1) continue;
            // Calculate the distance between two particles
            float dx = particle1.x - particle.x;
            float dy = particle1.y - particle.y;
            float distance = std::sqrt(dx * dx + dy * dy);
            float force = 0.0f;

            if (distance > 0.001f)
            {
                if (distance < r_repel) {
                    // Repulsion
                    float repel_factor = (distance / r_repel) - 1.0f;
                    force = repel_factor * r_power;
                }
                else if (distance >= r_repel && distance <= r_max) {
                    // Get the forces
                    force = rules[static_cast<size_t>(particle.type), static_cast<size_t>(particle1.type)];

                    float scale = (distance - r_repel) / (r_max - r_repel);
                    float curve = 1.0f - std::abs(2.0f * scale - 1.0f);
                    force = curve * force;
                }
                float dirX = dx / distance;
                float dirY = dy / distance;
                float ax = dirX * force * speed;
                float ay = dirY * force * speed;
                particle.accelerate(deltaTime, ax, ay);
            }
        }
        particle.update(deltaTime);
    }

    // Actually rendering
    for (auto& particle : particles) {
        particle.draw(renderer);
    }
}
