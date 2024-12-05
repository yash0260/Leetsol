class Solution {
public:
    bool canChange(string start, string target) {
        string startfiltered,targetfiltered;
        for(char c:start){
            if(c !='_')startfiltered +=c;
        }
        for(char c: target){
            if(c !='_') targetfiltered +=c;
        }
        if (startfiltered != targetfiltered){
return false;
        }
        int n =start.size();
        int i=0,j=0;
        while (i<n && j<n){
            while (i<n && start[i]=='_') i++;
            while (j<n && target[j]=='_') j++;
            if(i==n && j==n)return true;
            if(i==n || j==n)return false;
            if(start[i] != target[j])return false;
             if(start[i]  =='L' && i<j)return false;
             if(start[i] =='R' && i>j)return false;
            i++;
            j++;
            
            
            
        }
        return true;
    }
};