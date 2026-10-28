/*
	If we list all the natural numbers below 10 that 
	are multiples of 3 or 5, we get 3, 5, 6 and 9. 

	The sum of these multiples is 23.

	Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <iostream>

// so, [num % 3 or % 5] -> get sum

bool isMultiple(int);

int main() {
	std::cout << "Enter a number: "; // cout = "print("hello world", end = "")
	
	int num;
	std::cin >> num; // inputs a number in "num"
	
	long sum = 0;
	for (int i = 0; i < num; i++) {
		if (isMultiple(i)) {
			sum += i;
		}
	}
	
	std::cout << "Multiple sum: " << sum << std::endl;
	
}

bool isMultiple(int num) {
	if (num % 3 == 0 || num % 5 == 0)
		return true;
	
	return false;
}