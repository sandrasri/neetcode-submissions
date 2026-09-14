#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    
    if (strlen(s) != strlen(t)) {
        return false;
    }

    // a fixed-size array for character counts
    int char_counts[26] = {0};

    for (int i = 0; i < strlen(s); i++) {
        char_counts[s[i] - 'a']++;
        char_counts[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (char_counts[i] != 0) {
            return false;
        }
    }

    return true;
}
