#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

unsigned long long fibIterative(int n) {
	unsigned long long memo[n+1];
	if(n <= 1) {
    	return n;
	}
	memo[0] = 0;
	memo[1] = 1;

	for(int i = 2;i <= n ;++i){
		memo[i] = memo[i-1] + memo[i-2];
	}

	return memo[n];
}

int main() {

	auto start = high_resolution_clock::now();

    
	cout<<fibIterative(9)<<endl;
    auto end = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(end - start);


    double seconds = duration.count() / 1000000.0;
	cout << fixed << setprecision(6);
	cout<<seconds<<endl;
}
