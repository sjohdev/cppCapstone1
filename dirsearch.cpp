#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cassert>

namespace utils {
    bool stringControl(std::string inputString) {
        // Initialize variables
        const int numChars = inputString.length();
        int ascii = 0;
        bool isBadSymbol = false;
        
        // check each character for prohibited symbols: 
        for (char letter : inputString) {
            // Convert letter to ascii number
            ascii = static_cast<int>(letter);
            
            // Prohibited characters: ' ', ':', ';', '?', '//', '-'
            isBadSymbol = ascii < 42 || (ascii > 42 && ascii < 46) || (ascii > 57 && ascii < 65) || (ascii > 90 && ascii < 95) || ascii > 122;
            if (isBadSymbol) {
                // Prohibited character detected: Return Failed flag
                return false;
            }
        }
        return true;
    }
    
    void dirSearchMenu() {
        // Bash find command syntax: find DIR -name 'filename.ext'
        // Bash find file in current directory and subdirs: find $(pwd) -name 'filename.ext'
        // Alternatively: find ./ -name 'filename.ext'
        
        // Initialize input variable
        std::string targetDir;
        std::string fullFilename;
        
        // User prompt 1: directory 
        std::cout << "Directory Search." << std::endl;
        std::cout << "Please enter directory path (./ for current dir): ";
        std::getline(std::cin, targetDir);
        if (std::cin.fail()) {
            std::cout << "Error: cin failed. Exiting" << std::endl;
            assert(1==0); // forced exit
        }
        
        // User prompt 2: filename 
        std::cout << "Please enter full filename (*.ext for all files with extension 'ext'): ";
        std::getline(std::cin, fullFilename);
        if (std::cin.fail()) {
            std::cout << "Error: cin failed. Exiting" << std::endl;
            assert(1==0); // forced exit
        }
        
        // Perform rigorous input checking to block any injection attempts
        if (stringControl(targetDir) && stringControl(fullFilename)) {
            // If inputs are OK, proceed
            // Call bash find method and store result in logfile: 
            const std::string searchCommand = "find " + targetDir + " -name '" + fullFilename + "'" + " > cpplog.txt";
            // Make sure system process is available
            bool procReady = not(std::system(nullptr) == 0);
            if (procReady) {
                // Run search command using the Unix terminal
                std::system(searchCommand.c_str());
            }
            
            // Confirm user input, search command, and search result: 
            std::cout << "Directory: " << targetDir << std::endl;
            std::cout << "Filename: " << fullFilename << std::endl;
            std::cout << "Search command: " << searchCommand << std::endl;
            std::cout << "Search results: " << std::endl;
            std::cout << std::ifstream("cpplog.txt").rdbuf(); 
        } else {
            // Erroneous input strings from the user: Abort
            std::cout << "Error: invalid text input from user detected. Exiting" << std::endl;
        }
    }
}
