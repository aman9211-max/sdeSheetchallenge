#include<deque>

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    deque<int> q;
    vector<int> ans;
    for(int i = 0; i < k; i++) {
        while(!q.empty() and nums[q.back()] < nums[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(nums[q.front()]);
    int n = nums.size();
    for(int i = k; i < n; i++) {
        if(q.front() == i - k) {
            q.pop_front();
        }
         while(!q.empty() and nums[q.back()] < nums[i]) {
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(nums[q.front()]);
        
    }
    return ans;