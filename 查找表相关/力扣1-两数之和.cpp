#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//https://leetcode-cn.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

		unordered_map<int, int>record; //numsֵ������
		for (int i = 0; i < nums.size(); i++) {

			int complement = target - nums[i];
			if (record.find(complement) != record.end()) { //���ж�����Ϊ�������֮ǰ��Ԫ�غ�����Ԫ���ظ������¸��ǣ���������32��targetΪ64�����ǵ�һ��32�ᱻ����
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