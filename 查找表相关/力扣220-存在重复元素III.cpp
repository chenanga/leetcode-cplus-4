#include<iostream>
#include<vector>
#include<set>

using namespace std;


class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

		//�趨һ�����䳤��Ϊk ;

		set<long long>record;
		for (int i = 0; i < nums.size(); i++) {
			//if (record.find(nums[i]) != record.end())
				//return true;
			//��ʱ��Ԫ���ڲ��ұ��в�nums[i] - t nums[i] + t
			if (record.lower_bound((long long)nums[i] - (long long)t) != record.end()
				&& *record.lower_bound((long long)nums[i] - (long long)t) <= (long long)nums[i] + (long long)t)
				return true;
				record.emplace(nums[i]);

			if (record.size() == k + 1)
				record.erase(nums[i - k]); // ֮���Կ���֮��ȥ��ǰ��Ԫ�أ�����Ϊ��������û����ͬ��

		}

		return false;
	}
};
int main() {

	system("pause");
	return 0;
}
