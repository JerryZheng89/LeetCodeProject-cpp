#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 * Note:
 *   You must do this in-place without making a copy of the array.
 *   Minimize the total number of operations. 
 */


// Move Zeroes
// 双指针
// Time Complexity: O(n), Space Complexity: O(1)
class Solutions {
    public:
    int removeElement(vector<int>& nums, int target) {
        int slow = 0;
        for (int fast=0; fast<nums.size(); fast++) {
            if (nums[fast] != target) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
#if 1
    void moveZeroes(vector<int>& nums) {
        int slow = removeElement(nums, 0);
        for (int i = slow; i < nums.size(); i++)
            nums[i] = 0;
    }
#else 
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != 0) {
                swap(nums[slow++], nums[fast]);
            }
        }
    }
#endif
};

int main(int argc, char ** argv)
{
    Solutions slrm;
    int a[10] = {1,0,0,3,6,0,4,5,0,5};
    vector<int> va(a, a+10);

    slrm.moveZeroes(va);
    
    cout << "zj: rm dump vector is: " << endl;
    // for (const auto i : va)
        // cout << i << ' ';
    for (int i=0; i<va.size(); i++ )
        cout << va[i] << ' ';
    cout << endl;

    return 0;
}