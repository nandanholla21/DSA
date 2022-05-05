#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;   //to store remainder and index
        m[0] = -1;
        int sum = 0,r;
        for(int i=0;i<nums.size();i++){
            sum +=nums[i];
            r = sum%k;
            if(m.find(r) ==m.end()){
                m[r] = i;
            }
            else if(i - m[r] >1){
                return true;
            }
            
        }
        
        return false;
}

int main(){
    vector<int> nums;
    int n,k;
    cout<<"Enter the number of elements ";
    cin>>n;
    cout<<"Enter the value of k ";
    cin>>k;
    int item;
    for(int i=0;i<n;i++){
        cin>>item;
        nums.push_back(item);
    }
    if(checkSubarraySum(nums,k)==true){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}