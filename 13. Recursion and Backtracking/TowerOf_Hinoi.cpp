#include <iostream>
#include <stack>
using namespace std;

// Function to print the stacks (for understanding)
void printStacks(stack<int> s, stack<int> a, stack<int> d)
{
    cout << "\nCurrent Stacks:\n";

    cout << "Source: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\nAuxiliary: ";
    while (!a.empty())
    {
        cout << a.top() << " ";
        a.pop();
    }
    cout << "\nDestination: ";
    while (!d.empty())
    {
        cout << d.top() << " ";
        d.pop();
    }
    cout << "\n------------------------\n";
}

void towerOfHanoi(int n, stack<int> &source, stack<int> &aux, stack<int> &dest,
                  char s, char a, char d)
{
    if (n == 1)
    {
        int disk = source.top();
        source.pop();
        dest.push(disk);

        cout << "Move disk " << disk << " from " << s << " -> " << d << "\n";
        return;
        printStacks(source, aux, dest);
    }

    // Step 1: Move N-1 from source -> aux
    towerOfHanoi(n - 1, source, dest, aux, s, d, a);

    // Step 2: Move last disk
    int disk = source.top();
    source.pop();
    dest.push(disk);
    cout << "Move disk " << disk << " from " << s << " -> " << d << "\n";
    printStacks(source, aux, dest);
    // Step 3: Move N-1 from aux -> dest
    towerOfHanoi(n - 1, aux, source, dest, a, s, d);
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    stack<int> source, auxiliary, destination;

    // Fill source stack (largest at bottom)
    for (int i = n; i >= 1; i--)
    {
        source.push(i);
    }
    printStacks(source, auxiliary, destination);
    towerOfHanoi(n, source, auxiliary, destination, 'S', 'A', 'D');

    cout << "\nFinal contents of Destination stack:\n";
    while (!destination.empty())
    {
        cout << destination.top() << " ";
        destination.pop();
    }
    cout << endl;

    return 0;
}
