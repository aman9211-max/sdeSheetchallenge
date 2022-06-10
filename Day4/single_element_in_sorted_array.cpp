int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int x = 0;
    for(auto i : arr) x ^= i;
    return x;
}
