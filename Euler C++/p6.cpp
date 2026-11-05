#include <iostream>

/*
	The sum of the squares of the first ten natural numbers is,	
		1^2 + 2^2 + ... + 10^2 = 385.

	The square of the sum of the first ten natural numbers is,
		(1 + 2 + ... + 10)^2 = 55^2 = 3025.

	Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
	Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

int main() {
	const int SIZE = 100;
	
	int sq_sum = 0, sum_sq = 0;
	
	for (int i = 1; i < SIZE + 1; i++) {
		sq_sum += i * i;
		sum_sq += i;
	}
	
	sum_sq *= sum_sq;
	
	std::cout << sum_sq << " - " << sq_sum << " = " << sum_sq - sq_sum;
}