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
	vector<string> s(9);
	rep(i, 9) {
		cin >> s[i];
	}
	
	ans = 0;
	long long ix, iy, jx, jy, vx, vy;
	vector<long long> cx, cy;
	rep(ix, 9) {
		rep(iy, 9) {
			rep(jx, 9) {
				rep(jy, 9) {

					if (ix == jx && iy == jy) {
						continue;
					}

					jud = 1;
					vx = jx - ix; vy = jy - iy;
					x = ix; y = iy;
					cx = { x, x + vx,x + vx + vy,x + vy };
					cy = { y,y + vy,y + vy - vx,y - vx };
					rep(k, 4) {
						if (min(cx[k], cy[k]) < 0 || max(cx[k], cy[k]) >= 9) {
							jud = 0;
							break;
						}
						if (s[cx[k]][cy[k]] == '.') {
							jud = 0;
							break;
						}
					}
					if (jud == 1) {
						//cout << ix << iy << jx << jy << endl;
						ans++;
					}
				}
			}
		}
	}

	cout << ans/4 << endl;
	
}