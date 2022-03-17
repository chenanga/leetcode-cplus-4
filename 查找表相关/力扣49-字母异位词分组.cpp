#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<algorithm>

using namespace std;

//O(n^2)��ʱ

class Solution {

public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {

		vector<vector<string>>res;
		unordered_map<string, vector<string> >record; //�����������ַ������ұ���ԭʼ�ַ����ַ�

		for (string str : strs) {
			string tempStr = str;
			sort(tempStr.begin(), tempStr.end());
			record[tempStr].push_back(str);
		}
		for (unordered_map<string, vector<string> >::iterator iter = record.begin(); iter != record.end(); iter++) {
			res.push_back((*iter).second);
		}
		
		return res;
	}
};

int main() {

	unordered_map<string,vector<int>  >record;


	system("pause");
	return 0;
}