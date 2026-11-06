#include <iostream>
#include <cassert>
#include "utility.h"
#include <cstdlib>

namespace utils {
    void editorShellMenu() {
        // Initialize input variable
        int editorChoice = 1;
        std::string fullFilename;
        const char *editorList[] = {"gedit", "nano"};
        const int numEditors = sizeof(editorList) / sizeof(editorList[0]);
        bool isValidEditor = false;
        bool isvalidFilename = false;
        char continueYesNo = 'n';
        
        // User prompt 1: directory 
        std::cout << "Tex-Editor Shell." << std::endl;
        // List installed editors: 
        std::cout << "Number of installed editors: " << numEditors << std::endl;
        // List installed editors
        for (int i = 0; i < numEditors; i++) {
            std::cout << i + 1 << ". " << editorList[i] << std::endl;
        }
        std::cout << "Please select text-editor of choice (1-" << numEditors << "): ";
        std::cin >> editorChoice;
        if (std::cin.fail()) {
            std::cout << "Error: cin failed. Exiting" << std::endl;
            assert(1==0); // forced exit
        }
        
        // Flush input buffer before getline: 
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        
        // User prompt 2: filename 
        std::cout << "Please enter full filename (including extension): ";
        std::getline(std::cin, fullFilename);
        if (std::cin.fail()) {
            std::cout << "Error: cin failed. Exiting" << std::endl;
            assert(1==0); // forced exit
        }
        
        // input control: make sure editor selection and filename are valid
        isValidEditor = (editorChoice > 0 && editorChoice <= numEditors);
        isvalidFilename = stringControl(fullFilename);
        
        if (isValidEditor && isvalidFilename) {
            std::cout << "Input syntax OK." << std::endl;
            // If inputs are OK, proceed
             // Convert char array to string using string constructor
            std::string editorString(editorList[editorChoice - 1]);
            // assemble command to be run
            const std::string launchCommand = editorString + " " + fullFilename;
            std::cout << "Command to be run: " << launchCommand << std::endl;
            std::cout << "Continue (y/n)?: " << std::endl;
            std::cin >> continueYesNo;
            if (std::cin.fail()) {
                std::cout << "Error: cin failed. Exiting" << std::endl;
                assert(1==0); // forced exit
            }
            
            if (continueYesNo == 'y' || continueYesNo == 'Y') {
                std::cout << "Running command..." << std::endl;
                // Make sure system process is available before calling system()
                bool procReady = not(std::system(nullptr) == 0);
                if (procReady) {
                    // Run command using the Unix terminal
                    std::system(launchCommand.c_str());
                }
            } else {
                std::cout << "Command aborted." << std::endl;
            }
        } else {
            std::cout << "Error: invalid input detected. Exiting" << std::endl;
        }
    }
}
