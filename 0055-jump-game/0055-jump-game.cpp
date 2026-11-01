#define sz size
using v_int = vector<int>;
class Solution {
public:
    bool canJump(v_int & a) {
        int max_jump = a[0];
        for(int i=1; i<sz(a); i++){
          if(i<= max_jump) {
            max_jump = max(max_jump,i+a[i]);
          }
        }
        if(max_jump >= sz(a)-1) return true;
        return false;
    }
};