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
	long long query;
	cin >> n >> query;
	
	vector<multiset<int>> card(n);
	vector<set<int>> box(200000);
	while(query--) {
		cin >> k;
		if (k == 1) {
			cin >> x >> y;
			card[y - 1].insert(x - 1);
			box[x - 1].insert(y - 1);
		}
		else if (k == 2) {
			cin >> y;
			for (auto x : card[y - 1]) {
				cout << x + 1 << ' ';
			}
			cout << endl;
		}
		else {
			cin >> x;
			for (auto y : box[x - 1]) {
				cout << y + 1 << ' ';
			}
			cout << endl;
		}
	}
	
}