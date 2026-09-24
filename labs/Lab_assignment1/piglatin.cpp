#include <iostream>
#include <string>

using namespace std;

bool isVowel(char ch) {
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

string pigLatinReturn(string word) {
  int vowelIndex = 0;
  
  while (vowelIndex < word.length() && !isVowel(word[vowelIndex])) {
    vowelIndex++;
  }
  
  string firstPart = word.substr(0, vowelIndex);
  string lastPart = word.substr(vowelIndex);
  
  return lastPart + firstPart + "ay";
}

void pigLatinReference(string& word) {
  int vowelIndex = 0;
  
  while (vowelIndex < word.length() && !isVowel(word[vowelIndex])) {
    vowelIndex++;
  }
  
  string firstPart = word.substr(0, vowelIndex);
  string lastPart = word.substr(vowelIndex);
  
  word = lastPart + firstPart + "ay";
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