#include<iostream>
#include<unordered_map>

using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int lenS = s.size(), lenT = t.size();
        if (lenS != lenT) return false;

        unordered_map<char, char>s2t;
        unordered_map<char, char>t2s;

        for (int i = 0; i < lenS; i++) {

            if (s2t.count(s[i]) && s2t[s[i]] != t[i]) return false;
            if (t2s.count(t[i]) && t2s[t[i]] != s[i]) return false;

            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];

        }
        return true;


    }
};


int main() {

	system("pause");
	return 0;
}