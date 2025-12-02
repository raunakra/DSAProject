#include <bits/stdc++.h>
using namespace std;

// Amazon & Salesforce Frequently Asked Bit Manipulation Questions

// 1. Single Number (Amazon, Salesforce - Very Frequent)
// Find element that appears once (others appear twice)
// Time: O(n), Space: O(1)
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num; // XOR cancels out pairs
    }
    return result;
}

// 2. Number of 1 Bits (Amazon, Salesforce - Very Frequent)
// Count set bits (Hamming weight)
// Time: O(log n), Space: O(1)
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        count++;
        n &= (n - 1); // Remove rightmost set bit
    }
    return count;
}

// Alternative: Brian Kernighan's algorithm shown above
// Another approach: count += n & 1; n >>= 1;

// 3. Counting Bits (Amazon - Very Frequent)
// Count set bits for all numbers from 0 to n
// Time: O(n), Space: O(n)
vector<int> countBits(int n) {
    vector<int> result(n + 1);
    for (int i = 1; i <= n; i++) {
        result[i] = result[i >> 1] + (i & 1);
        // DP: bits[i] = bits[i/2] + (i is odd ? 1 : 0)
    }
    return result;
}

// 4. Reverse Bits (Amazon - Frequent)
// Reverse bits of 32-bit unsigned integer
// Time: O(1), Space: O(1)
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }
    return result;
}

// 5. Power of Two (Amazon, Salesforce - Frequent)
// Check if number is power of 2
// Time: O(1), Space: O(1)
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
    // Power of 2 has only one set bit
}

// 6. Single Number II (Amazon - Frequent)
// Find element that appears once (others appear 3 times)
// Time: O(n), Space: O(1)
int singleNumberII(vector<int>& nums) {
    int ones = 0, twos = 0;
    
    for (int num : nums) {
        twos |= ones & num;
        ones ^= num;
        
        int threes = ones & twos;
        ones &= ~threes;
        twos &= ~threes;
    }
    
    return ones;
}

// 7. Missing Number (Amazon, Salesforce - Very Frequent)
// Find missing number in range [0, n]
// Time: O(n), Space: O(1)
int missingNumber(vector<int>& nums) {
    int result = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        result ^= i ^ nums[i];
    }
    return result;
}

// 8. Sum of Two Integers (Amazon - Frequent)
// Add two integers without using + or -
// Time: O(1), Space: O(1)
int getSum(int a, int b) {
    while (b != 0) {
        unsigned int carry = (unsigned int)(a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

// 9. Bitwise AND of Numbers Range (Amazon - Frequent)
// Find bitwise AND of all numbers in range [left, right]
// Time: O(log n), Space: O(1)
int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left < right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }
    return left << shift;
}

// 10. Maximum XOR of Two Numbers (Amazon - Frequent)
// Find maximum XOR of two numbers in array
// Time: O(n), Space: O(n) with Trie
int findMaximumXOR(vector<int>& nums) {
    int maxXor = 0, mask = 0;
    
    for (int i = 31; i >= 0; i--) {
        mask |= (1 << i);
        unordered_set<int> prefixes;
        
        for (int num : nums) {
            prefixes.insert(num & mask);
        }
        
        int candidate = maxXor | (1 << i);
        
        for (int prefix : prefixes) {
            if (prefixes.count(candidate ^ prefix)) {
                maxXor = candidate;
                break;
            }
        }
    }
    
    return maxXor;
}

// 11. Single Number III (Amazon - Frequent)
// Find two elements that appear once (others appear twice)
// Time: O(n), Space: O(1)
vector<int> singleNumberIII(vector<int>& nums) {
    int xorAll = 0;
    for (int num : nums) {
        xorAll ^= num;
    }
    
    // Find rightmost set bit in xorAll
    int rightmostBit = xorAll & (-xorAll);
    
    int num1 = 0, num2 = 0;
    for (int num : nums) {
        if (num & rightmostBit) {
            num1 ^= num;
        } else {
            num2 ^= num;
        }
    }
    
    return {num1, num2};
}

// 12. Subsets (Amazon - Frequent)
// Generate all subsets using bit manipulation
// Time: O(n * 2^n), Space: O(1) excluding output
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int totalSubsets = 1 << n; // 2^n
    vector<vector<int>> result;
    
    for (int mask = 0; mask < totalSubsets; mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        result.push_back(subset);
    }
    
    return result;
}

// 13. UTF-8 Validation (Amazon - Frequent)
// Validate UTF-8 encoding
// Time: O(n), Space: O(1)
bool validUtf8(vector<int>& data) {
    int remaining = 0;
    
    for (int byte : data) {
        if (remaining == 0) {
            if ((byte >> 5) == 0b110) remaining = 1;
            else if ((byte >> 4) == 0b1110) remaining = 2;
            else if ((byte >> 3) == 0b11110) remaining = 3;
            else if ((byte >> 7) != 0) return false;
        } else {
            if ((byte >> 6) != 0b10) return false;
            remaining--;
        }
    }
    
    return remaining == 0;
}

