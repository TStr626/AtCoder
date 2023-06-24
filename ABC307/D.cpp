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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	string s;
	cin >> s;
	string t;
	cur = 0;
	rep(i, n) {
		t.push_back(s[i]);
		if (s[i] == '(') {
			cur++;
		}
		if (s[i] == ')' && cur) {
			while (t[t.size() - 1] != '(') {
				t.pop_back();
			}
			t.pop_back();
			cur--;
		}
	}
	cout << t << endl;
}