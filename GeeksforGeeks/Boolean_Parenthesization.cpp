// https://practice.geeksforgeeks.org/problems/boolean-parenthesization/0
// Correct

using namespace std;

int mem[2][205][205];
int solve(string &s, int i, int j, bool istrue) {
    if(mem[istrue][i][j] != -1)
        return mem[istrue][i][j];
    if(i == j)
        return mem[istrue][i][j] = istrue ? s[i] == 'T' : s[i] == 'F';
    int ways = 0;
    for(int k = i + 1; k <= j; k += 2) {
        int lt = solve(s, i, k - 1, true);
        int lf = solve(s, i, k - 1, false);
        int rt = solve(s, k + 1, j, true);
        int rf = solve(s, k + 1, j, false);
        if(s[k] == '&') {
            if(istrue)
                ways += (lt * rt) % 1003;
            else
                ways += (lf * rf + lt * rf + lf * rt) % 1003;
        }
        else if(s[k] == '|') {
            if(istrue)
                ways += (lt * rt + lt * rf + lf * rt) % 1003;
            else
                ways += (lf * rf) % 1003;
        }
        else {
            if(istrue)
                ways += (lf * rt + lt * rf) % 1003;
            else
                ways += (lf * rf + lt * rt) % 1003;
        }
    }
    return mem[istrue][i][j] = ways % 1003;
}

int main() {
    int t, n;
    string s;
    cin >> t;
    while(t--) {
        memset(mem, -1, sizeof(mem));
        cin >> n >> s;
        cout << solve(s, 0, n - 1, true) << endl;
    }
	return 0;
}