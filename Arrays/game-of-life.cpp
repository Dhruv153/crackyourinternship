class Solution {
public:
    int findNieghbor(vector<vector<int>>& board, int i, int j, int m, int n) {
        int cnt = 0;
        for (int c = i - 1; c <= i + 1; ++c) {
            for (int d = j - 1; d <= j + 1; ++d) {
                if (c == i && d == j)
                    continue;
                if (c >= 0 && c < m && d >= 0 && d < n &&
                    (board[c][d] == 1 || board[c][d] == 3)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = findNieghbor(board, i, j, m, n);
                if(board[i][j]==1 && (cnt<2 || cnt>3)){
                    board[i][j]=3;
                }
                if(board[i][j]==0 && cnt==3){
                    board[i][j]=2;
                }
            }
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ;j++){
                if(board[i][j]==3 ){
                    board[i][j]=0;
                }
                if(board[i][j] == 2)
                    board[i][j]=1;
            }
        }
    }
};
