// https://practice.geeksforgeeks.org/problems/kth-smallest-element/0
// Correct

using namespace std;

int main() {
    int t, n, k, x;
	cin >> t;
	while(t--) {
	    int count = 0, a[100005] = {};
	    cin >> n;
	    for(int i = 0; i < n; i++) {
	        cin >> x;
	        a[x] += 1;
	    }
        cin >> k;
        for(int i = 0; i < 100005; i++) {
            count += a[i];
            if(count >= k) {
                cout << i << endl;
                break;
            }
        }
	}
	return 0;
}