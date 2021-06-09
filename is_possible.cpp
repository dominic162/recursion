/*
    Coding Ninjas
Send Feedback
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.
Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
*/

#include<iostream>
#include<string>
using namespace std;

class Solution{
    public:

        bool help(bool ** visited , char ** mat , int rows , int cols , int i, int j , string s  , int k){

            if( k == s.size() ){
                return true;
            }

            if(i >= rows || i < 0 || j < 0 || j >= cols || mat[i][j] != s[k] || visited[i][j]){
                return false;
            }
            visited[i][j] = true;
            if(help(visited , mat , rows , cols , i + 1 , j , s , k + 1)){
                return true;
            }
            if(help(visited , mat , rows , cols , i - 1 , j , s , k + 1)){
                return true;
            }
            if(help(visited , mat , rows , cols , i  , j + 1 , s , k + 1)){
                return true;
            }
            if(help(visited , mat , rows , cols , i , j - 1, s , k + 1)){
                return true;
            }
            if(help(visited , mat , rows , cols , i + 1 , j + 1, s , k + 1)){
                return true;
            }
            if(help(visited , mat , rows , cols , i - 1 , j + 1 , s , k + 1)){
                return true;
            }
            if(help(visited , mat , rows , cols , i + 1 , j - 1, s , k + 1)){
                return true;
            }
            if(help(visited , mat , rows , cols , i - 1 , j - 1 , s , k + 1)){
                return true;
            }
            visited[i][j] = false;
            return false;

        }

        bool is_possible(string s , char ** mat , int rows , int cols){
            bool ** visited = new bool * [rows];

            for(int r = 0 ; r < rows ; ++r){
                visited[r] = new bool [cols];
                for(int c = 0 ; c < cols ; ++c ){
                    visited[r][c] = false;
                }
            }

            bool ans = false;
            for(int i = 0 ; i < rows ; ++i){

                for(int j = 0 ; j < cols ; ++j){
                    ans = help(visited , mat , rows , cols , i , j , s , 0);
                    if(ans){
                        break;
                    }
                }
                if(ans){
                    break;
                }

            }

            delete []visited;

            return ans;
        }
};

int main(){

    cout<<"Enter string: ";
    string s;
    cin>>s;

    int rows,cols;
    cout<<"Enter no of rows and column: ";
    cin>>rows>>cols;

    char ** mat = new char * [rows];
    cout<<"Enter matrix: ";
    for(int r = 0 ; r < rows ; ++r){

        mat[r] = new char [cols];

        for(int c = 0 ; c < cols ; ++c){
            cin>>mat[r][c];
        }

    }

    Solution sl;

    if(sl.is_possible(s, mat ,rows , cols)){
        cout<<"Possible";
    }
    else{
        cout<<"Not possible";
    }

    return 0;
}