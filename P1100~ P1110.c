#if 0 // 1100 [week11] B반 실습 4 : 문자열에 문자열 포함여부

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



#if 0 // 1101 [week12] A반 실습 3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int** makeArrayDynamic(int** _p, int _size) {
    _p = (int**)malloc(sizeof(int*) * _size);
    for (int i = 0; i < _size; i++)
        _p[i] = (int*)malloc(sizeof(int) * _size);
    return _p;
}
int sumofArray(int** _p, int _size) {
    int sum = 0;
    for (int i = 0; i < _size; i++)
        for (int j = 0; j < _size; j++)
            sum += _p[i][j];
    return sum;
}

int main() {

    int** p = NULL;
    int size, sum = 0;

    scanf("%d", &size); // 정사각 배열 사이즈를 입력받음.

    // [size x size] 크기의 배열 동적할당
    p = makeArrayDynamic(p, size);  // <- 1. 이 함수 구현


    // 배열에 원소 값을 순차적으로 입력
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &p[i][j]);
        }
    }

    // 배열 내에 있는 모든 원소의 합
    sum = sumofArray(p, size);   // <- 2. 이 함수 구현

    printf("%d", sum); // 합 출력

    // 동적할당 free
    for (int i = 0; i < size; i++) free(p[i]);
    free(p);

    return 0;
}
#endif



#if 0 // 1102 [week12] B반 실습 3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int** makeArrayDynamic(int** _p, int _size) {
    _p = (int**)malloc(sizeof(int*) * _size);
    for (int i = 0; i < _size; i++)
    _p[i] = (int*)malloc(sizeof(int) * _size);
    return _p;
}
int countEven(int** _p, int _size) {
    int count = 0;
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++)
            if (_p[i][j] % 2 == 0)
                count++;
    }
    return count;
}

int main() {

    int** p = NULL;
    int size, cnt = 0;

    scanf("%d", &size); // 정사각 배열 사이즈를 입력받음.

    // [size x size] 크기의 배열 동적할당
    p = makeArrayDynamic(p, size); // <- 1. 이 함수 구현


    // 배열에 원소 값을 순차적으로 입력
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &p[i][j]);
        }
    }

    // 배열 내에 있는 짝수인 원소의 개수
    cnt = countEven(p, size); // <- 2. 이 함수 구현

    printf("%d", cnt); // 합 출력

    // 동적할당 free
    for (int i = 0; i < size; i++) free(p[i]);
    free(p);

    return 0;
}

#endif



#if 0 // 1103 [week12] A반 실습 2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// scalarMultiple 함수 구현 ====================
void scalarMultiple(int arr[3][4],int n) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            arr[i][j] *= n;
}



// ===================================


int main() {

    int arr[3][4];
    int n = 0;
    scanf("%d", &n);

    // 입력
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // scalarMultiple 함수 호출 부분 (여기에 작성)==========
    scalarMultiple(arr, n);
    // =====================================

    // 출력
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
#endif



#if 0 // 1104 [week12] B반 실습 2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// makePow 함수 구현 ====================
void makePow(int* arr0,int*arr1,int*arr2, int n) {
    if (n == 0) {
        for (int i = 0; i < 4; i++) {
            if (arr0[i] >= 1)
                arr0[i] = 1;
            else
                arr0[i] = 0;
            if (arr1[i] >= 1)
                arr1[i] = 1;
            else
                arr1[i] = 0;
            if (arr2[i] >= 1)
                arr2[i] = 1;
            else
                arr2[i] = 0;
        }
    }

    int m[4] = { 0 };
    int f[4] = { 0 };
    int o[4] = { 0 };
    for (int i = 0; i < 4; i++) {
            m[i] = arr0[i];
            f[i] = arr1[i];
            o[i] = arr2[i];
    }
    for (int i = 0; i < 4;i++) {
        for (int k = n; k > 1; k--) {
            arr0[i] *= m[i];
            arr1[i] *= f[i];
            arr2[i] *= o[i];
        }
    }
}


// ===================================

int main() {

    int arr[3][4];
    int n = 0;
    scanf("%d", &n);

    // 입력
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // makePow 함수 호출 부분 (여기에 작성)==========
    makePow(arr[0],arr[1],arr[2], n);
    // ==================================

    // 출력
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

#endif



#if 0 // 1105 [week12] A반 실습 4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int cmp(char str[2][100]) {
    int count = 0;
    for (int i = 0; str[0][i] != '\0' && str[1][i] != '\0'; i++) {
        if (str[0][i] == str[1][i])
            count++;
    }
    return count;
}
int main() {

    char str[2][100];
    int cnt = 0; // 같은자리 같은문자 개수

    // 입력
    scanf("%s", str[0]);
    scanf("%s", str[1]);

    // cmp 함수 호출 ====================
    cnt = cmp(str);
    // =============================

    //출력
    printf("%d", cnt);

    return 0;
}

#endif



#if 0 //1106 [week12] B반 실습 4
void swap(char* str1, char* str2) {
    char* buffer[100] = { 0 };
    for (int i = 0; i < 100; i++)
        buffer[i] = str1[i];
    for (int i = 0; i < 100; i++)
        str1[i] = str2[i];
    for (int i = 0; i < 100; i++)
        str2[i] = buffer[i];

}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    char str[2][100];

    // 입력
    scanf("%s", str[0]);
    scanf("%s", str[1]);

    // swap 함수 호출 ====================
    swap(str[0], str[1]);
    // =============================

    //출력
    printf("%s\n%s", str[0], str[1]);

    return 0;
}
#endif



