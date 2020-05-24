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
		vvi present(n - 1, vi(n + 1, 0));	// [Segments][1-n]
		vi sze(n - 1);

		rep(i, n - 1) {
			in(s);
			sze[i] = s;
			while (s--) {
				in(x);
				present[i][x] = 1;
			}
		}

		fori(p1, 1, n) {
			vvi dp = present;
			vi sz = sze;

			vi arr(n + 1);
			arr[1] = p1;
			bool valid = 1;

			fori(i, 2, n) {
				// Delete arr[i-1] from each segment
				rep(seg, n - 1) {
					if (dp[seg][arr[i - 1]])
						dp[seg][arr[i - 1]] = 0, sz[seg]--;
				}
				vi sz_one;
				rep(seg, n - 1) {
					if (sz[seg] == 1) {
						sz_one.pb(seg);
					}
				}
				if (sz_one.size() != 1) {
					valid = 0;
					break;
				}
				int id = sz_one[0];
				fori(x, 1, n) {
					if (dp[id][x]) {
						arr[i] = x;
						break;
					}
				}
				// i index has been set
			}
			if (!valid) continue;

			vi idval(n + 1);
			set<int> rvals;

			fori(i, 1, n) {
				idval[arr[i]] = i;
			}
			rep(i, n - 1) {
				vi idv;
				fori(x, 1, n) {
					if (present[i][x])
						idv.pb(idval[x]);
				}
				sort(idv.begin(), idv.end());
				for (int id = 1; id < idv.size(); ++id) {
					if (idv[id] != idv[id - 1] + 1) {
						valid = 0;
						break;
					}
				}
				rvals.insert(idv.back());
			}

			// all the segments were a subarray of current perm.
			if (!valid || rvals.size() != n - 1)
				continue;

			fori(i, 1, n) {
				cout << arr[i] << ' ';
			}
			cout << endl;
			break;
		}
	}

	return 0;
}
