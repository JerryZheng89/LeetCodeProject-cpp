#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solutions {
    public:
    int removeDumplicates(vector<int>& nums) {
#if 0
        if (nums.empty()) return 0;

        int slow = 0;
        int dumpCount = -1;
        for (int fast=0; fast<nums.size(); fast++) {
            if (nums[fast] != nums[slow]) {
                if (dumpCount > 0) slow++;
                nums[++slow] = nums[fast];
                dumpCount = 0;
            } else {
                dumpCount++;
            }
        }
        if (dumpCount > 0) slow++;
        return slow+1;
#else
        const int N = 2;
        if (nums.size() <= N) return nums.size();

        int slow = N;
        for (int fast = N; fast < nums.size(); fast++){
            if (nums[fast] != nums[slow-N])
                nums[slow++] = nums[fast];
        }

        return slow;
#endif

#if 0
    int removeDuplicates(vector<int>& nums) {
        const int n = nums.size();
        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && i < n - 1 && nums[i] == nums[i - 1] && nums[i] == nums[i + 1])
                continue;

            nums[index++] = nums[i];
        }
        return index;
#endif
    }
};

int main(int argc, char ** argv)
{
    Solutions slrm;
    int a[10] = {1,2,2,3,3,3,4,5,6,7};
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