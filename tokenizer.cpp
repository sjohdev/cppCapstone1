#include <iostream>
#include <string>
#include <cassert>

namespace utils {
    void tokenizerMenu() {
        // Initialize input variable
        std::string inputString;
        
        // User prompt
        std::cout << "size of string: " << sizeof(inputString) << std::endl;
        std::cout << "size of int: " << sizeof(int) << std::endl;
        std::cout << "Tokenizer. " << std::endl; 
        std::cout << "Please enter text to be tokenized: ";
        std::getline(std::cin, inputString);
        if (std::cin.fail()) {
            std::cout << "Error: cin failed. Exiting" << std::endl;
            assert(1==0); // forced exit
        }
        std::cout << "String: " << inputString << std::endl;
        
        // initialize word lists:
        const int numChars = inputString.length();
        int wordIndexList[numChars];
        int wordLengthList[numChars];
        std::cout << "String length: " << numChars << std::endl;
        
        // identify position of all words in the string
        int startIndex = 0;
        int wordLength = 0;
        int wordIndex = 0;
        int character = 0;
        int numWords = 0;
        bool isSpecial = false;
        bool isEoString = false;
        for (int i = 0; i < numChars; i++) {
            character = inputString[i];
            isSpecial = character == ' ' || character == '.' || character == ',' || character == '?' || character == ':' || character == ';'; 
            isEoString = (not(isSpecial) && i == numChars - 1); // end of string and not special character
            if (isSpecial || isEoString) { 
                // End of word detected: store word in list and set new startindex
                wordLength = i - startIndex;
                if (wordLength > 0) {
                    // word has to be at least 1 characters long
                    if (isEoString) {
                        wordLengthList[wordIndex] = wordLength + 1;
                    } else {
                        wordLengthList[wordIndex] = wordLength;
                    }
                    wordIndexList[wordIndex] = startIndex;
                    wordIndex++;
                }
                // Omit special characters in words
                startIndex = i + 1;
            }
        }
        numWords = wordIndex;
        //int wordIncrement = wordLength - 1; 
        std::cout << "String has  " << numWords << " words: " << std::endl;
        
        // Print all words separately: 
        for (int j = 0; j < numWords; j++) {
            std::string word = inputString.substr(wordIndexList[j], wordLengthList[j]);
            std::cout << word << std::endl;
        }
        
        // Find all unique words and their number of occurrences:
        int uniqueWordIndice[numWords];
        int uniqueWordLengths[numWords];
        int uniqueWordCounter[numWords];
        int numUniqueWords = 0;
        bool isReplica = false;
        for (int j = 0; j < numWords; j++) {
            std::string word = inputString.substr(wordIndexList[j], wordLengthList[j]);
            for (int k = 0; k < numUniqueWords; k++) {
                std::string uniqueWord = inputString.substr(uniqueWordIndice[k], uniqueWordLengths[k]);
                if (word == uniqueWord) {
                    // Replica found in unique word list: 
                    isReplica = true;
                    uniqueWordCounter[k]++;
                    break;
                }
            }
            if (isReplica == false) {
                // Unique word found: add to unqie words:
                uniqueWordIndice[numUniqueWords] = wordIndexList[j];
                uniqueWordLengths[numUniqueWords] = wordLengthList[j];
                uniqueWordCounter[numUniqueWords] = 1;
                numUniqueWords++;
            }
            isReplica = false;
        }
        
        // Print all unique words together with their number of occurrences: 
        std::cout << "#" << numUniqueWords << " unique words found in text: " << std::endl;
        for (int n = 0; n < numUniqueWords; n++) {
            std::string uniqueWord = inputString.substr(uniqueWordIndice[n], uniqueWordLengths[n]);
            std::cout << n + 1 << ": '" << uniqueWord << "' occurs " <<  uniqueWordCounter[n] << " times. " << std::endl;
        }
    }
}

