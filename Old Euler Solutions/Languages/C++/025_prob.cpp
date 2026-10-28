/*
	Euler Problem #25: 1000-digit Fibonacci Number
	
	Find the index of the first fibonacci term with 1000 digits
	===> 10^0 = 1 digit
		--> 10^999 == 1000 digits
*/

#include <iostream>
#include <cmath>
#include <ctime>

int main() {
	bool trigger = false;
	long startTime = time(0);
	long long find, index = 1;
	// original code had a = 0, b = 1, tmp = 0;
	
	std::cout << "How many digits do you want to your smallest fibonnaci number to have? ";
	
	std::cin >> find;
	
	short tmp[find] = {0,}
	      , a[find] = {0,}
		  , b[find] = {0,};
	
	// setting arrays
	b[0] = 1;
	
	find = pow(10, find - 1);
	
	std::cout << std::endl;
		
	while( b / find < 1) { ///// This would THEORETICALLY work, but memory issue only leaves 10^19 instead of 10^999
		tmp = a + b;
		a = b;
		b = tmp;
		
		index++;
		std::cout << "\n" << index << ": " << b;
		
		long timeElapsed = time(0) - startTime;
		
		/*
		if (timeElapsed%5 == 0) {
			if (!trigger) {
				std::cout << timeElapsed << " second(s) have passed.\n";
				trigger = true;
			}
		}
		else
			trigger = false;
		*/
	}
	
	std::cout << "\n" << index << ": " << b;
	
}