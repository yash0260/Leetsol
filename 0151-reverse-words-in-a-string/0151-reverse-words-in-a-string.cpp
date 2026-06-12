class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string k="";
        string ans="";
        vector<string>arr;
        for(int i=0;i<n;i++){
                       if(s[i] == ' ') {

                if(k != "") {
                    arr.push_back(k);
                    k = "";
                }
            }
            else {
                k += s[i];
            }
        }
        if(k!="")arr.push_back(k);

        string res="";
        reverse(arr.begin(),arr.end());
        int j=arr.size();
        for(int j=0;j<arr.size();j++){
res+=arr[j];
if(j!=arr.size()-1)
res+=" ";

        }
        return res;
    }
};