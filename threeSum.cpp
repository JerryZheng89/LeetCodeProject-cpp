#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// 3Sum
// 先排序，然后双指针左右夹逼，注意跳过重复的数
// Time Complexity: O(n^2)
// Space Complexity: from O(logn) to O(n), depending on the
// implementation of the sorting algorithm
class Solutions {
    public:
    vector<vector<int>> twoSumII(vector<int> & nums, int start, int target) {
        vector<vector<int>> result;
        int low = start, high = nums.size() - 1;

        while(low < high) {
            int sum = nums[low] + nums[high];
            if (sum > target) {
                --high;
            } else if (sum < target) {
                ++low;
            } else {
                result.push_back({ nums[low++], nums[high--] });
                while(low < high && nums[low] == nums[low-1]) ++low;
                while(low < high && nums[high] == nums[high+1]) --high;
            }
        }
        return result;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                for (auto& lst: twoSumII(nums, i+1, 0-nums[i])) {
                    // cout << "0:" << lst[0] << ", 1:" << lst[1] << endl;
                    lst.insert(lst.begin(), nums[i]);
                    result.push_back(lst);
                }
            }
        }
        return result;
    }
};

int main(int argc, char ** argv)
{
    Solutions slrm;
    int a[] = {2,-3,-4,7,13,-15};
    int target = 11;

    vector<int> nums(a, a+6);
    vector<vector<int>> maps = slrm.threeSum(nums);

    cout << "list size is " << maps.size() << endl;
    for (int i =0; i < maps.size(); i++) {
        cout << " the three nums sum to zero is: " << maps[i][0] << ", " << maps[i][1] << ", " << maps[i][2] << endl;
    }

    return 0;
}