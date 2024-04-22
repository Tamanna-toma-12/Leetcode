class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n=a.size();
        vector<int>dp(n,1);
        sort(a.begin(),a.end());
        for(int i=1;i<n;i++){
            int c=0;
            for(int j=0;j<i;j++){
                if(a[i]%a[j]==0){
                    c=max(c,dp[j]);
                }
            }
            dp[i]+=c;
        }
        int mx=0,m=0;
        for(int i=0;i<n;i++){
            if(dp[i]>mx){
                mx=dp[i];
                m=a[i];
            }
        }
        vector<int>ans;
        ans.push_back(m);
        for(int i=n-1;i>=0;i--){
            if(a[i]==m){
                mx--;
                for(int j=0;j<i;j++){
                    if(dp[j]==mx&&m%a[j]==0){
                        ans.push_back(a[j]);
                        m=a[j];
                        break;
                    }
                }

            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
