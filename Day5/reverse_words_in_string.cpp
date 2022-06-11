#include<bits/stdc++.h>
string reverseString(string str)
{
    // Write your code here.
    vector<string>v;
    string s="";
    for(int i=0; i<str.size(); i++){
        if(str[i]!=' '){
            s+=str[i];
            if(str[i+1]==' ' or i==str.size()-1)
            {
                v.push_back(s);
                s="";
            }
        }
    }
    string ans="";
    for(int i=v.size()-1; i>0; i--){
        ans.append(v[i]);
        ans+=' ';
    }
    ans.append(v[0]);
    return ans;
}