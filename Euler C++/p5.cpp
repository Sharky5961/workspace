#include <iostream>
#include <cmath>

/*
	2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder. 
	What is the smallest positive number that is evenly divisible with no remainder by all of the numbers from 1 to 20? 
*/

using namespace std;

bool isPrime(int num) {
	if (num % 2 == 0) {
		return false;
	}
	
	for (int i = 3; i < sqrt(num) + 1; i+=2) {
		if (num % i == 0) 
			return false;
	}
	
	return true;
}

unsigned int smallestMultiple(int);

int main() {
	// NOTE: Scales up HORRIBLY with larger numbers - 0.5 seconds
	
	cout << smallestMultiple(20) << endl;
}

unsigned smallestMultiple(int thres = 20) { 
	unsigned int low = 1, high = 1;
	
	if (thres < 1) {
		return -1;
	}
	else if (thres == 1) {
		return 1;
	}
	
	// high range in this case, 11 -> 20 inclusive
	unsigned int i, j;
	for (i = thres/2 + 1; i < thres + 1; i++) {
		high *= i;
	}
	
	// low range = primes of 1 -> 20 inclusive
	for (i = 1; i < thres + 1; i++) {
		if (isPrime(i)) {
			low *= i;
		}
	}
	
	bool found = false;
	
	for (i = low; i < high + 1; i++) { // low threshold (primes) to high threshold (top half numbers)
		found = true;
		
		for (j = thres / 2; j < thres + 1; j++) { // 10 -> 20 inclusive
			if (i % j != 0) { 
				found = false;
				break;
			}
		}
		
		if (found) {
			break;
		}
	}
	
	return i;
}