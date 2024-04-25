   int maxArea(vector<int>& height) {
      int j=0,k=height.size()-1;
      int ans=0;
      for(int i=0;i<height.size();i++){
        ans=max(ans,(k-j)*min(height[k],height[j]));
        if(height[k]<height[j])k--;
        else j++;
      }  
      return ans;
        
    }
