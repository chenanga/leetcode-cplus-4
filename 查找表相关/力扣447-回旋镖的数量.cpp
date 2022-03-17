
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		int res = 0;
		//i��Ϊ��Ŧ��
		unordered_map<int, int>record; //��¼�����Ӧ�ĵ���� //��ϣ������ߣ�ʡ�ռ�
		for (int i = 0; i < points.size(); i++) {
			record.clear();
			for (int j = 0; j < points.size(); j++) {
				if (i != j)
					record[dis(points[i], points[j])]++;
			}
			for (unordered_map<int, int>::iterator iter = record.begin();
				iter != record.end(); iter++) {
				res += (*iter).second * ((*iter).second - 1);
			}
		}
		return res;


	}
private:
	int dis(vector<int>& x1, vector<int>& x2) {
		return (x2[1] - x1[1]) * (x2[1] - x1[1]) + (x2[0] - x1[0]) * (x2[0] - x1[0]);
	}
};


// //�Ż� (n)(n-1) = 2 * ( 1 + 2 + ... + n - 1)
// //������һ��ѭ��
// class Solution {
// public:
//     int numberOfBoomerangs(vector<vector<int>> &points) {
//         int ans = 0;
//         unordered_map<int, int> cnt;
//         for (auto&& x : points) {
//             cnt.clear();
//             for (auto&& y : points) {
//                 ans += 2 * cnt[(x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1])]++;
//             }
//         }
//         return ans;
//     }
// };

int main() {

	system("pause");
	return 0;
}