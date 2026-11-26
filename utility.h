
#ifndef UTILITY_H
#define UTILITY_H
namespace Utils {
    float calcBmi(float& weightKg, float& heightM);
    void bmiMenu();
    void tokenizerMenu();
    void editorShellMenu();
    void dirSearchMenu();
    bool stringControl(const std::string& inputString);
    void runSysCommand(const std::string& launchCommand);
    bool getUserConsent();
    int getUserInt(const std::string& prompt, const int min = 0, const int max = 255);
    void getUserStr(const std::string& prompt, std::string& targetStr);
}
#endif
