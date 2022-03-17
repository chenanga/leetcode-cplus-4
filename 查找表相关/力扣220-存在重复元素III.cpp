#include<iostream>
#include<vector>
#include<set>

using namespace std;


class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

		//设定一个区间长度为k ;

		set<long long>record;
		for (int i = 0; i < nums.size(); i++) {
			//if (record.find(nums[i]) != record.end())
				//return true;
			//此时的元素在查找表中查nums[i] - t nums[i] + t
			if (record.lower_bound((long long)nums[i] - (long long)t) != record.end()
				&& *record.lower_bound((long long)nums[i] - (long long)t) <= (long long)nums[i] + (long long)t)
				return true;
				record.emplace(nums[i]);

			if (record.size() == k + 1)
				record.erase(nums[i - k]); // 之所以可以之间去掉前面元素，是因为整个区间没有相同的

		}

		return false;
	}
};
int main() {

	system("pause");
	return 0;
}
