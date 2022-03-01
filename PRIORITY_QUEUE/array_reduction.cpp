class Solution 
{
public:
    int minSetSize(vector<int>& arr) 
    {
        unordered_map<int,int> mp;
        priority_queue<int> pq;
        int c=0,n=arr.size();
        for(auto x: arr)
        {
            mp[x]++;
        }
        for(auto x: mp)
        {
            pq.push(x.second);
        }
        while(!pq.empty())
        {
            n-=pq.top();
            c++;
            if(n<=arr.size()/2)
            {
                return c;
            }
            pq.pop();
        }
        return c;
    }
};
