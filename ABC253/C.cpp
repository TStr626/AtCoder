#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353, inf = 10000000;
	multiset<long long> ms;
	long long query, c, t;
	cin >> query;
	auto itr = ms.begin();
	while (query--) {
		cin >> t;
		if (t == 1) {
			cin >> x;
			ms.insert(x);
		}
		else if (t == 2) {
			cin >> x >> c;
			rep(i, c) {
				if (ms.count(x)) {
					itr = ms.find(x);
					ms.erase(itr);
				}
				else {
					break;
				}
			}
		}
		else {
			itr = ms.begin();
			x = *itr;
			itr = ms.end();
			itr--;
			y = *itr;
			cout << y - x << endl;
		}
	}

}
