#include <vector>
#include <iostream>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0; 

    int k = 1; 

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[k - 1]) { 
            nums[k] = nums[i]; 
            k++; 
        }
    }
    return k;
}

int main() {
    
    vector<int> nums1 = {1, 1, 2};
    int k1 = removeDuplicates(nums1);
    cout << "Unique count: " << k1 << ", Array: ";
    for (int i = 0; i < k1; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;

   
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = removeDuplicates(nums2);
    cout << "Unique count: " << k2 << ", Array: ";
    for (int i = 0; i < k2; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    return 0;
}