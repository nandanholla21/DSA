
// program to find the subarray whose sum is equal to k
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int subarraySum(vector<int>& nums, int k) {
        int c=0;
        unordered_map<int,int> m;
        int i=0;
        int sum = 0;
        while(i<nums.size()){
            sum+=nums[i];
            if(sum == k){
                c++;
            }
            if(m.find(sum-k) !=m.end()){
                c +=m[sum-k];
            }
            m[sum] +=1;
            i++;
        }
        return c;
}
int main(){
    vector<int> nums;
    int n;
    cout<<"Enter the value of n ";
    cin>>n;
    int k;
    cout<<"\nEnter the target sum ";
    cin>>k;
    int item;
    for(int i=0;i<n;i++){
        cin>>item;
        nums.push_back(item);
    }
    int count = subarraySum(nums,k);
    cout<<"The number of subarrays are "<<count;
    return 0;
}