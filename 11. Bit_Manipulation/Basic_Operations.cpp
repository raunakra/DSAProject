#include <iostream>

using namespace std;

int main() {
    int a = 5;  // 0101
    int b = 3;  // 0011
    
    cout << "a & b: " << (a & b) << endl; // 0001 -> 1
    cout << "a | b: " << (a | b) << endl; // 0111 -> 7
    cout << "a ^ b: " << (a ^ b) << endl; // 0110 -> 6
    cout << "~a: " << (~a) << endl;       // ...1010 -> -6
    cout << "a << 1: " << (a << 1) << endl; // 1010 -> 10
    cout << "a >> 1: " << (a >> 1) << endl; // 0010 -> 2
    
    // Set bit at position i
    int i = 1;
    int setBit = a | (1 << i); // 0101 | 0010 -> 0111 (7)
    cout << "Set bit 1: " << setBit << endl;
    
    // Clear bit at position i
    int clearBit = a & ~(1 << 0); // 0101 & 1110 -> 0100 (4)
    cout << "Clear bit 0: " << clearBit << endl;
    
    // Toggle bit at position i
    int toggleBit = a ^ (1 << 1); // 0101 ^ 0010 -> 0111 (7)
    cout << "Toggle bit 1: " << toggleBit << endl;
    
    // Check bit at position i
    bool isSet = (a & (1 << 2)); // 0101 & 0100 -> 4 (true)
    cout << "Is bit 2 set? " << isSet << endl;
    
    return 0;
}
