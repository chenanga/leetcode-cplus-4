#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

	struct CmpByValue {
		bool operator()(const pair<char, int>& lhs, const pair<char, int>& rhs) {
			return lhs.second < rhs.second;
		}

    string frequencySort(string s) {

		//统计出现的频率，然后找到对应频率的字符
		unordered_map<char, int>freq;
		for (char ch : s) 
			freq[ch]++;
		
		vector< pair<char,int> > freqV(freq.begin(),freq.end());
		sort(freqV.begin(), freqV.end(), CmpByValue());
		string res = "";
		for (int i = 0; i < freqV.size(); i++) {
			for (int j = 0; j < freqV[i].second; j++) {
				res += freqV[i].first;
			}
		}
		return res;
};


int main() {

	system("pause");
	return 0;
}