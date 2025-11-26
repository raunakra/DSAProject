#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

// 1. Reverse String
void reverseString(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

// 2. Check Palindrome (Alphanumeric only)
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (!isalnum(s[left])) { left++; continue; }
        if (!isalnum(s[right])) { right--; continue; }
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++;
        right--;
    }
    return true;
}

// 3. String Parsing (Split by delimiter)
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    vector<char> s = {'h','e','l','l','o'};
    reverseString(s);
    for(char c : s) cout << c;
    cout << endl;
    
    cout << "Is Palindrome: " << isPalindrome("A man, a plan, a canal: Panama") << endl;
    
    vector<string> words = split("Hello World C++", ' ');
    for(const string& w : words) cout << w << endl;
    
    return 0;
}
