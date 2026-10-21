class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        
        for (int i = 0; i < moves.size(); ++i) {
            int r = moves[i][0];
            int c = moves[i][1];
            board[r][c] = (i % 2 == 0) ? 'X' : 'O';
        }
        
        if (checkWinner(board, 'X')) {
            return "A";
        } else if (checkWinner(board, 'O')) {
            return "B";
        } else if (moves.size() == 9) {
            return "Draw";
        } else {
            return "Pending";
        }
    }

    bool checkWinner(const vector<vector<char>>& board, char player) {
        // check rows
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
                return true;
        }
        
        // check columns
        for (int j = 0; j < 3; ++j) {
            if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
                return true;
        }
        
        //   check diagonals
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            return true;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            return true;

        return false;
    }
};