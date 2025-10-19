class Solution {
public:
void rotate(string&curr,int&b){
    reverse(curr.begin(),curr.end());
    reverse(curr.begin(),curr.begin()+b);
    reverse(curr.begin()+b, curr.end());
}
    string findLexSmallestString(string s, int a, int b) {
       string smallest=s;
       queue<string>q;
       unordered_set<string>visited;
       q.push(s);
       visited.insert(s);
       while(!q.empty()){
        string curr = q.front();
        q.pop();
        
        if(curr<smallest)
        smallest=curr;

        //add 
        string temp =curr;
        for(int i =1;i<temp.length();i+=2){
            temp[i]=(temp[i]-'0'+a)%10+'0';

        }
        if(!visited.count(temp)){
            visited.insert(temp);
            q.push(temp);
        }
        //rotate
        rotate(curr,b);
        if(!visited.count(curr)){
            visited.insert(curr);
            q.push(curr);
        }
        
       }      
       return smallest;
    }
};