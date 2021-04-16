/*
    No of subsets having sum equal to given sum
*/


#include<bits/stdc++.h>
using namespace std;

int getans(int* arr,int n, int sum){
    
    if(n==0){
        return (sum==0)?1:0;
    }

    return getans(arr,n-1,sum) + getans(arr,n-1,sum-arr[n-1]);

}

int main(){
    
    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;
    int* arr=new int [n];
    cout<<"Enter elements: ";
    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }
    int sums;
    cout<<"Enter sum : ";
    cin>>sums;
    int ans;
    ans=getans(arr,n,sums);

    cout<<"No of subsets having sum "<<sums<<" are "<<ans;

    return 0;
}