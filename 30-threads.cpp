#include <iostream>
#include <thread>
#include <chrono>

namespace file30{
    struct Timer {
        std::chrono::time_point<std::chrono::steady_clock> start, end;
        std::chrono::duration<float> duration;

        Timer() {
            start = std::chrono::high_resolution_clock::now();
        };

        ~Timer() {
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            float ms = duration.count() * 1000.0f;
            std::cout << ms << "ms" << std::endl;
        }
    };

    void print() {
        Timer timer;
        for (int i = 0; i < 100; i++) {
            std::cout << "Hello\n";
        }
    }
}


static bool is_finished = false;

void DoWork() {
    using namespace std::literals::chrono_literals;
    std::cout << std::this_thread::get_id() << std::endl;
    while (!is_finished) {
        std::cout << "Working...\n";
        std::this_thread::sleep_for(1s);
    }
}

int main30() {
    auto start = std::chrono::high_resolution_clock::now();
    std::thread worker(DoWork);
    std::cin.get();
    is_finished = true;
    worker.join();
    std::cout << std::this_thread::get_id() << std::endl;
    std::cout << "Finished" << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = end - start;
    return 0;
}