class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();

        if (sLen == 0) {
            return true;
        }

        int idxS = 0;
        int idxT = 0;

        while (idxS<sLen && idxT<tLen) {
            if (s[idxS] == t[idxT]) {
                if (idxS == sLen-1) {
                    return true;
                }
                idxS++;

            }
            idxT++;
        }

        return false;
    }
};
