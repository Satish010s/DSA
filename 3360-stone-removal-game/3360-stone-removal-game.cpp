class Solution {
public:
    bool canAliceWin(int n) {
        bool status=true;
        if(n<10) return false;
        int move=10;
        while(n>=move){
            if(status && move<=n){
                n-=move;
                move-=1;
                status=false;
            }
            else if(!status && move<=n){
                n-=move;
                move-=1;
                status=true;
            }
            
        }
        return !status;
    }
};