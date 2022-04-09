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
	cin >> n;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}

	if (n == 1 && a[0] == 0) {
		cout << "Yes" << endl;
	}
	else if (a[0] == 1) {
		cout << "No" << endl;
	}else{
		i = 0; j = n - 1; jud = 0;
		while (j > i) {
			if (a[j] == jud) {
				j--;
			}
			else if (a[i] == jud && a[i + 1] != jud) {
				i++;
				jud ^= 1;
			}
			else {
				break;
			}
		}
		if (i == j) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}