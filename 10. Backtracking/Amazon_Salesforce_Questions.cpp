#include <bits/stdc++.h>
using namespace std;

// Amazon & Salesforce Frequently Asked Backtracking Questions

// 1. Letter Combinations of a Phone Number (Amazon - Very Frequent)
// Generate all letter combinations from digit string
// Time: O(4^n), Space: O(n) for recursion depth
vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    
    vector<string> result;
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    function<void(int, string)> backtrack = [&](int index, string current) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        string letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            backtrack(index + 1, current + c);
        }
    };
    
    backtrack(0, "");
    return result;
}

// 2. Generate Parentheses (Amazon, Salesforce - Very Frequent)
// Generate all valid combinations of n pairs of parentheses
// Time: O(4^n / sqrt(n)) - Catalan number, Space: O(n)
vector<string> generateParenthesis(int n) {
    vector<string> result;
    
    function<void(string, int, int)> backtrack = [&](string current, int open, int close) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        if (open < n) {
            backtrack(current + "(", open + 1, close);
        }
        if (close < open) {
            backtrack(current + ")", open, close + 1);
        }
    };
    
    backtrack("", 0, 0);
    return result;
}

// 3. Combination Sum (Amazon, Salesforce - Very Frequent)
// Find all unique combinations that sum to target
// Time: O(2^n), Space: O(target/min)
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    
    function<void(int, int)> backtrack = [&](int start, int remaining) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }
        if (remaining < 0) return;
        
        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            backtrack(i, remaining - candidates[i]); // Can reuse same element
            current.pop_back();
        }
    };
    
    backtrack(0, target);
    return result;
}

// 4. Word Search (Amazon - Very Frequent)
// Check if word exists in board
// Time: O(m*n*4^L) where L is word length, Space: O(L)
bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    
    function<bool(int, int, int)> backtrack = [&](int i, int j, int index) {
        if (index == word.length()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) {
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '#'; // Mark as visited
        
        bool found = backtrack(i+1, j, index+1) || backtrack(i-1, j, index+1) ||
                     backtrack(i, j+1, index+1) || backtrack(i, j-1, index+1);
        
        board[i][j] = temp; // Restore
        return found;
    };
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (backtrack(i, j, 0)) return true;
        }
    }
    
    return false;
}

// 5. N-Queens (Amazon - Frequent)
// Place n queens on n×n chessboard
// Time: O(n!), Space: O(n^2)
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    vector<bool> cols(n), diag1(2*n), diag2(2*n);
    
    function<void(int)> backtrack = [&](int row) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            int d1 = row - col + n, d2 = row + col;
            
            if (cols[col] || diag1[d1] || diag2[d2]) continue;
            
            board[row][col] = 'Q';
            cols[col] = diag1[d1] = diag2[d2] = true;
            
            backtrack(row + 1);
            
            board[row][col] = '.';
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    };
    
    backtrack(0);
    return result;
}

// 6. Permutations (Amazon, Salesforce - Very Frequent)
// Generate all permutations of distinct integers
// Time: O(n!), Space: O(n)
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    
    function<void(int)> backtrack = [&](int start) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(start + 1);
            swap(nums[start], nums[i]);
        }
    };
    
    backtrack(0);
    return result;
}

// 7. Subsets (Amazon, Salesforce - Very Frequent)
// Generate all subsets (power set)
// Time: O(2^n), Space: O(n)
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    
    function<void(int)> backtrack = [&](int start) {
        result.push_back(current);
        
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(i + 1);
            current.pop_back();
        }
    };
    
    backtrack(0);
    return result;
}

// 8. Palindrome Partitioning (Amazon - Frequent)
// Partition string into palindromic substrings
// Time: O(n * 2^n), Space: O(n)
vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> current;
    
    auto isPalindrome = [](const string& str, int left, int right) {
        while (left < right) {
            if (str[left++] != str[right--]) return false;
        }
        return true;
    };
    
    function<void(int)> backtrack = [&](int start) {
        if (start == s.length()) {
            result.push_back(current);
            return;
        }
        
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1);
                current.pop_back();
            }
        }
    };
    
    backtrack(0);
    return result;
}

