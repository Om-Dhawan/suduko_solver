#include<iostream>
#include<cmath>
using namespace std;

bool can_place(int mat[][9],int i, int j,int n,int num){
    for(int x=0;x<n;x++){
        // Row and COl check
        if(mat[x][j]==num || mat[i][x]==num){
            return false;
        }
    }
    //Checking in a block
    int rn=sqrt(n);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;
    for(int x=sx;x<(sx+rn);x++){
        for(int y=sy;y<(sy+rn);y++){
            if(mat[x][y]==num){
                return false;
            }
        }
    }
    return true;
}

bool solve(int mat[][9],int i,int j,int n){
    //Base case
    if(i==n){
        //Print matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    // Case row ends
    if(j==n){
        return solve(mat,i+1,0,n);
    }
    // Skip the prefilled elements
    if(mat[i][j]!=0){
        return solve(mat,i,j+1,n);
    }
    // Recursive case -Find the current cell with possible numbers
    for (int num=1;num<=n;num++){
        if(can_place(mat,i,j,n,num)){
            //Assume
            mat[i][j]=num;
            bool canwesolve=solve(mat,i,j+1,n);
            if(canwesolve==true){
                return true;
            }
        }
    }
    // Backtracking - if false then erase the previous element
    mat[i][j]=0;
    return false;
}

int main(){
    int n=9;
    int mat[9][9];
    cout<<"Enter the unsolved sudoku(where unknown elements are inputed as 0)"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    cout<<"Unsolved sudoku is: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"Solved sudoku is: "<<endl;
    solve(mat,0,0,9);
}
