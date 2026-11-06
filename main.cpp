#include <iostream>
#include <cassert>
#include "utility.h"

int main() {
    // Initialize variables
    int progSelect = 1;
    bool isValidSelection = false;
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
        std::cout << "Please select program: ";
        std::cin >> progSelect;
        // Make sure cin did not crash and if so handle the error
        if (std::cin.fail()) {
            std::cout << "Error: cin failed. Exiting" << std::endl;
            return 0;
        }
        // Make sure user input is a valid option
        isValidSelection = (progSelect > 0 && progSelect < 5);
        if (!isValidSelection) {
            std::cout << "Error: invalid option selected. Exiting" << std::endl;
            return 0;
        }
        assert(isValidSelection);
        
        // Flush input buffer before running programs: 
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        
        // Run selected program
        switch (progSelect) {
            case 1: 
                utils::bmiMenu();
                break;
            case 2:
                utils::tokenizerMenu();
                break;
            case 3:
                utils::editorShellMenu();
                break;
            case 4: 
                utils::dirSearchMenu();
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
