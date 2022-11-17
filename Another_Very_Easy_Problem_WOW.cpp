#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mod 1988
#define um unordered_map
#define us unordered_set
#define f first
#define s second
#define v vector
#define all(arr) arr.begin(), arr.end()
template <typename T> istream& operator>>(istream &istream, vector<T> &nums){ for(auto &val: nums) cin >> val; return istream;}
template <typename T1, typename T2> istream& operator>>(istream &istream, pair<T1, T2> &p){ return (istream >> p.f >> p.s);}
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...);}
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')';}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NONI_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// For explanation: https://github.com/anudeex/Non_Codeforces_Codes/blob/master/COUNT%20-%20Another%20Very%20Easy%20Problem!%20WOW!!!.cpp
int solve(int n, int k, v<v<int>> &dp){
    if (n < 0)  return 0;
    if (n == 0) return 1;
    if (k == 0) return 0;
    if (dp[n][k] != -1) return dp[n][k];
    return dp[n][k] = (solve(n, k-1, dp) + solve(n-k, k, dp)) % mod; 
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        int n, k;cin >> n >> k;
        if (n == 0) break;
        v<v<int>> dp(n+1, v<int> (k+1, -1));
        cout << (solve(n, k, dp) - solve(n, k-1, dp) + mod) % mod << '\n';
        
        
    }
}