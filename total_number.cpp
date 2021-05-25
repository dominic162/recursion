/*
    given a number , find no of digits greater than that number with same number of digits;
*/

#include<iostream>
using namespace std;

int get_ans(int * input , int n , int * fact , int freq[]){
    
    if(n == 0 || n == 1){
        return 0;
    }

    int ans = 0 ;
    
    for(int i = input[0] + 1 ; i < 10 ; ++i){

        ans += freq[i];

    }

    ans *= fact[n-1];

    for(int i = 0 ; i < 10 ; ++i){
        ans /= fact[freq[i]];
    }

    
    --freq[input[0]];

    ans += get_ans(input +1 , n -1 , fact , freq);

    return ans;

}

int main(){

    int n;
    cin>>n;

    int * number  = new int[n];
    int freq [10] = {};
    int * fact = new int [n+1];
    fact[0] = 1;
    
    for(int i = 0 ; i < n ; ++i){
        cin>>number[i];
        freq[number[i]]++;
        fact[i+1] = (i+1)*fact[i];
    }

    int ans = get_ans(number , n , fact , freq);

    cout<<"total number greater than current number : "<<ans;

    delete []number;
    delete []fact;

    return 0;

}