class Solution
{
public:
    // vector<vector<string>> solveNQueens(int n) {
    //     vector<vector<string>> res;
    //     vector<string> nQueens(n, string(n, '.'));
    //     solvenqueens(res, nQueens, 0, n);
    //     return res;
    // }

    vector<vector<string>> solveNQueens(int n)
    {
        //I need to give all the solutions
        vector<vector<string>> response;
        //Canvas for inidi=vidual queen setup
        vector<string> nQueen(n, string(n, '.'));
        solvenqueen(response, nQueen, 0, n);
        return response;
    }

    void solvenqueen(vector<vector<string>> &res, vector<string> &nQueen, int row, int n)
    {
        if (row == n)
        {
            res.push_back(nQueen);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (isValid(nQueen, row, i, n))
            {
                nQueen[row][i] = 'Q';
                solvenqueen(res, nQueen, row + 1, n);
                //Backtracking
                nQueen[row][i] = '.';
            }
        }
    }

    // void solvenqueens(vector<vector<string>> &res, vector<string> &nQueens, int row, int n){
    //     if(row==n){
    //         res.push_back(nQueens);
    //         return;
    //     }
    //     for(int col=0;col!=n;col++){
    //         if(isValid(nQueens, row, col, n)){
    //             nQueens[row][col] = 'Q';
    //             solvenqueens(res, nQueens, row+1, n);
    //             //Backtracking process
    //             nQueens[row][col] = '.';
    //         }
    //     }
    // }

    bool isValid(vector<string> &nQueens, int row, int col, int n)
    {
        //checking if the column has a queen before this
        for (int i = 0; i < n; i++)
        {
            if (nQueens[i][col] == 'Q')
            {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (nQueens[i][j] == 'Q')
            {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j <= n; i--, j++)
        {
            if (nQueens[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
};