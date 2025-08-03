#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;
unsigned long long fibonacci(int n,vector<unsigned long long>& memo) {

	
	if(1 == n || 0 == n) {
    	return n;
	}
		    	
	if(memo[n] != -1) {
    	return memo[n];
	}
		return memo[n] = fibonacci(n - 1,memo) + fibonacci(n - 2,memo);

}

int main() {
 	vector<unsigned long long> memo;
	int n = 10;
    memo.resize(n + 1, -1);	
    
	auto start = high_resolution_clock::now();
  
	cout<<fibonacci(8,memo)<<endl;
      auto end = high_resolution_clock::now();
  
      auto duration = duration_cast<microseconds>(end - start);
  
  
     double seconds = duration.count() / 1000000.0;
      cout << fixed << setprecision(6);
	 cout<<seconds;
	return 0;
}
