#include<iostream>
#include<vector>
#include<utility>
using namespace std;
 
int main(){
    int n,m;
    cout<<"Enter the number of vertices\n";
    cin>>n;
    cout<<"Enter the number of edges\n";
    cin>>m;
    vector<pair<int,int>> graph[n];
    //input
    int a,b,wt;
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        graph[a].push_back({b,wt});
        graph[b].push_back({a,wt});
    }
    int parent[n];
    bool mst[n];
    int key[n];
    for(int i=0;i<n;i++){
        parent[i] = -1;
        key[i] = INT_MAX;
        mst[i] = false;
    }
    key[0] = 0;

    for(int i=0;i<n-1;i++){

        int min = INT_MAX,u;
        for(int j=0;j<n;j++){
            if(mst[j] == false && key[j]<min){
                min = key[j];
                u=j;
            }
        }
        mst[u] = true;
        for(auto x: graph[u]){
            int q = x.first;
            int w = x.second;
            if(mst[q] == false && w<key[q]){
                key[q] = w;
                parent[q] = u;
            }
        }
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=key[i];
    }
    //the vertices of minimum spanning tree
    for(int i=1;i<n;i++){
        cout<<parent[i]<<" ";
    }
    cout<<"\n";
    cout<<"The sum of the keys are "<<sum<<"\n";

    return 0;
}