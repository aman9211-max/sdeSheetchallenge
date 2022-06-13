string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    
    string ans;
    bool end = false;
    for(int i = 0; i < arr[0].size(); i++)  {
        for(int j = 1; j < arr.size(); j++) {
            if(i >= arr[j].size()) {
                end = true;
                break;
            }
            if(arr[j][i] != arr[j - 1][i]) {
                end = true;
                break;
            }
        }
        if(end) {
            break;
        }
        ans.push_back(arr[0][i]);
    }
    return ans;
    
}


