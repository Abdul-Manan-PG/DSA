#include <iostream>
#include <string>
#include <cctype> // for tolower() in task 3
#include <math.h> // for abs() e.g for absolute value in task 3
#include <climits> // for INT_MAX in task 7
#include <vector> // for letters in task 10


using namespace std;

// 1. Print ASCII Value of Each Character in a String

void Print_ASCII(string str){
    for (int i : str)
    {
        cout << i << endl;   
    }
}

// int main(){
//     Print_ASCII("Manan");
//     return 0;
// }

// 2. Count Letters, Numbers, and Special Characters in a String

void Counting(string str){
    int letters = 0, numbers = 0, schars = 0;
    for (char i : str){
        if (isdigit(i))
        numbers++;
        else if (isalpha(i))
        letters++;
        else 
        schars++;
    }
    cout << "Letters: " << letters << endl;
    cout << "Numbers: " << numbers << endl;
    cout << "Special chars: " << schars << endl;
}

// int main()
// {
//     Counting("Hello! everyone my passs is 86743");
//     return 0;
// }



// 3 Find the Difference between the Number of Consonants and Vowels in a String

int consonantVowelDifference(const string &s)
{
    int vowels = 0, consonants = 0;
    for (char c : s)
    {
        if (isalpha(c))
        {                             // Check if it's a letter
            char lowerC = tolower(c); // Convert to lowercase
            if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
    }
    return abs(consonants - vowels);
}

// int main()
// {
//     cout << "Difference: " << consonantVowelDifference("Hello world") << endl;
//     return 0;
// }

// 4. Convert Uppercase to Lowercase and Vice Versa in a String

char To_upper_or_to_lower(char c){
    if (c >= 'a' && c <= 'z') 
    {
        return c - 32;
    }
    if (c >= 'A' && c <= 'Z')
    {
        return c + 32;
    }
    return c; // return unchanged if it's not lowercase
}

// int main() 
// {
//     // Write C++ code here
//     cout << To_upper_or_to_lower('a') << endl;
//     cout << To_upper_or_to_lower('b') << endl;
//     cout << To_upper_or_to_lower('c') << endl;
//     cout << To_upper_or_to_lower('X') << endl;
//     cout << To_upper_or_to_lower('Y') << endl;
//     cout << To_upper_or_to_lower('Z') << endl;

//     return 0;
// }

// 5. Remove Leading, Trailing, and Extra Spaces in a String

string removeExtraSpaces(const string &s) {
    int n = s.length();
    int start = 0, end = n - 1;
    
    // Trim leading spaces
    while (start <= end && isspace(s[start])) {
        start++;
    }
    
    // Trim trailing spaces
    while (end >= start && isspace(s[end])) {
        end--;
    }
    
    // Remove extra spaces between words
    string cleaned;
    bool space = false;
    for (int i = start; i <= end; i++) {
        if (isspace(s[i])) {
            if (!space) {
                cleaned += ' ';
                space = true;
            }
        } 
        else {
            cleaned += s[i];
            space = false;
        }
    }
    
    return cleaned;
}

// int main() {
//     string input = "   Hello   World!   I am    learning     dsa  ";
//     string output = removeExtraSpaces(input);
//     cout << "Cleaned: \"" << output << "\"" << endl;
//     return 0;
// }

// 6. Count the Number of Words in a String

int countWords(const string& str) {
    int count = 0;
    bool inWord = false;

    for (char ch : str) {
        if (isspace(ch)) {
            inWord = false;
        } else {
            if (!inWord) {
                count++;
                inWord = true;
            }
        }
    }

    return count;
}

// int main() {
//     string input = "Count     the number of words in this sentence.";
//     int wordCount = countWords(input);
//     cout << "Number of words: " << wordCount << endl;

//     return 0;
// }

// 7. Find the Maximum and Minimum Occurring Characters in a String

void findMaxMinChar(const string& str) {
    int freq[256] = {0};  // ASCII character frequency

    // Count frequency of each character
    for (char ch : str) {
        freq[(unsigned char)ch]++;
    }

    char maxChar, minChar;
    int maxFreq = 0, minFreq = INT_MAX;

    for (int i = 0; i < 256; ++i) {
        if (freq[i] > 0) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = i;
            }
            if (freq[i] < minFreq) {
                minFreq = freq[i];
                minChar = i;
            }
        }
    }

    cout << "Maximum occurring character: '" << maxChar << "' (" << maxFreq << " times)" << endl;
    cout << "Minimum occurring character: '" << minChar << "' (" << minFreq << " time" << (minFreq > 1 ? "s" : "") << ")" << endl;
}

