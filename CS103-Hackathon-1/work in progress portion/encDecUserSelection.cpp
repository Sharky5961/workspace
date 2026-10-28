/*
	This program encloses both projects together and a user interface.
	Program done by group 3.

	Team Roles and main jobs:
		Frank Desueza
			
		Lillianeth Rivas
		
		
		Richard Masak 
		
		
		Vitalii KOcvalchuk
		
	
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <unistd.h>

using namespace std;

int main() {

    //Variable declarations
    int option;
    int goBack;
    
	unsigned int i, j;
    
    do {
        //---------------- USER INTERFACE--------------------------------------------------
        cout << "\n"
            "==================================================\n"
            "         TEAM 3 BOB & ALICE CRYPTO LAB            \n"
            "        Rich, Frank, Lillianeth & Vitalii         \n"
            "==================================================\n"
            "  Welcome! What would you like to do?\n\n"
            "  1. Analyze & decrypt\n"
            "     Explore the assigned encrypted text.\n\n"
            "  2. Encrypt a message\n"
            "     Turn your own message into a secret.\n\n"
            "==================================================\n"
            "  Enter your choice (1 or 2): ";

        cin >> option;
        cin.ignore();

        if (option == 1) {
            // ---------------------PART ONE DECRYPTION----------------------------------------
            
            cout << "\n"
                "                                                   \n"
                "              TEXT ANALYSIS & DECRYPTION           \n"
                "---------------------------------------------------\n"
                "  Let's uncover Alice's secret message!\n\n"
                "  The program will:\n"
                "  ~ Count each letter in the encrypted text.\n"
                "  ~ Test possible keys from keys.txt.\n"
                "  ~ Suggest a key and reveal the decrypted text.\n\n"
                "                                                   \n"
                "  Reading encrypted text from 3.txt...\n"
                "---------------------------------------------------\n\n";
                usleep(5 * pow(10,6)); // 5 seconds
            /*	Purpose: Set up to get values from text file "3.txt"	*/

            ifstream inputFile; // input file stream

            vector<int> freq(26);

            string tempString, totalWords = "";

            /*	Purpose: Reading from "3.txt" to populate vector<string> words	*/

            inputFile.open("3.txt");

            while (!inputFile.fail()) {
                inputFile >> tempString;
                totalWords += tempString;
            }

            inputFile.close();
            
			/*	Purpose: KILLING XANG (extra word given by inputFile)	*/

            tempString = "";

            for (i = 0; i < totalWords.size() - 4; i++) {
                tempString += totalWords[i];
            }

            totalWords = tempString;

            /*	Purpose: Counting Frequency of characters using totalWords	*/

            for (i = 0; i < totalWords.size(); i++) {
                if (totalWords[i] != ' ')
                    freq.at((totalWords.at(i) - 'A'))++;
            }

            // END FREQ ANALYSIS

        /*	Purpose: Reading from "keys.txt" to populate vector<string> keys  */

            vector<string> keys;

            inputFile.open("keys.txt");

            while (!inputFile.fail()) {
                inputFile >> tempString;
                keys.push_back(tempString);
            }

            inputFile.close();

            /*	Purpose: Brute force; Checks every key against totalWords  */

            int consonants;
            string current_key;

            for (i = 0; i < keys.size() - 1; i++) {		// grabs key (for some reason "sleet" key printed twice)
                current_key = keys[i]; 
                consonants = 0;

                cout << "Testing key: " << current_key << "\n";
                usleep(pow(10,5)); // 1/10 second

                for (j = 0; j < totalWords.size(); j++) {//ill go over all letter of the encrypted text

                    // Organization

                    if (j % 4 == 0) {
                        cout << " ";
                    }

                    if (j % 32 == 0) {
                        cout << endl;
                    }

                    // Logic

                    int wordToZero = totalWords[j] - 'A',//convert each word to a number
                        keyToZero = current_key[j % current_key.size()] - 'a',
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
            usleep(15 * pow(10,5)); // 1.5 seconds
            cout << "\n[ " << current_key << " ] is the key: \n\n"
                "THE ANALYTICAL ENGINE WEAVES ALGEBRAIC PATTERNS\n"
                "JUST AS THE JACQUARD LOOM WEAVES FLOWERS AND LEAVES\n\n"
                "THE ANALYTICAL ENGINE HAS NO PRETENSIONS WHATEVER TO ORIGINATE ANYTHING\n"
                "IT CAN DO WHATEVER WE KNOW HOW TO ORDER IT TO PERFORM.\n\n"
                "IT CAN FOLLOW ANALYSIS; BUT IT HAS NO POWER OF ANTICIPATING ANY ANALYTICAL RELATIONS OR TRUTHS.\n"
                "ITS PROVINCE IS TO ASSIST US IN MAKING AVAILABLE WHAT WE ARE ALREADY ACQUAINTED WITH. \n\n"
                "THERE ARE IN ALL EXTENSIONS OF HUMAN POWER OR ADDITIONS TO HUMAN KNOWLEDGE VARIOUS COLLATERAL INFLUENCES\n"
                "BESIDES THE MAIN AND PRIMARY OBJECT ATTAINED\n" << endl;
			usleep(3*pow(10,6));
			
			cout << "What we thought of this text: \n"
					"Lovelace's work on the analytical engine, and what she wrote as a result is a grim reminder that \n"
					"artifical intelligence does not actually come to conclusions or make novel ideas, and are entirely \n"
					"on user input. We can and should only use the concept of artifical intelligence to help us in \n"
					"the things 'we are already acquainted with'. \n"
					"It also reminded us of a quote from an IBM training manual that stated: \n"
					"\n"
					"\t A computer can never be held accountable, therefore a computer must never make a management decision \n"
					"\n"
					"As much as these new technologies are powerful, we must be aware of what they do under the hood, and the \n"
					"reliance they still have on user input, because they are not alive, nor do they create." << endl;

            // Frequency Finder:
			
			
            cout << "-------------------------------------------------------\n" << endl;

            cout << "> The frequency of letters in encrypted text..." << endl;
            usleep(15 * pow(10,5)); // 1.5 seconds

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
            usleep(15 * pow(10,5)); // 1.5 seconds

            for (i = 0; i < freq.size(); i++) {
                if (i % 7 == 0)
                    cout << endl;

                cout << char('A' + i) << ": " << double(freq[i]) / sum * 100 << "\t\t";
            }
        }
       

        //--------------------------------------------END OF PART 1 -------------------------------------------


        //--------------------------------PART 2 STARTS HERE ENCRYPTION ---------------------------------------
        else if (option == 2) {

            string userInputText;
            vector<int> primeNumbers = {2};
            vector<int> genKeys;
            
            //user input
            cout << "\n"
                "                                                  \n"
                "                 ENCRYPT A MESSAGE                \n"
                "--------------------------------------------------\n"
                "  Enter a message with at least one word.\n"
                "  Spaces and punctuation will be preserved.\n\n"
                "  Your message:\n";

            getline(cin, userInputText);

            //------------------------------------
            /*The first two groups of consecutive english letters
            provide the seeds. Non-letter characters separate groups.
            Letter values are added using A = 0 through Z = 25,
            then reduced modulo 26.

            if there is only one group, X_1 = X_0.
            */

            //count letters into the first two words
            int firstWord = 0;
            int secondWord = 0;
            //accumulate letter values to create the seeds
            int X_0 = 0;
            int X_1 = 0;
            //false while reading the first word
            bool nextWord = false;

            for (i = 0; i < userInputText.size(); i++) {
                //user uppercase to give lcase letters the same values
                char letter = toupper(userInputText.at(i));

                if (letter >= 'A' && letter <= 'Z') {
                    if (!nextWord) {
                        //count and add values from the first word
                        firstWord++;
                        X_0 += letter - 'A';
                    }
                    else {
                        ///count and add values from second word
                        secondWord++;
                        X_1 += letter - 'A';
                    }
                }
                else {
                    if (firstWord > 0) {
                        nextWord = true;
                    }
                    //stop collecting whn second word ends
                    if (secondWord > 0) {
                        break;
                    }
                }
            }

            if (firstWord == 0) {
                cout << "Error: Please enter a message containing at least 1 letter.\n";
                goBack = 1;
                continue;
            }

            X_0 = X_0 % 26;//to keep seeds btwwn 0-25

            if (secondWord == 0) {//is there is only one words, copy x1 into x2
                X_1 = X_0;
            }
            else {
                X_1 = X_1 % 26;
            }

            
            //------------------ Count letters ------------------

            //count letters only, spaces and punctuation are ignored
            int totalLetters = 0;

            for (i = 0; i < userInputText.size(); i++) {

                char myLetter = toupper(userInputText.at(i));

                if (myLetter >= 'A' && myLetter <= 'Z') {
                    totalLetters++;
                }
            }
            cout << "\nPreparing your encryption key..." << endl;
            usleep(5 * pow(10,5)); // 0.5 seconds
            //------------------ Generate prime numbers ------------------

            /*
            Generate as many prime numbers as letters.

            The sequence begins with 3:  3, 5, 7, 11, 13, ...

            AI assistance:
            ChatGPT helped me understand how to test divisors up to the square root of a number,
            using division instead of sqrt().

            prompt:
            "how I check if is a prime? whithout using sqrt()"
            Accessed: October 2026.
            */
			
			int number = 3, current_number, i; // b/c primeNumbers already has {2}
            
			while (primeNumbers.size() < totalLetters + 1) {
				bool myPrime = true;
				
				current_number = number;
                
				//Check whether the number has a divisor
        		for (i = 0; i < primeNumbers.size(); i++) {
                	
            		if (current_number % primeNumbers[i] == 0) {
                		myPrime = false;
                		break;
            		}
            
            		if (int(sqrt(current_number)) <= primeNumbers[i]) {
            			break;
					}
                    
        		}//how tho check if only the 

                //Store the number only if it is prime
        		if (myPrime) {
            		primeNumbers.push_back(current_number);
    			}
                
        		number++;
    		}
    		
    		vector<int> temp;
    		for (i = 1; i < primeNumbers.size(); i++) { // we don't want to use 2
    			temp.push_back( primeNumbers[i] );
			}
			
			primeNumbers = temp;

            //------------------ Generate PRNG values ------------------

            /*
            pseudorandom generator formula:

            X_(n+1) = (p_n * X_n + X_(n-1) + n + 1) % 26

            This recurrence was developed with ChatGPT assistance from my ideas involving prime numbers,
            two previous states, and modular arithmetic.

            The generator is deterministic: the same seeds produce the same sequence.

            X_0 and X_1 are the initial states.
            X_2 is the first shift used for encryption.

            AI assistance:
            ChatGPT helped express the recurrence mathematically.
            prompt:
            "I have this formula, and i want to combine it with a list of prime numbers
            an use it with two initial data. and continue calculating more using mod 26."
            Accessed: October 2026.
            */

            genKeys.push_back(X_0);
            genKeys.push_back(X_1);

            //Generate one shift for each letter
            for (i = 1; i <= totalLetters; i++) {

                int next_X = (primeNumbers.at(i - 1) * genKeys.at(i) + genKeys.at(i - 1) + i + 1) % 26;

                genKeys.push_back(next_X);
            }

            //------------------ Encrypt the message ------------------

            /*
            Encryption formula:
            cesar!
            C = (P + K) % 26

            Each letter uses the next generated shift. Uppercase and lowercase letters are preserved.
            Spaces, numbers, and punctuation remain unchanged and do not consume a shift.
            I use the code implemented in our class as base.

            */

            string encText = "";

            //The first two vector elements contain the seeds
            int keyIndex = 2;

            for (i = 0; i < userInputText.size(); i++) {

                char thisLetter = userInputText.at(i);

                if ((thisLetter >= 'A' && thisLetter <= 'Z') || (thisLetter >= 'a' && thisLetter <= 'z')) {

                    char base = 'A';

                    if (thisLetter >= 'a' && thisLetter <= 'z') {
                        base = 'a';
                    }

                    int P = thisLetter - base;
                    int K = genKeys.at(keyIndex);
                    int C = (P + K) % 26;

                    encText += char(C + base);
                    keyIndex++;
                }
                else {
                    encText += thisLetter;
                }
            }
    //------------------------------------END OF PART 2 ------------------------------------------------------
            //------------------display results ------------------

            cout << endl;
            cout << "--------------------------------------------------\n";
            cout<<"  Encrypted text: \n" << encText << endl << endl;
            cout << " ---keys are: ---                                 \n";
            cout << "Key X_0: " << X_0 << endl;
            cout << "Key X_1: " << X_1 << endl;
            cout << "--------------------------------------------------\n";

        }
        else {
            cout << "Invalid option." << endl;
        }
        cout << endl;
        cout << "\n1. Return to the main menu" << endl;
        cout << "2. Exit" << endl;
        cout << "Choose an option: ";
        cin >> goBack;

    } while (goBack == 1);

    cout << "Bye! Team 3 wish you a wonderful day!" << endl;

    return 0;
}
