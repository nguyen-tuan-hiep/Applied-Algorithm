// Consider the array { 5, 3, -6, 2 }.
 
// The total number of ways to reach a target of 6 using only + and – operators is 4 as:
 
// (-)-6 = 6
// (+) 5 (+) 3 (-) 2 = 6
// (+) 5 (-) 3 (-) -6 (-) 2 = 6
// (-) 5 (+) 3 (-) -6 (+) 2 = 6
 
// Similarly, there are 4 ways to calculate the target of 4:
 
// (-)-6 (-) 2 = 4
// (-) 5 (+) 3 (-)-6 = 4
// (+) 5 (-) 3 (+) 2 = 4
// (+) 5 (+) 3 (+)-6 (+) 2 = 4

#include <iostream>
#include <vector>
using namespace std;
 
// Count ways to calculate a target from elements of the specified array
int countWays(vector<int> const &nums, int i, int target)
{
    // base case: if a target is found
    if (target == 0 && i == nums.size()) {
        return 1;
    }
 
    // base case: no elements are left
    if (i == nums.size()) {
        return 0;
    }
 
    // 1. ignore the current element
    int exclude = countWays(nums, i + 1, target);
 
    // 2. Consider the current element
 
    // 2.1. Subtract the current element from the target
    // 2.2. Add the current element to the target
    int include = countWays(nums, i + 1, target - nums[i]) +
                countWays(nums, i + 1, target + nums[i]);
 
    // Return total count
    return exclude + include;
}
 
int main()
{
    // input array and target number
    vector<int> nums = { 5, 3, -6, 2 };
    int target = 6;
 
    cout << countWays(nums, 0, target) << " ways";
 
    return 0;
}