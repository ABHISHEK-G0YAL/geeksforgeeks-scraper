// https://practice.geeksforgeeks.org/problems/cutted-segments/0
// Correct

#include <bits/stdc++.h>
using namespace std;

int rodcut(int a[], int x, int n) {
    int dp[x + 1][n + 1];
    for(int i = 0; i <= x; i++)                 // if(n == 0)
        dp[i][0] = 0;                           //     return 0;
    for(int j = 0; j <= n; j++)                 // if(n < 0 or x == 0)
        dp[0][j] = INT_MIN;                     //     return INT_MIN;
    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= n; j++) {
            int a1;
            if(j - a[i - 1] < 0)
                a1 = INT_MIN;
            else
                a1 = 1 + dp[i][j - a[i - 1]];   // int a1 = 1 + rodcut(a, x, n - a[x-1]);
            int a2 = dp[i - 1][j];              // int a2 = rodcut(a, x - 1, n);
            dp[i][j] = max(a1, a2);             // return max(a1, a2)
        }
    }
    return dp[x][n];
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[3];
        for(int i = 0; i < 3; i++)
            cin >> a[i];
        int y = rodcut(a, 3, n);
        cout << y << endl;
    }
	return 0;
}