#include <bits/stdc++.h>
using namespace std;

#define ll long long



//Seive Approach - Generating a array containing prime numbers
vector<int> PrimeSieve(int *p, int n) {

	//first all odd numbers as prime as they can be potential prime
	for (int i = 3; i <= 1000000; i += 2) {
		p[i] = 1;
	}
	//Sieve
	for (ll i = 3; i <= 1000000; i += 2) {
		//if current number is not marked (it is prime)
		if (p[i] == 1) {
			//mark all the multiples of i as not prime
			for (ll j = i * i; j <= 1000000; j = j + i) {
				p[j] = 0;
			}
		}
	}
	//Special cases
	p[2] = 1;
	p[1] = p[0] = 0;

	vector<int> primes;
	primes.push_back(2);

	for (int i = 3; i <= n; i += 2) {
		if (p[i] == 1)
			primes.push_back(i);

	}

	return primes;


}

int no_of_divisors(int m, vector<int> &primes) {

	int i = 0;
	int p = primes[0];
	int ans = 1;

	while (p * p <= m) {

		if (m % p == 0) {
			int count = 0;

			while (m % p == 0) {
				count++;
				m = m / p;
			}
			ans = ans * (count + 1);
		}
		// go to next position
		i++;
		p = primes[i];
	}

//if m is not reduced to 1 , it means m also a prime number
	if (m != 1) {
		ans = ans * 2;
	}
	return ans;

}




int main() {


	int p[1000000] = {0};
	vector<int> primes = PrimeSieve(p, 100000);

	int t; cin >> t;
	while (t--) {
		int no; cin >> no;
		int divs = no_of_divisors(no, primes);
		cout << divs << endl;



	}

	return 0;


}