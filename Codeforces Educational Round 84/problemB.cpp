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
		vector<bool> done(n + 1, 0);
		int free_girl = 0;
		for (int i = 1; i <= n; i++) {
			in(k);
			bool girl_done = 0;
			while (k--) {
				in(pi);
				if (girl_done)
					continue;
				// the girl isn't married yet
				if (done[pi])	// price is already married
					continue;
				// price also isn't married yet
				done[pi] = 1;
				girl_done = 1;
			}
			if (!girl_done) {
				free_girl = i;
			}
		}
		if (free_girl == 0) {
			cout << "OPTIMAL" << endl;
		} else {
			cout << "IMPROVE" << endl;
			cout << free_girl << ' ';
			for (int i = 1; i <= n; i++) {
				if (!done[i]) {
					cout << i << endl;
					break;
				}
			}
		}
	}

	return 0;
}
