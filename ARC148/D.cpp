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
	long long query;
	cin >> n >> m;
	n *= 2;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}

	/*
	cur = 0;
	rep(i, n) {
		cur = (cur + a[i]) % m;
	}
	*/
	
	map<long long, long long> mp;
	rep(i, n) {
		mp[a[i]]++;
	}
	
	auto itr = mp.begin();
	jud = 1; cur = 0;
	for (itr = mp.begin(); itr != mp.end(); itr++) {
		if (m % 2 == 1) {
			// m odd
			if (itr->second % 2 == 1) {
				jud = 0;
			}
		}
		else {
			// m even
			res = itr->first;
			if (res >= m / 2) {
				break;
			}
			if (mp[res] % 2 == 0 && mp[(res + m / 2) % m] % 2 == 0) {
				// safe
			}
			else if (mp[res] % 2 == 1 && mp[(res + m / 2) % m] % 2 == 1) {
				// make pair
				cur++;
			}
			else {
				// out
				jud = 0;
			}
		}
		
	}
	if (jud == 1 && (cur % 2 == 0)) {
		cout << "Bob" << endl;
	}
	else {
		cout << "Alice" << endl;
	}
}