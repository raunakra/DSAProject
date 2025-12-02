#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Palindrome Partitioning
// Problem: Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.
// 
// Example 1:
//   Input: s = "aab"
//   Output: [["a","a","b"], ["aa","b"]]
//
// Example 2:
//   Input: s = "a"
//   Output: [["a"]]
//
// Approach: Use backtracking to explore all possible partitions. At each position, try all substrings
// that form palindromes and recursively partition the remaining string.
//
// Time Complexity: O(N * 2^N) where N is the length of string. In worst case, we have 2^N partitions
// and for each partition we spend O(N) to check palindromes and build the result.
// Space Complexity: O(N) for recursion stack depth, excluding output space.

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
