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
	cin >> n;
	vector<long long> a(0),b(0);
	rep(i, n) {
		cin >> x;
		if (x > 0) {
			a.push_back(x);
		}
		else {
			b.push_back(x);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<long long>());
	double hi = -3.0, lo = 3.0;
	cur = a.size(), res = b.size();
	double d;
	if (a.size() >= 3) {
		hi = max(hi, double(a[0] + a[1] + a[2]) / double(a[0] * a[1] * a[2]));
		lo = min(lo, double(a[cur - 1] + a[cur - 2] + a[cur - 3]) / double(a[cur - 1] * a[cur - 2] * a[cur - 3]));
	}
	if (a.size() >= 2 && b.size() >= 1) {
		d = double(a[0] + a[1] + b[0]) / double(a[0] * a[1] * b[0]);
		hi = max(hi, d); lo = min(lo, d);
		d = double(a[0] + a[cur - 1] + b[0]) / double(a[0] * a[cur - 1] * b[0]);
		hi = max(hi, d); lo = min(lo, d);
		d = double(a[cur - 2] + a[cur - 1] + b[0]) / double(a[cur - 2] * a[cur - 1] * b[0]);
		hi = max(hi, d); lo = min(lo, d);

		d = double(a[0] + a[1] + b[res-1]) / double(a[0] * a[1] * b[res-1]);
		hi = max(hi, d); lo = min(lo, d);
		d = double(a[0] + a[cur - 1] + b[res - 1]) / double(a[0] * a[cur - 1] * b[res - 1]);
		hi = max(hi, d); lo = min(lo, d);
		d = double(a[cur - 2] + a[cur - 1] + b[res - 1]) / double(a[cur - 2] * a[cur - 1] * b[res - 1]);
		hi = max(hi, d); lo = min(lo, d);
	}
	if (a.size() >= 1 && b.size() >= 2) {
		d = double(a[0] + b[0] + b[1]) / double(a[0] * b[0] * b[1]);
		hi = max(hi, d); lo = min(lo, d);
		d = double(a[0] + b[0] + b[res - 1]) / double(a[0] * b[0] * b[res - 1]);
		hi = max(hi, d); lo = min(lo, d);
		d = double(a[0] + b[res - 2] + b[res - 1]) / double(a[0] * b[res - 2] * b[res - 1]);
		hi = max(hi, d); lo = min(lo, d);

		d = double(a[cur - 1] + b[0] + b[1]) / double(a[cur - 1] * b[0] * b[1]);
		hi = max(hi, d); lo = min(lo, d);
		d = double(a[cur - 1] + b[0] + b[res - 1]) / double(a[cur - 1] * b[0] * b[res - 1]);
		hi = max(hi, d); lo = min(lo, d);
		d = double(a[cur - 1] + b[res - 2] + b[res - 1]) / double(a[cur - 1] * b[res - 2] * b[res - 1]);
		hi = max(hi, d); lo = min(lo, d);
	}
	if (b.size() >= 3) {
		d = double(b[0] + b[1] + b[2]) / double(b[0] * b[1] * b[2]);
		hi = max(hi, d); lo = min(lo, d);
		d = double(b[res - 3] + b[res - 2] + b[res - 1]) / double(b[res - 3] * b[res - 2] * b[res - 1]);
		hi = max(hi, d); lo = min(lo, d);
	}
	cout << setprecision(13);
	cout << lo << endl << hi << endl;
}