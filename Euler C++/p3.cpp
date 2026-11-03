#include <iostream>
#include <cmath>

/*
	The prime factors of 13195 are 
		5, 7, 13 and 29.

	What is the largest prime factor of the number 600851475143?
*/

bool isPrime(unsigned long x) {
	if (x % 2 == 0)
		return false;

	for (unsigned int i = 3; i < sqrt(x) + 1; i+=2) {
		if (x % i == 0) {
			return false;
		}		
	}

	return true;
}

int main() {
	const unsigned long long CAP = 600851475143; // this is wayyy too big D:
	
	long i = long(sqrt(CAP)) % 2 + 1; // forces odd
	
	for (i = i + sqrt(CAP); i > 0; i-=2) {
		
		if (CAP % i == 0) { // is divisible (either composite or prime)
			if (isPrime(i)) // prime checker
				break;
		}
	}
	
	std::cout << i;
	
}