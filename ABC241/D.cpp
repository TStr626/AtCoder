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
	long long n, m, i, j, k, ans, cur, res, jud, mod = 998244353;
	long long query, x, t;
	multiset<long long> ms1,ms2;
	cin >> query;
	auto itr = ms1.begin();
	while (query--) {
		cin >> t;
		if (t == 1) {
			cin >> x;
			ms1.insert(-x);
			ms2.insert(x);
		}
		else if (t == 2) {
			cin >> x >> k;
			itr = ms1.lower_bound(-x);
			while (k > 1 && itr != ms1.end()) {
				k--;
				itr++;
			}
			if (itr == ms1.end()) {
				cout << -1 << endl;
			}
			else {
				cout << -1 * (*itr) << endl;
			}
		}
		else {
			cin >> x >> k;
			itr = ms2.lower_bound(x);
			while (k > 1 && itr != ms2.end()) {
				k--;
				itr++;
			}
			if (itr == ms2.end()) {
				cout << -1 << endl;
			}
			else {
				cout << *itr << endl;
			}
		}
	}
}