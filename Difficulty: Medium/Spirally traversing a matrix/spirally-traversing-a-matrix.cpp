class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        // code here
        //top col = 0 ; col < colsize; colsize++, mat[row][col] , row++
        // right col: ; row < rowsize; row++, mat[row][col] , col--
        // down row : col = col - 1; col >=0; col-- , mat[row][col], row--;
        //left col: row >=1
        int rowSize = mat.size();
        int colSize = mat[0].size();
        
        int topRow = 0, botRow = rowSize-1;
        int leftCol = 0, rightCol = colSize-1;
        
        vector<int> ans;
        while(topRow <= botRow && leftCol <= rightCol){
            //top row 
            for(int i = leftCol; i<=rightCol; i++){
                ans.push_back(mat[topRow][i]);
            }
            topRow++;
            
            //rightCol
            if(topRow > botRow){
                continue;
            }
            else{
                for(int i = topRow; i<= botRow;i++){
                    ans.push_back(mat[i][rightCol]);
                }
                rightCol--;
            }
            
            //bottom row
            if(rowSize%2==0 ){
                for(int i = rightCol; i>=leftCol;i--){
                    ans.push_back(mat[botRow][i]);
                }
                botRow--;
            }
            else {
                if(topRow == botRow){
                    continue;
                }else{
                    for(int i = rightCol; i>=leftCol;i--){
                        ans.push_back(mat[botRow][i]);
                    }
                    botRow--;
                }
            }
            
            //leftCol
            if(colSize %2==0){
                for(int i=botRow; i>=topRow; i--){
                    ans.push_back(mat[i][leftCol]);
                }
                leftCol++;
            }
            else{
                if(leftCol >= rightCol){
                    continue;
                }else{
                    for(int i=botRow; i>=topRow; i--){
                        ans.push_back(mat[i][leftCol]);
                    }
                    leftCol++;
                }
            }
        }
        return ans;
    }
};