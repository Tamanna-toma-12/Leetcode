    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        for(int i=1;i<n;i++){
            int c=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    c=max(c,dp[j]);
                }
            }
            //cout<<nums[i]<<" "<<c<<endl;
            int co=0;
            for(int k=0;k<i;k++){
                if(nums[k]<nums[i]&&dp[k]==c)co+=cnt[k];
            }
            dp[i]+=c;
            cnt[i]+=max(0,co-1);
        }
        int mx=0;
        for(auto u:dp){
           // cout<<u<<" ";
            mx=max(mx,u);
        }
        int ans=0;
        for(int i=0;i<n;i++){
          if(dp[i]==mx)ans+=cnt[i];  
        }
        return ans;
    }
