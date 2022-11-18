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

int solve(int i, int j, v<int> &nums, v<int> &tom, v<v<int>> &dp){
    int n = nums.size(), m = tom.size();
    if (i == n or j == m)   return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if (nums[i] == tom[j]){
        return dp[i][j] = 1 + solve(i + 1, j + 1, nums, tom, dp);
    }
    else return dp[i][j] = max(solve(i + 1, j, nums, tom, dp), solve(i, j + 1, nums, tom, dp));
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin >> t;
    while (t--){
        v<int> nums;
        int val;cin >> val;
        while(val != 0){
            nums.pb(val);
            cin >> val;
        }
        int ans = 0;
        while(1){
            v<int> tom;
            cin >> val;
            if (val == 0)   break;
            while(val != 0){
                tom.pb(val);
                cin >> val;
            }
            // dbg(tom);
            v<v<int>> dp(nums.size(), v<int> (tom.size(), -1));
            // Just here doing the lcs
            ans = max(ans, solve(0, 0, nums, tom, dp));
            
        }
        cout << ans << "\n";
    }
}
