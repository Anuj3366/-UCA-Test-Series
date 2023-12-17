#include <stdlib.h>
#include <string.h>

char *removeDuplicateLetters(char *s) {
    int freq[26] = {0};
    int len = strlen(s);
    char *ans = (char*)malloc((len + 1) * sizeof(char));
    char *start = ans;

    while(*s != '\0'){
        int rep = (*s - 'a');
        if(freq[rep] == 0){
            freq[rep]++;
        }
        s++;
    }
    for(int i = 0;i<26;i++){
        if(freq[i] > 0){
            *ans = (i+'a');
            ans++;
        }
    }
    *ans = '\0';
    return start;
}