// 9. Combination Sum II (Amazon - Frequent)
// Find combinations that sum to target (each number used once)
// Time: O(2^n), Space: O(n)
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> current;
    
    function<void(int, int)> backtrack = [&](int start, int remaining) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }
        if (remaining < 0) return;
        
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1]) continue; // Skip duplicates
            
            current.push_back(candidates[i]);
            backtrack(i + 1, remaining - candidates[i]); // Each element used once
            current.pop_back();
        }
    };
    
    backtrack(0, target);
    return result;
}

// 10. Restore IP Addresses (Amazon - Frequent)
// Generate all valid IP addresses from string
// Time: O(3^4) = O(1), Space: O(1)
vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    
    auto isValid = [](const string& segment) {
        if (segment.empty() || segment.length() > 3) return false;
        if (segment[0] == '0' && segment.length() > 1) return false;
        int num = stoi(segment);
        return num >= 0 && num <= 255;
    };
    
    function<void(int, int, string)> backtrack = [&](int start, int parts, string current) {
        if (parts == 4) {
            if (start == s.length()) {
                result.push_back(current.substr(0, current.length() - 1)); // Remove trailing dot
            }
            return;
        }
        
        for (int len = 1; len <= 3 && start + len <= s.length(); len++) {
            string segment = s.substr(start, len);
            if (isValid(segment)) {
                backtrack(start + len, parts + 1, current + segment + ".");
            }
        }
    };
    
    backtrack(0, 0, "");
    return result;
}

// 11. Sudoku Solver (Amazon - Frequent)
// Solve 9x9 Sudoku puzzle
// Time: O(9^m) where m is empty cells, Space: O(1)
void solveSudoku(vector<vector<char>>& board) {
    auto isValid = [&](int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num || board[i][col] == num) return false;
            int r = 3 * (row / 3) + i / 3;
            int c = 3 * (col / 3) + i % 3;
            if (board[r][c] == num) return false;
        }
        return true;
    };
    
    function<bool()> backtrack = [&]() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(i, j, num)) {
                            board[i][j] = num;
                            if (backtrack()) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    };
    
    backtrack();
}

int main() {
    // Letter Combinations
    vector<string> combos = letterCombinations("23");
    cout << "Letter Combinations of '23': ";
    for (const string& s : combos) cout << s << " ";
    cout << "\n";
    
    // Generate Parentheses
    vector<string> parens = generateParenthesis(3);
    cout << "Generate Parentheses (n=3): " << parens.size() << " combinations\n";
    
    // Combination Sum
    vector<int> candidates1 = {2,3,6,7};
    auto sums = combinationSum(candidates1, 7);
    cout << "Combination Sum (target=7): " << sums.size() << " combinations\n";
    
    // Word Search
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << "Word Search 'ABCCED': " << (exist(board, "ABCCED") ? "true" : "false") << "\n";
    
    // N-Queens
    auto queens = solveNQueens(4);
    cout << "N-Queens (n=4): " << queens.size() << " solutions\n";
    
    // Permutations
    vector<int> nums1 = {1,2,3};
    auto perms = permute(nums1);
    cout << "Permutations of [1,2,3]: " << perms.size() << " permutations\n";
    
    // Subsets
    vector<int> nums2 = {1,2,3};
    auto subs = subsets(nums2);
    cout << "Subsets of [1,2,3]: " << subs.size() << " subsets\n";
    
    // Palindrome Partitioning
    auto parts = partition("aab");
    cout << "Palindrome Partitioning 'aab': " << parts.size() << " partitions\n";
    
    // Combination Sum II
    vector<int> candidates2 = {10,1,2,7,6,1,5};
    auto sums2 = combinationSum2(candidates2, 8);
    cout << "Combination Sum II (target=8): " << sums2.size() << " combinations\n";
    
    // Restore IP Addresses
    auto ips = restoreIpAddresses("25525511135");
    cout << "Restore IP Addresses: " << ips.size() << " valid IPs\n";
    
    // Sudoku Solver
    vector<vector<char>> sudoku = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    solveSudoku(sudoku);
    cout << "Sudoku Solver: Solved\n";
    
    return 0;
}
