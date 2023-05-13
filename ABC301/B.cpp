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
void yes() {
	cout << "Yes" << endl;
}
void no() {
	cout << "No" << endl;
}
void vec_h(vector<long long> a) {
	int n = a.size(), i;
	rep(i, n) {
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << endl;
}
void vec_v(vector<long long> a) {
	for (auto c : a) {
		cout << c << endl;
	}
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	vector<long long> vans(0);
	vans.push_back(a[0]);
	for (i = 1; i < n; i++) {
		if (a[i - 1] + 1 < a[i]) {
			cur = a[i - 1] + 1;
			while (cur < a[i]) {
				vans.push_back(cur);
				cur++;
			}
		}
		else if(a[i-1]-1>a[i]){
			cur = a[i - 1] - 1;
			while (cur > a[i]) {
				vans.push_back(cur);
				cur--;
			}
		}
		vans.push_back(a[i]);
	}
	vec_h(vans);
}