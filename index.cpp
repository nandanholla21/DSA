#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the elements of the array";
    cin>>n;
    vector<int>arr;
    int item;
    for(int i=0;i<n;i++){
        cin>>item;
        arr.push_back(item);
    }
    //maximum sum
    int best=INT_MIN,sum=0;
    for(int i=0;i<n;i++){
        sum = max(arr[i],sum+arr[i]);
        best = max(best,sum);
    }
    cout<<"The maximum sub array sum is "<<best;
}