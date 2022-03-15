#include<iostream>
#include<unordered_map>


using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> record;
        for (int i = 0; i < s.size(); i++) {
            record[s[i]]++;
            record[t[i]]--;
        }
        for (unordered_map<char, int>::iterator iter = record.begin(); iter != record.end(); iter++) 
            if ((*iter).second != 0)
                return false;
        
        return true;
    }
};

int main() {

	system("pause");
	return 0;
}