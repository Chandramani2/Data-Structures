#include<bits/stdc++.h>
using namespace std;
/*  Given N Queens and Board of M*N, place all the 
    N Queens, such that no Q will kill each other
*/
void print2DVector(vector<vector<int>> mat){
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[i].size(); j++){
            cout<<mat[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void NQueens(int i,int Q,vector<vector<int>> board,int M,int N, 
    int rows[],int cols[],int rightdiag[],int leftdiag[]){
    if(i == Q){
        // we have placed all the Q Queen
        print2DVector(board);
        return;
    }
    /*  - place Q on ith row
        - Iterate on all columns and place Q on i'th row 
        and check if possible or not
        - board[i][j] -> we cannot place next Q at i'th row and j'th column
        so we mark them false and for diagonals
        Observation:
            - Right diagonals = (i+j) mark false
            - Left Diagonals = (j-i) + (M-1) mark false
            - (j-i) will come -ve, we have to map to make it +ve.. so + (M-1)
    */
    for(int j=0; j<N; j++){
        // we're placing Q at mat[i][j]
        if(rows[i]&&cols[j]&&rightdiag[i + j]&&leftdiag[j-i+M-1]){
            rows[i]=cols[j]=rightdiag[i + j]=leftdiag[j-i+M-1] = 0;
            board[i][j] = 1;
            NQueens(i+1,Q,board,M,N,rows,cols,rightdiag,leftdiag);
            board[i][j] = 0;
            rows[i]=cols[j]=rightdiag[i + j]=leftdiag[j-i+M-1] = 1;
        }
    }
}

int main(){
    int Q=5;
    int M=5, N=5, i=0; // i represent row number
    vector<vector<int>> board(M, vector<int>(N,0));
    int rows[M]; fill(rows, rows+M, 1);
    int cols[N]; fill(cols, cols+N, 1);
    int rightdiag[M+N-1]; fill(rightdiag, rightdiag+M+N-1, 1);
    int leftdiag[M+N-1]; fill(leftdiag, leftdiag+M+N-1, 1);

    NQueens(i,Q,board, M, N, rows, cols, rightdiag, leftdiag);
    return 0;
}