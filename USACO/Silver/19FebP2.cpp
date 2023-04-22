#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	long long ar[n], temp = 0;
	for (int i = 0; i < n; i++){
		long long a;
		cin >> a;
		temp += a;
		ar[i] = temp;
	}
	
	long long ans = -100000000, mi = 100000000, ma = -100000000;
	for (int i = 0; i < n; i++){

		mi = min(mi, ar[i]);
	}
}