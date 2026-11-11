#include "Prime.h"
#include <cmath>

bool Prime::ifPrime(int num) {
	if (num == 2)
		return true;

	if (num % 2 == 0 || num < 2)
		return false;

	for (int i = 3; i < sqrt(num) + 1; i++) {
		if (num % i == 0)
			return false;
	}

	return true;
}

Prime::Prime(int prime) {
	this->prime = prime;

	isPrime = ifPrime(prime);
}

Prime::Prime() {}

int Prime::getPrime() {
	return prime;
}

bool Prime::getIfPrime() {
	return isPrime;
}
