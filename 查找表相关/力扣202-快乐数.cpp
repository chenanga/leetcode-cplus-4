#include<iostream>
#include<unordered_map>


using namespace std;

class Solution {
public:
    bool isHappy(int n) {

        unordered_map<int, int>order;

        while (true) {
            n = sumSquare(n);
            if (n == 1)
                return true;
            if (order[n] != 0)
                return false;
            order[n]++;
        }
        return true;

    }
private:
    int sumSquare(int n) {

        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};

//还有一种方法称为快慢指针


int main() {

	system("pause");
	return 0;
}