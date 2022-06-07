#include <bits/stdc++.h> 
using namespace std;
void setZeros(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
      vector<vector<int> > ans(matrix.begin(), matrix.end());
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            if(matrix[i][j] == 0) {
                for(int k = 0; k < matrix.size(); k++) {
                    ans[k][j] = 0`;
                }
                for(int k = 0; k < matrix[0].size(); k++) {
                    ans[i][k] = 0;
                }
                
            }
        }
    }
    matrix = ans;
}

int main() {
    setZeros(matrix);

}