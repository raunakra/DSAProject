#include <bits/stdc++.h>
using namespace std;

// Amazon & Salesforce Frequently Asked Binary Search Questions

// 1. Binary Search (Amazon, Salesforce - Very Frequent)
// Standard binary search in sorted array
// Time: O(log n), Space: O(1)
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

// 2. Search in Rotated Sorted Array (Amazon - Very Frequent)
// Search target in rotated sorted array
// Time: O(log n), Space: O(1)
int searchRotated(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        
        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } 
        // Right half is sorted
        else {
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1;
}

// 3. Find Minimum in Rotated Sorted Array (Amazon - Very Frequent)
// Find minimum element in rotated sorted array
// Time: O(log n), Space: O(1)
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return nums[left];
}

// 4. Find Peak Element (Amazon - Frequent)
// Find a peak element (greater than neighbors)
// Time: O(log n), Space: O(1)
int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

// 5. Search a 2D Matrix (Amazon, Salesforce - Frequent)
// Search in matrix with sorted rows and first element of each row > last of previous
// Time: O(log(m*n)), Space: O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    
    int m = matrix.size(), n = matrix[0].size();
    int left = 0, right = m * n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / n][mid % n];
        
        if (midValue == target) {
            return true;
        } else if (midValue < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false;
}

// 6. First and Last Position of Element (Amazon - Very Frequent)
// Find starting and ending position of target
// Time: O(log n), Space: O(1)
vector<int> searchRange(vector<int>& nums, int target) {
    auto findBound = [&](bool findFirst) {
        int left = 0, right = nums.size() - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                result = mid;
                if (findFirst) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    };
    
    return {findBound(true), findBound(false)};
}

// 7. Sqrt(x) (Amazon - Frequent)
// Compute square root (integer part)
// Time: O(log x), Space: O(1)
int mySqrt(int x) {
    if (x < 2) return x;
    
    long left = 1, right = x / 2;
    
    while (left <= right) {
        long mid = left + (right - left) / 2;
        long square = mid * mid;
        
        if (square == x) {
            return mid;
        } else if (square < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return right;
}

// 8. Find First and Last Position (Amazon - Frequent)
// Alternative: Find insert position
// Time: O(log n), Space: O(1)
int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return left;
}

// 9. Koko Eating Bananas (Amazon - Frequent)
// Minimum eating speed to finish all bananas in h hours
// Time: O(n log m) where m is max pile, Space: O(1)
int minEatingSpeed(vector<int>& piles, int h) {
    auto canFinish = [&](int k) {
        long hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k; // Ceiling division
        }
        return hours <= h;
    };
    
    int left = 1, right = *max_element(piles.begin(), piles.end());
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (canFinish(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

// 10. Capacity To Ship Packages Within D Days (Amazon - Frequent)
// Minimum capacity to ship all packages in D days
// Time: O(n log(sum)), Space: O(1)
int shipWithinDays(vector<int>& weights, int days) {
    auto canShip = [&](int capacity) {
        int daysNeeded = 1, currentLoad = 0;
        
        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                daysNeeded++;
                currentLoad = weight;
            } else {
                currentLoad += weight;
            }
        }
        
        return daysNeeded <= days;
    };
    
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (canShip(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

// 11. Find K Closest Elements (Amazon - Frequent)
// Find k closest elements to x
// Time: O(log(n-k) + k), Space: O(1)
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int left = 0, right = arr.size() - k;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (x - arr[mid] > arr[mid + k] - x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return vector<int>(arr.begin() + left, arr.begin() + left + k);
}

// 12. Split Array Largest Sum (Amazon - Frequent)
// Split array into m subarrays, minimize the largest sum
// Time: O(n log(sum)), Space: O(1)
int splitArray(vector<int>& nums, int m) {
    auto canSplit = [&](int maxSum) {
        int splits = 1, currentSum = 0;
        
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                splits++;
                currentSum = num;
            } else {
                currentSum += num;
            }
        }
        
        return splits <= m;
    };
    
    int left = *max_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0);
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (canSplit(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

// 13. Find Smallest Letter Greater Than Target (Amazon - Frequent)
// Find smallest character that is greater than target
// Time: O(log n), Space: O(1)
char nextGreatestLetter(vector<char>& letters, char target) {
    int left = 0, right = letters.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (letters[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return letters[left % letters.size()];
}

int main() {
    // Binary Search
    vector<int> nums1 = {-1,0,3,5,9,12};
    cout << "Search 9: index " << search(nums1, 9) << "\n";
    
    // Search in Rotated Sorted Array
    vector<int> nums2 = {4,5,6,7,0,1,2};
    cout << "Search 0 in rotated: index " << searchRotated(nums2, 0) << "\n";
    
    // Find Minimum in Rotated Sorted Array
    vector<int> nums3 = {3,4,5,1,2};
    cout << "Find Min in rotated: " << findMin(nums3) << "\n";
    
    // Find Peak Element
    vector<int> nums4 = {1,2,3,1};
    cout << "Peak Element index: " << findPeakElement(nums4) << "\n";
    
    // Search 2D Matrix
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << "Search 3 in matrix: " << (searchMatrix(matrix, 3) ? "true" : "false") << "\n";
    
    // First and Last Position
    vector<int> nums5 = {5,7,7,8,8,10};
    vector<int> range = searchRange(nums5, 8);
    cout << "Range of 8: [" << range[0] << ", " << range[1] << "]\n";
    
    // Sqrt(x)
    cout << "Sqrt(8): " << mySqrt(8) << "\n";
    
    // Search Insert Position
    vector<int> nums6 = {1,3,5,6};
    cout << "Insert position for 5: " << searchInsert(nums6, 5) << "\n";
    
    // Koko Eating Bananas
    vector<int> piles = {3,6,7,11};
    cout << "Min eating speed (h=8): " << minEatingSpeed(piles, 8) << "\n";
    
    // Capacity To Ship Packages
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    cout << "Ship capacity (days=5): " << shipWithinDays(weights, 5) << "\n";
    
    // Find K Closest Elements
    vector<int> nums7 = {1,2,3,4,5};
    vector<int> closest = findClosestElements(nums7, 4, 3);
    cout << "4 closest to 3: ";
    for (int x : closest) cout << x << " ";
    cout << "\n";
    
    // Split Array Largest Sum
    vector<int> nums8 = {7,2,5,10,8};
    cout << "Split array (m=2): " << splitArray(nums8, 2) << "\n";
    
    // Next Greatest Letter
    vector<char> letters = {'c','f','j'};
    cout << "Next letter after 'a': " << nextGreatestLetter(letters, 'a') << "\n";
    
    return 0;
}
