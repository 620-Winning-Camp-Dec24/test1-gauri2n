#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int arr[n];
    

    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                 
            }
            
        }if(count>n/2){
            cout<< arr[i];
            return 0;
        }
    }
    
    return 0;
   
}
