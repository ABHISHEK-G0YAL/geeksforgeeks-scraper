// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays/0
// Correct

using namespace std;
int main() {
    int t, n, m, i, j, temp;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int a[n], b[m];
        for(i = 0; i < n; i++)
            cin >> a[i];
        for(i = 0; i < m; i++)
            cin >> b[i];
        i = 0, j = 0;
        while(i < n and j < m) {
            if(a[i] < b[j]) {
                cout << a[i] << " ";
                i += 1;
            }
            else {
                cout << b[j] << " ";
                j += 1;
            }
        }
        while(i < n) {
            cout << a[i] << " ";
            i += 1;
        }
        while(j < m) {
            cout << b[j] << " ";
            j += 1;
        }
        cout << endl;
    }
	return 0;
}
        //     for(int i = 0; i < n; i++)
        //         cout << a[i] << ' ';
        //     cout << endl;
        //     for(int i = 0; i < m; i++)
        //         cout << b[i] << ' ';
        //     cout << endl << endl;
        //         temp = a[i]
        //     if(a[i] > b[j]) {
        //         swap(a[i], b[j]);
        //         i += 1;
        //     }
        //     else
        //         j += 1;
        // for(i = 0; i < n; i++)
        //     cout << a[i] << ' ';
        // for(i = 0; i < m; i++)
        //     cout << b[i] << ' ';
        // cout << endl;