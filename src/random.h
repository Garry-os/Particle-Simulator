#pragma once
#include <random>

class RandomGenerator {
public:
    RandomGenerator()
        :rng(std::random_device{}()) {}
    ~RandomGenerator() = default;

    template <typename T>
    T value(T min, T max) {
        if constexpr (std::is_integral_v<T>) {
            std::uniform_int_distribution<int> dist(min, max);
            return dist(rng);
        }
        else {
            std::uniform_real_distribution<double> dist(min, max);
            return dist(rng);
        }
    }

private:
    std::mt19937 rng;
};
