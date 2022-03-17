
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int len = nums.size();
//         vector<vector<int>>res;
//         sort(nums.begin(), nums.end());

//         for (int a = 0; a < len - 3; a++) {
//             if (a > 0 && nums[a] == nums[a - 1]) continue;
//             for (int b = a + 1; b < len -2; b++) {
//                 if (b > a + 1 && nums[b] == nums[b - 1]) continue;
//                 long sum = target - nums[a] - nums[b];
//                 for (int c = b + 1; c < len - 1; c++) {
//                     int d = len - 1;
//                     if(c >b + 1 && nums[c] == nums[c - 1]) continue;
//                     while (c < d && sum - nums[c] - nums[d] < 0)
//                         d--;
//                     if (c == d) break;
//                     if (sum - nums[c] - nums[d] == 0)
//                         res.push_back({nums[a],nums[b],nums[c],nums[d]});
//                 }
//             }

//         }

//         return res;
//     }
// };



//优化1
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());

        for (int a = 0; a < len - 3; a++) {
            if (a > 0 && nums[a] == nums[a - 1]) continue;
            if ((long)nums[a] + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) break;
            if ((long)nums[a] + nums[len - 1] + nums[len - 2] + nums[len - 3] < target) continue;

            for (int b = a + 1; b < len - 2; b++) {
                if (b > a + 1 && nums[b] == nums[b - 1]) continue;
                if ((long)nums[a] + nums[b] + nums[b + 1] + nums[b + 2] > target) break;
                if ((long)nums[a] + nums[b] + nums[len - 1] + nums[len - 2] < target) continue;

                int c = b + 1, d = len - 1;
                while (c < d) {
                    int sum = target - nums[a] - nums[b] - nums[c] - nums[d];
                    if (sum == 0) {
                        res.push_back({ nums[a],nums[b],nums[c],nums[d] });
                        while (c < d && nums[c] == nums[c + 1])
                            c++;
                        c++;

                        while (c < d && nums[d] == nums[d - 1])
                            d--;
                        d--;
                    }
                    else if (sum > 0) {
                        c++;
                    }
                    else { //sum - nums[c] - nums[d] < 0
                        d--;
                    }
                }
            }

        }

        return res;
    }
};










//执行用时：4 ms, 在所有 C++ 提交中击败了99.79%的用户
//官方解答
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         vector<vector<int>> quadruplets;
//         if (nums.size() < 4) {
//             return quadruplets;
//         }
//         sort(nums.begin(), nums.end());
//         int length = nums.size();
//         for (int i = 0; i < length - 3; i++) {
//             if (i > 0 && nums[i] == nums[i - 1]) {
//                 continue;
//             }
//             if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
//                 break;
//             }
//             if ((long) nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
//                 continue;
//             }
//             for (int j = i + 1; j < length - 2; j++) {
//                 if (j > i + 1 && nums[j] == nums[j - 1]) {
//                     continue;
//                 }
//                 if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
//                     break;
//                 }
//                 if ((long) nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
//                     continue;
//                 }
//                 int left = j + 1, right = length - 1;
//                 while (left < right) {
//                     int sum = nums[i] + nums[j] + nums[left] + nums[right];
//                     if (sum == target) {
//                         quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
//                         while (left < right && nums[left] == nums[left + 1]) {
//                             left++;
//                         }
//                         left++;
//                         while (left < right && nums[right] == nums[right - 1]) {
//                             right--;
//                         }
//                         right--;
//                     } else if (sum < target) {
//                         left++;
//                     } else {
//                         right--;
//                     }
//                 }
//             }
//         }
//         return quadruplets;
//     }
// };
int main() {

    Solution s;
    int arr[4] = { 2,2,2,2 };
    vector<int>vec(arr, arr + sizeof(arr) / sizeof(int));
    s.fourSum(vec, 8);

    system("pause");
    return 0;
}









