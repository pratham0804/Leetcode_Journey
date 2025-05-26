class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> m,n;

        for(int i=0 ; i<s.size() ; i++){
            m[s[i]]+=i;
        }

        for(int i=0 ; i<t.size() ; i++){
            n[t[i]]+=i ;
        }

        for(int i=0 ; i<m.size() ; i++){
            if(m[s[i]]!=n[t[i]]){
                return false;
            }
        }

        return true;

    }
};