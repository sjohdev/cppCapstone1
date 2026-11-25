#include <iostream>
#include <cassert>
#include "utility.h"
#include <cstdlib>
#include <format>

namespace Utils {

    void runSysCommand(const std::string& launchCommand) {
        // Make sure system process is available
        bool procReady = not(std::system(nullptr) == 0);
        if (procReady) {
            // Run command using the Unix terminal
            std::system(launchCommand.c_str());
        }
    }
    
    bool getUserConsent() {
        char usrInput;
        std::cout << "Continue (y/n)?: ";
        std::cin >> usrInput;
        if (std::cin.fail()) {
            std::cout << "Error: cin failed. Exiting" << std::endl;
            assert(1==0); // forced exit
        }
        return (usrInput == 'y') || (usrInput == 'Y'); 
    }

    int getUserInt(const std::string& prompt, const int min, const int max) {
        int result = min - 1;
        std::cout << prompt;
        std::cin >> result;
        if (std::cin.fail() || (result < min) || (result > max)) {
            std::cout << "Error: cin failed. Exiting" << std::endl;
            assert(1==0); // forced exit
        }
        return result;
    }

    void editorShellMenu() {
        // Initialize input variable
        int editorChoice = 1;
        std::string fullFilename;
        const char *editorList[] = {"gedit", "nano", "code"};
        const int numEditors = sizeof(editorList) / sizeof(editorList[0]);
        bool isvalidFilename = false;
        char continueYesNo = 'n';
        
        // User prompt 1: directory 
        std::cout << "Tex-Editor Shell." << std::endl;
        std::cout << "Number of installed editors: " << numEditors << std::endl;
        // List installed editors
        for (int i = 0; i < numEditors; i++) {
            std::cout << i + 1 << ") " << editorList[i] << std::endl;
        }
        
        // prompt 1: editor nr
        std::string prompt = std::format("Please select text-editor (1-{}): ", numEditors);
        editorChoice = getUserInt(prompt, 1, numEditors);
        
        // Flush input buffer before getline: 
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        
        // User prompt 2: filename 
        getUserStr("Please enter full filename (including extension): ", fullFilename);
        
        // input control: filename are valid. editorChoice control is checked in getUserInt
        isvalidFilename = stringControl(fullFilename);
        
        if (isvalidFilename) {
            std::cout << "Input syntax OK." << std::endl;
            // If inputs are OK, proceed
             // Convert char array to string using string constructor
            std::string editorString(editorList[editorChoice - 1]);
            // assemble command to be run
            const std::string launchCommand = editorString + " " + fullFilename;
            std::cout << "Command to be run: " << launchCommand << std::endl;
            continueYesNo = getUserConsent();
            
            if (continueYesNo) {
                std::cout << "Running command..." << std::endl;
                runSysCommand(launchCommand);
            } else {
                std::cout << "Command aborted." << std::endl;
            }
        } else {
            std::cout << "Error: invalid input detected. Exiting" << std::endl;
        }
    }
}
