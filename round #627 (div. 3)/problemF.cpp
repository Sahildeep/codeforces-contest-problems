#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef priority_queue<int> pqb;
typedef priority_queue<int, vi, greater<int> > pqs;

#define iamtheflash         ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod                 1000000007
#define debug1(x)           cout<<"#x: "<<x<<"\n"
#define debug2(x,y)         cout<<"#x: "<<x<<" #y: "<<y<<"\n"
#define debug3(x,y,z)       cout<<"#x: "<<x<<" #y: "<<y<<" #z: "<<z<<"\n"
#define debug4(x,y,z,w)     cout<<"#x: "<<x<<" #y: "<<y<<" #z: "<<z<<" #w: "<<w<<"\n"
#define rep(i,n)            for(int i=0;i<(n);i++)
#define repl(i,n)           for(ll i=0;i<(n);i++)
#define fori(i,a,b)         for(int i=(a);i<=(b);i++)
#define forl(i,a,b)         for(ll i=(a);i<=(b);i++)
#define ford(i,a,b)         for(int i=(a);i>=(b);i--)
#define fordl(i,a,b)        for(ll i=(a);i>=(b);i--)
#define pb                  push_back
#define mp                  make_pair
#define ff                  first
#define ss                  second
#define mid(s,e)            (s+(e-s)/2)
#define setbits(x)          __builtin_popcountll(x)
#define zrobits(x)          __builtin_ctzll(x)
#define ps(x,y)             fixed<<setprecision(y)<<x
#define w(x)                int x; cin>>x; while(x--)
#define in(x)               int x; cin>>x;
#define ins(x)              string x; cin>>x;
#define endl                '\n'
#define infi                INT_MAX
#define infll               LLONG_MAX
#define infim               INT_MIN
#define infllm              LLONG_MIN
#define mk(arr,n,type)      type *arr = new type[n];
#define umap(x,type1,type2) unordered_map<type1, type2 > x;

void singh07() {
	iamtheflash
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int n;
int a[200001];
vi adj[200001];
int dp1[200001];
int dp2[200001];

void dfs1(int nd = 1, int pr = 0) {
	dp1[nd] = a[nd] == 1 ? 1 : -1;
	for (auto neigh : adj[nd]) {
		if (neigh == pr) {
			continue;
		}
		dfs1(neigh, nd);
		dp1[nd] += max(0, dp1[neigh]);
	}
}

void dfs2(int nd = 1, int pr = 0) {
	dp2[nd] = dp1[nd];
	if (pr) {
		int val = dp2[pr] - max(0, dp1[nd]);
		dp2[nd] += max(0, val);
	}
	for (auto neigh : adj[nd]) {
		if (neigh == pr) {
			continue;
		}
		dfs2(neigh, nd);
	}
}

int32_t main() {
	singh07();

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	rep(i, n - 1) {
		in(u);
		in(v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs1();
	dfs2();
	for (int i = 1; i <= n; i++) {
		cout << dp2[i] << " ";
	}

	return 0;
}