#if 0 // 1107 [week12] A반 실습 5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

    int** p = NULL;
    int** q = NULL;

    int a, b; // 순서대로 행, 열
    scanf("%d %d", &a, &b);

    // 코드 작성 ==============================
    p = (int**)malloc(sizeof(int*) * a);
    for (int i = 0; i < a; i++)
        p[i] = (int*)malloc(sizeof(int) * b);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++)
            scanf("%d", &p[i][j]);
    }
    q = (int**)malloc(sizeof(int*) * b);
    for (int i = 0; i < b; i++)
        q[i] = (int*)malloc(sizeof(int) * a);
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++)
            q[i][j] = p[j][i];
    }




    // ====================================

    // 출력
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            printf("%d ", q[i][j]);
        }
        printf("\n");
    }

    // 동적할당 free
    for (int i = 0; i < a; i++) free(p[i]);
    free(p);
    for (int i = 0; i < b; i++) free(q[i]);
    free(q);

    return 0;
}

#endif



#if 0 // 1108 [week12] B반 실습 5

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

    int p[100];
    int** q = NULL;

    int size; // 배열 p의 사이즈
    int n; // 몇 행으로 만들 것인가

    scanf("%d %d", &size, &n);

    // 여기에 코드 작성 =======================================
    if (size % n != 0) {
        printf("ERROR");
        return 0;
    }
    q = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
        q[i] = (int*)malloc(sizeof(int) * size/n);
    for (int i = 0; i < n; i++)
        for(int j=0; j<size/n; j++)
        scanf("%d", &q[i][j]);



    // ==================================================

    // 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < size / n; j++) {
            printf("%d ", q[i][j]);
        }
        printf("\n");
    }

    // 동적할당 free
    for (int i = 0; i < n; i++) free(q[i]);
    free(q);

    return 0;
}

#endif



#if 0 // 1109 [week12] A반 실습 1


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

makeArrayandInput(char* str[]) {
    for (int i = 0; i < 6; i++)
        str[i] = (char*)malloc(sizeof(char) * 100);
    for (int i = 0; i < 6; i++)
        scanf("%s", str[i]);
}
int main() {

    char* str[6];

    makeArrayandInput(str);

    // 출력
    for (int j = 0; j < 6; j++)
    {
        printf("%s\n", str[j]);
    }

    // 동적할당 free
    for (int i = 0; i < 6; i++) free(str[i]);

    return 0;
}
#endif



#if 0 // 1110 [week12] B반 실습 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void getInputValue(char str[6][100]) {
    for (int i = 0; i < 6; i++)
        scanf("%s", &str[i]);
}

void printValue(char str[6][100]) {
    for (int i = 0; i < 6; i++) {
        for(int j=0; str[i][j]!='\0'; j++)
            printf("%c", str[i][j]);
        printf(" ");
    }
}
int main() {

    char str[6][100];

    getInputValue(str);

    printValue(str);

    return 0;
}

#endif
