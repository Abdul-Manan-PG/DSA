#include <string>
#include <iostream>

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
