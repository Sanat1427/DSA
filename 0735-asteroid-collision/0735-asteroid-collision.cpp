class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int>st;
        for(int i =0;i<n;i++){
            if(asteroids[i]>0)
            st.push_back(asteroids[i]);// only push psotive number
            else{
            while(!st.empty()&& st.back()>0 && st.back()<abs(asteroids[i])){
                st.pop_back();// ex 10 vs -20 , so pop_back(10)
            
            }
            if(!st.empty()&& st.back()>0 && st.back()==abs(asteroids[i]))
            st.pop_back(); // ex 10 vs -10
            else if(st.empty() || st.back()<0)
            st.push_back(asteroids[i]);
            // ex- empty stack or -5 -10 , so then push negative number
            }
        }
        return st;
    }
};