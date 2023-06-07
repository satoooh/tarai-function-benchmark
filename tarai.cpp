#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <cmath>
#include <version>

using namespace std;

int tarai(int x, int y, int z) {
    if (x <= y) {
        return y;
    } else {
        return tarai(tarai(x - 1, y, z), tarai(y - 1, z, x), tarai(z - 1, x, y));
    }
}

double average(const vector<double>& v) {
    return reduce(v.begin(), v.end()) / v.size();
}

double standard_deviation(const vector<double>& v) {
    auto avg = average(v);
    return sqrt(transform_reduce(v.begin(), v.end(), 0.0, plus<>(), [avg](double x) { return (x - avg) * (x - avg); }) / v.size());
}

int main() {
    const int n_iter = 10;
    vector<double> times;

    for (int i = 0; i < n_iter; i++) {
        auto start_time = chrono::high_resolution_clock::now();
        tarai(13, 5, 0);
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_time = end_time - start_time;
        times.push_back(elapsed_time.count());
    }

    auto avg_time = average(times);
    auto std_dev_time = standard_deviation(times);

    cout << "C++ version: " << __cplusplus << "\n";
    cout << "Average elapsed_time: " << avg_time << " sec\n";
    cout << "Standard deviation: " << std_dev_time << " sec\n";

    return 0;
}
