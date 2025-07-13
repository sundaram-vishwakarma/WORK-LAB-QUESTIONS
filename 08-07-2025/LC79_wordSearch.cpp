class Solution {
public:
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Helper function
    bool searchWord(vector<vector<char>>& board, int i, int j, int index, const string& word) {
        int rows = board.size();
        int cols = board[0].size();

        if (index == word.length()) {
            return true;
        }

        if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] == '*' || board[i][j] != word[index]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '*';

        for (auto& dir : direction) {
            int newX = i + dir[0];
            int newY = j + dir[1];
            if (searchWord(board, newX, newY, index + 1, word)) {
                return true;
            }
        }

        board[i][j] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0] && searchWord(board, i, j, 0, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};
