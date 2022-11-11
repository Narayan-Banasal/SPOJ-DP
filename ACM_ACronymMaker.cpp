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

v<string> split(string &str, set<string> &st){
    v<string> words;
    int n = str.size();
    string temp;
    for (int i = 0;i < n;i++){
        if (str[i] == ' '){
            while(i < n-1 and str[i] == ' ')  i += 1;
            if (st.find(temp) != st.end()){
                i--;
                temp = "";
                continue;
            }
            transform(all(temp), temp.begin(), ::tolower);
            words.pb(temp);
            temp = "";
        }
        temp.push_back(str[i]);
    }
    if (st.find(temp) != st.end()){
        return words;
    }
    transform(all(temp), temp.begin(), ::tolower);
    words.pb(temp);
    return words;
}
int dp[150][150];

int solve(v<string> &words, v<int> &pre, int i, int j, int word){
    int n = words[0].size(), m = words.size();
    if (i == n){
        // cout << word << ' ';
        if (word == m) return 1;
        return 0;
    }
    if (word == m) return 0;
    int pos = pre[word-1] + j;
    if (dp[i][pos] != -1) return dp[i][pos];

    int sz = words[word].size();
    int ans = 0;
    for (int k = j;k < sz;k++){
        if (words[0][i] == words[word][k]){
            ans += solve(words, pre, i+1, 0, word+1);
            if (k < sz-1)  ans += solve(words, pre, i+1, k+1, word);
        }
    }
    
    return dp[i][pos] = ans;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        int n;cin >> n;
        if (n == 0) break;
        set<string> st;
        for (int i = 0;i < n;i++){
            string temp;cin >> temp;
            st.insert(temp);
        }
        while(1){
            string str;getline(cin, str);
            if (str.size() == 0)    continue;
            if (str == "LAST CASE")    break;
            v<string> words = split(str, st);
            memset(dp, -1, sizeof(dp));
            v<int> pre;
            for (int i = 0;i < words.size();i++){
                if (pre.size()){
                    int val = pre[pre.size() - 1] + words[i].size();
                    pre.pb(val);
                }
                else {
                    pre.pb(words[0].size());
                }
            }
            int ans = solve(words, pre, 0, 0, 1);
            // dbg(words);
            transform(all(words[0]), words[0].begin(), ::toupper);
            if (ans == 0){
                cout << words[0] << " is not a valid abbreviation\n";
            }
            else {
                cout << words[0] << " can be formed in " << ans << " ways\n";
            }
        }
    }
}
