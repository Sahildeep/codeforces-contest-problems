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

#define iamtheflash 		ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 				1000000007
#define debug1(x) 			cout<<"#x: "<<x<<"\n"
#define debug2(x,y)			cout<<"#x: "<<x<<" #y: "<<y<<"\n"
#define debug3(x,y,z) 		cout<<"#x: "<<x<<" #y: "<<y<<" #z: "<<z<<"\n"
#define debug4(x,y,z,w) 	cout<<"#x: "<<x<<" #y: "<<y<<" #z: "<<z<<" #w: "<<w<<"\n"
#define rep(i,n) 			for(int i=0;i<(n);i++)
#define repl(i,n) 			for(ll i=0;i<(n);i++)
#define fori(i,a,b) 		for(int i=(a);i<=(b);i++)
#define forl(i,a,b) 		for(ll i=(a);i<=(b);i++)
#define ford(i,a,b) 		for(int i=(a);i>=(b);i--)
#define fordl(i,a,b) 		for(ll i=(a);i>=(b);i--)
#define pb 					push_back
#define mp 					make_pair
#define ff 					first
#define ss 					second
#define mid(s,e) 			(s+(e-s)/2)
#define setbits(x) 			__builtin_popcountll(x)
#define zrobits(x) 			__builtin_ctzll(x)
#define ps(x,y) 			fixed<<setprecision(y)<<x
#define w(x) 				int x; cin>>x; while(x--)
#define endl 				'\n'
#define infi				INT_MAX
#define infll				LLONG_MAX
#define infim				INT_MIN
#define infllm				LLONG_MIN
#define mk(arr,n,type)		type *arr = new type[n];
#define umap(x,type1,type2)	unordered_map<type1, type2 > x;

void singh07() {
	iamtheflash
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

// https://codeforces.com/contest/1324


int32_t main() {
	singh07();

	mk(a, 105, int);

	w(t) {
		int n;
		cin >> n;

		rep(i, n) {
			cin >> a[i];
		}
		int cnt[2] = {0};
		rep(i, n) {
			cnt[a[i] % 2]++;
		}
		if (cnt[0] && cnt[1]) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}

	return 0;
}
