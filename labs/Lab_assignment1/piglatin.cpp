#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string pigLatinReturn(string str) {
    size_t vowelIndex = 0;
    
    while (vowelIndex < str.length() && !isVowel(str[vowelIndex])) {
        vowelIndex++;
    }
    
    string prefix = str.substr(0, vowelIndex);
    string suffix = str.substr(vowelIndex);
    
    return suffix + prefix + "ay";
}

void pigLatinReference(string& str) {
    size_t vowelIndex = 0;
    
    while (vowelIndex < str.length() && !isVowel(str[vowelIndex])) {
        vowelIndex++;
    }
    
    string prefix = str.substr(0, vowelIndex);
    string suffix = str.substr(vowelIndex);
    
    str = suffix + prefix + "ay";
}

int main() {
    string name = "julie";

    string str1 = pigLatinReturn(name);
    cout << "pigLatinReturn(\"julie\"): " << str1 << endl;
    cout << "Original name variable: " << name << endl;
    
    pigLatinReference(name);
    cout << "pigLatinReference(name):  " << name << endl;

    return 0;
}