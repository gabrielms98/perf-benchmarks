#include <bits/stdc++.h>

using namespace std;

void dfs(vector<set<int>> &graph, vector<bool> &visited, int no)
{
    if(visited[no])
    {
        return;
    }
    visited[no] = true;

    for(auto &x : graph[no])
    {
        dfs(graph, visited, x);
    }
}

int solve(vector<set<int>> &graph)
{
    vector<bool> visited(graph.size(), false);

    int count = 0;
    for(int i = 0; i < visited.size(); i++)
    {
        if(!visited[i])
        {
            count++;
            dfs(graph, visited, i);
        }
    }

    return count;
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

        string str;
        stringstream ss;
        char a, b;
        
        char no;
        cin >> no;
        cin.ignore();

        vector<pair<char, char> > edges;

        while(getline(cin, str))
        {
            if(str == "")
            {
                break;
            }

            ss.clear();
            ss << str;

            ss >> a >> b;
            edges.push_back({a, b});
        }

        // cout << no << endl;
        // for(auto &x : edge)
        // {
        //     cout << x.first << " " << x.second << endl;
        // }solve(graph)

        vector<set<int>> graph(no - 'A' + 1);

        for(auto &x : edges)
        {
            graph[x.first - 'A'].insert(x.second - 'A');
            graph[x.second - 'A'].insert(x.first - 'A');
        }

        // for(auto &con : graph)
        // {
        //     for(auto &x : con)
        //     {
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }

        cout << solve(graph) << endl;
    }
}