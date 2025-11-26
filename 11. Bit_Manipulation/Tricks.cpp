#include <iostream>

using namespace std;

// Check if power of 2
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// Count set bits (Brian Kernighan's Algorithm)
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    cout << "Is 16 power of 2? " << isPowerOfTwo(16) << endl;
    cout << "Is 18 power of 2? " << isPowerOfTwo(18) << endl;
    
    cout << "Set bits in 7 (0111): " << countSetBits(7) << endl;
    return 0;
}
