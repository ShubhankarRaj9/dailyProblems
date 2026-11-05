class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int sz_a = a.size(), sz_b = b.size();
        int t[sz_a+1][sz_b+1];
        int max_len = 0;
        // initialisation
        for(int i=0; i<sz_a+1; i++){
            for(int j=0; j<sz_b+1; j++){
                if(i==0 || j==0) t[i][j] = 0;
            }
        }
        // choice-diagram
        for(int i=1; i<sz_a+1; i++){
            for(int j=1; j<sz_b+1; j++){
                if(a[i-1] == b[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                    max_len = max(max_len, t[i][j]);
                }
                else{
                    t[i][j] = 0;
                }
            }
        }
        return max_len;
    }
};