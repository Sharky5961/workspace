#ifndef PRIME_H
#define PRIME_H

#include <string>

class Prime {
	private:
		int prime;

		bool isPrime;
		bool ifPrime(int num);

	public:
		Prime(int prime);
		Prime();

		int  getPrime();
		bool getIfPrime();

};

#endif
