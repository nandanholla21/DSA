#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> result;
void dfs(int node, vector<int> adj[], vector<int> &visi){
    visi[node] = 1;
    result.push_back(node);
    for(auto x:adj[node]){
        if(visi[x] == 0){
            visi[x] = 1;
            dfs(x,adj,visi);
        }
    }
}

int main(){
    int n,m; //n is number of vertices and m is number if edges
    cout<<"Enter the number of vertices and number of edges of the graph \n";
    cin>>n>>m;
    vector<int> adj[n];
    int u,v;
    cout<<"Enter the graph \n";
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    } 
    vector<int> visi(n+1,0);
    int source;
    cout<<"Enter the source vertex \n";
    cin>>source;
    dfs(source,adj,visi); 
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}