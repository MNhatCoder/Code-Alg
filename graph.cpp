#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define pb push_back
#define qi queue<int>
#define ari array<int>
#define str string
#define nl "\n"
#define sc ' '
#define F first
#define S second
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
const int n1e3 = 1e3 + 1; 
const int n1e4 = 1e4 + 1;
const int n1e5 = 1e5 + 1;
const int n1e6 = 1e6 + 1;

vector<pll> adj[n1e5];
// #define LOCAL
int main() {
    #ifdef LOCAL
        IOS;
        freopen("main.inp","r",stdin);
        freopen("main.out","w",stdout);
    #endif   
    int n, m, u, v, w; cin >> n >> m;
    FOR(i,1,m) {
        cin >> u >> v >> w;
        adj[u].pb({v,w});
    }
    priority_queue<pll> q;
    q.push({0,1});
    vll dis(n+1,LLONG_MAX);
    dis[1] = 0;
    vector<bool> vis(n+100,false);
    while (!q.empty()) {
        int u = q.top().S;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for(auto cr : adj[u]) {
            int b = cr.F, w = cr.S;
            if (dis[b] > dis[u] + w) {
                dis[b] = dis[u] + w;
                q.push({-dis[b], b});
            } 
        }
    }
    FOR(i,1,n) cout << dis[i] << ' ';
}