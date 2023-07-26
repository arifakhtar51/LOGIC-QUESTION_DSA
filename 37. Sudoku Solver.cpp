class Solution {
public:
bool isSafe(vector<vector<char>>& board,char val,int i,int j){
    //row
    for(int row =0;row<9;row++){
        if(board[row][j]==val)return 0;
    }

    //col
    for(int col =0;col<9;col++){
        if(board[i][col]==val)return 0;
    }

    //3*3 mat
    for(int k=0;k<9;k++){
        if(board[3*(i/3)+(k/3)][3*(j/3)+(k%3)]==val){
            return 0;
        }
    }
    return 1;



}
    bool solve(vector<vector<char>>& board){
        int n=9;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    for(char val='1';val<='9';val++){
                        if(isSafe(board,val,i,j)){
                            board[i][j]=val;
                            //recursion samaal lega
                            bool aagekasol=solve(board);
                            if(aagekasol==1){
                                return 1;
                            }
                            board[i][j]='.';

                        }
                    }
                      return 0;
                }
            }
        }
        return 1;
      
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};



int main(){
    vector<vector<char>> board{{'.','.','.','9','.','1','.','.','2'},
                                {'.','.','.','.','.','5','.','.','.'},  
                                {'.','.','.','6','3','7','5','8','.'},
                                {'.','.','8','.','.','.','.','6','9'},
                                {'.','9','.','.','.','.','.','4','.'},
                                {'2','1','.','.','.','.','8','.','.'},
                                {'.','8','6','4','1','3','.','.','.'},
                                {'.','.','.','5','.','.','.','.','.'},
                                {'4','.','.','2','.','8','.','.','.'}};
    



    solveSudoku(board);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



