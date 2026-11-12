class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (vector<char>& row: board){ //checking horizontal
            unordered_map<char, int> hori_check;

            for (char c: row){
                if (c!='.'){
                    hori_check[c]++;
                }
            }

            for (const auto& [key, val]: hori_check){
                for (int i=0; i<hori_check.size(); i++){
                    if (val>1){
                        return false;
                    }
                }
            }
        }

       //------------------

        for (int i=0; i<9; i++){ //vertical checking
            unordered_map<char, int> vert_check;

            for (vector<char>& row: board){
                if (row[i]!='.'){
                    vert_check[row[i]]++;
                }
            }

            for (const auto& [key, val]: vert_check){
                for (int i=0; i<vert_check.size(); i++){
                    if (val>1){
                        return false;
                    }
                }
            }
        }

        //--------------------
        int vbc = 0; //vertical block count
        int hbc = 0; //horizontal block count

        while (vbc<3){ //while not all searched
            hbc = 0;
            while (hbc<3){
                unordered_map<char, int> box;
                for (int i=(vbc*3); i<(vbc+1)*3; i++){
                    for (int j=(hbc*3); j<(hbc+1)*3; j++){
                        if (board[i][j]!='.'){
                            box[board[i][j]]++;
                        }
                    }
                    for (const auto& [key, val]: box){
                        for (int i=0; i<box.size(); i++){
                            if (val>1){
                                return false;

                            }
                        }
                    }
                }
                hbc++;
            }
            vbc++;
        }

        return true;
    }
};
