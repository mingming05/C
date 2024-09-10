#include <stdio.h>
#include <string.h>
 
void strLeftStrip(char *str, char *chars) {
    int mov = 0;
    char *pStr = str;
    while (*pStr) {
        if (strchr(chars, *pStr)) ++mov;
        else break;
        ++pStr;
    }
    if (mov) memmove(str - mov, str, strlen(str) + 1);
}
 
void strRightStrip(char *str, char *chars) {
    int len = 0;
    char *pStr = str + strlen(str) - 1;
    while (pStr >= str) {
        if (strchr(chars, *pStr)) ++len;
        else break;
        --pStr;
    }
    *(str + strlen(str) - len) = '\0';
}
 
int main() {
    char str1[1000] = "", chars[1000] = "", str2[1000] = "";
    scanf("%[^\n] %[^\n]", str1, chars);
    memcpy(str2, str1, strlen(str1) + 1);
 
    strLeftStrip(str1, chars);
    puts(str1);
    strRightStrip(str2, chars);
    puts(str2);
    strRightStrip(str1, chars);
    puts(str1);
    return 0;
}