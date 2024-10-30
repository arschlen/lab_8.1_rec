#include <iostream>
#include <cstring>
using namespace std;

// Рекурсивна функція для підрахунку кількості символів "+", "-", "="
int CountSymbols(const char* str, int& plusCount, int& minusCount, int& equalCount, int i = 0) {
    if (str[i] == '\0') {
        return 0;
    }
    if (str[i] == '+') plusCount++;
    if (str[i] == '-') minusCount++;
    if (str[i] == '=') equalCount++;
    return CountSymbols(str, plusCount, minusCount, equalCount, i + 1);
}

// Рекурсивна функція для заміни пар символів "++", "--", "==" на "***"
char* ReplacePairs(char* dest, const char* str, int i = 0, int j = 0) {
    if (str[i] == '\0' || str[i + 1] == '\0') {
        dest[j] = '\0';
        return dest;
    }
    if ((str[i] == '+' && str[i + 1] == '+') ||
        (str[i] == '-' && str[i + 1] == '-') ||
        (str[i] == '=' && str[i + 1] == '=')) {
        dest[j] = '*';
        dest[j + 1] = '*';
        dest[j + 2] = '*';
        return ReplacePairs(dest, str, i + 2, j + 3);  // Переходимо на 2 символи вперед у str і на 3 у dest
    }
    else {
        dest[j] = str[i];
        return ReplacePairs(dest, str, i + 1, j + 1);  // Переходимо на 1 символ вперед у str і dest
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int plusCount = 0, minusCount = 0, equalCount = 0;
    CountSymbols(str, plusCount, minusCount, equalCount);

    cout << "Count of '+' : " << plusCount << endl;
    cout << "Count of '-' : " << minusCount << endl;
    cout << "Count of '=' : " << equalCount << endl;

    char* modifiedStr = new char[151];
    ReplacePairs(modifiedStr, str);

    cout << "Modified string: " << modifiedStr << endl;

    delete[] modifiedStr;
    return 0;
}
