#include <stdlib.h>
#include <string.h>

char *removeDuplicateLetters(char *s) {
    int count[26] = {0};
    int visited[26] = {0};
    int len = strlen(s);
    char *result = (char*)malloc((len + 1) * sizeof(char));
    int pos = 0;

    for(int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }

    for(int i = 0; i < len; i++) {
        count[s[i] - 'a']--;
        if(visited[s[i] - 'a']) continue;
        while(pos > 0 && s[i] < result[pos - 1] && count[result[pos - 1] - 'a'] > 0) {
            visited[result[--pos] - 'a'] = 0;
        }
        result[pos++] = s[i];
        visited[s[i] - 'a'] = 1;
    }
    result[pos] = '\0';
    return result;
}
