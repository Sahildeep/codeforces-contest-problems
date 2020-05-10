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

// largest prefix that matches a suffix
int kmp(string s) {
	vector<int> lps(s.size(), 0);
	for (int i = 1; i < (int)lps.size(); ++i) {
		int prev_idx = lps[i - 1];
		while (prev_idx > 0 && s[i] != s[prev_idx]) {
			prev_idx = lps[prev_idx - 1];
		}
		lps[i] = prev_idx + (s[i] == s[prev_idx] ? 1 : 0);
	}
	return lps[lps.size() - 1];
}

int largest_prefix_pal(string s) {
	string t = s + "?";
	reverse(s.begin(), s.end());
	t += s;
	return kmp(t);
}

int32_t main() {
	singh07();

	w(t) {
		ins(s);
		int n = s.length();
		int l = 0;
		for (int i = 0, j = n - 1; i < j; i++, j--) {
			if (s[i] == s[j]) l++;
			else break;
		}
		// remaining is s[l...n-l-1]
		string rem = s.substr(l, n - 2 * l);
		string ans = s.substr(0, l);
		if (rem.size()) {
			int l_pre = largest_prefix_pal(rem);
			reverse(rem.begin(), rem.end());
			int l_suf = largest_prefix_pal(rem);
			if (l_pre > l_suf) {
				reverse(rem.begin(), rem.end());
				ans += rem.substr(0, l_pre);
			} else {
				ans += rem.substr(0, l_suf);
			}
		}
		ans += s.substr(n - l, l);
		cout << ans << endl;
	}

	return 0;
}
