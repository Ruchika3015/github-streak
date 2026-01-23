class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       int a=0;
       int maxm=0;
       for(int n:gain)
       {
        a+=n;
        maxm=max(a,maxm);
       }
       return maxm;
    }
};
