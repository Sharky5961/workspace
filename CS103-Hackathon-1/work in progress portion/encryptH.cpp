/*
LILLIANETH RIVAS.

Encryption Algorythm desing nothes:

in this program, i want to design my own encryption algorithm using a pseudorandom number generator
the program will read text entered by the user, encrypt it, and display both the encrypted message and the key in the console.

I usually take my time to think about what I want to do before writing any code. 
Sometimes I even draw diagrams or write down the steps to better understand my ideas. 
These are my initial thoughts and the process i plan to follow.

my steps:

-get the original text from the user
-obtain the initial values (seeds)
-design a pseudorandom number generator (PRNG)
-generate a sequence of shifts using mathematical operations (took me many hours)
-decide how to apply the mathematical operations to each character
-encrypt the text using the generated shifts
-display the encrypted message and the key in the console
-check reversibility. can my teammates use the key and the same algorithm to recover the original message?

my initial idea for the prng:

my first idea was to use the words entered by the user to obtain the initial values for my generator.
for example, if the first word is: >>	H U N G R Y  << the word contains six letters, but since indexing starts at zero, the last index is 5
so, i could use the number 5 as the first initial value for my mathematical formula. i also considered using the second word to obtain another 
initial value, since i am exploring a formula that depends on two previous numbers. later, i started exploring how prime numbers could be involved
(im personally interested in odd numbers for my phD :) ) in generating the next values. i wanted to use modular arithmetic to keep the results 
between 0 and 25, corresponding to the 26 letters of the english alphabet.
my goal is to generate different shifts for the characters instead of using one fixed shift like the Caesar cipher.

This idea is still a work in progress. I need to test the formula, understand its limitations, and make sure that the encryption process can be reversed by my teammates.

inspiration:
my encryption method is inspired by the one-time pad, particularly the idea of using a different shift for each character. however, my approach uses a 
deterministic pseudorandom sequence, so it is not a true one-time pad and does not provide the same security guarantees.
I am mainly focusing on understanding the mathematics, creating a reversible process, and experimenting with my own ideas.

	MATHEMATICAL FORMULA AND prng DESIG

	after thinking about how to generate the initial values, I started exploring different mathematical operations for my pseudorandom number generator.
	i wanted to use prime numbers because i find them interesting, and i thought they could be useful for generating different values instead of using a fixed number.
	i explored a formula that uses prime numbers, the two previous values, and modular arithmetic:

	X_(n+1) = (p_n X_n + X_(n-1) + n + 1) mod 26

	-X_(n+1): the next number generated.
	-X(n): the previous number.
	-X(n−1): the number before the previous one.
	-p(n): a prime number used during the current iteration.
	-n: the iteration index.
	-mod 26: Keeps the results between 0 and 25, matching the english alphabet.

	I chose to explore a formula that uses two previous values because i wanted each new number to depend on more than one previous result(i tried with one 
	value and was repetitive).The prime numbers also change as the sequence progresses. for example, the first few primes used could be 3, 5, 7, 11, 13, and so on. 
	the purpose is to produce a sequence of numbers that can be used as different shifts when encrypting the text. i am still testing how the sequence behaves and 
	how to implement the process independently in C++. The sequence is deterministic, meaning that the same initial values and the same formula will always generate 
	the same numbers. This is important because my teammates need to reproduce the sequence to decrypt the message.

further explanations:
first two words ---- > are the initial values
then prime bases PRNG
sequence of numbers 0-25
apply shifts to plain text
ciphertext + key
*/
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cctype>

