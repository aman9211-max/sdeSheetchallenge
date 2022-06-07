void sort012(int *arr, int n)
{
    int s = 0;
    int e = n - 1;
    int i = 0;
    
    while(i <= e) {
        if(arr[i] == 0) {
            swap(arr[i++], arr[s++]);
        }
        else if(arr[i] == 1) {
            i++;
        }
        else {
            swap(arr[e--], arr[i]);
            
        }
        
    }
}