
#include<map>
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    
    map<char, int> cnt;
    for(auto i : str1) {
        cnt[i]++;
    }
    for(auto i : str2) {
        cnt[i]--;
    }
    for(auto i : cnt) {
        if(i.second != 0) {
            return 0;
        }
    }
    return 1;
    
}