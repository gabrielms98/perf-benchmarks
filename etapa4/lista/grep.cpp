#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    vector<string> a, b;

    while(cin >> str)
    {
        if(str[0] == '*')
        {
            break;
        }

        a.push_back(str);
    }

    while(cin >> str)
    {
        b.push_back(str);
    }

    for(int i = 0; i < a.size(); i++)
    {
        cout << a[i] << ", " << b[i] << endl;
    }
}