#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         //寻找a+b=-c
//         set < vector<int>>res;
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < nums.size(); i++) {

//             if( i > 0 && nums[i] == nums[i - 1]) continue;
//             int a = nums[i];
//             unordered_map<int, int>record;
//             for (int j = i + 1; j < nums.size(); j++) {
//                 // if( j >i + 1 && nums[j] == nums[j - 1]) continue;

//                 int complement = 0 - a - nums[j];

//                 if (record.find(complement) != record.end())
//                     res.insert({ nums[record[complement]], nums[i], nums[j],  });
//                 record[nums[j]] = j;
//             }
//         }
//         vector<vector<int>> myres(res.begin(), res.end());
//         return myres;
//     }
// };

// // 模仿官方题解
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {

//         int len = nums.size();
//         int first = 0, second = 1; //三个指针
//         sort(nums.begin(), nums.end());
//         vector<vector<int>>ans;

//         for (; first < len; first++) {

//             //如果当前first和上一个值相同，调过
//             if (first > 0 && nums[first] == nums[first - 1]) continue;
//             for (second = first + 1; second < len; second++) {
//                 int third = len - 1;
//                 while (second < third) {
//                     if (second > first + 1 && nums[second] == nums[second - 1]) {
//                         second++;
//                         continue;
//                     }
//                     int sum = nums[first] + nums[second] + nums[third];
//                     if (sum == 0) { 
//                         ans.push_back({ nums[first], nums[second], nums[third] }); 
//                         second++;
//                         third--;
//                     }
//                     else if (sum > 0) third--;
//                     else second++;
//                }
//                 if (second >= third) break;

//             }
//         }

//         return ans;
//     }
// };


// 官方题解
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int len = nums.size();
        int first = 0, second = 1; //三个指针
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;

        for (; first < len; first++) {

            //如果当前first和上一个值相同，调过

            if (first > 0 && nums[first] == nums[first - 1]) continue;
            int third = len - 1;
            int target = -nums[first];
            for (second = first + 1; second < len; second++) {

                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;
                while (second < third && nums[second] + nums[third] > target)
                    third--;


                if (second == third) break;
                if (nums[third] + nums[second] == target)
                    ans.push_back({ nums[first], nums[second], nums[third] });


            }
        }

        return ans;
    }
};

int main() {

    Solution s;
    int res1[6] = { -1,0,1,2,-1,-4 };
    vector<int>res(res1,res1 + sizeof(res1)/sizeof(res1[0]));
    s.threeSum(res);
	system("pause");
	return 0;
}