int main() {
	//variables and vector decl
	int key;
	string userInputText;
	vector<string> userText;
	int i;
	vector<int> primeNumbers;
	vector<int> genKeys;

	//get text from user
	cout << "This program will encrypt the text you enter." << endl<<endl;
	cout << "Please, write the text you want to encrypt: " << endl;

	getline(cin, userInputText);
	cout << endl;
	string word = "";
	//store characters until a space is found
	//save the word in the vector and start a new one
	for (i = 0; i < userInputText.size(); i++) {
		if (userInputText.at(i) != ' ') {
			word = word + userInputText.at(i);
		}//save the word when a space is found
		else if (!word.empty()) {
			userText.push_back(word);//push the word to vector
			word = "";//clear the word to start againn
		}
	}//save the last word if it is not empty
	if (!word.empty()) {
		userText.push_back(word);
	}

	//check that input should be at least 2 words
	if (userText.size() < 2) {
		cout << "Error, please enter at least two words!" << endl;
		return 1;
	}
	//-------------getting firt initializer------------------
	//initialize counter
	int sum1 = 0;
	for (i = 0; i < userText.at(0).size(); i++) {
		char letter = toupper(userText.at(0).at(i));
		if (letter >= 'A' && letter <= 'Z') {
			sum1 = sum1 + (letter - 'A');
		}
	}//in each iteration, we convert a letter into its alphabetical 
	// position and add that number to sum:
	//for example RANDOM 
	//R -17   sum = 17
	//A -0	  sum = 17
	//N -13   sum = 30
	//D -3    sum =33
	//O -14   sum = 47
	//M -12   sum =59
	int X_0 = sum1 % 26; //and apply 59 mod 26 = 7
	cout <<"initial state X_0: " << X_0 << endl;

	//-------------getting second initializer------------------
	int sum2 = 0; 
	//If we did not reset the sum before processing the word, 
	// we would be accumulating the values ​​of both words, we need a new one
	for (int j = 0; j < userText.at(1).size(); j++) {
		char letter = toupper(userText.at(1).at(j));
		if (letter >= 'A' && letter <= 'Z') {
			sum2 = sum2 + (letter - 'A');
		}
		
	}
	int X_1 = sum2 % 26;
	cout << "initial state X_1: " << X_1 << endl<<endl;

	//---------------prng starts here :DDD lets see if work-------------
	//formula X_(n+1) = (p_n X_n + X_(n-1) + n + 1) mod 26



	for (int k = 3; primeNumbers.size() < 100; k++) {//start looking numbers from 3 and so on
		bool myPrime = true;//suppose is prime

		//check if k is prime
		for (i = 2; i < k; i++) {
			if (k % i == 0) {//is divisible by other number?
				myPrime = false;
				break;
			}
		}
		//store the prime number
		if (myPrime) {
			primeNumbers.push_back(k);
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << primeNumbers.at(i) << " " << endl;
	}
	//------------------------------------------

	//count the letters in the message
	int totalLetters = 0;

	for (i = 0; i < userInputText.size(); i++) {
		char letter = toupper(userInputText.at(i));

		if (letter >= 'A' && letter <= 'Z') {
			totalLetters++;
		}
	}
	cout << "Total letters: " << totalLetters << endl;

	//--------------creat out first value X_2-------------
	
	// testing int X_2 = (primeNumbers.at(0) * X_1 + X_0 + 2) % 26;
	//testing cout << "First generated value: " << X_2 << endl;

	//store the initial states
	genKeys.push_back(X_0);
	genKeys.push_back(X_1);
	//generate the next prng values
	for (i = 1; i <= totalLetters; i++) {
		//formula X_(n+1) = (p_n X_n + X_(n-1) + n + 1) mod 26
		int nextX = (primeNumbers.at(i - 1) * genKeys.at(i) + genKeys.at(i - 1) + i + 1) % 26;
		genKeys.push_back(nextX);
	}

	/*//-----------testing-----
	for (int i = 0; i < genKeys.size(); i++) {
		cout << "X" << i << ": " << genKeys.at(i) << endl;}
		*/

	//----------------------------------encrypting!!!-----------------------------------------
	// 
	//store the encrypted message
	string encText = "";
	//keep track of the generated keys
	int keyIndex = 2;// x0= initial x1= initial x2= first letter...so on
	// Encrypt the message character by character
	//this for loop is not encoding yet, first we should separate the three cases in order to preserve
	//uppercase and lowecase, spaces and punctiation

	//to encrypt one uppercase what an i do?
	//imgoing to use c=(p+k)mod26 ( cesar) we can use a different one of course(to be original) but 
	// for now my mind is going to explode!
	// 
	// c= position of the letter encrypted
	// p= position of the original letter
	// k = the key generated by our prng
	// mod 26 keeps our result btween 0 and 25
	for (i = 0; i < userInputText.size(); i++) {
		char letter = userInputText.at(i);

		if (letter >= 'A' && letter <= 'Z') {
			int P = letter - 'A';
			int K = genKeys.at(keyIndex);
			int C = (P + K) % 26;
			encText = encText + char(C + 'A');
			keyIndex++;
			//encrypt uppercase
		}
		else if (letter >= 'a' && letter <= 'z') {
			int P = letter - 'a';
			int K = genKeys.at(keyIndex);
			int C = (P + K) % 26;
			encText = encText + char(C + 'a');
			keyIndex++;
			//encrypt lowercase
		}
		else {
			//keep spaces and punctuation unchanged
			encText = encText + letter;
		}
	}
	cout << endl;
	cout << "original text: " << userInputText << endl;
	cout << "encrypted text: " << encText << endl;
	cout << "key X_0: " << X_0 << endl;
	cout << "Key X_1: " << X_1 << endl;


	return 0;
}