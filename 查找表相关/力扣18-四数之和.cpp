
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        // int a = 0, b = a + 1, c = b + 1, d = c + 1;
        for (int a = 0; a < len; a++) {
            if (a > 0 && nums[a] == nums[a - 1]) continue;
            for (int b = a + 1; b < len; b++) {
                if (b > a + 1 && nums[b] == nums[b - 1]) continue;
                long sum = target - nums[a] - nums[b];
                for (int c = b + 1; c < len - 1; c++) {
                    int d = len - 1;
                    if (c > b + 1 && nums[c] == nums[c - 1]) continue;
                    while (c < d && sum - nums[c] - nums[d] < 0)
                        d--;
                    if (c == d) break;
                    if (sum - nums[c] - nums[d] == 0)
                        res.push_back({ nums[a],nums[b],nums[c],nums[d] });
                }
            }

        }

        return res;
    }
};
int main() {

    Solution s;
    int arr[4] = { 2,2,2,2 };
    vector<int>vec(arr, arr + sizeof(arr) / sizeof(int));
    s.fourSum(vec, 8);

    system("pause");
    return 0;
}









