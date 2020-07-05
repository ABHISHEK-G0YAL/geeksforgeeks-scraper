// https://practice.geeksforgeeks.org/problems/palindromic-patitioning/0
// Correct

using namespace std;
int dp[1001][1001];
int pdp[1001][1001];

int ispalindrome(string &s, int i, int j) {
    if(pdp[i][j] != -1)
        return pdp[i][j];
    while(i < j) {
        if(s[i] != s[j])
            return pdp[i][j] = 0;
        ++i;
        --j;
    }
    return pdp[i][j] = 1;
}
int solve(string &s, int i, int j) {
    if(dp[i][j] != -1)
        return dp[i][j];
    if(ispalindrome(s, i, j))
        return 0;
    int ans = (j - i) + 1;
    for(int k = i; k <= j - 1; k++)
        if(ispalindrome(s, i, k))
            ans = min(ans, 1 + solve(s, k + 1, j));
    return dp[i][j] = ans;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        memset(dp, -1, sizeof(dp));
        memset(pdp, -1, sizeof(pdp));
        int x = solve(s, 0, s.size() - 1);
        cout << x << endl;
    }
	return 0;
}