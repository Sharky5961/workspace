#include <iostream>

/*
	If we list all the natural numbers below 10 that are multiples of 3 or 5, 

	we get 3, 5, 6 and 9. The sum of these multiples is 23.

	Find the sum of all the multiples of 3 or 5 below 1000.
*/

int main() {
	const int MAX = 1000;
	int a = 3, b = 5,
		sum = 0;
	
/*	BRUTE FORCE

	int i;
	for (i = a; i < MAX; i++) {
		if (i % a == 0 || i % b == 0) {
			sum += i;
		}
	}
*/

// BRUTE FORCE ONLY CHECKING MULTIPLES OF a AND b

	int i;
	for (i = 1; i < MAX/a + (MAX % a); i++) {
		sum += i * a;
	}
	
	for (i = 1; i < MAX/b + (MAX % b); i++) {
		if (i % 3 != 0) {
			sum += i * b;
		}
	}
	
	std::cout << sum << std::endl;
}