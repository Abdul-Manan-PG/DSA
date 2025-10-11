#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// Function to convert a positive decimal number to binary (as an integer form)
// int to_binary(int decimal)
// {
//     int ans = 0;
//     int pow = 1;
//     while (decimal > 0)
//     {
//         int rem = decimal % 2;  // Get remainder (bit)
//         decimal /= 2;           // Divide by 2 for next bit
//         ans += rem * pow;       // Append bit at correct position
//         pow *= 10;              // Move to next digit place (binary digit)
//     }
//     return ans;
// }

// Function to convert a binary (as integer digits) to decimal
// int to_decimal(int binary)
// {
//     int powOf2 = 1;
//     int ans = 0;
//     while (binary > 0)
//     {
//         int rem = binary % 10;  // Extract last binary digit
//         binary /= 10;
//         ans += rem * powOf2;    // Convert binary bit to decimal
//         powOf2 *= 2;
//     }
//     return ans;
// }

// Function to compute the two's complement binary representation
// int twos_complement(int decimal)
// {
//     // For positive numbers, normal binary is fine
//     if (decimal >= 0)
//         return to_binary(decimal);

//     // Step 1: Get binary of the absolute value
//     int binary = to_binary(-decimal);
//     string s = to_string(binary);

//     // Step 2: Pad with leading zeros to fix bit length (for simplicity, use 8 bits)
//     while (s.length() < 8)
//         s = "0" + s;

//     // Step 3: Invert bits (1’s complement)
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] == '0')
//             s[i] = '1';
//         else
//             s[i] = '0';
//     }

//     // Step 4: Add 1 to get two’s complement
//     int invertedDecimal = to_decimal(stoi(s));
//     int twosDecimal = invertedDecimal + 1;

//     // Step 5: Convert back to binary for display
//     int resultBinary = to_binary(twosDecimal);
//     return resultBinary;
// }


// int main()
// {
//     // Display decimal → binary conversion
//     for (int i = 0; i < 16; i++)
//     {
//         int binary = to_binary(i);
//         cout << i << " = " << binary << endl;
//     }

//     // Show two's complement of positive and negative values
//     cout << "Two's complement of 10: " << twos_complement(10) << endl;
//     cout << "Two's complement of -10: " << twos_complement(-10) << endl;
//     cout << "original val: " << from_twos_complement("10110") << endl;
    
//     return 0;
// }

// ===============================
// Utility Conversion Functions
// ===============================

// Convert a positive decimal number to binary (as a string)
string to_binary(int decimal)
{
    if (decimal == 0)
        return "00000000"; // return 8-bit zero

    string ans = "";
    while (decimal > 0)
    {
        ans = char('0' + (decimal % 2)) + ans;
        decimal /= 2;
    }

    // Pad to 8 bits
    while (ans.length() < 8)
        ans = "0" + ans;

    return ans;
}

// Convert binary string → decimal integer
int to_decimal(const string &binary)
{
    int ans = 0;
    for (char bit : binary)
        ans = ans * 2 + (bit - '0');
    return ans;
}

// ===============================
// Two's Complement Conversion
// ===============================

// Convert signed decimal → two’s complement (8-bit) binary
string twos_complement(int decimal)
{
    // If number is positive, just return padded binary
    if (decimal >= 0)
        return to_binary(decimal);

    // Step 1: Get binary of absolute value
    int absVal = -decimal;
    string bin = to_binary(absVal);

    // Step 2: Invert bits (1’s complement)
    for (char &c : bin)
        c = (c == '0') ? '1' : '0';

    // Step 3: Add 1 (two’s complement)
    int val = to_decimal(bin) + 1;
    string result = to_binary(val);

    return result;
}

// Convert a two’s complement binary string → signed decimal
int from_twos_complement(const string &binary)
{
    // Step 1: If MSB = 0 → positive number
    if (binary[0] == '0')
        return to_decimal(binary);

    // Step 2: If MSB = 1 → negative number
    // Invert bits (1’s complement)
    string inverted = binary;
    for (char &c : inverted)
        c = (c == '0') ? '1' : '0';

    // Step 3: Add 1 and make it negative
    int val = to_decimal(inverted) + 1;
    return -val;
}

// ===============================
// Main Demonstration
// ===============================
int main()
{
    cout << "Decimal → Binary (unsigned)" << endl;
    for (int i = 0; i < 16; i++)
        cout << i << " = " << to_binary(i) << endl;

    cout << "\nTwo’s Complement Examples\n";

    int num1 = 10;
    int num2 = -10;

    string bin1 = twos_complement(num1);
    string bin2 = twos_complement(num2);

    cout << "Decimal: " << num1 << "  => Two’s Complement: " << bin1 << endl;
    cout << "Decimal: " << num2 << "  => Two’s Complement: " << bin2 << endl;

    // Reverse conversion
    cout << "\nReverse (Two’s Complement → Decimal)\n";
    cout << bin1 << " => " << from_twos_complement(bin1) << endl;
    cout << bin2 << " => " << from_twos_complement(bin2) << endl;

    // Custom test
    cout << "\nCustom test: from_twos_complement(\"10110\") = "
         << from_twos_complement("00010110") << endl;

    return 0;
}
