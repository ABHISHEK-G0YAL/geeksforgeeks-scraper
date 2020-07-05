// https://practice.geeksforgeeks.org/problems/remove-duplicates/0
// Correct

#include<bits/stdc++.h>
using namespace std;
void removeduplicates(string &s)
{
    string result="";
    set<char>s2;
    for(int i=0;i<s.length();i++)
    {
        if(s2.find(s[i])==s2.end())
        {
            s2.insert(s[i]);
            result+=s[i];
        }
    }
  cout<<result<<endl;
    
}
int main() {
int t;
string temp;
cin>>t;
getline(cin,temp);
while(t--)
{
    string s;
    getline(cin,s);
  removeduplicates(s);
}

	return 0;
}