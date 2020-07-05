// https://practice.geeksforgeeks.org/problems/edit-distance/0
// Correct


using namespace std;

vector<vector<int> > mem;

int minDistance(string w1, string w2) {
    int l1=w1.length(),l2=w2.length();
    if(mem[l1][l2]!=-1)
        return mem[l1][l2];
    if(l1==0 || l2==0)
        mem[l1][l2]=l1?l1:l2;
    else if(w1[0]==w2[0])
        mem[l1][l2]=minDistance(w1.substr(1),w2.substr(1));
    else
        mem[l1][l2]=1+min( { minDistance(w1.substr(1),w2.substr(1)),
                      minDistance(w1.substr(1),w2),
                     minDistance(w1,w2.substr(1)) } );
    return mem[l1][l2];
}
int main() {
    string w1,w2;
    int t, n1, n2;
    cin >> t;
    while(t--) {
        cin >> n1 >> n2;
        cin >> w1 >> w2;
        mem=vector<vector<int> > (1000,vector<int> (1000,-1));
        cout << minDistance(w1,w2) << endl;
    }
}
