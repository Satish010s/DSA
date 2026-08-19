class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int totalGroup=n*2;
        unordered_map<int,vector<bool>>reservedMp;
        for(auto &it:reservedSeats){
            int row=it[0];
            int col=it[1];
            if(reservedMp.find(row)==reservedMp.end()){
                reservedMp[row]=vector<bool>(11,false);
            }
            reservedMp[row][col]=true;
        }

        for(auto& [row,isReserved]:reservedMp){
            bool left=!isReserved[2] && !isReserved[3] && !isReserved[4] && !isReserved[5]; 
            bool middle=!isReserved[4] && !isReserved[5] && !isReserved[6] && !isReserved[7]; 
            bool right=!isReserved[6] && !isReserved[7] && !isReserved[8] && !isReserved[9]; 
            
            int allocationSeat=0;
            if(left && right){
                allocationSeat=2;
            }
            else if(left || right || middle){
                allocationSeat=1;
            }
            else   allocationSeat=0;

            totalGroup-=(2-allocationSeat);
        }
       return  totalGroup;
    }
};