#include "Text.h"
#include <iostream>

int integer(char num) {
    return num - '0';
}

int main() {
    Text import;

    std::string text = import.text;

    int temp;
    std::cin >> temp;

    const int amountOfNumbers = temp;
    unsigned long long product, max = 0;

    int i, j;
    for (i = 0; i < text.size() - amountOfNumbers; i++) {
        product = 1;

        for (j = 0; j < amountOfNumbers; j++) {
            product *= integer(text[i + j]);
        }

        if (max < product) {
            max = product;
            std::cout << max << std::endl;
        }
    }
    std::cout << "\n[Largest Product Found = " << max << "]\n" << std::endl;
}

// NOTE: biggest issue is datatype size
// result of scaling up -> overflow datasize
// ==> easily reaches binary number cap
