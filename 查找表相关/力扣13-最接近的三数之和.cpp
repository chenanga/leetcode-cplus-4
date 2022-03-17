#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {


		int len = nums.size();
		int best = 1e7;
		if (len == 3) return nums[0] + nums[1] + nums[2];
		sort(nums.begin(), nums.end());

		for (int a = 0; a < len - 2; a++) {

			int left = a + 1, right = len - 1;
			while (left < right ) {

				int sum = nums[a] + nums[left] + nums[right];

				// 根据差值的绝对值来更新答案
				if (abs(sum - target) < abs(best - target)) {
					best = sum;
				}
				if (sum == target)
					return sum;
				else if (sum > target)
					right--;
				else
					left++;
			}
		}
		return best;
	}

};

int main() {


	Solution s;
	int arr[] = { -1,2,1,-4 };
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	s.threeSumClosest(vec, 1);
	system("pause");
	return 0;
}