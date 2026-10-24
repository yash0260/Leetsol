class Solution {
public:
int convert(string date){
    vector<int>daysinmonth={31,28,31,30,31,30,31,31,30,31,30,31};
    int month=stoi(date.substr(0,2));
    int day=stoi(date.substr(3,2));
    int total=day;
    for(int i=0;i<month-1;i++){
        total+=daysinmonth[i];
    }
    return total;
}

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startAlice=convert(arriveAlice);
        int endAlice=convert(leaveAlice);
        int startBob=convert(arriveBob);
        int endBob=convert(leaveBob);
        int ans=0;
        for(int day=1;day<=365 ;day++){
            bool alicePresent= (day>=startAlice && day <= endAlice);
            bool bobPresent= (day>=startBob && day <=endBob);
            if(alicePresent && bobPresent){
                ans++;
            }
        }
        return ans;
    }
};