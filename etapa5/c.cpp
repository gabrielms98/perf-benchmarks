#include <bits/stdc++.h>

using namespace std;

void print(vector<int> &v)
{
    for(auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int hashVector(vector<int> &v)
{
    int n = 0;
    n |= v[0] << 12;
    n |= v[1] << 8;
    n |= v[2] << 4;
    n |= v[3];

    return n;
}

vector<int> unhash(int n)
{
    vector<int> v(4);
    v[0] = (n & (0xf << 12)) >> 12;
    v[1] = (n & (0xf << 8)) >> 8;
    v[2] = (n & (0xf << 4)) >> 4;
    v[3] = n & 0xf;

    return v;
}


int bfs(vector<vector<int>> &graph, vector<bool> &visited, int inicial, int final)
{
    vector<int> dist(visited.size(), 1 << 30);
    queue<int> k;
    
    k.push(inicial);
    visited[inicial] = true;
    dist[inicial] = 0;

    if(inicial == final)
    {
        return 0;
    }

    while(!k.empty())
    {
        int no = k.front();
        k.pop();

        auto aux1 = unhash(no);
        // print(aux1);

        for(auto &x : graph[no])
        {
            if(!visited[x])
            {
                visited[x] = true;
                dist[x] = dist[no] + 1;
                k.push(x);

                if(x == final)
                {
                    return dist[x];
                }
            }
        }
    }

    return -1;
}

int main()
{
    // vector<int> a{4, 3, 2, 1};
    // print(a);
    // cout << hashVector(a) << endl;
    // a = unhash(17185);
    // print(a);

    int t;
    cin >> t;

    vector<vector<int>> graph(0xffff + 1);
    for(int i = 0; i < graph.size(); i++)
    {
        vector<int> v = unhash(i);

        int aux = v[0];
        v[0] = (aux - 1 + 10) % 10; 
        graph[i].push_back(hashVector(v));
        v[0] = (aux + 1) % 10; 
        graph[i].push_back(hashVector(v));
        v[0] = aux;

        aux = v[1];
        v[1] = (aux - 1 + 10) % 10; 
        graph[i].push_back(hashVector(v));
        v[1] = (aux + 1) % 10; 
        graph[i].push_back(hashVector(v));
        v[1] = aux;

        aux = v[2];
        v[2] = (aux - 1 + 10) % 10; 
        graph[i].push_back(hashVector(v));
        v[2] = (aux + 1) % 10; 
        graph[i].push_back(hashVector(v));
        v[2] = aux;

        aux = v[3];
        v[3] = (aux - 1 + 10) % 10; 
        graph[i].push_back(hashVector(v));
        v[3] = (aux + 1) % 10; 
        graph[i].push_back(hashVector(v));
        v[3] = aux;
    }
    
    while(t--)
    {
        vector<bool> blocked(0xffff + 1, false);

        vector<int> init(4);
        cin >> init[0] >> init[1] >> init[2] >> init[3]; 

        vector<int> end(4);
        cin >> end[0] >> end[1] >> end[2] >> end[3]; 

        int n;
        cin >> n;
        vector<vector<int> > forb(n, vector<int>(4));

        for(auto &f : forb)
        {
            cin >> f[0] >> f[1] >> f[2] >> f[3]; 
        }

        for(auto &f : forb)
        {
            blocked[hashVector(f)] = true;
        }

        cout << bfs(graph, blocked, hashVector(init), hashVector(end)) << endl;

    }
}