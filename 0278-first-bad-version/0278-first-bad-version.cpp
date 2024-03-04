// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int a=1,b=n;
        int mid;
        while(a<b){
            mid=a+(b-a)/2;
            if(isBadVersion(mid)){
                b=mid;
            }
            else{
                a=mid+1;
            }
        }
        return a;
    }
};