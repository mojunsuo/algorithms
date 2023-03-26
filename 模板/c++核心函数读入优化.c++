auto _{ []() noexcept
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}() };


#include<bits/stdc++.h>
using namespace std;


#pragma GCC optimize(2)
//o2”≈ªØ

//
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;

#define yn(ans) printf("%s\n", (ans)?"Yes":"No");
template<class T> bool chmax(T &a, T b) {
	if (a >= b) return false;
	a = b; return true;
}
template<class T> bool chmin(T &a, T b) {
	if (a <= b) return false;
	a = b; return true;
}
#define x first
#define y second
#define FOR(i, s, e, t) for ((i) = (s); (i) < (e); (i) += (t)) 
#define REP(i, e) for (int i = 0; i < (e); ++i) 
#define REP1(i, s, e) for (int i = (s); i < (e); ++i)
#define RREP(i, e) for (int i = (e); i >= 0; --i)
#define RREP1(i, e, s) for (int i = (e); i >= (s); --i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define qb pop_back
#define pf push_front
#define qf pop_front
#define maxe max_element
#define mine min_element
ll inf = 1e18;
#define DEBUG printf("%d\n", __LINE__); fflush(stdout);
template<class T> void print(vector<T> &v, bool withSize) {
	if (withSize) cout << v.size() << endl;
	REP(i, v.size()) cout << v[i] << " \n"[i == v.size() - 1];
}

//



void solve(){

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}