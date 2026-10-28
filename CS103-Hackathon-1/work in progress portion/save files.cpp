#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

vector<string> solution(int);

string filePath(int x) {
	string temp = "";
	
	while(x > 0) {
		temp += '0' + x % 10;
		x /= 10;
	}
	
	string reverse = "texts\\";
	for (int i = temp.size(); i > 0; i--) {
		reverse += temp[i-1];
	}
	
	return reverse + ".txt";
}

string filePath(int x, string folderPath) {
	string temp = "";
	
	while(x > 0) {
		temp += '0' + x % 10;
		x /= 10;
	}
	
	string reverse = folderPath + "\\";
	for (int i = temp.size(); i > 0; i--) {
		reverse += temp[i-1];
	}
	
	return reverse + ".txt";
}

int main() {
	ofstream output;	// cout, but for files
	
	vector<string> found;
	
	string path = "solutions";
	
	for (int i = 0; i < 15; i++) {
		output.open( filePath(i+1, path) );
		
		found = solution(i+1);
		
		output << i + 1 << ".txt is... " << found[1] << endl;
		output << found[0] << endl;
		
		output << endl;
		
		output.close();
	}

}

vector<string> solution(int page) {
	
	ifstream inputFile;
	
	string fileDirectory = filePath(page);
	
	cout << '\n' << fileDirectory << '\n';
	
/*	Purpose: Set up to get values from text file "3.txt"	*/

	vector<int> freq(26);

	string tempString, totalWords = "";
		
	inputFile.open(fileDirectory);

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
	string current_key, temp;

	for (i = 0; i < keys.size() - 1; i++) {			// grabs key (for some reason "sleet" key printed twice)
		current_key = keys[i]; consonants = 0;
		temp = "";

		for (j = 0; j < totalWords.size(); j++) {	// repeat 2x bug for inputFile, reason for subtraction

		// Logic

			int wordToZero = totalWords[j] - 'A', 
			    keyToZero  = current_key[j % current_key.size()] - 'a',
			    decryptKey = -keyToZero + 26;
			
			char letter = (wordToZero + decryptKey) % 26 + 'A';
			
			//cout << letter; 
			temp += letter;
			
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

		if (j == totalWords.size()) // found the word
			break;
	}
	
	return {temp, current_key};
}
