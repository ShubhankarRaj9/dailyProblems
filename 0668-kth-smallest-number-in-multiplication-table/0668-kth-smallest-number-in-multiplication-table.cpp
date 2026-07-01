#define ll long long
class Solution {
public:

    int findElements(int row, int col, ll guess) {
        int i = row-1;
        int j = 0;
        int cnt = 0;
        while(i>=0 && j<col){
            if((i+1)*1ll*(j+1) <= guess){
                cnt += (i+1);
                j++;
            }
            else{
                i--;
            }
        }
        return cnt; 
    }

    int findKthNumber(int m, int n, int k) {
        int low = 1;
        ll high = m*1ll*n;
        int res = -1;
        while(low <= high){
            ll guess = low + (high-low)/2;

            int cnt = findElements(m,n,guess);

            if(cnt < k) {
                low = guess + 1;
            }
            else{
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
};