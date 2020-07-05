// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0
// Correct

#include <bits/stdc++.h>
using namespace std;
string reverseword(string &a)
{
    string s1="";
    stack<char>s;
    for(int i=a.length()-1;i>=0;i--)
    {
        if(a[i]!='.')
        {
            s.push(a[i]);
        }
        else
        {
          while(s.empty()==false)
        {
            char x=s.top();
            s.pop();
            s1.push_back(x);
        }
        }
        if(s.empty()==true)
        {
            s1.push_back('.');
        }
       
    }
    while(s.empty()==false)
    {
        char x=s.top();
        s.pop();
        s1.push_back(x);
    }
    return s1;
}
int main() {
int t;
cin>>t;
string a;
getline(cin,a);
while(t--)
{
    getline(cin,a);
   string s2=reverseword(a);
    cout<<s2<<endl;
}
	return 0;
}