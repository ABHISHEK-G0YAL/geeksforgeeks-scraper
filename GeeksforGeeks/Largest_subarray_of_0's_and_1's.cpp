// https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1
// Correct

#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n);

int main() {
    // your code goes here
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends
/*You are required to complete this method*/
int maxLen(int a[], int n) {
    int sum = 0, maxL = 0;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0)
            a[i] = -1;
        sum += a[i];
        if(sum == 0)
            maxL = max(maxL, i + 1);
        if(mp.find(sum) == mp.end())
            mp[sum] = i;
        else
            maxL = max(maxL, i - mp[sum]);
    }
    return maxL;
}