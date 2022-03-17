#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//class Solution {
//public:
//	bool containsNearbyDuplicate(vector<int>& nums, int k) {
//
//		//设定一个区间[left,right] right = left + k - 1 ;
//		int len = nums.size();
//
//
//		int left = 0, right = left + k - 1;
//		unordered_map<int, int>record;
//		for (int i = 0; i <= (right, len - 1); i++) {
//			if (record[nums[i]]) return true;
//			record[nums[i]]++;
//
//		}
//
//		while (right < len - 1 && right - left == k - 1) {
//			if (record[nums[right + 1]])
//				return true;
//			else {
//				record[nums[left]]--;
//				left++;
//
//				right++;
//				record[nums[right]]++;
//
//
//			}
//		}
//
//		return false;
//	}
//};

//课上讲的方法
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {

		//设定一个区间长度为k ;

		unordered_set<int>record;
		for (int i = 0; i <nums.size(); i++) {
			if (record.find(nums[i]) != record.end())
				return true;
			record.emplace(nums[i]);

			if (record.size() == k + 1)
				record.erase(nums[i - k]); // 之所以可以之间去掉前面元素，是因为整个区间没有相同的

		}

		
		

		return false;
	}
};

// //官方
// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         unordered_map<int, int> dictionary;
//         int length = nums.size();
//         for (int i = 0; i < length; i++) {
//             int num = nums[i];
//             if (dictionary.count(num) && i - dictionary[num] <= k) {
//                 return true;
//             }
//             dictionary[num] = i;
//         }
//         return false;
//     }
// };
int main() {


	Solution s;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int>vec(arr, arr + sizeof(arr) / sizeof(int));
	cout << s.containsNearbyDuplicate(vec, 15);

	system("pause");
	return 0;
}