class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string& word, int rowIndex, int colIndex, int wordIndex){
        if(wordIndex > word.length()) return true;

        if(rowIndex<0 or rowIndex>=board.size()) return false;
        if(colIndex<0 or colIndex>=board[0].size()) return false;

        char currentChar = board[rowIndex][colIndex];

        if(currentChar!=word[wordIndex-1]) return false;

        //if currentChar matches

        board[rowIndex][colIndex] = '1';

        bool boolean = backtrack(board, word, rowIndex-1, colIndex, wordIndex+1) or
                backtrack(board, word, rowIndex+1, colIndex, wordIndex+1) or
                backtrack(board, word, rowIndex, colIndex-1, wordIndex+1) or
                backtrack(board, word, rowIndex, colIndex+1, wordIndex+1);
        
        board[rowIndex][colIndex] = currentChar;

        return boolean;
    }

    bool exist(vector<vector<char>>& board, string word) {
        char firstLetter = word[0];

        int numRows = board.size();
        int numCols = board[0].size();

        for(int i=0; i<numRows; i++){
            for(int j=0; j<numCols; j++){
                if(board[i][j]==firstLetter){
                    if(backtrack(board, word, i, j, 1)) return true; //if backtrack gives a result
                }
            }
        }

        return false;
    }
};
