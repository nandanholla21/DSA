#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
void dijkstra(int node, vector<pair<int,int>> adj[], vector<int> &dist){
    while(!pq.empty()){
        int a = pq.top().first;
        int b = pq.top().second;
        pq.pop();
        for(auto x: adj[b]){
            if(dist[b]+x.second < dist[x.first] ){
                dist[x.first] = dist[b] +x.second;
                pq.push({dist[x.first],x.first});
            }
        }
    }
}

int main(){
    int n,m;
    cout<<"Enter the number of vertices and edges in the graph\n";
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    int u,v,wt;
    for(int i=0;i<m;i++){
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    vector<int> dist(n+1,INT_MAX);
    int source;
    dist[source] = 0;
    pq.push({0,source});
    dijkstra(source,adj,dist);
    cout<<"\n The distance is \n";
    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
}