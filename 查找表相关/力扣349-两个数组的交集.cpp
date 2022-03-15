#include<iostream>
#include<vector>
#include<set>

//https://leetcode-cn.com/problems/intersection-of-two-arrays/
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

		//set<int>record;
		//for (int i = 0; i < nums1.size(); i++) 
			//record.insert(nums1[i]);
		//修改为如下一行代码
		set<int>record(nums1.begin(), nums1.end());

		set<int>resultSet;
		for (int i = 0; i < nums2.size(); i++) 
			if (record.find(nums2[i]) != record.end())
				resultSet.insert(nums2[i]);
		
		/*vector<int>resultVector;
		for (set<int>::iterator iter = resultSet.begin(); iter != resultSet.end(); iter++) 
			resultVector.push_back(*iter);
		
		return resultVector;*/
		//修改为下面
		return vector<int>(resultSet.begin(), resultSet.end());
	}
};


int main() {

	system("pause");
	return 0;
}