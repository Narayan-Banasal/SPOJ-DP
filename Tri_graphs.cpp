#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mod 1000000007
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

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(1){
        int n;cin >> n;
        if (n == 0) break;
        v<v<int>> nums(n, v<int> (3)), dp(n+1, v<int> (3, 1e15));
        cin >> nums;
        dp[1][1] = nums[0][1], dp[1][2] = dp[1][1] + nums[0][2];
        for (int i = 1;i < n;i++){
            for (int j = 0;j < 3;j++){
                if (j == 0){
                    dp[i+1][j] = min({dp[i][j] + nums[i][j], dp[i][j+1] + nums[i][j], dp[i+1][j]});
                }
                else if (j == 1){
                    dp[i+1][j] = min({dp[i][j-1] + nums[i][j], dp[i+1][j-1] + nums[i][j], dp[i][j+1] + nums[i][j], dp[i][j] + nums[i][j], dp[i+1][j]});
                }
                else {
                    dp[i+1][j] = min({dp[i+1][j-1] + nums[i][j], dp[i][j-1] + nums[i][j], dp[i][j] + nums[i][j], dp[i+1][j]});
                }
            }
        }
        // dbg(dp);
        cout << t << ". " << dp[n][1] << "\n";
        t += 1;
        
    }
}
