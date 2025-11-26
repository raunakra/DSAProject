#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Evaluate Reverse Polish Notation (Postfix)
int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (const string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            if (token == "+") s.push(a + b);
            else if (token == "-") s.push(a - b);
            else if (token == "*") s.push(a * b);
            else s.push(a / b);
        } else {
            s.push(stoi(token));
        }
    }
    return s.top();
}

// Basic Calculator II (Infix with +, -, *, /)
int calculate(string s) {
    stack<int> myStack;
    char sign = '+';
    int num = 0;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
        if ((!isdigit(s[i]) && !isspace(s[i])) || i == n - 1) {
            if (sign == '-') {
                myStack.push(-num);
            } else if (sign == '+') {
                myStack.push(num);
            } else if (sign == '*') {
                int top = myStack.top();
                myStack.pop();
                myStack.push(top * num);
            } else if (sign == '/') {
                int top = myStack.top();
                myStack.pop();
                myStack.push(top / num);
            }
            sign = s[i];
            num = 0;
        }
    }
    
    int result = 0;
    while (!myStack.empty()) {
        result += myStack.top();
        myStack.pop();
    }
    return result;
}

int main() {
    vector<string> rpn = {"2", "1", "+", "3", "*"};
    cout << "RPN Result: " << evalRPN(rpn) << endl;
    
    string infix = "3+2*2";
    cout << "Infix Result: " << calculate(infix) << endl;
    return 0;
}
