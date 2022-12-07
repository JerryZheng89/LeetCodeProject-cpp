#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solutions {
    public:
    int removeTarget(vector<int>& nums, int target) {
        if (nums.empty()) return 0;

        int slow = 0;
        for (int fast=0; fast<nums.size(); fast++) {
            if (nums[fast] != target) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};

int main(int argc, char ** argv)
{
    Solutions slrm;
    int a[10] = {1,2,2,3,3,3,4,5,5,5};
    vector<int> va(a, a+10);
    int value = 3;

    int length = slrm.removeTarget(va, value);
    
    cout << "zj: rm dump vector is: " << endl;
    // for (const auto i : va)
        // cout << i << ' ';
    for (int i=0; i<length; i++ )
        cout << va[i] << ' ';
    cout << endl;

    return 0;
}