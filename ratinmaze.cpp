#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>> array,int row,int col,char c,int i,int j){
    if(c=='D' && i==row-1 && j<col){
        return false;
    }
    else if(c=='L' && i<row && j==0){
        return false;
    }
    else if(c=='R' && i<row && j==col-1){
        return false;
    }
    else if(c=='U' && i==0 && j<col){
        return false;
    }
    return true;
}

void ratInMaze(vector<vector<int>> array, int row,int col,vector<vector<int>> visited,string res,int i,int j,string s){

    if(i==row-1 && j==col-1){
        cout<<res<<" ";
        return;
    }

    for(int k=0;k<s.length();k++){
        if( isSafe(array,row,col,s[k],i,j)){
            
            if(s[k]=='D' && visited[i+1][j]!=1 && array[i][j]!=0 ){
                visited[i][j]=1;
                ratInMaze(array,row,col,visited,res+s[k],i+1,j,s);
                visited[i][j]=0;
            }
            else if(s[k]=='L' && visited[i][j-1]!=1 && array[i][j]!=0){
                visited[i][j]=1;
                ratInMaze(array,row,col,visited,res+s[k],i,j-1,s);
                visited[i][j]=0;
            }
            else if(s[k]=='R' && visited[i][j+1]!=1 && array[i][j]!=0){
                visited[i][j]=1;
                ratInMaze(array,row,col,visited,res+s[k],i,j+1,s);
                visited[i][j]=0;
            }
            else if(s[k]=='U' && visited[i-1][j]!=1 && array[i][j]!=0){
                visited[i][j]=1;
                ratInMaze(array,row,col,visited,res+s[k],i-1,j,s);
                visited[i][j]=0;
            }
        }
    }


}

int main(){
    vector<vector<int>> array;
    int row,col;
    cout<<"Enter the row of the grid\n";
    cin>>row;
    cout<<"Enter the col of the grid\n";
    cin>>col;
    string s = "DLRU";
    //input
    int val;
    vector<vector<int>> visited;
    vector<int> dupe;
    vector<int> samp;
    for(int i=0;i<row;i++){
        samp.clear();
        dupe.clear();
        for(int j=0;j<col;j++){
            cin>>val;
            samp.push_back(val);
            dupe.push_back(0);
        }
        visited.push_back(dupe);
        array.push_back(samp);
    }
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //         cout<<array[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    ratInMaze(array,row,col,visited,"",0,0,s);
    
    return 0;
}
