// https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately/0
// Correct

using namespace std;
int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int i = 0;
        n = n - 1;
        while(i < n)
            cout << a[n--] << ' ' << a[i++] << ' ';
        if(i == n)
            cout << a[i] << ' ';
        cout << endl;
    }
	return 0;
}