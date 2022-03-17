#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		int res = 0;
		unordered_map<int, int>record;
		for (int i = 0; i < nums3.size(); i++)
			for (int j = 0; j < nums4.size(); j++) 
				record[nums3[i] + nums4[j]]++;
		
		for (int i = 0; i < nums1.size(); i++)
			for (int j = 0; j < nums2.size(); j++)
				if (record.find(0 - nums1[i] - nums2[j]) != record.end())//����жϿ��Բ��ӣ�c++ ��ϣ���������һ��������key�����ʼ��valueΪ0����Ӱ����
					res += record[0 - nums1[i] - nums2[j]];
		return res;
	}
};

int main() {

	system("pause");
	return 0;
}