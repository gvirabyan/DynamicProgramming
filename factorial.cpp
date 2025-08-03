#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

vector<unsigned long long> memo;
vector<unsigned long long> memoIter;

unsigned long long facRec(int num) {
    memo.resize(num + 1, -1);

    if(num == 1 || num == 0) {
        return 1;
    }
    if(memo[num] != -1){
        return memo[num];
    }
    return memo[num] = facRec(num - 1) * num;
}

unsigned long long facIterative(int num) {
    memoIter.resize(num + 1, -1);

    unsigned long long result = 1;
    if(num == 0 || num == 1) {
        return 1;
    }
    if(memoIter[num] != -1) {
        return memoIter[num];
    }
    for(int i = 2; i <= num; ++i){
        result *= i;
        memoIter[i] = result;
    }
    return memoIter[num];
}

int main() {
    cout << fixed << setprecision(6);

    
    auto start1 = high_resolution_clock::now();
    cout << "Recursive: " << facRec(20) << endl;
    auto end1 = high_resolution_clock::now();
    double sec1 = duration_cast<nanoseconds>(end1 - start1).count() / 1e9;
    cout << "Recursive time: " << sec1 << " sec\n";

   
    auto start2 = high_resolution_clock::now();
    cout << "Iterative: " << facIterative(20) << endl;
    auto end2 = high_resolution_clock::now();
    double sec2 = duration_cast<nanoseconds>(end2 - start2).count() / 1e9;
    cout << "Iterative time: " << sec2 << " sec\n";

    return 0;
}

