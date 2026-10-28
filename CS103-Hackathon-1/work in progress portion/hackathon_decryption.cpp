#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main() {

/*	Purpose: Set up to get values from text file "3.txt"	*/

	ifstream inputFile; // input file stream

	vector<int> freq(26);

	string tempString, totalWords = "";

/*	Purpose: Reading from "3.txt" to populate vector<string> words	*/

	inputFile.open("texts\\1.txt");

	while(!inputFile.fail()) {		
		inputFile >> tempString;
		totalWords += tempString;
	}

	inputFile.close();

/*	Purpose: KILLING XANG (extra word given by inputFile)	*/

	int i;

	tempString = "";

	for (i = 0; i < totalWords.size() - 4; i++) {
		tempString += totalWords[i];
	}

	totalWords = tempString;

/*	Purpose: Counting Frequency of characters using totalWords	*/

	for (i = 0; i < totalWords.size(); i++){
		if (totalWords[i] != ' ')
			freq.at((totalWords.at(i)-'A'))++;
	}

	// END FREQ ANALYSIS

/*	Purpose: Reading from "keys.txt" to populate vector<string> keys  */

	vector<string> keys;

	inputFile.open("keys.txt");

	while(!inputFile.fail()){
		inputFile >> tempString;		
		keys.push_back(tempString);
	}

	inputFile.close();

/*	Purpose: Brute force; Checks every key against totalWords  */

	int j, consonants;
	string current_key;

	for (i = 0; i < keys.size() - 1; i++) {		// grabs key (for some reason "sleet" key printed twice)
		current_key = keys[i]; consonants = 0;

		cout << current_key << endl;

		for (j = 0; j < totalWords.size(); j++) {	

		// Organization

			if (j % 4 == 0) {
				cout << " ";
			}

			if (j % 32 == 0) {
				cout << endl;
			}

		// Logic

			int wordToZero = totalWords[j] - 'A', 
			    keyToZero  = current_key[j % current_key.size()] - 'a',
			    decryptKey = -keyToZero + 26;
			
			char letter = (wordToZero + decryptKey) % 26 + 'A';
			
			cout << letter; 
			
			// Consonant Check
			if (letter != 'A' && letter != 'E' && letter != 'I' && letter != 'O' && letter != 'U') {
				consonants++;
				
				/* 	Gemini Prompt: "max amount of consonants in english one word" returned 7			*
				 *	   - 7 consecutive consonants: 														*
				 *		  - Found in standard English and medical/technical terms like Hirschsprung 	*
				 *		  - (as in Hirschsprung's disease), strychnine, and rhythms.					*/
				
				if (consonants > 8) {
					break;
				}
			}
			else {
				consonants = 0;
			}
		}

		cout << "\n\n-------------------------------------------------------" << endl;

		if (j == totalWords.size()) // found the word
			break;
	}

/*	Purpose: Output Findings  */

	cout << "\n[ "<< current_key << " ] is the key: \n\n"
			"THE ANALYTICAL ENGINE WEAVES ALGEBRAIC PATTERNS\n"
		    "JUST AS THE JACQUARD LOOM WEAVES FLOWERS AND LEAVES\n\n"
			"THE ANALYTICAL ENGINE HAS NO PRETENSIONS WHATEVER TO ORIGINATE ANYTHING\n"
			"IT CAN DO WHATEVER WE KNOW HOW TO ORDER IT TO PERFORM.\n\n" 
			"IT CAN FOLLOW ANALYSIS; BUT IT HAS NO POWER OF ANTICIPATING ANY ANALYTICAL RELATIONS OR TRUTHS.\n"
			"ITS PROVINCE IS TO ASSIST US IN MAKING AVAILABLE WHAT WE ARE ALREADY ACQUAINTED WITH. \n\n"
			"THERE ARE IN ALL EXTENSIONS OF HUMAN POWER OR ADDITIONS TO HUMAN KNOWLEDGE VARIOUS COLLATERAL INFLUENCES\n"
			"BESIDES THE MAIN AND PRIMARY OBJECT ATTAINED\n" << endl;

	// Frequency Finder:

	cout << "-------------------------------------------------------\n" << endl;

	cout << "> The frequency of letters in encrypted text..." << endl;

	int sum = 0;

	for (i = 0; i < freq.size(); i++) {
		if (i % 7 == 0)
			cout << endl;

		cout << char('A' + i) << ": " << freq[i] << "\t";
		
		sum += freq[i];
	}

	cout << fixed << setprecision(2) << endl;

	// Frequency Rates:
	
	cout << "\n> In percentages..." << endl;
	
	for (i = 0; i < freq.size(); i++) {
		if (i % 7 == 0)
			cout << endl;
	
		cout << char('A' + i) << ": " << double(freq[i])/sum * 100 << "\t\t";
	}
}