class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int>dp(n,1);
       for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(words[j].size()>words[j+1].size()){
                swap(words[j],words[j+1]);
            }
        }
       }
        for(int i=1;i<n;i++){
            int c=0;
            for(int j=0;j<i;j++){
                string s=words[i];
                string t=words[j];
                bool d=1,y=0;
                int l=0;
                for(int k=0;k<s.size();k++){
                     if(s[k]==t[l])l++;
                     else{
                        if(!y){
                            y=1;
                        }
                        else{
                            d=0;
                            break;
                        }
                     }
                }
                if(d&&y&&l==t.size())c=max(c,dp[j]);
            }
            dp[i]+=c;
        }
        int mx=0;
        //for(auto u:words)cout<<u<<" ";
        for(auto u:dp)mx=max(mx,u);
        return mx;
    }
};