// 14. Hamming Distance (Amazon, Salesforce - Frequent)
// Count positions where bits differ
// Time: O(1), Space: O(1)
int hammingDistance(int x, int y) {
    int xorVal = x ^ y;
    int count = 0;
    
    while (xorVal) {
        count++;
        xorVal &= (xorVal - 1);
    }
    
    return count;
}

// 15. Total Hamming Distance (Amazon - Frequent)
// Sum of Hamming distances between all pairs
// Time: O(n), Space: O(1)
int totalHammingDistance(vector<int>& nums) {
    int total = 0;
    int n = nums.size();
    
    for (int i = 0; i < 32; i++) {
        int ones = 0;
        for (int num : nums) {
            ones += (num >> i) & 1;
        }
        total += ones * (n - ones);
    }
    
    return total;
}

// 16. Repeated DNA Sequences (Amazon - Frequent)
// Find repeated 10-letter sequences using bit manipulation
// Time: O(n), Space: O(n)
vector<string> findRepeatedDnaSequences(string s) {
    if (s.length() <= 10) return {};
    
    unordered_map<char, int> toNum = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    unordered_set<int> seen;
    unordered_set<string> result;
    
    int hash = 0;
    for (int i = 0; i < 10; i++) {
        hash = (hash << 2) | toNum[s[i]];
    }
    seen.insert(hash);
    
    int mask = (1 << 20) - 1; // 10 * 2 bits
    
    for (int i = 10; i < s.length(); i++) {
        hash = ((hash << 2) & mask) | toNum[s[i]];
        if (seen.count(hash)) {
            result.insert(s.substr(i - 9, 10));
        }
        seen.insert(hash);
    }
    
    return vector<string>(result.begin(), result.end());
}

// 17. Divide Two Integers (Amazon - Frequent)
// Divide without using *, /, or % operators
// Time: O(log^2 n), Space: O(1)
int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    
    long long dvd = abs((long long)dividend);
    long long dvs = abs((long long)divisor);
    
    int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
    
    long long result = 0;
    while (dvd >= dvs) {
        long long temp = dvs, multiple = 1;
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        dvd -= temp;
        result += multiple;
    }
    
    return sign * result;
}

int main() {
    // Single Number
    vector<int> nums1 = {4,1,2,1,2};
    cout << "Single Number: " << singleNumber(nums1) << "\n";
    
    // Number of 1 Bits
    cout << "Hamming Weight of 11: " << hammingWeight(11) << "\n";
    
    // Counting Bits
    vector<int> bits = countBits(5);
    cout << "Count Bits [0-5]: ";
    for (int b : bits) cout << b << " ";
    cout << "\n";
    
    // Reverse Bits
    cout << "Reverse Bits of 43261596: " << reverseBits(43261596) << "\n";
    
    // Power of Two
    cout << "Is 16 power of 2: " << (isPowerOfTwo(16) ? "true" : "false") << "\n";
    
    // Single Number II
    vector<int> nums2 = {2,2,3,2};
    cout << "Single Number II: " << singleNumberII(nums2) << "\n";
    
    // Missing Number
    vector<int> nums3 = {3,0,1};
    cout << "Missing Number: " << missingNumber(nums3) << "\n";
    
    // Sum of Two Integers
    cout << "Sum of 1 and 2: " << getSum(1, 2) << "\n";
    
    // Bitwise AND Range
    cout << "Range AND [5,7]: " << rangeBitwiseAnd(5, 7) << "\n";
    
    // Maximum XOR
    vector<int> nums4 = {3,10,5,25,2,8};
    cout << "Maximum XOR: " << findMaximumXOR(nums4) << "\n";
    
    // Single Number III
    vector<int> nums5 = {1,2,1,3,2,5};
    auto singles = singleNumberIII(nums5);
    cout << "Single Number III: " << singles[0] << ", " << singles[1] << "\n";
    
    // Subsets
    vector<int> nums6 = {1,2,3};
    auto subs = subsets(nums6);
    cout << "Subsets of [1,2,3]: " << subs.size() << " subsets\n";
    
    // Hamming Distance
    cout << "Hamming Distance (1, 4): " << hammingDistance(1, 4) << "\n";
    
    // Total Hamming Distance
    vector<int> nums7 = {4,14,2};
    cout << "Total Hamming Distance: " << totalHammingDistance(nums7) << "\n";
    
    // Repeated DNA Sequences
    auto dna = findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    cout << "Repeated DNA: " << dna.size() << " sequences\n";
    
    // Divide Two Integers
    cout << "Divide 10 by 3: " << divide(10, 3) << "\n";
    
    return 0;
}
