#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int p =  1;
	bool sieve[n+1]; // doesn't work with an old compilators 
	for (int i = 2; i < n+1; i++) {
		sieve[i] = true;

	}
	int x=2;

	while (x * x <= n) {
		if (sieve[x]) { // find new prime number
			for (int y = x * x; y <= n; y += x) {
				sieve[y] = false;
			}
		}

		x += 1;

	}
	for (int i = 2; i < n + 1; i++) {
		if (sieve[i]) {
			cout << i << " ";
		}
	}
	
	return 0;

}