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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long z;
	cin >> n >> x >> y >> z;
	vector<pair<long long, long long>> mat(n), eng(n), sum(n);
	vector<bool> pass(n, false);
	rep(i, n) {
		cin >> mat[i].first;
		mat[i].first *= -1;
		mat[i].second = i;
	}
	rep(i, n) {
		cin >> eng[i].first;
		eng[i].first *= -1;
		eng[i].second = i;
		sum[i].first = mat[i].first + eng[i].first;
		sum[i].second = i;
	}

	sort(mat.begin(), mat.end());
	sort(eng.begin(), eng.end());
	sort(sum.begin(), sum.end());

	rep(i, x) {
		pass[mat[i].second] = true;
	}
	i = 0;
	while (y > 0) {
		if (!pass[eng[i].second]) {
			pass[eng[i].second] = true;
			y--;
		}
		i++;
	}

	i = 0;
	while (z > 0) {
		if (!pass[sum[i].second]) {
			pass[sum[i].second] = true;
			z--;
		}
		i++;
	}

	rep(i, n) {
		if (pass[i]) {
			cout << i + 1 << endl;
		}
	}
}