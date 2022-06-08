
vector<int> ans;
void find(vector<int> &nums, int i, int sum) {
    
    if(i == nums.size()) {
        ans.push_back(sum);
        return;
    }
    find(nums, i + 1, sum + nums[i]);
    find(nums, i + 1, sum);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    find(num, 0, 0);
    sort(ans.begin(), ans.end());
    vector<int> t =  ans;
    ans.clear();
    return t;
}