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



int32_t main() {
	singh07();

	w(t) {
		in(n);
		in(k);
		mk(a, n, int);

		rep(i, n) cin >> a[i];

		vi mxvls, mnvls;
		umap(sum_cnt, int, int);
		rep(i, n / 2) {
			int mn = min(a[i], a[n - i - 1]);
			int mx = max(a[i], a[n - i - 1]);
			mxvls.pb(mx);
			mnvls.pb(mn);
			sum_cnt[mx + mn]++;
		}

		sort(mxvls.begin(), mxvls.end());
		sort(mnvls.begin(), mnvls.end());

		int ans = infi;

		fori(x, 2, 2 * k) {
			int mx_less_than_x_minus_k = lower_bound(mxvls.begin(), mxvls.end(), x - k) - mxvls.begin();
			int mn_less_than_x = lower_bound(mnvls.begin(), mnvls.end(), x) - mnvls.begin();
			int mn_greater_than_x_minus_1 = n / 2 - mn_less_than_x;

			int cost2 = mn_greater_than_x_minus_1 + mx_less_than_x_minus_k;
			int cost0 = sum_cnt[x];
			int cost1 = n / 2 - cost0 - cost2;

			ans = min(ans, 2 * cost2 + cost1);
		}
		cout << ans << endl;
	}

	return 0;
}