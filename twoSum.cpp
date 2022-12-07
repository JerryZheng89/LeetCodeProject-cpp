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

// Two Sum
// 方法2：HashMap + 两次遍历。用一个哈希表，存储每个数对应的下标
// Time Complexity: O(n)，Space Complexity: O(n)
class Solutions {
    public:

#if 0
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i< nums.size(); i++) {
            m[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            auto complement = m.find(target - nums[i]);
            if (complement != m.end() && complement->second > i) {
                return {i, complement->second};
            }
        }
        return {-1, -1};
    }
#else 
// Two Sum
// 方法2：HashMap + 单次遍历。用一个哈希表，存储每个数对应的下标
// Time Complexity: O(n)，Space Complexity: O(n)
// 疑问: unordered_map [] 操作符, 遇到没有的键值, 自动插入这个键值对, 
//      遇到key相同, 值不同的也会插入(代码验证得来的结果)
//      但如果遇到 key相同, 值也相同时, []的赋值操作会得到什么样的结果呢???
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            auto complement = m.find(target - nums[i]);
            if (complement != m.end()) {
                return {i, complement->second};
            }
            m[nums[i]] = i;
        }
        return {-1, -1};
    }
#endif

};

int main(int argc, char ** argv)
{
    Solutions slrm;
    int a[] = {2,3,4,7,11,15};
    vector<int> nums(a, a+6);
    vector<int> maps;
    maps = slrm.twoSum(nums, 9);
    cout << "target:" << 6<<  "with sum indexs is: " << maps[0]  << ", " << maps[1] << endl;

    return 0;
}