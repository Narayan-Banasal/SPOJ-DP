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

int solve(int i, int j, v<int> &nums, v<int> &arr, v<v<int>> &dp){
    int n = nums.size(), m = arr.size();
    if (i == 0) if (j == n) return 0;
    if (i == 1) if (j == m) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = INT_MIN;
    if (i == 0){
        int id = (lb(all(arr), nums[j]) - arr.begin()) + 1;
        if (id < m+1 and (arr[id-1] == nums[j])) ans = nums[j] + solve(1, id, nums, arr, dp);
        ans = max(ans, nums[j] + solve(0, j+1, nums, arr, dp));
    }
    else {
        int id = (lb(all(nums), arr[j]) - nums.begin()) + 1;
        if (id < n+1 and (nums[id-1] == arr[j]))   ans = arr[j] + solve(0, id, nums, arr, dp);
        ans = max(ans, arr[j] + solve(1, j+1, nums, arr, dp));
    }

    return dp[i][j] = ans;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(1){
        int n;cin >> n;
        if (n == 0) break;
        v<int> nums(n);
        cin >> nums;
        int m;cin >> m;
        v<int> arr(m);cin >> arr;
        v<v<int>> dp(2, v<int> (max(n, m), -1));
        cout << max(solve(0, 0, nums, arr, dp), solve(1, 0, nums, arr, dp)) << '\n';
    }
}
