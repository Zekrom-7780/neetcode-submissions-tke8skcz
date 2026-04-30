class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,int>umap;
        unordered_set<char> st;
        for (auto itr:words){
            for (char c:itr){
                st.insert(c);
            } 
        }
        int idx=0;
        for (char c:st){
            umap[c]=idx++;
        }
        vector<char> rev(idx);
        for (auto &p : umap) {
            rev[p.second] = p.first;
        }
        vector<vector<int>>adj(st.size());
        for (int i=0;i<words.size()-1;i++){
            string pref=words[i];
            string suf=words[i+1];
            if (pref.substr(0, suf.size()) == suf && pref.size() > suf.size()) return "";
            for (int i=0;i<pref.size();i++){
                if (pref[i]!=suf[i]){
                    adj[umap[pref[i]]].push_back(umap[suf[i]]);
                    break;
                }
            }
        }
        string ans="";
        vector<int> status(st.size(),0);
        bool isCycle=0;
        function<void(int)> topo=[&](int i){
            status[i]=1;
            for (auto itr:adj[i]){
                if (status[itr]==0){
                    topo(itr);
                    if (isCycle) return;
                }
                if (status[itr]==1){
                    isCycle=1;
                    return;
                }
            }
            status[i]=2;
            ans.push_back(rev[i]);
        };

        for (int i=0;i<status.size();i++){
            if (!status[i]){
                topo(i);
            }
        }
        if (isCycle) return "";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
