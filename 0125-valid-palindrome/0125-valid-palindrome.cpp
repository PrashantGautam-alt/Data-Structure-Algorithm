class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();

        string str = "";

        for(int i=0; i<n; i++){
            if(isalnum(s[i])){
                str += tolower(s[i]);
            }
        }

        int st = 0;
        int end = str.length()-1;

        while(st<end){
            if(str[st]!=str[end]){
                return false;
            }
            st++;
            end--;
        }

        return true;

    }
};