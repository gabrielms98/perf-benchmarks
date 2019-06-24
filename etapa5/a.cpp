#include <bits/stdc++.h>

using namespace std;

int contador = 100;

int calcArea(vector<string> &m, vector<vector<bool>> &visited, int i, int j, char c)
{
    // assert(contador-- > 0);

    if(i < 0 || j < 0 || i >= m.size() || j >= m[0].size())
    {
        return 0;
    }

    if(visited[i][j])
    {
        return 0;
    }
    // cout << i << " " << j << " " << m[i][j] << endl;

    if(m[i][j] != c)
    {
        return 0;
    }

    visited[i][j] = true;
    
    int sum = 1;
    sum += calcArea(m, visited, i    , j - 1, c);
    sum += calcArea(m, visited, i    , j + 1, c);
    sum += calcArea(m, visited, i - 1, j    , c);
    sum += calcArea(m, visited, i - 1, j - 1, c);
    sum += calcArea(m, visited, i - 1, j + 1, c);
    sum += calcArea(m, visited, i + 1, j    , c);
    sum += calcArea(m, visited, i + 1, j - 1, c);
    sum += calcArea(m, visited, i + 1, j + 1, c);
    
    // cout << sum << endl;
    return sum;
}

void solve(vector<string> &m, vector<pair<int, int>> &vp)
{
    pair<int, int> shape({m.size(), m[0].size()});

    for(auto &x : vp)
    {
        vector<vector<bool>> visited(shape.first, vector<bool>(shape.second, false));
        cout << calcArea(m, visited, x.first - 1, x.second - 1, m[x.first - 1][x.second - 1]) << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    bool first = true;
    while(t--)
    {
        if(!first)
        {
            cout << endl;
        }
        first = false;

        vector<string> m;
        
        string str;
        while(getline(cin, str))
        {
            if(str == "")
            {
                continue;
            }

            if(str[0] - '0' < 9 && str[0] - '0' >= 0)
            {
                break;
            }

            m.push_back(str);
        }

        vector<pair<int, int>> vp;

        stringstream ss;
        ss << str;
        int a, b;
        ss >> a >> b;
        vp.push_back({a, b});

        while(getline(cin, str))
        {
            if(str == "")
            {
                break;
            }

            ss.clear();
            ss << str;
            ss >> a >> b;
            vp.push_back({a, b});
        }

        // for(auto &x : m)
        // {
        //     cout << x << endl;
        // }

        // for(auto &x : vp)
        // {
        //     cout << x.first << " " << x.second << endl;
        // }

        solve(m, vp);
    }
}