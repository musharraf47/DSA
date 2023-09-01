#include <bits/stdc++.h>
#include <vector>
using namespace std;
bool checkpalindrome(string s)
{
    int start = 0, end = s.length() - 1;
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }
    return true;
}
int main()
{
    string s;
    getline(cin, s);
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'z'||s[i] >= 'a' && s[i] <= 'z'||s[i] >= 0 && s[i] <= 9)
        temp.push_back(s[i]);
        else
            continue;
    }
    cout << temp << endl;
    for (int i = 0; i < temp.length(); i++)
    {
        if (temp[i] >= 'A' && temp[i] <= 'Z')
        {
            temp[i] += 32;
        }
    }
    cout << temp << endl;
    cout << "palindrome : " << checkpalindrome(temp);
}