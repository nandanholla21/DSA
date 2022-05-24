#include<iostream>
using namespace std;

int total_set_bits(int x){
    if(x<=0){
        return 0;
    }
    return (x%2==0?0:1)+total_set_bits(x/2);
}
int countBits(int n){
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum+=total_set_bits(i);
    }
    return sum;
}
int main(){
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;
    cout<<"The number of set bits are "<<countBits(n);
    return 0;
}