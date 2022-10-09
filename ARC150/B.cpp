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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf = 10000000001;
	long long test, a, b;
	cin >> test;
	while (test--) {
		cin >> a >> b;
		ans = 2000000000ll;

		
		if (b <= a) {
			ans = min(ans, a - b);
		}
		ans = min(ans, (a - (b % a)) % a);

		i = 1;
		while (a * i <= b && i * i <= 1000000000) {
			y = (i - (b % i)) % i;
			x = ((b + y) / i) - a;
			ans = min(ans, x + y);
			i++;
		}
		
		for (x = 0; x < a && x * x <= 1000000000; x++) {
			cur = x + a;
			y = (cur - b % cur) % cur;
			ans = min(ans, x + y);
			if (ans > x + y) {
				//cout << x << ' ' << y << endl;
				
			}
		}
		cout << ans << endl;
	}
	
}