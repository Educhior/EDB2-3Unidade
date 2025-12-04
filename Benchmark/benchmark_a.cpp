
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

int solve_inefficient(vector<int>& a) {
    int n = a.size();
    int maxVal = -1;
    int result = -1;
    for (int i = 0; i < n; i++) {
        int duplicateCount = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j]) {
                duplicateCount++;
            }
        }
        if (duplicateCount == 1 && a[i] > maxVal) {
            maxVal = a[i];
            result = i + 1;
        }
    }
    return result;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    cout << "n,time_ms" << endl;
    for (int n = 1000; n <= 10000; n += 500) {
        vector<int> a(n);
        uniform_int_distribution<> dis(1, n * 2);
        for (int i = 0; i < n; i++) {
            a[i] = dis(gen);
        }
        const int NUM_RUNS = 10;
        double total_time = 0;
        for (int run = 0; run < NUM_RUNS; run++) {
            auto start = high_resolution_clock::now();
            solve_inefficient(a);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            total_time += duration.count() / 1000000.0;
        }
        double avg_time = total_time / NUM_RUNS;
        cout << n << "," << avg_time << endl;
    }
    return 0;
}