#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str, word;
    getline(cin, str);
    stringstream s(str);
    while (s >> word)
    {
        reverse(word.begin(),word.end());
        cout<<word<<" ";
    }
    
}