#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct node
{
    int val;
    node *next;
    node() : val(0), next(nullptr) {}
    node(int val) : val(val), next(nullptr) {}
};

class SLL
{
private:
    node *head;
    node *current;

public:
    SLL() : head(nullptr), current(nullptr) {}

    ~SLL()
    {
        node *temp;
        while (head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int val)
    {
        node *newNode = new node(val);
        if (head)
        {
            current->next = newNode;
            current = current->next;
        }
        else
        {
            head = newNode;
            current = head;
        }
    }

    void insertAtFirst(int val)
    {
        node *newNode = new node(val);
        if (head)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            head = newNode;
            current = head;
        }
    }

    void insertAtIndex(int val, int index)
    {
        node *newNode = new node(val);
        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        node *runnerPtr = head;
        int currentIndex = 0;
        while (runnerPtr && currentIndex < index - 1)
        {
            runnerPtr = runnerPtr->next;
            currentIndex++;
        }
        if (!runnerPtr)
        {
            cout << "Index out of bounds" << endl;
            delete newNode;
            return;
        }
        newNode->next = runnerPtr->next;
        runnerPtr->next = newNode;
    }

    void printList()
    {
        node *temp = head;
        while (temp)
        {
            cout << temp->val;
            if (temp->next)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};