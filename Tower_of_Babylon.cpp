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
        v<v<int>> nums;
        for (int i = 0;i < n;i++){
            int a, b, c; cin >> a >> b >> c;
            nums.pb({a, min(b, c), max(b, c)});
            nums.pb({b, min(a, c), max(a, c)});
            nums.pb({c, min(b, a), max(b, a)});
        }
        sort(all(nums), [&](v<int> &a, v<int> &b){
            return (a[1]*a[2] < b[1]*b[2]);
        });
        v<int> dp(3*n);
        for (int i = 0;i < 3*n;i++){
            int mx = nums[i][0];
            for (int j = i-1;j >= 0;j--){
                if (nums[i][1] > nums[j][1] and nums[i][2] > nums[j][2]){
                    mx = max(mx, dp[j] + nums[i][0]);
                }
            }
            dp[i] = mx;
        }
        cout << *max_element(all(dp)) << '\n';
    }
}
