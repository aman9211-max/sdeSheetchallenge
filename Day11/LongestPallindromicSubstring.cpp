string longestPalinSubstring(string str)
{
     string ans = "";
     for(int i = 0; i < str.size(); i++) {
         int l = i;
         int r = i;
         while(l >= 0 and r < str.size()) {
             if(str[l] != str[r]) 
             {
                 break;
             }
             l--;
             r++;
         }
         if(r - l - 1 > ans.size()) {
             ans = str.substr(l + 1, r - l - 1);
         }
         l = i;
         r = i + 1;
         
         while(l >= 0 and r < str.size()) {
             if(str[l] != str[r]) {
                 break;
             }
             l--;
             r++;
         }
         if(ans.size() < r - l - 1) {
             ans = str.substr(l + 1, r -l - 1);
         }
     }
    return ans;
}