class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end());
        string res="";        
        for(auto x:dictionary)
        {
            if(x.length()>res.length())
            {
                if(checklcs(s,x))
                    res=x;
            }
        }
        return res;
    }
    int checklcs(string& p,string& q)
    {
        int j=0;
        for(int i=0;i<p.length();i++)
        {
            if(p.length()-i < q.length()-j)// lcs not possible
                return 0;
            if(p[i]==q[j])
                j++;
            if(j==q.length())
                return 1;
        }
        return 0;
    }
};