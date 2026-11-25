#include <iostream>
#include <cassert>
#include "utility.h"

int main() {
    // Initialize variables
    int progSelect = 1;
    bool isNextLoop = false;
    char newloopYesNo = 'n';
    do {
        // Present program selection to user
        std::cout << "====== Command-line Utility App ======" << std::endl;
        std::cout << "Available programs: " << std::endl;
        std::cout << "1. BMI calculator " << std::endl;
        std::cout << "2. Text tokenizer " << std::endl;
        std::cout << "3. Text-editor shell " << std::endl;
        std::cout << "4. Directory file-search" << std::endl;
        progSelect = Utils::getUserInt("Please select program: ", 1, 4);
        
        // Flush input buffer before running programs: 
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        
        std::cout << "======================================" << std::endl;
        // Run selected program
        switch (progSelect) {
            case 1: 
                Utils::bmiMenu();
                break;
            case 2:
                Utils::tokenizerMenu();
                break;
            case 3:
                Utils::editorShellMenu();
                break;
            case 4: 
                Utils::dirSearchMenu();
                break;
            default: 
                assert(1==0); // Should never happen
                break;
        }
        // Ask if user wants to run another program
        std::cout << "Run another program (y/n)?: " << std::endl;
        std::cin >> newloopYesNo;
        // Make sure cin did not crash and if so handle the error
        if (std::cin.fail()) {
            std::cout << "Error: cin failed. Exiting" << std::endl;
            return 0;
        }
        isNextLoop = (newloopYesNo == 'y' || newloopYesNo == 'Y');
    } while (isNextLoop);
    
    return 0;
}

