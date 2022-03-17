#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

class Solution {
	struct ComplieByValue {
		bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
			return a.second > b.second;
		}
	};
public:
	int maxPoints(vector<vector<int>>& points) {
		int res = 0;
		if (points.size() <= 2) return points.size();
		//key Ϊ���Ӻͷ�ĸ��ɵ��ַ�����valueΪ���ִ���
		unordered_map<string, int >record;
		for (int i = 0; i < points.size(); i++) {
			record.clear();
			for (int j = i + 1; j < points.size(); j++) {
				int dx = points[j][0] - points[i][0];
				int dy = points[j][1] - points[i][1];

				if (dx == 0)
					dy = 1; //���б��Ϊ0��ͳһ����Ϊ0/1
				else if (dy == 0)
					dx = 1; //���б��Ϊ���ͳһ����Ϊ1/0
				else if (dy < 0) { //Ϊ��ʹ�����ڷ��� ���� -3/2 3/-2 б��һ�������Ƿ���λ�ò�ͬ
					dx = -dx;
					dy = -dy;
				}
				int commonDivisor = gcd(abs(dx), abs(dy));
				dx /= commonDivisor, dy /= commonDivisor;
				record[to_string(dx) + "_" + to_string(dy)]++;

			}
			if (!record.empty()) {

				vector< pair<string, int> > freqV(record.begin(), record.end());
				sort(freqV.begin(), freqV.end(), ComplieByValue());
				res = max(res, freqV[0].second + 1);
			}
		}
		return res;


	}
private:
	int gcd(int a, int b) {
		return b ? gcd(b, a % b) : a;
	}
};


////���ڹٷ����Ż�
//class Solution {
//	struct ComplieByValue {
//		bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
//			return a.second > b.second;
//		}
//	};
//public:
//	int maxPoints(vector<vector<int>>& points) {
//		int res = 0;
//		if (points.size() <= 2) return points.size();
//		//key Ϊ���Ӻͷ�ĸ��ɵ��ַ�����valueΪ���ִ���
//		unordered_map<int, int >record;
//		for (int i = 0; i < points.size(); i++) {
//			if (res >= points.size() - i || res > points.size() / 2) break;
//			record.clear();
//			for (int j = i + 1; j < points.size(); j++) {
//				int dx = points[j][0] - points[i][0];
//				int dy = points[j][1] - points[i][1];
//
//				if (dx == 0)
//					dy = 1; //���б��Ϊ0��ͳһ����Ϊ0/1
//				else if (dy == 0)
//					dx = 1; //���б��Ϊ���ͳһ����Ϊ1/0
//				else if (dy < 0) { //Ϊ��ʹ�����ڷ��� ���� -3/2 3/-2 б��һ�������Ƿ���λ�ò�ͬ
//					dx = -dx;
//					dy = -dy;
//				}
//				int commonDivisor = gcd(abs(dx), abs(dy));
//				dx /= commonDivisor, dy /= commonDivisor;
//				// record[to_string(dx) + "_" + to_string(dy)]++;
//				record[dy + dx * 20001]++;
//			}
//
//
//			int maxn = 0;
//			for (auto& [_, num] : record) {
//				maxn = max(maxn, num + 1);
//			}
//			res = max(res, maxn);
//
//		}
//		return res;
//
//	}
//private:
//	int gcd(int a, int b) {
//		return b ? gcd(b, a % b) : a;
//	}
//};
int main() {

	Solution s;

	int arr1[2] = { 1,1 };
	int arr2[2] = { 2,2 };
	int arr3[2] = { 3,3 };
	vector<vector<int>>points;
	vector<int>onePoint1(arr1, arr1 + sizeof(arr1) / sizeof(int));
	vector<int>onePoint2(arr2, arr2 + sizeof(arr2) / sizeof(int));
	vector<int>onePoint3(arr3, arr3 + sizeof(arr3) / sizeof(int));
	points.push_back(onePoint1);
	points.push_back(onePoint2);
	points.push_back(onePoint3);
	cout << s.maxPoints(points);


	system("pause");
	return 0;
}