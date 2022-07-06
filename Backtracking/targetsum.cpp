//program to find target sum using backtracking

#include<iostream>
#include<vector>
using namespace std;
int c=0;
void targetSum(vector<int> arr, int index,int sum,int target){
    if(sum == target && index == arr.size()){
        c++;
        return;
    }
    if( index == arr.size()){
        return;
    }
    
    for(int i=0;i<2;i++){
        //for plus
        if(i == 0){
            sum+=arr[index];
            targetSum(arr,index+1,sum,target);
            sum-=arr[index];
        }
        //for minus
        else{
            sum-=arr[index];
            targetSum(arr,index+1,sum,target);
            sum+=arr[index];
        }
    }
}
int main(){
    int n;
    cout<<"Enter the elements of the array\n";
    cin>>n;
    int item;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>item;
        arr.push_back(item);
    }
    int target;
    cout<<"Enter the target sum\n";
    cin>>target;
    targetSum(arr,0,0,target);
    cout<<"The number of different ways are "<<c;
    return 0;
}