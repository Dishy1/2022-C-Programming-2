#if 0 //1100

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  isKeyIncluded(char* key, char* str) {
    int keyleng = 0;
    while (key[keyleng] != '\0')
        keyleng++;

    for (int i = 0; str[i] != '\0'; i++) {
        if (key[0] == str[i]) {
            {
                for (int j = 0; key[j] != '\0' && str[i+j]!='\0'; ++j) {
                    if (key[j] != str[i + j])
                        break;
                    if (j == keyleng-1)
                        return 1;
                }
            }
        }
    }
    return 0;
}

int main(void)
{
    char key[10];
    char str[100];

    scanf("%s", key);
    scanf("%s", str);

    printf("%d", isKeyIncluded(key, str));

}
#endif
