#include <iostream>
#include <cmath>

/*
	A palindromic number reads the same both ways.
	The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

	Find the largest palindrome made from the product of two 3-digit numbers.
*/

bool isPalindrome(int a) {
	std::string temp = std::to_string(a);
	
	for (int i = 0; i < temp.size()/2; i++) {
		if (temp[i] != temp[temp.size() - i - 1]) {
			return false;
		} 
	}
	
	return true;
}

int main () {
	int product, max = 0;
	
	int a, b;

	for (a = 999; a > 999/2; a--) { // ceiling to ceiling / 2
		for (b = 999; b > 99; b--) {
			product = a * b;
			
			if (isPalindrome(product) && product > max) {
				max = product;
			}
		}
	}	
	
	std::cout << max;
	
}