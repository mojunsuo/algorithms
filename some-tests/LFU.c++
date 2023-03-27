
class LFUCache {
public:
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    unordered_map<int,int>cnt;
    unordered_map<int,int>a;
    int m;
    int now=0;
    LFUCache(int capacity) {
        m=capacity;
    }
    
    int get(int key) {
        /*if(key==2)
        {
            cout<<pq.top().second<<" "<<pq.top().first;
        }*/
        if(m==0)
        {
            return -1;
        }
        
        if(a.count(key))
        {
            cnt[key]++;
            now++;
            pq.push({cnt[key],now,key});
            return a[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m==0)
        {
            return;
        }
        now++;
        if(a.count(key))
        {
            a[key]=value;
            cnt[key]++;
        }
        else{
            //cout<<a.size()<<endl;
            if(a.size()==m)
            {
                if(!pq.empty())
                {
                    while(cnt[pq.top()[2]]!=pq.top()[0])
                    {
                        //cout<<pq.top().second<<endl;
                        pq.pop();
                    }
                    a.erase(pq.top()[2]);
                    cnt.erase(pq.top()[2]);
                    pq.pop();
                }
            }
            a[key]=value;
            cnt[key]++;
        }
        pq.push({cnt[key],now,key});
        //cout<<pq.top().second<<" "<<pq.top().first<<" "<<cnt[pq.top().second]<<endl;
        //return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */