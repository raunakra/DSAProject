#include <bits/stdc++.h>
using namespace std;

// Amazon & Salesforce Frequently Asked Stack/Queue Questions

// 1. Valid Parentheses (Amazon, Salesforce - Very Frequent)
// Time: O(n), Space: O(n)
bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
    
    for (char c : s) {
        if (pairs.count(c)) {
            if (st.empty() || st.top() != pairs[c]) return false;
            st.pop();
        } else {
            st.push(c);
        }
    }
    return st.empty();
}

// 2. Min Stack (Amazon - Very Frequent)
// Design stack that supports push, pop, top, and retrieving minimum in O(1)
// Time: O(1) for all operations, Space: O(n)
class MinStack {
private:
    stack<int> data;
    stack<int> minStack;
    
public:
    MinStack() {}
    
    void push(int val) {
        data.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (data.top() == minStack.top()) {
            minStack.pop();
        }
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

// 3. Implement Queue using Stacks (Amazon, Salesforce - Frequent)
// Time: O(1) amortized for all operations, Space: O(n)
class MyQueue {
private:
    stack<int> input, output;
    
    void transfer() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }
    
public:
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        transfer();
        int val = output.top();
        output.pop();
        return val;
    }
    
    int peek() {
        transfer();
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

// 4. Implement Stack using Queues (Salesforce - Frequent)
// Time: O(n) for push, O(1) for pop and top, Space: O(n)
class MyStack {
private:
    queue<int> q;
    
public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        // Rotate queue to make new element at front
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

// 5. Evaluate Reverse Polish Notation (Amazon - Frequent)
// Evaluate arithmetic expression in RPN
// Time: O(n), Space: O(n)
int evalRPN(vector<string>& tokens) {
    stack<int> st;
    
    for (string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else st.push(a / b);
        } else {
            st.push(stoi(token));
        }
    }
    
    return st.top();
}

// 6. Daily Temperatures (Amazon - Very Frequent)
// Find how many days until warmer temperature (monotonic stack)
// Time: O(n), Space: O(n)
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> st; // stores indices
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int idx = st.top();
            st.pop();
            result[idx] = i - idx;
        }
        st.push(i);
    }
    
    return result;
}

// 7. Largest Rectangle in Histogram (Amazon - Frequent)
// Find largest rectangle area in histogram
// Time: O(n), Space: O(n)
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    heights.push_back(0); // sentinel
    
    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }
    
    heights.pop_back();
    return maxArea;
}

// 8. Sliding Window Maximum (Amazon - Very Frequent)
// Find maximum in each sliding window of size k
// Time: O(n), Space: O(k)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // stores indices
    vector<int> result;
    
    for (int i = 0; i < nums.size(); i++) {
        // Remove elements outside window
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        
        // Remove smaller elements (they're useless)
        while (!dq.empty() && nums[i] > nums[dq.back()]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        // Add to result if window is full
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    
    return result;
}

// 9. Basic Calculator (Amazon - Frequent)
// Evaluate expression with +, -, (, )
// Time: O(n), Space: O(n)
int calculate(string s) {
    stack<int> st;
    int result = 0;
    int number = 0;
    int sign = 1;
    
    for (char c : s) {
        if (isdigit(c)) {
            number = number * 10 + (c - '0');
        } else if (c == '+') {
            result += sign * number;
            number = 0;
            sign = 1;
        } else if (c == '-') {
            result += sign * number;
            number = 0;
            sign = -1;
        } else if (c == '(') {
            st.push(result);
            st.push(sign);
            result = 0;
            sign = 1;
        } else if (c == ')') {
            result += sign * number;
            number = 0;
            result *= st.top(); st.pop(); // sign before parenthesis
            result += st.top(); st.pop(); // result before parenthesis
        }
    }
    
    result += sign * number;
    return result;
}

// 10. Decode String (Amazon - Frequent)
// Decode encoded string like "3[a2[c]]" -> "accaccacc"
// Time: O(n), Space: O(n)
string decodeString(string s) {
    stack<int> countStack;
    stack<string> strStack;
    string currentStr;
    int k = 0;
    
    for (char c : s) {
        if (isdigit(c)) {
            k = k * 10 + (c - '0');
        } else if (c == '[') {
            countStack.push(k);
            strStack.push(currentStr);
            currentStr = "";
            k = 0;
        } else if (c == ']') {
            string temp = currentStr;
            currentStr = strStack.top();
            strStack.pop();
            int count = countStack.top();
            countStack.pop();
            for (int i = 0; i < count; i++) {
                currentStr += temp;
            }
        } else {
            currentStr += c;
        }
    }
    
    return currentStr;
}

int main() {
    // Valid Parentheses
    cout << "Valid '()[]{}': " << (isValid("()[]{}") ? "true" : "false") << "\n";
    
    // Min Stack
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Min Stack getMin: " << minStack.getMin() << "\n"; // -3
    minStack.pop();
    cout << "Min Stack top: " << minStack.top() << "\n";       // 0
    cout << "Min Stack getMin: " << minStack.getMin() << "\n"; // -2
    
    // Evaluate RPN
    vector<string> tokens = {"2","1","+","3","*"};
    cout << "\nRPN '2 1 + 3 *': " << evalRPN(tokens) << "\n"; // (2+1)*3 = 9
    
    // Daily Temperatures
    vector<int> temps = {73,74,75,71,69,72,76,73};
    auto days = dailyTemperatures(temps);
    cout << "\nDaily Temperatures: ";
    for (int d : days) cout << d << " ";
    cout << "\n";
    
    // Largest Rectangle
    vector<int> heights = {2,1,5,6,2,3};
    cout << "\nLargest Rectangle: " << largestRectangleArea(heights) << "\n"; // 10
    
    // Sliding Window Maximum
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    auto maxWindow = maxSlidingWindow(nums, 3);
    cout << "\nSliding Window Max (k=3): ";
    for (int m : maxWindow) cout << m << " ";
    cout << "\n";
    
    // Basic Calculator
    cout << "\nCalculate '1 + 1': " << calculate("1 + 1") << "\n";
    cout << "Calculate ' 2-1 + 2 ': " << calculate(" 2-1 + 2 ") << "\n";
    cout << "Calculate '(1+(4+5+2)-3)+(6+8)': " << calculate("(1+(4+5+2)-3)+(6+8)") << "\n";
    
    // Decode String
    cout << "\nDecode '3[a]2[bc]': " << decodeString("3[a]2[bc]") << "\n"; // "aaabcbc"
    cout << "Decode '3[a2[c]]': " << decodeString("3[a2[c]]") << "\n";   // "accaccacc"
    
    return 0;
}
