#include <iostream>
#include <array>
#include <thread>
#include <cstdlib>
#include <chrono>
#include <vector>


const int size = 160000;

std::array<std::vector<int>, 4> generateVec() {
    std::array<std::vector<int>, 4> arrays;
    for (int i = 0; i < 4; ++i) {
        arrays[i] = std::vector<int>(size);
        for (int j = 0; j < size; ++j) {
            arrays[i][j] = std::rand() % 10000;
        }
    }
    return arrays;
}

void sortVec(std::vector<int>& v) {
    int i, j, key;
    for (i = 1; i < v.size(); ++i) {
        key = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    auto arrays = generateVec();

    std::thread t1(sortVec, std::ref(arrays[0]));
    std::thread t2(sortVec, std::ref(arrays[1]));
    std::thread t3(sortVec, std::ref(arrays[2]));
    std::thread t4(sortVec, std::ref(arrays[3]));

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Total Execution Time: " << duration.count() << " seconds." << std::endl;

    return 0;
}
