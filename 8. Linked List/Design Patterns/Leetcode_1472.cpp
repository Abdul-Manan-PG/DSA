// 1472. Design Browser History

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    string val;
    Node *next;
    Node *pre;
    Node(string v)
    {
        val = v;
        next = NULL;
        pre = NULL;
    }
};

class BrowserHistory
{
private:
    Node *curr;

public:
    BrowserHistory(string homepage)
    {
        curr = new Node(homepage);
    }

    ~BrowserHistory()
    {
        deleteNodes(curr->next);
        while (curr)
        {
            Node *temp = curr;
            curr = curr->pre;
            delete temp;
        }
    }

    void deleteNodes(Node *head)
    {
        if (!head)
            return;
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void visit(string url)
    {
        if (curr->next)
        {
            deleteNodes(curr->next);
        }
        curr->next = new Node(url);
        curr->next->pre = curr;
        curr = curr->next;
    }

    string back(int steps)
    {
        while (steps > 0 && curr->pre)
        {
            curr = curr->pre;
            steps--;
        }
        return curr->val;
    }

    string forward(int steps)
    {
        while (steps > 0 && curr->next)
        {
            curr = curr->next;
            steps--;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */