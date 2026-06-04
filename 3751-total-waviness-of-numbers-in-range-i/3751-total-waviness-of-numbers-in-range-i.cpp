class Solution {
public:
    int findwaviness(int i){
       
        string s= to_string(i);
        int l = s.size();
        if(l<3)
        return 0;
        int cnt =0;
        for(int j =1;j<=l-2;j++){
            //peak
            if(s[j]>s[j-1]&& s[j]>s[j+1])
            cnt++;
            //valley
            else if(s[j]<s[j-1]&&s[j]<s[j+1])
            cnt++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int score =0;
        for(int i= num1;i<=num2;i++){
            score+=findwaviness(i);

        }
        return score;
    }
};