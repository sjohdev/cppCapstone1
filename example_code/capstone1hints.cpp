// Example of input validation for a numeric input
double getValidNumber() {
    double num;
    while (!(std::cin >> num)) {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return num;
}
