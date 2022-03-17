#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {

		unordered_set<int>record;
		for (int i = 0; i < nums.size(); i++) {
			if (record.count(nums[i]))
				return true;
			record.emplace(nums[i]);
		}
		return false;
	}
};



int main() {

	system("pause");
	return 0;
}