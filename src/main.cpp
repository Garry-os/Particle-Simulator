#include "renderer.h"
#include "particles_manager.h"
#include "random.h"
#include <memory>

constexpr int window_width = 1280;
constexpr int window_height = 720;

int main() {
    Renderer renderer;
    renderer.create_window(window_width, window_height, "Particles simulation");

    RandomGenerator random;

    std::unique_ptr<ParticlesManager> manager = std::make_unique<ParticlesManager>();

    for (int i = 0; i < 300; i++) {
        manager->add_particle(random.value(0, window_width), random.value(0, window_height), ParticleType::Blue);
        manager->add_particle(random.value(0, window_width), random.value(0, window_height), ParticleType::Red);
        manager->add_particle(random.value(0, window_width), random.value(0, window_height), ParticleType::Green);
        manager->add_particle(random.value(0, window_width), random.value(0, window_height), ParticleType::White);
    }

    manager->add_random_rules();


    float deltaTime = 0.0f;
    while (!renderer.window_should_close()) {
        // Get deltaTime
        deltaTime = GetFrameTime();

        renderer.begin();

        renderer.clear_bg(BLACK);

        manager->update(renderer, deltaTime, 100.0f);

        renderer.end();
    }

    return 0;
}
