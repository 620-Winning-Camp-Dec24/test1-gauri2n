#include<iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> queue;
    int head;
    int tail;
    int size;

public:
    MyCircularQueue(int k) {
        queue.resize(k);  
        head = -1;        
        tail = -1;        
        size = k;         
    }

    bool enQueue(int value) {
        if (isFull()) { 
            return false;
        }

        if (isEmpty()) { 
            head = 0;
        }

        tail = (tail + 1) % size;  
        queue[tail] = value;       
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {  
            return false;
        }

        if (head == tail) {  
            head = -1;
            tail = -1;
        } else {
            head = (head + 1) % size;  
        }
        return true;
    }

    int Front() {
        if (isEmpty()) {  
            return -1;
        }
        return queue[head];  
    }

    int Rear() {
        if (isEmpty()) {  
            return -1;
        }
        return queue[tail];  
    }

    bool isEmpty() {
        return head == -1;  
    }

    bool isFull() {
        return (tail + 1) % size == head;  
    }
};


int main() {
    MyCircularQueue myCircularQueue(3);

    myCircularQueue.enQueue(1);
    myCircularQueue.enQueue(2); 
    myCircularQueue.enQueue(3); 
    myCircularQueue.enQueue(4); 
    cout << myCircularQueue.Rear() << endl;     
    cout << myCircularQueue.isFull() << endl;   
    myCircularQueue.deQueue();  
    myCircularQueue.enQueue(4);     
    cout << myCircularQueue.Rear() << endl;     

    return 0;
}