// int main() {
//     string input = "Find the maximum and minimum occurring characters";
//     findMaxMinChar(input);
//     return 0;
// }

// 8. Check if There are Two or Three Consecutive Identical Characters in a String

int hasConsecutiveIdentical(const string& str) {
    int count = 0;
    for (size_t i = 1; i < str.length(); ++i) {
        if (str[i] == str[i - 1]) {
            count++;
        }
    }
    
    return count;
}

// int main() {
//     string input = "hello world";
//     cout << "line has: " << hasConsecutiveIdentical(input) << " consecutive identical characters"  << endl;

//     return 0;
// }

// 9. Find the First and Last Index of Occurrence for Each Character in a String

void first_and_last_oc_words(string str){
    int count = 1;
    bool new_word = true;
    for (int i = 0; i < str.length(); i++){
        if (isalpha(str[i])){
            if (new_word){
                new_word = false;
                cout <<  "word " << count++ << ": start at " << i << " "; 
            }
        }
        else if ((isspace(str[i]) || i == str.length() - 1)){
                cout << "and ends at " << i - 1 << endl;
            new_word = true;
        }
        if (i == str.length() - 1)
                cout << "and ends at " << i << endl;
    }
}

// int main(){
//     first_and_last_oc_words("My name is Abdul Manan");
//     return 0;
// }

// 10: Check if a String Contains All Letters from 'a' to 'z'

bool Pangram_check(string str)
{
    vector<bool> letters(26, false);
    for (char c : str){
        if (isalpha(c)){
            char lowerchar = tolower(c);
            letters[lowerchar - 'a'] = true;
        }
    }
    for (bool present : letters){
        if (!present){
            return false;
        }
    }
    return true;
}

// int main() {
//     string input = "The quick brown fox jumps over the lazy dog";
//     bool result = Pangram_check(input);
//     cout << "Is pangram? " << (result ? "Yes" : "No") << endl;
//     return 0;
// }

string insertCharacter(const string &s, char c, int k) {
    string result = s;
    
    // Insert at first position
    if (!result.empty()) {
        result.insert(0, 1, c);
    } 
    else {
        result += c;
    }
    
    // Insert at last position
    result += c;
    
    // Insert at Kth position (if valid)
    if (k > 0 && k <= result.length()) {
        result.insert(k - 1, 1, c);
    } 
    else {
        cout << "Invalid K position. Skipping Kth insertion." << endl;
    }
    
    return result;
}

// int main() {
//     string input = "Hello";
//     char ch = '*';
//     int k = 3;
    
//     string output = insertCharacter(input, ch, k);
//     cout << "Modified string: " << output << endl;
    
//     return 0;
// }

// 12: Remove the First, Last, and Kth Character from a String 

string removeCharacters(const string &s, int k) {
    string result = s;

    // Remove first character (if string is not empty)
    if (!result.empty()) {
        result.erase(0, 1);
    } 
    else {
        cout << "String is empty. Cannot remove first character." << endl;
    }

    // Remove last character (if string is not empty)
    if (!result.empty()) {
        result.pop_back();
    }
    else {
        cout << "String is empty. Cannot remove last character." << endl;
    }

    // Remove Kth character (if valid)
    if (k > 0 && k <= result.length()) {
        result.erase(k - 1, 1);
    } 
    else {
        cout << "Invalid K position. Skipping Kth removal." << endl;
    }

    return result;
}

// int main() {
//     string input = "HelloWorld";
//     int k = 3;

//     string output = removeCharacters(input, k);
//     cout << "Modified string: " << output << endl;

//     return 0;
// }

// 13. Find a Specific Substring within a String

int find_sub_string(string str, string substring){
    int n = str.length() - substring.length();
    if (n < 0){
        return -1;
    }
    for (int i = 0; i <= n ; i++){
        if (str.substr(i,substring.length()) == substring){
            return i;
        }
    }
    return -1;
}

// int main() {
//     cout << "Index: " <<find_sub_string("Hello World!", "ld!");

//     return 0;
// }

// 14. Generate All Possible Substrings of a String

void generateSubstrings(const string &s) {
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            cout << s.substr(i, j - i + 1) << endl;
        }
    }
}

// int main() {
//     string input = "abc";
//     cout << "All substrings of \"" << input << "\":" << endl;
//     generateSubstrings(input);
//     return 0;
// }
