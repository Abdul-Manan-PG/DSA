#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>

using namespace std;

// 1. fibonacci function

int fibonacci(int n) {
    if (n <= 1) return n;
    cout << "Calculating fibonacci(" << n << ")" << endl;
    // Recursive call to calculate fibonacci of n-1 and n-2
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter a number to calculate its Fibonacci value: ";
    cin >> n;

    // Call the fibonacci function and print the result
    int result = fibonacci(n);
    cout << "Fibonacci(" << n << ") = " << result << endl;

    return 0;
}