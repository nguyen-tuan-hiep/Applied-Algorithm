#include<iostream>
#include<map>
using namespace std;

// use map, key = num, value = index[num] for each num in the array.

int main(){
    int arr[] = {1,2,3,9,11};
    // map = ({1,0}, {2,1}, {3,2}, {9,3}, {11,4}})
    int k = 12;
    int len = sizeof(arr)/sizeof(arr[0]);
    map<int,int> m;
    for(int i = 0; i<len; i++){
        int tmp = k-arr[i];
        if(m.count(tmp)>0){     //check if tmp is in the key of map
            cout << arr[m[tmp]] << " " << arr[i] << endl;
        }else
            m.insert({arr[i], i});
    }
    //print the key of map
    // for(auto it = m.begin(); it!=m.end(); it++){
    //     cout << it->first << " ";
}



// return index of 2 integers.
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int,int> m;
//         for(int i = 0; i<nums.size(); i++){
//             int n = nums[i];
//             int complement = target-n;
//             if(m.count(complement)){   // found
//                 return {m[complement],i};
//             }
//             m[n]= i;
//         }
//         return {};
//     }
// };