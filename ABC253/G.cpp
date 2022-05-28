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

pair<long long, long long> convert(long long n, long long a) {
	long long cur, res, i, j;
	pair<long long, long long> p;
	cur = a; res = 0;
	i = 0; j = 0;
	while (cur > 0) {
		if (n - 1 - i < cur) {
			cur -= n - 1 - i;
			i++;
		}
		else {
			j = i + cur;
			cur = 0;
		}
	}
	return { i,j };
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	long long l, r;
	cin >> n >> l >> r;
	pair<long long, long long> p, q;
	vector<long long> a(n), b(n);
	rep(i, n) {
		a[i] = i;
	}
	p = convert(n, l), q = convert(n, r);
	//cout << p.first << p.second << q.first << q.second;
	if (p.first == q.first) {
		i = p.first;
		for (j = p.second; j <= q.second; j++) {
			swap(a[i], a[j]);
		}
	}
	else {
		i = p.first;
		for (j = p.second; j < n; j++) {
			swap(a[i], a[j]);
		}

		for (i = 0; i <= p.first; i++) {
			b[i] = a[i];
		}
		cur = p.first + 1;
		res = q.first - cur;
		for (i = 0; i < n - p.first - 1; i++) {
			b[cur + (i + res) % (n - cur)] = a[cur + i];
		}
		reverse(b.begin() + cur, b.begin() + cur + res);
		
		rep(i, n) {
			a[i] = b[i];
			//cout << a[i];
		}

		i = q.first;
		for (j = i + 1; j <= q.second; j++) {
			swap(a[i], a[j]);
		}
		/*
		
		
		res = n - 1; cur = q.first - p.first - 1;
		for (i = p.first + 1; i < q.first; i++) {
			b[i] = a[res];
			res--;
		}
		for (i = q.first; i < n; i++) {
			b[i] = a[i - cur];
		}
		

		rep(i, n) {
			a[i] = b[i];
			cout << a[i];
		}
		cout << endl;
		*/
	}

	rep(i, n) {
		if (i) cout << ' ';
		cout << a[i] + 1;
	}
	cout << endl;
}
