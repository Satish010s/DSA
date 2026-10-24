class Solution {
public:

    int dateToDays(string& date){
        vector<int>daysInMonth={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month=stoi(date.substr(0,2));
        int days=stoi(date.substr(3,2));
        int totalDays=days;
        for(int i=0;i<(month-1);i++){
            totalDays+=daysInMonth[i];
        }
        return totalDays;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
       int arrAlice=dateToDays(arriveAlice);
       int leavAlice=dateToDays(leaveAlice);
       int arrBob=dateToDays(arriveBob);
       int leavBob=dateToDays(leaveBob);

       int startDay=max(arrAlice,arrBob);
       int endDay=min(leavAlice,leavBob);
       return max(0,endDay-startDay+1);
    }
};