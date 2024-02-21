#include <iostream>
#include <thread>
#include <vector>
#include <iomanip>

std::vector<int> generateRandomVector(int size) {
    std::vector<int> vec(size);
    for (int i = 0; i < size; i++) {
        vec[i] = std::rand() % 1000 + 1;
    }
    return vec;
}

void parallelQuickSort(std::vector<int>& vec, int numThreads) {
    if (numThreads == 1) {
        std::sort(vec.begin(), vec.end());
        return;
    }

    std::vector<int> left(vec.begin(), vec.begin() + vec.size() / 2);
    std::vector<int> right(vec.begin() + vec.size() / 2, vec.end());

    int numThreadsLeft = numThreads / 2;
    int numThreadsRight = numThreads - numThreadsLeft;

    std::thread t1([&left, numThreadsLeft] { parallelQuickSort(left, numThreadsLeft); });
    std::thread t2([&right, numThreadsRight] { parallelQuickSort(right, numThreadsRight); });

    t1.join();
    t2.join();

    std::merge(left.begin(), left.end(), right.begin(), right.end(), vec.begin());
}

int main() {
    std::vector<int> sizes = {10000, 100000, 1000000, 10000000, 100000000};
    int hw_concurrency = static_cast<int>(std::thread::hardware_concurrency());
    std::vector<int> threads = {1, 2, hw_concurrency, 2 * hw_concurrency};
    std::vector<double> time1(sizes.size(), 0.0);

    std::cout << std::endl;
    std::cout << "+-------------------------------------------------------------------------------------------------------------+" << std::endl;
    std::cout << "|              |                                 The number of vector elements                                |" << std::endl;
    std::cout << "|              |------------------+------------------+------------------+------------------+------------------|" << std::endl;
    std::cout << "|              |      10 000      |      100 000     |     1 000 000    |    10 000 000    |    100 000 000   |" << std::endl;
    std::cout << "|--------------|--------+---------|--------+---------|--------+---------|--------+---------|--------+---------|" << std::endl;
    std::cout << "| Thread count |  Time  |  Boost  |  Time  |  Boost  |  Time  |  Boost  |  Time  |  Boost  |  Time  |  Boost  |" << std::endl;
    std::cout << "|--------------|--------|---------|--------|---------|--------|---------|--------|---------|--------|---------|" << std::endl;

    for (int numThreads : threads) {
        std::cout << "| " << std::setw(12) << numThreads << " |";
        for (int i = 0; i < sizes.size(); i++) {
            std::vector<int> vec = generateRandomVector(sizes[i]);
            auto start = std::chrono::high_resolution_clock::now();
            parallelQuickSort(vec, numThreads);
            auto end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> duration = end - start;

            if (numThreads == 1) {
                time1[i] = duration.count();
                std::cout << std::fixed << std::setprecision(4) << std::setw(7) << time1[i] << " |    X    |";
            } else {
                double boost = time1[i] / duration.count();
                std::cout << std::fixed << std::setprecision(4) << std::setw(7) << duration.count() << " | " << std::setw(7) << boost << " |";
            }
        }
        std::cout << std::endl;
        std::cout << "+--------------+--------+---------+--------+---------+--------+---------+--------+---------+--------+---------+" << std::endl;

    }

    return 0;
}