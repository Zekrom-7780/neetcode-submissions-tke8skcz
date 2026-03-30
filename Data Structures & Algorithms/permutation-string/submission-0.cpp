class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size()<s1.size()){
            return false;
        }
        bool ans=false;
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for (int i=0;i<s1.size();i++){
            v1[s1[i]-'a']++;
        }
        int i=0;
        int j=s1.size();
        for (int i=0;i<j;i++){
            v2[s2[i]-'a']++;
        }
        if (v1==v2) return true;
        while(j<s2.size()){
           v2[s2[j]-'a']++;
           v2[s2[i]-'a']--;
           j++;
           i++;
           if (v1==v2){
            return true;
           }
        }
        return false;
    }
};
