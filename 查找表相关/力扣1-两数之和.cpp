#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//https://leetcode-cn.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

		unordered_map<int, int>record; //nums值，索引
		for (int i = 0; i < nums.size(); i++) {

			int complement = target - nums[i];
			if (record.find(complement) != record.end()) { //先判断是因为避免加入之前的元素和现在元素重复，导致覆盖，比如两个32，target为64，但是第一个32会被覆盖
				return { i, record[complement] };
			}
			record[nums[i]] = i;
		}
		throw invalid_argument("no solution");
    }
};


int main() {

	system("pause");
	return 0;
}