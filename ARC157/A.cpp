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
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b == 0 && c == 0){
		if (min(a, d) == 0) {
			yes();
		}else{
			no();
		}
		return 0;
	}

	if (abs(b - c) <= 1) {
		yes();
	}
	else { 
		no();
	}
}