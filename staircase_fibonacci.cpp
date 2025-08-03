#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int countWaysTopDown(int n, vector<int>& memo) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    if (memo[n] != -1) return memo[n];
    return memo[n] = countWaysTopDown(n - 1, memo) + countWaysTopDown(n - 2, memo);
}
 
int countWaysBottomUp(int n) {
    if (n <= 1) return 1;
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    vector<int> memo(n + 1, -1);
    memo[0] = 1;
    auto start1 = high_resolution_clock::now();
    int resultTopDown = countWaysTopDown(n, memo);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    auto start2 = high_resolution_clock::now();
    int resultBottomUp = countWaysBottomUp(n);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    cout << resultTopDown << "\n";
    double seconds1 = static_cast<double>(duration1.count()) / 1000000.0;
    cout << fixed << setprecision(6);
    cout << seconds1 << "\nduration of Top-down\n";

    cout << resultBottomUp << "\n";
    double seconds2 = static_cast<double>(duration2.count()) / 1000000.0;
    cout << seconds2 << "\nduration of bottom-up";

    return 0;
}
