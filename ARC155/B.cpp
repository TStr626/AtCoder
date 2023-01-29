#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long query, t;
	cin >> query >> x >> y;
	set<long long> ms;
	ms.insert(-100000000001);
	ms.insert(-100000000000);
	ms.insert(100000000000);
	ms.insert(100000000001);
	ms.insert(x + y);
	ms.insert(x - y);
	while (query--) {
		cin >> t;
		if (t == 1) {
			cin >> x >> y;
			ms.insert(x + y);
			ms.insert(x - y);
		}
		else {
			cin >> x >> y;
			auto itr1 = ms.lower_bound(x);
			auto itr2 = ms.lower_bound(y);
			auto itr3 = itr1;
			auto itr4 = itr2;
			itr3--; itr4--;
			//cout << *itr1 << *itr2 << ' ';
			if (itr1 == itr2) {
				ans = min(abs(x - *itr3), abs(y - *itr2));
			}
			else {
				ans = 0;
			}
			cout << ans << endl;
		}
	}
	
}
