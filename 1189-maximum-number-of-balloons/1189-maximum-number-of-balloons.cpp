class Solution {
public:
    int maxNumberOfBalloons(string text) {
       int b =0;
       int a =0;
       int l=0;
       int o=0;
       int n =0;
       for(int i =0;i<text.size();i++){
        if(text[i]=='b'){
            b++;
        }
        if(text[i]=='a'){
            a++;
        }
        if(text[i]=='l')
        l++;
        if(text[i]=='o')
        o++;
        if(text[i]=='n')
        n++;
       }
      int ans = min({b, a, l/2, o/2, n});
       return ans;
    }
};