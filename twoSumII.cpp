#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * @brief 
 * 描述​

Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
Constraints:
- 2<=nmums.length<=10^5
- -10^9 <=nums[i]<=10^9
- -10^9 <=target<=10^9
- Only one valid answer exists
 */

// 2Sum II
// Time Complexity: O(n)，Space Complexity: O(1)
class Solutions {
    public:
    vector<int> twoSum(vector<int> & nums, int target) {
        int left = 0, right = nums.size() -1;
        while(left < right) {
            int sum = nums[left] + nums[right];
            if (sum > target) {
                right--;
            } else if (sum < target) {
                left++;
            } else {
                return {left, right};
            }
        }

        return {-1, -1};
    }
};

int main(int argc, char ** argv)
{
    Solutions slrm;
    int a[] = {2,3,4,7,13,18};
    int target = 11;

    vector<int> nums(a, a+6);
    vector<int> maps = slrm.twoSum(nums, target);
    cout << "target: " << target<<  " with sum indexs is: " << maps[0]  << ", " << maps[1] << endl;

    return 0;
}