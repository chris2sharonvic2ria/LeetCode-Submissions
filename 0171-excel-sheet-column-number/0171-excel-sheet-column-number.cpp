class Solution {
public:
    int titleToNumber(string ct) {
        int n=ct.size();
        int one=26;
        int ans=0;
        int curr=0;
        for(int i=0;i<n;i++){
            curr=ct[i]-'A'+1;
            ans=ans*one+curr;
        }
        return ans;
    }
};