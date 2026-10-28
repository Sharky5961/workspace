/*
	Fibonacci sequence...

	By considering the terms in the Fibonacci sequence whose values do not exceed four million, 
	find the SUM of the EVEN-VALUED terms.
*/

#include <iostream>

int fib (int x) {
	switch(x) {
		case 0 : return 0;
		case 1 : return 1;
	}
	
	return fib(x-2) + fib(x-1);
}

int main() {
	int sum = 0; int ans = 0; int count = 0;
	
	do {
		if (ans % 2 == 0) {
			sum += ans;
		}
		
		ans = fib(count++);

	} while(ans < 4000000);
	
	std::cout << sum << std::endl;
}