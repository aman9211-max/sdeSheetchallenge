#include<bits/stdc++.h>

int calculateMinPatforms(int at[], int dt[], int n) {
    vector<pair<int,int>>ans;   

 for(int i=0;i<n;i++)

{   ans.push_back({at[i],dt[i]});   

 }

   sort(ans.begin(),ans.end());

   int cnt=1;

   priority_queue<int,vector<int>,greater<int>>res;

   res.push(ans[0].second); 

   for(int i=1;i<n;i++){        

           if(ans[i].first<=res.top()){         

                    cnt++;     

   }    

      else{            res.pop();    

               }     

   res.push(ans[i].second);   

 }

   return cnt;

}