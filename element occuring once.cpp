#include<iostream>
using namespace std;
int singleelement(int arr[],int n){
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count==1){
            return arr[i];
        }
    }

return -1;
}
int main(){
   int arr[] = {1, 1, 2, 2, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

cout<<singleelement(arr, n);
}

