// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0
// Correct

#include <bits/stdc++.h>
using namespace std;

vector<int> lefti(vector<long> &a) {
    int n = a.size();
    vector<int> v(n, -1);
    stack<int> s;
    s.push(0);
    for(int i = 1; i < n; i++) {
        if(a[s.top()] < a[i])
            v[i] = s.top();
        else {
            while(!s.empty() and a[s.top()] >= a[i])
                s.pop();
            if(!s.empty())
                v[i] = s.top();
        }
        s.push(i);
    }
    return v;
}

vector<int> righti(vector<long> &a) {
    int n = a.size();
    vector<int> v(n, n);
    stack<int> s;
    s.push(n - 1);
    for(int i = n - 2; i >= 0; i--) {
        if(a[s.top()] < a[i])
            v[i] = s.top();
        else {
            while(!s.empty() and a[s.top()] >= a[i])
                s.pop();
            if(!s.empty())
                v[i] = s.top();
        }
        s.push(i);
    }
    return v;
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<long> a(n);
        for(long &i : a)
            cin >> i;
        vector<int> i_left = lefti(a);
        vector<int> i_right = righti(a);
        long mx = 0;
        for(int i = 0; i < n; i++)
            mx = max(mx, a[i] * (i_right[i] - i_left[i] - 1));
        cout << mx << endl;
    }
	return 0;
}