// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
// Correct

#include<vector>
using namespace std;
int main()
{
	//code
	int t, n, s;
	cin >> t;
	while(t--) {
	    cin >> n >> s;
	    vector<int> arr(n);
	    for(int &i : arr)
	        cin >> i;
        int curr_sum = 0;
        int start = 0;
        for(int i = 0; i < n; i++)
        {
            curr_sum = curr_sum + arr[i];
            while(curr_sum > s) {
                curr_sum = curr_sum - arr[start];
                start++;
            }
            if(curr_sum == s) {
                cout << start + 1 << " " << i + 1 << endl;
                break;
            }
        }
        if(curr_sum != s)
            cout << -1 << endl;
	}
	return 0;
}