#include <iostream>
using namespace std;
#define N 4 //matrix order

bool isSafe(int board[N][N],int row,int col ,int n ) {
	int x = 0 , y =0;

	//check for col attack
    for(x = 0 ; x < row ; x++)
        if(board[x][col])
            return false;

    //check for lower diagonal attack
    for(x = row,y = col ; x>=0 && y>=0 ; x--,y--)
        if(board[x][y])
            return false;

    //check for upper diagonal attack
    for(x = row,y = col ; x>=0 && y<n ; x--,y++)
        if(board[x][y])
            return false;

return true;

}

void printboard(int board[N][N]) {
    for(int i = 0; i < N;i++) {
        for(int j = 0; j < N ;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}

bool solveNQueen(int board[N][N],int i,int n) {
    //base case
    if(i == n) {
        printboard(board) ;
        return true;
    }

    //assume i as row & we are iterating through col j
    for(int j = 0; j < n; j++) {
    	 //sending row,col to check attack
        if(isSafe(board,i,j,n)) {

            board[i][j] = 1;

        if(solveNQueen(board,i+1,n))
            return true;
        }

        board[i][j] = 0;
    }

    return false;
}

int main()
{

    int board[N][N] = {{0}};


    int n = 4; //no of queens

    solveNQueen(board,0,n);

    return 0;


}
