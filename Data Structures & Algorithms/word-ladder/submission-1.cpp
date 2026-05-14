class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>umap;
        for (auto s:wordList){
            umap[s]++;
        }
        if (umap.find(endWord)==umap.end()) return 0;
        queue<string>q;
        q.push(beginWord);
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            ans++;
            while(size--){
                auto itr=q.front();
                q.pop();
                if (itr==endWord) return ans;
                    for (int i=0;i<itr.size();i++){
                        char ori=itr[i];
                        for (char c='a';c<='z';c++){
                            itr[i]=c;
                            if (umap.find(itr)!=umap.end()){
                                q.push(itr);
                                umap.erase(itr);
                            }
                        }
                        itr[i]=ori;
                    }
                }
            }
        return 0;
    }
};
