#include <iostream>
#include <cassert>
#include <iomanip>  // For formatting output

namespace utils {
    void bmiMenu() {
        // Initialize variables
        float weightKg = 0.0;
        float heightM = 1.0;
        
        // User prompt:
        std::cout << "BMI calculator. Please enter your weight and height. " << std::endl;
        std::cout << "Weight [kg]: ";
        std::cin >> weightKg;
        if (std::cin.fail()) {
            std::cout << "Error: cin failed. Exiting" << std::endl;
            assert(1==0); // forced exit
        }
        std::cout << "Height [m]: ";
        std::cin >> heightM;
        if (std::cin.fail()) {
            std::cout << "Error: cin failed. Exiting" << std::endl;
            assert(1==0); // forced exit
        }
        
        // Making sure the divisor is not close to zero:
        if (heightM > 0.01 || heightM < -0.01) {
            std::cout << std::fixed << std::setprecision(1); // One decimal in result
            std::cout << "Your BMI = " <<  weightKg / (heightM * heightM) << std::endl;     
        } else {
            std::cout << "Error: Close to dividing by zero. Exiting" << std::endl;
        }
    }
}
