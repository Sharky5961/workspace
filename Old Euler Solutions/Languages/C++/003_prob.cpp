/*
	The prime factors of 13195 are 5, 7, 13 and 29.

	What is the largest prime factor of the number 600,851,475,143?

	600851475143
*/

#include <iostream>
#include <cmath>

bool isPrime(long long x) {
	switch (x) {
		case 0 : return false;
		case 1 : return false;
	}
	
	for(int i = sqrt(x); i > 1 ; i--){
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	long long find = 600851475143;
	
	long long largest = sqrt(find);
	
	long long peak = largest;
	
	while(find % largest != 0) {
		if(isPrime(--peak)) {
			largest = peak;
		}
	}
	
	std::cout << largest;
}