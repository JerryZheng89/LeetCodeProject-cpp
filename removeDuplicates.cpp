#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * For example, Given input array A = [1,1,2],
 * Your function should return length = 2, and A is now [1,2]. 
 * 
 */


class Solutions {
    public:
    int removeDumplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int slow = 0;
        for (int fast=0; fast<nums.size(); fast++) {
            if (nums[fast] != nums[slow]) {
                nums[++slow] = nums[fast];
            }
        }
        return slow+1;
    }
};

int main(int argc, char ** argv)
{
    Solutions slrm;
    int a[10] = {1,2,2,3,3,3,4,5,5,5};
    vector<int> va(a, a+10);
    int length = slrm.removeDumplicates(va);
    
    cout << "zj: rm dump vector is: " << endl;
    // for (const auto i : va)
        // cout << i << ' ';
    for (int i=0; i<length; i++ )
        cout << va[i] << ' ';
    cout << endl;

    return 0;
}