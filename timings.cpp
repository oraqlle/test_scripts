#include <iostream>
#include <chrono>
#include <thread>

using time_point_t = std::chrono::time_point<std::chrono::steady_clock>;
using durationf = std::chrono::duration<float>;

struct Timer
{
    time_point_t start, end;
    durationf duration;

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;
        std::cout << "Program took: " << ms << "ms\n";
    }
};

void foo()
{
    Timer timer;

    for (int i = 0; i < 100; i++)
        std::cout << "Hello World\n";
}


int main()
{
    foo();

    std::cin.get();
}