#include <iostream>
#include <math.h>

using namespace std;

// Practice problem no 1

void fibonacci_numbers(int n)
{
    /* Fibonacci initialization */
    int a = 0;
    int b = 1;
    int c = 0;

    cout << "Fibonacci terms: " << endl;

    /* Iterate through n terms */
    for (int i = 0; i < n; i++)
    {
        cout << c << ", ";
        a = b;     // Copy n-1 to n-2
        b = c;     // Copy current to n-1
        c = a + b; // New term
    }

    // Time complexity O(n)
}

// Problem no 2
// Write a Program to input a number from user and find all factors of the given number using for loop

void Find_factors(int n)
{
    cout << "Factors of " << n << " are: " << endl;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            cout << i << ", ";
        }
    }
    // Time complexity O(n)
}

// Problem no 3
// Write a C++ program to print all Prime numbers between 1 to n using loop

void print_prime_numbers(int n)
{
    if (n < 2)
        return;
    cout << "Prime numbers b/w 1 to " << n << ": ";
    for (int i = 2; i <= n; i++)
    {
        bool prime = true;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                prime = false;
            }
        }
        if (prime)
            cout << i << ", ";
    }
    // Time complexity O(n^2)
}

// Problem no 4
// Write a C++ program to input a number from user and find Prime factors of the given number using loop.

void print_prime_factors(int n)
{
    if (n < 2)
        return;
    cout << "Prime factor of " << n << ": ";
    for (int i = 2; i <= n; i++) // n -1
    {
        bool prime = true;
        for (int j = 2; j < i; j++) // n
        {
            if (i % j == 0)
            {
                prime = false;
            }
        }
        if (prime && n % i == 0)
            cout << i << ", ";
    }

    // Time complexity O(n^2)
}

// problem no 5
// ..Write a C++ program to input two numbers from user and find LCM (Lowest Common Multiple) of the two numbers using loop.

void find_lcm(int a, int b)
{
    for (int i = ((a > b) ? a : b); i < a * b; i++)
    {
        if (i % a == 0 && i % b == 0)
        {
            cout << "LCM of " << a << " and " << b << ": " << i;
            return;
        }
    }
    cout << "No LCM" << endl;
    return;

    // Time complexity: calculate every case seperately
    // Space complexity O(1)
}

// Problem no 6
// Write a C++ program to input two numbers from the user and find HCF (Highest Common Factor) / GCD (Greatest Common Divisor).

void Find_HCF(int a, int b)
{
    // Handle edge case where one of the numbers is 0
    if (a == 0 || b == 0)
    {
        int hcf = (a == 0) ? b : a;
        cout << "HCF of " << a << " and " << b << ": " << hcf;
        return;
    }

    for (int i = ((a > b) ? b : a); i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            cout << "HCF of " << a << " and " << b << ": " << i;
            return;
        }
    }

    // This line is theoretically unreachable because HCF is at least 1
    cout << "No LCM" << endl;

    // Time complexity: O(min(a, b)) e.g half of smaller entity
    // Space complexity O(1)
}

// Problem no 7
// Write a C++ program to input a number from the user and check whether the given number is an Armstrong number or not.

void Find_Armstrong_number(int n)
{
    // find length
    int a = n, l = 0;
    while (a != 0)
    {
        l++;
        a /= 10;
    }
    a = n;

    int result = 0;
    for (int i = 0; i < l; i++, a /= 10)
    {
        result += pow(a % 10, l);
    }
    if (n == result)
        cout << n << " is Armstrong number";
    else
        cout << n << " is not an Armstrong number";

    // Time complexity: O(length(n))
    // Space complexity O(1)
}

// Problem no 7
// Write a C++ program to input a number and check whether the number is a Perfect number or not.

void Perfect_Number(int n)
{
    int sum;
    for (int i = 1; i <= n / 2; i++)
    {
        /* If i is a divisor of num */
        if (n % i == 0)
        {
            sum += i;
        }
    }

    if (sum == n && n > 0)
    {
        cout << "It is a PERFECT NUMBER";
    }
    else
    {
        cout << "It is NOT a PERFECT NUMBER";
    }
}
