#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
class KVP
{
public:
	int day;
	int profit;
	KVP(int day, int profit) : day{ day }, profit{ profit }{};
	KVP() {}
};

int GetMaxProfit(int idx,int n, KVP kvpArr[15])
{
	if (idx >= n) {
		return 0;
	}

	int profitNext = GetMaxProfit(idx + 1 , n ,kvpArr);
	int profit = 0;

	if (idx + kvpArr[idx].day <= n) {
		profit = kvpArr[idx].profit + GetMaxProfit(idx + kvpArr[idx].day,n,kvpArr);
	}
	return max(profitNext, profit);
}

int main(void) {
	int n;

	cin >> n;

	KVP kvpArr[15]{};
	for (int i = 0; i < n; i++) {
		int day, profit;
		cin >> day >> profit;

		KVP vp(day, profit);
		kvpArr[i] = vp;
	}

	

	cout << GetMaxProfit(0,n,kvpArr);
}
	


