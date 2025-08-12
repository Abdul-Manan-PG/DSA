// 2614. Prime in Diogonal 


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution1 {
public:
    bool isPrime(int n) {
    // Handle edge cases
    if (n <= 1) return false;
    if (n == 2) return true;    // 2 is the only even prime
    if (n % 2 == 0) return false; // eliminate all even numbers
    
    // Check divisors up to square root of n
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}
    int diagonalPrime(vector<vector<int>>& nums) {
        int largest = 0;
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < nums[0].size(); j++){
                if (i == j || (i + j == nums[0].size() - 1)){
                    if (isPrime(nums[i][j]) && nums[i][j] > largest){
                        largest = nums[i][j];
                    }
                }
            }
        }
        return largest;
    }
};

class Solution2 {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        
        int sqrt_n = sqrt(n);
        for (int i = 3; i <= sqrt_n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
    
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int largest = 0;
        
        for (int i = 0; i < n; i++) {
            // Check main diagonal
            int val1 = nums[i][i];
            if (val1 > largest && isPrime(val1)) {
                largest = val1;
            }
            
            // Check anti-diagonal (skip center element if n is odd)
            int j = n - 1 - i;
            if (j != i) {
                int val2 = nums[i][j];
                if (val2 > largest && isPrime(val2)) {
                    largest = val2;
                }
            }
        }
        
        return largest;
    }
};