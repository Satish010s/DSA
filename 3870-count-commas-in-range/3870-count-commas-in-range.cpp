class Solution {
public:
    int countCommas(int n) {
        int comma=0;
        if(n>=1000){
        while(n>=1000){
            n--;
            comma++;
        }
        }
        
        return comma;
    }
};