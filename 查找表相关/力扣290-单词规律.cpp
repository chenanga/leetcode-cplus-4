#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;


//class Solution {
//public:
//    bool wordPattern(string pattern, string s) {
//
//		unordered_map<char,int>recoredC;
//		unordered_map<string, int>recoredS;
//		for (int i = 0; i < pattern.size(); i++) 
//			recoredC[pattern[i]]++;
//		
//        vector<string>strVector;
//        strVector = splitStr(s, " ");
//        for (int i = 0; i < strVector.size(); i++) {
//            recoredS[strVector[i]]++;
//        }
//
//        vector<int>compare1;
//        vector<int>compare2;
//
//        for (unordered_map<char, int>::iterator iter = recoredC.begin(); iter != recoredC.end(); iter++) 
//            compare1.push_back((*iter).second);
//        for (unordered_map<string, int>::iterator iter = recoredS.begin(); iter != recoredS.end(); iter++)
//            compare2.push_back((*iter).second);
//        sort(compare1.begin(),compare1.end());
//        sort(compare2.begin(), compare2.end());
//        if (compare1 == compare2) 
//            return true;
//        else
//            return false;
//
//
//
//
//    }
//private:
//
//	vector<string> splitStr(string &str, string pattern) {
//        vector<string> resVec;
//
//        if ("" == str)
//        {
//            return resVec;
//        }
//
//        //方便截取最后一段数据
//        string strs = str + pattern;
//
//        size_t pos = strs.find(pattern);
//        size_t size = strs.size();
//
//        while (pos != string::npos)
//        {
//            string x = strs.substr(0, pos);
//            resVec.push_back(x);
//            strs = strs.substr(pos + 1, size);
//            pos = strs.find(pattern);
//        }
//
//        return resVec;
//
//	}
//};

//官方代码
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string>char2str;
        unordered_map<string, char>str2char;
        int len = str.size();
        int i = 0;
        for (char ch : pattern) {
            if (i >= len) return false;//此时说明pattern长于s

            int j = i;
            while (j < str.size() && str[j] != ' ') {
                j++;
            }
            string word = str.substr(i, j - i);
            if (char2str.count(ch) && char2str[ch] != word)
                return false;
            if (str2char.count(word) && str2char[word] != ch)
                return false;

            char2str[ch] = word;
            str2char[word] = ch;

            i = j + 1;
        }

        return i >= len; //如果i<len，说明pattern比s短
    }
};


int main() {

    Solution s1;
    cout<< s1.wordPattern("he", "unit");
  
	system("pause");
	return 0;
}