// 1670. Design Front-Middle-Back Queue

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class FrontMiddleBackQueue {
private:
    vector<int> data;

public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        data.insert(data.begin(), val);
    }
    
    void pushMiddle(int val) {
        int mid = data.size() / 2;
        data.insert(data.begin() + mid, val);
    }
    
    void pushBack(int val) {
        data.push_back(val);
    }
    
    int popFront() {
        if (data.empty()) return -1; // or throw an exception
        int frontVal = data.front();
        data.erase(data.begin());
        return frontVal;
    }
    
    int popMiddle() {
        if (data.empty()) return -1; // or throw an exception
        int mid = (data.size() - 1) / 2; // choose the middle element
        int midVal = data[mid];
        data.erase(data.begin() + mid);
        return midVal;
    }
    
    int popBack() {
        if (data.empty()) return -1; // or throw an exception
        int backVal = data.back();
        data.pop_back();
        return backVal;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
