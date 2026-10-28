/* Linked @: https://gist.github.com/Sharky5961/44c498f7172e7292c2dd724f3f5ca0e4 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

int specialNum(char LETTER) {
	if (isalpha(LETTER))
		return rand() % 26;
	else
    	return rand() % 10;
}

// SCROLL TO THE BOTTOM TO SEE DEFINITIONS
string cypher (string, int, int, int); 

// Overloaded functions for future use: makes cypher(string, int, int) valid for shorthand and randCypher(string, int, int) for shorthand

string cypher (string plainText, int key, int type) { return cypher(plainText, key, type, 0); } // Function Overloading to make Default case (no case randomizer)
string randCypher (string plainText, int key, int type) { return cypher(plainText, key, type, 1); } // Overloading for casing randomizer case

char encrypt(char, int);
char decrypt(char, int);

int stringToInt(string text) {
	int len = text.size();
	
	int num = 0;
	for (int i = 0; i < len; i++) {
		num += pow(10, len-i-1) * (text[i] - '0');
	}
	
	return num;
}

int main() {
	
	// Operating System terminal clear: by default set for windows ["cls"] ; Manually change to ["clear"] for LINUX DISTROs
	const char* clear = "cls"; 

/* ------------ MAIN POINT: Whether user wants to do ENCRYPTION or DECRYPTION ------------ */

	int CRYPTION; // [0 : encryption] || [1 : decryption]
	
	cout << "[0 : encryption] || [1 : decryption]" << endl;
	cout << "  > "; cin >> CRYPTION;
	
	system(clear); // clears terminal, found searching Gemini prompt ["sys clear c++"]; is inside of <cstdlib>
	
/* ------------ MAIN POINT: Whether user wants to do NO "RANDOMIZED" CASINGS or wants "RANDOMIZED" CASINGS ------------ */

	int randomizer = 1;
	
	do {
		
		if (randomizer != 1 && randomizer != 0) {
			cout << "Wrong Input, try again...\n" << endl;
		}
		
		cout << "[0 : Random Casing Off] || [1 : Random Casing On]" << endl;
		cout << "  > "; cin >> randomizer;
		
		system(clear);
		
	} while(randomizer != 1 && randomizer != 0);
	
/* ------------ MAIN POINT: __Gathers__ user values in BULK for the encrypt/decrypt and no-casing/casing settings ------------ */

	vector<vector<string>> values;
	
	string key, val;

	cout << "KEY, VALUE (-1 to end): \n" << endl;
	
	do {	
		cout << "  > "; cin >> key; cin >> val;

		if (key != "-1") 
			values.push_back( {val, key} );
	
	} while(key != "-1");
	
	cout << endl;

/* ------------ MAIN POINT: __Returns__ user values in BULK for the encrypt/decrypt and no-casing/casing settings ------------ */

	for (int i = 0; i < values.size(); i++) {
		cout << cypher(values[i][0], stringToInt(values[i][1]), CRYPTION, randomizer) << endl;
	}

}

string cypher (string plainText, int key, int type, int flip) { // where type = {0: encrypt; 1: decrypt}
	string temp = "";

	srand(key);

	vector <int> shifts(plainText.size());
	
	for (int i = 0; i < plainText.size(); i++) {
		shifts[i] = specialNum( plainText[i] ); // fills shift w/ the shifting numbers
	}
	
	for (int i = 0; i < shifts.size(); i++) {
    	if (flip == 1 && isalpha(plainText[i])) {
			if (rand()%2 == 1)
				if(isupper(plainText[i]))
    	            plainText[i] = tolower(plainText[i]);
				else
    	            plainText[i] = toupper(plainText[i]);  
    	}
        
    	if (type == 0)
    	    temp += encrypt(plainText[i], shifts[i]);
		else
    	    temp += decrypt(plainText[i], shifts[i]);    
	}
	
	return temp;
}

char encrypt(char LETTER, int shift) { // "shift" is hard-coded option
    // PRELIMINARY SET UP WHEN NEGATIVE SHIFT
    if (shift < 0) {
    	if (isalpha(LETTER))
        	shift += 26;
        else
			shift += 10;
    }
    
    // NEW CHAR
    if (isalpha(LETTER)) {
        if (isupper(LETTER))
            return (LETTER - 'A' + shift) % 26 + 'A';
        else
            return (LETTER - 'a' + shift) % 26 + 'a';
        }
    
	else if (isdigit(LETTER)) {
        return (LETTER - '0' + shift) % 10 + '0';
    }
    
    return LETTER; 
}

char decrypt(char LETTER, int shift) { 
	return encrypt(LETTER, shift*-1); 
}