#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=(int)b;++i)
#define pi pair<int,int>
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mp make_pair
#define pb push_back
#define nl "\n"
#define mi map<int,int>
#define ll long long
#define vi vector<int>
#define ins insert
#define all(x) x.begin(),x.end()
using namespace std;

const int n1e3 = 1e3 + 1; 
const int n1e4 = 1e4 + 1;
const int n1e5 = 1e5 + 1;
const int n1e6 = 1e6 + 1;


int res(vi& v)
{
    vector<int> f(v.size(), 0);
    int length = 1;  
    f[0] = v[0];
 
    for (int i = 1; i < (int)v.size(); i++) {
        auto b = f.begin(), e = f.begin() + length;
        auto it = upper_bound(b, e, v[i]);
        if (it == f.begin() + length)
            f[length++] = v[i];
        else
            *it = v[i];
    }
 
    return length;
}
// #define LOCAL
int main() {
	#ifdef LOCAL
		IOS;
		freopen("main.inp","r",stdin);
		freopen("main.out","w",stdout);
	#endif
	int n; cin >> n;
	vi a(n);
	// FOR(i,0,n-1) cin >> a[i];
	// cout << res(a);
	vector<pi> x(n);
	FOR(i,0,n-1) {
		cin >> x[i].fi >> x[i].se;
	}
	sort(all(x), [](pi xx, pi yy){
		return (xx.fi > yy.fi) || (xx.fi == yy.fi && xx.se < yy.se);
	});
	FOR(i,0,n-1) {
		a[i] = x[i].se;	
	}
	cout << res(a);
}