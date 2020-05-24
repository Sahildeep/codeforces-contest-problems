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

vi adj[200005];
int n, m, a, b, c;

vi bfs(int src) {
	queue<int> q;
	vector<bool> visited(n + 1);
	vector<int> d(n + 1);

	q.push(src);
	visited[src] = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : adj[v]) {
			if (!visited[u]) {
				visited[u] = true;
				q.push(u);
				d[u] = d[v] + 1;
			}
		}
	}
	return d;
}

int32_t main() {
	singh07();

	w(t) {
		cin >> n >> m >> a >> b >> c;

		mk(p, m + 1, ll);
		fori(i, 1, m) cin >> p[i];

		sort(p + 1, p + m + 1);

		p[0] = 0;
		fori(i, 1, m) {
			p[i] += p[i - 1];
		}

		fori(i, 1, n) {
			adj[i].clear();
		}

		rep(i, m) {
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		vi ad = bfs(a);
		vi bd = bfs(b);
		vi cd = bfs(c);

		ll ans = infll;

		fori(d, 1, n) {
			int id = ad[d] + bd[d] + cd[d];
			int ext = bd[d];

			if (id > m) continue;

			ll cur = p[ext] + p[id];
			ans = min(ans, cur);
		}
		cout << ans << endl;
	}

	return 0;
}
