#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>>adj;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//min-heap priority queue

int main()
{
    int v,e;
    cin>>v>>e;
    adj.resize(v);
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int source;
    cin>>source;
    pq.push({source,0});//priority queue =>{node,distance}
    vector<int>dist(v,INT_MAX);//distance array to store distance
    dist[source]=0;
    while(!pq.empty())
    {
        auto p=pq.top();
        pq.pop();
        for(auto it:adj[p.first])
        {
            if(p.second+it.second<dist[it.first])
            {
                dist[it.first]=p.second+it.second;
                pq.push({it.first,dist[it.first]});
            }
        }
    }
    for(int i:dist)cout<<i<<" ";

    return 0;
}
