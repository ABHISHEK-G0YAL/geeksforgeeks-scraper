// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0
// Correct

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    while(t--) {
        getline(cin, s);
        int len = 0, start, end, n_len, n = s.length();
        for(int i = 0; i < n; i++) {
            int x = 0;
            while(true) {
                if(i - x == -1)
                    break;
                if(i + x == n)
                    break;
                if(s[i - x] != s[i + x])
                    break;
                ++x;
            }
            x -= 1;
            n_len = 1 + 2 * x;
            if(n_len > len) {
                len = n_len;
                start = i - x;
                end = i + x;
            }
        }
        for(int i = 1; i < n; i++) {
            int il = i - 1, ir = i;
            int x = 0;
            while(true) {
                if(il - x == -1)
                    break;
                if(ir + x == n)
                    break;
                if(s[il - x] != s[ir + x])
                    break;
                ++x;
            }
            x -= 1;
            n_len = 2 + 2 * x;
            if(n_len > len) {
                len = n_len;
                start = il - x;
                end = ir + x;
            }
        }
        for(int i = start; i <= end; i++)
            cout << s[i];
        cout << endl;
    }
	return 0;
}