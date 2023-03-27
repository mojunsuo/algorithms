class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>>a;
        for(int i=0;i<ranges.size();i++)
        {
            a.push_back({i-ranges[i],i+ranges[i]});
        }
        sort(a.begin(),a.end());
        int cur=0,cnt=0,right=0;
        while(right<n)
        {
            int newright=-1;
            if(cur<a.size())
            {
                while(a[cur][0]<=right)
                {
                    newright=max(a[cur][1],newright);
                    cur++;
                    if(cur>=a.size())
                    {
                        break;
                    }
                } 
            }
            
            if(newright==-1)
            {
                return -1;
            }
            cnt++;
            right=newright;
        }
        return cnt;
    }
};