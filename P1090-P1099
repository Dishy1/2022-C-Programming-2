#define _CRT_SECURE_NO_WARNINGS



#if 0 // 1090 [week08]예비고사 4 : 특정 문자열 바꾸기
#include <stdio.h> 

void SWAP(char* p) {
	int i = 0;
	int j = 0;
	int flag = 0;
	int count = 0;
	for (int i = 0; p[i] != '\0'; i++) {
		if (p[i] == 'a' && p[i + 1] == 'n' && p[i + 2] == 'd') {
			p[i] = '&';
			flag++;
			j = i;
			while (p[j+ 3]!='\0') {
				p[j + 1] = p[j + 3];
				j++;
			}
		}
		count++;
	}
	p[count - flag*2] = '\0';
}


int main() {
	char text[50];
	scanf("%s", text);
	SWAP(text);
	printf("%s", text);
	return 0;
}
#endif



#if 0 // 1091 [week11] A반 실습 3 : 문자열 비교 (대소문자 반전)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cmp(char src[][100]) {
    int flag = 1;

    for (int i = 0; src[0][i] != '\0' && src[1][i]!='\0'; i++) {
        if (src[0][i] >= 'A' && src[0][i] <= 'Z') {
            if (src[0][i] != src[1][i] - 32)
                flag = -1;

        }

        else if (src[0][i] >= 'a' && src[0][i] <= 'z') {
            if (src[0][i] != src[1][i] + 32)
                flag = -1;
        }
        else if (src[0][i] != src[1][i])
            flag = -1;

        
    }
    return flag;
}

int main(void)
{
    char arr[2][100];

    scanf("%s", arr[0]);
    scanf("%s", arr[1]);

    printf("%d", cmp(arr)); // 1 또는 -1이 리턴되어 출력 되는 형태

    return 0;
}
#endif



#if 0 // 1092 [week11] A반 실습 3 : 문자열 비교 (대소문자 반전)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cmp(char src[][100]) {

    for (int i = 0; src[0][i] != '\0'|| src[1][i] != '\0'; ++i) {
        if (src[0][i] >= 'A' && src[0][i] <= 'Z') {
            if (src[1][i] >= 'a' && src[1][i] <= 'z') {
                if (src[1][i] != src[0][i] + 32)
                    return -1;
            }
            else if (src[1][i] != src[0][i])
                return -1;
        }
        else if (src[0][i] >= 'a' && src[0][i] <= 'z') {
            if (src[1][i] >= 'A' && src[1][i] <= 'Z') {
                if (src[1][i] != src[0][i] - 32)
                    return -1;
            }
            else if (src[1][i] != src[0][i])
                return -1;
        }
        else if (src[1][i] != src[0][i])
            return -1;

    }

    return 1;
}
int main(void)
{
    char arr[2][100];

    scanf("%s", arr[0]);
    scanf("%s", arr[1]);


    printf("%d", cmp(arr));

    return 0;
}
#endif



#if 0 // 1093 [week11] A반 실습 5 : 2차원 배열 동적할당

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char** ese(char** _p) {
    _p = (char**)malloc(sizeof(char*) * 3);
    _p[0] = (char*)malloc(sizeof(char) * 30);
    _p[1] = (char*)malloc(sizeof(char) * 30);
    _p[2] = (char*)malloc(sizeof(char) * 30);
    for (int i = 0; i < 3; i++)
        scanf("%s", _p[i]);
    return _p;
}

int main(void)
{
    char** p = NULL;

    p = ese(p);

    printf("%s\n%s\n%s", *p, *(p + 1), *(p + 2));

    for (int i = 0; i < 3; i++) free(p[i]);
    free(p);

    return 0;
}
#endif



#if 0 // 1094 [week11] B반 실습 5 : 2차원 배열 동적할당

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char** ese(char** _p) {
    char** m = (char**)malloc(3 * sizeof(char*));

    m[0] = (char*)malloc(50 * sizeof(char));
    m[1] = (char*)malloc(50 * sizeof(char));
    m[2] = (char*)malloc(50 * sizeof(char));
    for (int i = 0; i < 3; i++)
        scanf("%s", m[i]);
    return m;
}

int main(void)
{
    char** p = NULL;

    p = ese(p);

    printf("%s\n%s\n%s", *p, *(p + 1), *(p + 2));

    for (int i = 0; i < 3; i++) free(p[i]);
    free(p);

    return 0;
}

#endif



#if 0 // 1095 [week11] A반 실습 1 : 문자열 안에 특정 문자 개수 카운트
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  countKey(char* str, char key) {
    int counter = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == key)
            counter++;
    }
    return counter;
}

int main(void)
{
    char str[100];
    char key;

    scanf("%c", &key);
    scanf("%s", str);

    printf("%d", countKey(str, key));

}

#endif



#if 0 // 1096 [week11] A반 실습 4 : 문자열에 문자열 포함여부
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  isKeyIncluded(char* str, char* key) {
    int flag = 0, count = 0, keylength =0;
    while (key[keylength] != '\0')
        keylength++;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == key[0]) {
            for (int j = 0; str[i+j] != '\0'&&key[j]!='\0'; j++) {
                if (str[i + j] != key[j])
                    break;
                if (j == keylength-1)
                    flag = 1;
            }
        }
    }
    return flag;
}

int main(void)
{
    char str[100];
    char key[10];

    scanf("%s", str);
    scanf("%s", key);

    printf("%d", isKeyIncluded(str, key));
}
#endif



#if 0 // 1097 [week11] A반 실습 2 : 2진수 값에 따라 문자열로 표현

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void makeDot(unsigned int data, char* _binary) {
    int k = 31;
    for (int i = 0; i < 32; i++)
        _binary[i] = 0;
    while (data != 0) {
        _binary[k] = data % 2;
        data /= 2;
        k--;
    }

    //for (int i = 0; i < 32; i++)
    //    printf("%d", _binary[i]);

    for (int i = 0; i < 32; i++) {
        if (_binary[i] == 0)
            _binary[i] = '-';
        else if (_binary[i] == 1)
            _binary[i] = '*';
    }
}

int main(void)
{
    unsigned int data;
    char binary[33];
    scanf("%u", &data);

    makeDot(data, binary);
    binary[32] = NULL;

    printf("%s", binary);
    return 0;
}
#endif

#if 0 // 1098 [week11] B반 실습 1 : 문자열 안에 특정 문자 포함 여부
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int  isCharIncluded(char* str, char key) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == key)
            return 1;
    }
    return 0;
}


int main(void)
{
    char str[100];
    char key;

    scanf("%c", &key);
    scanf("%s", str);

    printf("%d", isCharIncluded(str, key));

}

#endif

#if 0 // 1099 [week11] B반 실습 2 : 2진수 값에 따라 문자열로 표현, binary 1의 개수
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int makeDot(unsigned int data, char* _binary){
    int k = 31, count = 0;
    while (k>=0) {
        _binary[k] = data % 2;
        //printf("%d", _binary[k]);
        data /= 2;
        k--;
    }
    for (int i = 0; i < 32; i++) {
        
        if (_binary[i] == 0)
            _binary[i] = '!';
        else if (_binary[i] == 1) {
            _binary[i] = '@';
            count++;
        }
    }
    return count;
}

int main(void)
{
    unsigned int data;
    char binary[33];
    scanf("%u", &data);

    printf("%d\n", makeDot(data, binary));
    binary[32] = NULL;

    printf("%s", binary);
    return 0;
}
#endif
