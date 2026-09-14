class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, int> countS;
        std::unordered_map<char, int> countT;

        for (size_t i = 0; i < s.length(); i++) {
            countS[s[i]]++;
            countT[t[i]]++;
        }
        for (const auto& pair : countS) {
            char cha = pair.first;

            if (countT.count(cha) == 0 || countS[cha] != countT[cha]) {
                return false;
            }
        }
        return true;

    }
};
