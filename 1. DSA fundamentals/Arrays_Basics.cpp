#include <iostream>
#include <string>

using namespace std;

// 1. Print Each Element and its Index in an Array

void printArrayWithIndices(int nums[], int size)
{

    // Loop through the array to print each element and its index
    for (int index = 0; index < size; ++index)
    {

        // Print the value at the current index
        cout << "Value at Index " << index << " is " << nums[index] << endl;
    }

    //Time Complexity: O(n)
    //Space Complexity: O(1)
}

// 2. Print Array in Reverse Order

void printArrayInReverse(int nums[], int size)
{
    for (int index = size - 1; index >= 0; --index)
    {
        cout << nums[index] << " ";
    }
    cout << endl; // Newline for better output formatting

    //Time Complexity: O(n)
    //Space Complexity: O(1)
}

// 3. Print Alternate Elements of an Array

void printAlternateByIncrement(int nums[], int size)
{
    for (int index = 0; index < size; index += 2)
    {
        cout << nums[index] << " ";
    }
    cout << endl;

    //Time Complexity: O(n)
    //Space Complexity: O(1)
}

// 4. Create Duplicate of an Array

void createAndPrintDuplicate(int nums[], int size, int d_nums[])
{

    // Copy each element from nums to d_nums
    for (int index = 0; index < size; ++index)
    {
        d_nums[index] = nums[index];
    }

    // Print the elements of the duplicate array d_nums
    for (int index = 0; index < size; ++index)
    {
        cout << d_nums[index] << " ";
    }

    //Time Complexity: O(n)
    //Space Complexity: O(n)
}

// 5. Function to separate odd and even elements

void separateOddEven(int nums[], int size)
{
    int odd_count = 0, even_count = 0;

    // Count odd and even elements
    for (int index = 0; index < size; ++index)
    {
        if (nums[index] % 2 == 0)
        {
            ++even_count;
        }
        else
        {
            ++odd_count;
        }
    }

    int *odd_nums = new int[odd_count];
    int *even_nums = new int[even_count];
    int odd_index = 0, even_index = 0;

    for (int index = 0; index < size; ++index)
    {
        if (nums[index] % 2 == 0)
        {
            even_nums[even_index++] = nums[index];
        }
        else
        {
            odd_nums[odd_index++] = nums[index];
        }
    }

    cout << "Odd elements: ";
    for (int index = 0; index < odd_count; ++index)
    {
        cout << odd_nums[index] << " ";
    }
    cout << endl;

    cout << "Even elements: ";
    for (int index = 0; index < even_count; ++index)
    {
        cout << even_nums[index] << " ";
    }
    cout << endl;
    delete odd_nums;
    delete even_nums;

    //Time Complexity: O(n)
    //Space Complexity: O(n )
}

// 6. Function to calculate the sum and product of the array

void calculateSumAndProduct(int nums[], int size)
{
    int sum = 0;
    int product = 1;
    for (int index = 0; index < size; ++index)
    {
        sum += nums[index];

        product *= nums[index];
    }

    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;

    //Time Complexity: O(n)
    //Space Complexity: O(1)
}

// 7. Function to count occurrences of the target number in the array

int countOccurrences(int nums[], int size, int target)
{
    // Initialize a counter to keep track of occurrences
    int count = 0;

    // Loop through the array to count occurrences of the target number
    for (int index = 0; index < size; ++index)
    {
        // If the current element matches the target, increment the count
        if (nums[index] == target)
        {
            ++count;
        }
    }

    // Return the final count
    return count;

    //Time Complexity: O(n)
    //Space Complexity: O(1)
}

// 8. Function to check if the array is sorted forward, backward, or not sorted

string checkSorted(int nums[], int size)
{
    // Initialize flags for ascending and descending order
    bool isAscending = true;
    bool isDescending = true;

    // Iterate through the array to check order
    for (int i = 0; i < size - 1; ++i)
    {
        // If current element is greater than the next, it's not ascending
        if (nums[i] > nums[i + 1])
        {
            isAscending = false;
        }
        // If current element is smaller than the next, it's not descending
        if (nums[i] < nums[i + 1])
        {
            isDescending = false;
        }
    }

    // Return results based on the flags
    if (isAscending)
    {
        return "Sorted in Forward Order";
    }
    else if (isDescending)
    {
        return "Sorted in Backward Order";
    }
    else
    {
        return "Not Sorted";
    }

    //Time Complexity: O(n)
    //Space Complexity: O(1)
}

// 9. Function to count the number of unique and duplicate elements in the array

