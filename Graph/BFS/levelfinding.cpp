#include<bits/stdc++.h>
using namespace std; 
#define ll long long
vector<ll> g[100000];
int v[100000]={0};
void bfs(int s,int * level)
{
    v[s]=1;
    level[s]=0;
    queue<int> q;
    q.push(s);
    
    while(!q.empty())
    {
        int w=q.front();
        q.pop();
        for(int i=0;i<g[w].size();++i)
        {
            if(v[g[w][i]]==0)
            {  
               q.push(g[w][i]);
                v[g[w][i]]=1;
               level[g[w][i]]=level[w]+1;
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
    int level[n+1];
    bfs(1,level);  // ADD SOURCE NODE
    for(int i=1;i<n+1;++i) cout<<level[i]<<" "; 
    return 0;
}
