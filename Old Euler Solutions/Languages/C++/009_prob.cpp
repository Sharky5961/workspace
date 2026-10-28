/*
	a^2 + b^2 = c^2 ---> c = sqrt(a^2 + b^2)
	a + b + c = 1000 --> a + b + sqrt(a^2 + b^2) = 1000
	a * b * c = ???
*/

#include <iostream>
#include <cmath>

int c(int a, int b) { 
	double temp = sqrt(pow(a, 2) + pow(b, 2));
	
	int num = temp;
	
	if (temp == num){
		return num;
	}
	
	return -1;
}

 triplet(int terms, int range) {
	for(int a = range; a > 0; a--) {
		for(int b = range; b > 0; b--) {
			int c_val = c(a, b);

			if ( (a + b + c_val) == 1000) {
				std::cout << "a = " << a << " | b = " << b << " | c = " << c_val << "\n\n";
				return a * b * c_val;
			}
		}
	}
}

int main() {
	int terms = 3;
	
	int range = 1000/2;
	
	std::cout << "Product: " << triplet(terms, range) << std::endl;

}
