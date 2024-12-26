#include <iostream>
using namespace std;

int lastRemaining(int n) {
    int head = 1;  
    int step = 1;  
    bool leftToRight = true;  
    while (n > 1) {  
        if (leftToRight || n % 2 == 1) {
           
            head += step;
        }
        step *= 2;  
        n /= 2;  
        leftToRight = !leftToRight; 
    }
    return head;  
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "The last remaining number is: " << lastRemaining(n) << endl;
    return 0;
}

