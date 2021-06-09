#include<iostream>
using namespace std;

int no_of_steps(int n){

    if(n < 0){
        return 0;
    }

    if( n == 0){
        return 1;
    }

    int ans = no_of_steps(n-1) + no_of_steps(n-2) + no_of_steps(n-3);

    return ans;

}

int main(){
    int n;
    cin>>n;

    cout<<(no_of_steps(n));

    return 0;
}