void countUniqueAndDuplicates(int nums[], int n)
{
    // Initialize a hash table (array) for values 1 to 100
    int hash_table[101] = {0};

    // Count frequencies of each element using the hash table
    for (int i = 0; i < n; ++i)
    {
        // Increment the frequency count for this number in the hash table
        hash_table[nums[i]]++;
    }

    // Variables to store the counts of unique and duplicate elements
    int unique_count = 0, duplicate_count = 0;

    // Calculate unique and duplicate counts by traversing the hash table
    for (int i = 1; i <= 100; ++i)
    {
        // If the frequency is 1, the element is unique
        if (hash_table[i] == 1)
        {
            unique_count++;
        }
        // If the frequency is greater than 1, the element has duplicates
        else if (hash_table[i] > 1)
        {
            // The number of duplicates for this element is (frequency - 1)
            duplicate_count += hash_table[i] - 1;
        }
    }

    // Output the results
    cout << unique_count << " " << duplicate_count << endl;

    //Time Complexity: O(n)
    //Space Complexity: O(n)
}

// 10. Sum of Pair Equal to Target in Array1

void hasPairWithSum(int nums[], int n, int target)
{

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // If the indexes are the same, skip
            if (i == j)
                continue;

            if (nums[i] + nums[j] == target)
            {
                cout << "true";
                return;
            }
        }
    }
    cout << "false";

    //Time Complexity: O(n^3)
    //Space Complexity: O(1)
}

// 11. Sum of Triplet Equal to Target in Array

void hasTripletWithSum(int nums[], int n, int target)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // Skip if the indexes are the same as the first element
            if (i == j)
                continue;

            for (int k = 0; k < n; ++k)
            {
                // Skip if the indexes are the same as the first or second element
                if (k == i || k == j)
                    continue;

                if (nums[i] + nums[j] + nums[k] == target)
                {
                    cout << "true";
                    return;
                }
            }
        }
    }

    // Print false if no such triplet is found after checking all possibilities
    cout << "false";

    //Time Complexity: O(n^3)
    //Space Complexity: O(1)
}

// 12. Function to find the maximum element in the array

void findMaxElement(int nums[], int n)
{
    int maxElement = nums[0];
    for (int i = 1; i < n; ++i)
    {
        if (nums[i] > maxElement)
        {
            maxElement = nums[i];
        }
    }
    cout << "The maximum element is: " << maxElement << endl;

    //Time Complexity: O(n)
    //Space Complexity: O(1)
}

// 13. Function to find the minimum element in the array

void findMinElement(int nums[], int n)
{
    int minElement = nums[0];
    for (int i = 1; i < n; ++i)
    {
        if (nums[i] < minElement)
        {
            minElement = nums[i];
        }
    }
    cout << "The minimum element is: " << minElement << endl;

    //Time Complexity: O(n)
    //Space Complexity: O(1)
}

// 14. Function to find the 2nd maximum element in the array

void findSecondMaxElement(int nums[], int n)
{
    if (n == 1)
    {
        return;
    }
    int maxElement = INT_MIN;
    int secondMaxElement = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] > maxElement)
        {
            secondMaxElement = maxElement;
            maxElement = nums[i];
        }
        else if (nums[i] > secondMaxElement && nums[i] < maxElement)
        {
            secondMaxElement = nums[i];
        }
    }
    cout << secondMaxElement << endl;

    //Time Complexity: O(n)
    //Space Complexity: O(1)
}

// 15. Function to find the 2nd minimum element in the array

void findSecondMinElement(int nums[], int n)
{
    if (n == 1)
    {
        return;
    }
    int minElement = INT_MAX;
    int secondMinElement = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        if (nums[i] < minElement)
        {
            secondMinElement = minElement;
            minElement = nums[i];
        }
        else if (nums[i] < secondMinElement && nums[i] > minElement)
        {
            secondMinElement = nums[i];
        }
    }
    cout << secondMinElement << endl;

    //Time Complexity: O(n)
    //Space Complexity: O(1)
}
// 16. Insertion at Xth Position 

void insertAtPosition(int *nums, int n, int X, int val) {
    // Step 1: Shift elements one position to the right from the end to index X
    for (int i = n; i > X; i--) {
        nums[i] = nums[i - 1];
    }

    // Step 2: Insert the new value at index X
    nums[X] = val;

    //Time Complexity: O(n-x)
    //Space Complexity: O(1)
}

// 17. Deletion at Xth Position

void deleteElementAtIndex(int nums[], int &n, int X) {

    // Shift elements to the left from index X
    for (int i = X; i < n - 1; i++) {
        nums[i] = nums[i + 1];
    }
    // Reduce the size by 1
    n--;

    //Time Complexity: O(n-x)
    //Space Complexity: O(1)
}

// .....................................................................