class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int r = matrix.size();
        int c = matrix[0].size();
        int StartingRow = 0;
        int StartingCol = 0;
        int endingRow = r-1;
        int endingCol = c -1;
        int count = 0;
        int total = r*c;
        while(count < total){
            
            for(int index = StartingCol ;count < total && index <= endingCol ; index++){
                ans.push_back(matrix[StartingRow][index]);
                count++;
            }
            StartingRow++;
            
            for(int index = StartingRow ;count < total && index <= endingRow ; index++){
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            
            for(int index = endingCol ;count < total && index >= StartingCol ; index--){
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            
            for(int index = endingRow ;count < total && index >= StartingRow ; index--){
                ans.push_back(matrix[index][StartingCol]);
                count++;
            }
            StartingCol++;
            
    }
    return ans;
    }
};
