#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int count =0;
        if(k<0){
            return count;
        }
        if(k == 0){
            
            for(auto x:m){
                if(x.second>1){
                    count++;
                }
            }
        }
        else {
            for(auto x:m){
                if(m.count(x.first-k)){
                    count++;
                }
            }
        }
        return count;
}
int main(){
    vector<int> nums;
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    int item,k;
    cout<<"Enter the value of k\n";
    cin>>k;
    for(int i=0;i<n;i++){
        cin>>item;
        nums.push_back(item);
    }
    cout<<findPairs(nums,k);
    return 0;
}