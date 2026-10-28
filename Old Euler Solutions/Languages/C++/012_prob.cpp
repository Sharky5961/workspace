#include <iostream>
#include <cmath>

int divisors(long x) {
	int count = 0;
	
	switch(x) {
		case 1 : return 1;
		case 3 : return 2;
	}
	
	for(int i = sqrt(x); i > 0; i--) {
		if (x % i == 0)
			count++;
	}
	
	return count * 2;
}

long triangle(int x) {
	if (x == 1) {
		return 1;
	}
	else {
		return x + triangle(x-1);
	}
}

int main() {
	std::cout << "What divisor cap are you looking for? ";
	
	int cap;
	std::cin >> cap;
	
	int run = 0; 	// loop counter
	int count = 0; // num of divisors
	long sum = 1; // run's sum
	
	do {
		run++;
		sum = triangle(run);
		count = divisors(sum);
		
	} while(count < cap);
	
	std::cout << "\n[sum, divisor] : [" << sum << ", " << count << "]\n";
}