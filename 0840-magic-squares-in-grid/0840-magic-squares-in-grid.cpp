class Solution {
public:

    bool check( int i, int j, vector<vector<int>> &grid){
        int totSum = 0;
        for(int itr_j=j; itr_j<= j+2 ; itr_j++){
            totSum += grid[i][itr_j];
        }
        
        vector<bool> visited(10,false);

        for(int itr_i=i; itr_i <=i+2; itr_i++){
            int rowSum = 0;
            for(int itr_j=j; itr_j<=j+2; itr_j++){
                
                int currNum = grid[itr_i][itr_j];
                //check if out of range 
                if(currNum < 1 || currNum > 9)
                    return false;

                //check if distinct
                if(visited[currNum])
                    return false;
                
                //add in curr row sum
                rowSum += currNum;
                visited[currNum] =true;
            }
            if(rowSum != totSum) return false;
        }

        // check for the colum sum 
        for(int itr_j=j; itr_j <=j+2; itr_j++){
            int colSum = 0;
            for(int itr_i=i; itr_i <= i+2;itr_i++){
                int currNum = grid[itr_i][itr_j];

                colSum += currNum;
            }
            if(colSum != totSum ) return false;
        }

        // check for diagonal sum
        // check right to left diagonal 
        int itr_i = i, itr_j = j;
        int diagSum = 0;
        while(itr_i <= i+2 && itr_j <= j+2){
            diagSum += grid[itr_i++][itr_j++];
        }
        if(diagSum != totSum ) return false;

        itr_i = i, itr_j=j+2;
        diagSum =0;
        while(itr_i <= i+2 && itr_j >= j){
            diagSum += grid[itr_i++][itr_j--];
        }
        if(diagSum != totSum ) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        if (n <= 2 || m <= 2)
            return 0;

        // we have to iterate on rows from 0 <= n-3
        // for each row iteration we have to choose the index of j
        // where we can form a 3*3 grid and then check for the conditions
        // for that
        int ans =0;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                // int rowLimit = i+2, colLimit = j+2;

                if(check(i,j,grid)) ans++;
            }
        }
        return ans;
    }
};