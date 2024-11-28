#include <stdio.h>
#include <string.h>
#include <ctype.h>
int isPalindrome(char *str) {
    int length = strlen(str);
    char *start = str;           
    char *end = str + length - 1;    
    while (start < end) {
        while (!isalnum(*start) && start < end) start++;
        while (!isalnum(*end) && start < end) end--;
        if (tolower(*start) != tolower(*end)) {
            return 0;  
        }
        start++;
        end--;
    }
    return 1;  
}
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
{
printf("Darshan.M");
}
    return 0;
}
