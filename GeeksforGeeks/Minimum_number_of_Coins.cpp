// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins/0
// Correct

using namespace std;

int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

int main() {
    int t, amount;
    cin >> t;
    while(t--) {
        cin >> amount;
        int i = 9;
        while(amount != 0) {
            if(coins[i] <= amount) {
                amount -= coins[i];
                cout << coins[i] << " ";
            }
            else
                i -= 1;
        }
        cout << endl;
    }
	return 0;
}