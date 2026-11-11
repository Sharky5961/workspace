#include <iostream>
#include <fstream>
#include "Prime.h"

int main() {
    std::ifstream fin;
    std::ofstream fout;

    int iter = 2;
    int foundPrimes = 0;
    int threshold;

    Prime num;

    std::cin >> threshold;

    fout.open("primes\\storage.txt");

    fout << "Last Program Checked for prime at " << threshold << std::endl;
    while (foundPrimes < threshold) {
        num = Prime(iter++);
        if (num.getIfPrime()) {
            foundPrimes++;
            if (foundPrimes % (4 + 1) != 0)
                fout << "[ " << foundPrimes << " - " << num.getPrime() << " ]    ";
            else
                fout << std::endl;
        }
    }

    fout.close();

    std::cout << '[' << num.getPrime() << ']' << std::endl;

}
