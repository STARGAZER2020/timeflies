
/* print all value level wise */
#include<bits/stdc++.h>
using namespace std; 
#define ll long long
vector<ll> g[100000];
int v[100000]={0};
void bfs(int s)
{
    v[s]=1;
    queue<int> q;
    q.push(s);
    cout<<s<<" "; // print source node
    while(!q.empty())
    {
        int w=q.front();
        q.pop();
        for(int i=0;i<g[w].size();++i)
        {
            if(v[g[w][i]]==0)
            {   q.push(g[w][i]);
                v[g[w][i]]=1;
                cout<<g[w][i]<<" "; // print all node except source node
             }
        }
    }
}
int main()
{
    int n,m,x,y;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        cin>>x>>y;
        g[y].push_back(x);
        g[x].push_back(y);
    }
    bfs(1);  // ADD SOURCE NODE
    return 0;
}
