class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            count += expand(s, i, i);
            count += expand(s, i, i + 1);
        }
        return count;
    }

private:
    int expand(const string& s, int left, int right) {
        int found = 0;
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            ++found;
            --left;
            ++right;
        }
        return found;
    }
};
