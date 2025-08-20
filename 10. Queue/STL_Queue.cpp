#include <queue>

/* Inserts an element x at the back of the queue q */
void push(std::queue<int> &q, int x) {
    q.push(x);
}

/* Pops out the front element from the queue q and returns it */
int pop(std::queue<int> &q) {
    if (q.empty()) return -1; // throw an exception
    int front = q.front();
    q.pop();
    return front;
}

/* Returns the size of the queue q */
int getSize(std::queue<int> &q) {
    return q.size();
}

/* Returns the last element of the queue */
int getBack(std::queue<int> &q) {
    if (q.empty()) return -1; // throw an exception
    // To get the last element, we need to use a temporary queue
    std::queue<int> temp = q;
    int back;
    while (!temp.empty()) {
        back = temp.front();
        temp.pop();
    }
    return back;
}

/* Returns the first element of the queue */
int getFront(std::queue<int> &q) {
    if (q.empty()) return -1; // throw an exception
    return q.front();
}
