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
#define mod                 998244353
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
#define int                 ll

void singh07() {
	iamtheflash
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int pwmd(int a, int n) {
	if (!n) {
		return 1;
	}
	int pt = pwmd(a, n / 2);
	pt *= pt;
	pt %= mod;
	if (n & 1) {
		pt *= a;
		pt %= mod;
	}
	return pt;
}

int32_t main() {
	singh07();

	in(n);
	fori(i, 1, n) {
		int ans;
		if (i == n) {
			ans = 10;
		} else if (i == n - 1) {
			ans = 2 * 10 * 9;
		} else {
			// the block is either prefix or suffix
			// rem = n-(i+1)
			int rem = n - i - 1;
			ans = 2 * 10 * 9 * pwmd(10, rem);

			// rest of the cases (block is in middle)
			// total positions = n-i+1
			rem = n - i - 2;
			int rest = (n - i + 1 - 2) * 10 * 9 * 9 * pwmd(10, rem);
			ans += rest;
			ans %= mod;
		}
		cout << ans << ' ';
	}

	return 0;
}
