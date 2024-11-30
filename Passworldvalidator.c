#include <stdio.h>
#include <string.h>
#include <ctype.h>
int checkPassword(const char *password) {
    int length = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    const int minLength = 8, maxLength = 20;
    if (length < minLength || length > maxLength) {
        printf("Password must be between 8 and 20 characters long.\n");
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = 1;
        else if (islower(password[i])) hasLower = 1;
        else if (isdigit(password[i])) hasDigit = 1;
        else if (strchr("!@#$%^&*(),.?\":{}|<>", password[i])) hasSpecial = 1;
    }
    if (!hasUpper) {
        printf("Password must include at least one uppercase letter.\n");
        return 0;
    }
    if (!hasLower) {
        printf("Password must include at least one lowercase letter.\n");
        return 0;
    }
    if (!hasDigit) {
        printf("Password must include at least one digit.\n");
        return 0;
    }
    if (!hasSpecial) {
        printf("Password must include at least one special character.\n");
        return 0;
    }
    printf("Password is valid.\n");
    return 1;
}
int main() {
    char password[100];
    printf("Enter a password: ");
    scanf("%s", password);
    checkPassword(password);
    return 0;
}
