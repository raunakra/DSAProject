#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) return false;
    }
    return true;
}

void partitionUtil(int index, string& s, vector<string>& current, vector<vector<string>>& result) {
    if (index == s.length()) {
        result.push_back(current);
        return;
    }
    
    for (int i = index; i < s.length(); i++) {
        if (isPalindrome(s, index, i)) {
            current.push_back(s.substr(index, i - index + 1));
            partitionUtil(i + 1, s, current, result);
            current.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> current;
    partitionUtil(0, s, current, result);
    return result;
}

int main() {
    string s = "aab";
    vector<vector<string>> parts = partition(s);
    cout << "Number of partitions: " << parts.size() << endl;
    return 0;
}
