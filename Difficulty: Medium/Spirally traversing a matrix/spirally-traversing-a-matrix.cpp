//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &matrix) {
        vector<int> ans;
        int lb_row=0,lb_col=0,ub_row=matrix.size()-1,ub_col=matrix[0].size()-1;
        while(lb_row<=ub_row && lb_col<=ub_col) {
            // Traversing right
            for(int c=lb_col;c<=ub_col;c++) ans.push_back(matrix[lb_row][c]);
            lb_row++;
            // Traversing down
            for(int r=lb_row;r<=ub_row;r++) ans.push_back(matrix[r][ub_col]);
            ub_col--;
            // Traversing left
            if(lb_row<=ub_row) {
                for(int c=ub_col;c>=lb_col;c--) ans.push_back(matrix[ub_row][c]);
                ub_row--;
            }
            // Traversing up
            if(lb_col<=ub_col) {
                for(int r=ub_row;r>=lb_row;r--) ans.push_back(matrix[r][lb_col]);
                lb_col++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends