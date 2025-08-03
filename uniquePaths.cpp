#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;


using unsignedLL = unsigned long long;

unsignedLL countPaths(int m, int n) {

	vector<vector<unsignedLL>> memo(m, vector<unsignedLL>(n, 1));
	for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
        }
    }
    return memo[m - 1][n - 1];
}

int main() {
    int m, n;
    cin >> m >> n;

    auto start = high_resolution_clock::now();
    unsignedLL paths = countPaths(m, n);
    auto end = high_resolution_clock::now();

    duration<double> duration_seconds = end - start;

    cout << paths << endl;
    cout << fixed << setprecision(6) << duration_seconds.count() << " sec" << endl;

    return 0;
}

