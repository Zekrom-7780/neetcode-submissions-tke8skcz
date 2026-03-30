class Solution {
public:
    int Operations (int a,int b, string s){
        if(s=="+"){
            return a+b;
        }
        if (s=="-"){
            return a-b;
        }
        if (s=="*"){
            return a*b;
        }
        if (s=="/"){
            return a/b;
        }
        return 0;
    }
    bool isNotOperations(string tokens){
        return (tokens!="+" && tokens !="-" && tokens !="*" && tokens!="/");
    }
    int evalRPN(vector<string>& tokens) {
        if (tokens.size()==1){
            return stoi(tokens[0]);
        }
        stack<int> st;
        int ans=0;
        for (string itr:tokens){
            if (isNotOperations(itr)){
                st.push(stoi(itr));
            }
            else{
                ans=st.top();
                st.pop();
                ans=Operations(st.top(),ans,itr);
                st.pop();
                st.push(ans);
            }
        }
        return ans;
    }
};
