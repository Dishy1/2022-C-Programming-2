#define _CRT_SECURE_NO_WARNINGS



#if 0 // 1050 [week05] B반 실습 2 : 배열 인덱스 계산 2


#include <stdio.h>

int sumofEvenandMaxIdx(int arr[], int n) {
	// 이 부분에 코드를 작성하시오. ===========================




	int jj = 0;
	int big = 0;
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			jj += i;
			m = i;
		}
	}

	return jj + m;
	// =============================================
}


int main() {

	int n;
	int arr[100];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("%d", sumofEvenandMaxIdx(arr, n));


	return 0;
}

#endif


#if 0 //1050 error

#include <stdio.h>

int sumofEvenandMaxIdx(int arr[], int n) {
	int sum = 0, max=arr[0], maxindex = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			
			sum += i;
			if (arr[i] > max) {
				maxindex = i;
				max = arr[i];
			}
		}
	}
	//printf("%d %d ", sum, maxindex);
	return sum+maxindex;
}


int main() {

	int n;
	int arr[100];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("%d", sumofEvenandMaxIdx(arr, n));


	return 0;
}

#endif



#if 0 // 1051 [week05] A반 실습 1 : 1차원 배열 ReLU
//arr[10] 내에서 0 이하일 경우 0으로 바꾸어서 출력, 나머지는 그대로 출력
#include <stdio.h>
int main() {

    int arr[10];
    for(int i=0;i<10;i++)
    scanf("%d", &arr[i]);
    // 이 부분에 코드를 작성하시오. ===========================

    for (int j = 0; j < 10; j++) {
        if (arr[j] < 0) {
            arr[j] = 0;
        }
    }





    // ==============================================

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

#endif



#if 0 // 1052 [week05] B반 실습 1 : 1차원 배열 Unit Step

#include <stdio.h>

int main() {

	int arr[10];
	for (int m = 0; m < 10; m++)
		scanf("%d", &arr[m]);

	for (int i = 0; i < 10; i++) {
		if (arr[i] < 0)
			arr[i] = 0;
		else if (arr[i] >= 0)
			arr[i] = 1;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}


#endif




#if 0 // 1053 [week05] A반 실습 3 : 조건에 맞는 문자열 길이 1 (eseStrlen)
//strlen + ese시 str 길이 *10, !혹은 \0일 시 종료

#include <stdio.h>
#include <math.h>

int eseStrlen(char string[]) {
    // 이 부분에 코드를 작성하시오. ==============
    int strlen = 0,ese=0;
    for (int i = 0; i < 100; i++) {
        if (string[i] == 'e')
            if (string[i + 1] == 's')
                if (string[i + 2] == 'e')
                    ese++;
        if (string[i] == '\0'||string[i]=='!')
            break;
        strlen++;
    }
        strlen = strlen * pow(10,ese);


    return strlen;

    // ==================================
}

int main() {
    char arr[100];
    scanf("%s", arr);

    printf("%d", eseStrlen(arr));
}


#endif



#if 0 // 1054 [week05] B반 실습 3 : 조건에 맞는 문자열 길이 2 (eseStrlen)


#include <stdio.h>


int eseStrlen(char string[]) {
	int length = 0, mult = 0;
	for (int i = 0; string[i]!='\0'; i++) {
		if (string[i] == '!')
			break;
		else if (string[i] >= 'A' && string[i] <= 'Z') {
			mult++;
		}
		length++;

	}

	if (mult != 0)
		length = length * mult;
	return length;
}

int main() {
	char arr[100];
	scanf("%s", arr);

	printf("%d", eseStrlen(arr));
}

#endif



#if 0 // 1055 [week05] A반 실습 4 : 2차원 배열 행렬 곱, 1056 [week05] B반 실습 4 : 2차원 배열 행렬 곱

#include <stdio.h>

int main() {
	int a, b, c, d;
	scanf("%d %d", &a, &b);
	int arr1[50][50];
	int arr2[50][50];
	int arr3[50][50];
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			scanf("%d", &arr1[i][j]);
		}
	}
	scanf("%d %d", &c, &d);
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < d; j++) {
			scanf("%d", &arr2[i][j]);
		}
	}

	if (b != c) {
		printf("Error");
		return 0;
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < d; j++) {
			arr3[i][j] = 0;
			for (int k = 0; k < c; k++)
				arr3[i][j] += arr1[i][k] * arr2[k][j];
		}
		

	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < d; j++)
			printf("%d ", arr3[i][j]);
		printf("\n");
	}
}

#endif



#if 0 // 1057 [week05] A반 실습 5 : 문자열 역순 출력 + 조건
#include <stdio.h>

int main() {
	int length = 0;
	char string[100], editstring[100]={0};
	scanf("%s", string);
	for (int m = 0; string[m] != '\0'; m++) {
		length++;
	}
	for (int i = 0; i < length; i++) {
			editstring[i] = string[length-i-1];
			if (editstring[0] >= 'a' && editstring[0] <= 'z')
				editstring[0] -= 32;
	}
	printf("%s", editstring);
}

#endif



#if 0 // 1058 [week05] B반 실습 5 : 문자열 역순 출력 + 조건
#include <stdio.h>

int main() {
	int length = 0;
	char string[100], editstring[100] = { 0 };
	scanf("%s", string);
	for (int m = 0; string[m] != '\0'; m++) {
		length++;

	}
	if (string[0] >= 'a' && editstring[0] <= 'z')
		string[0] -= 32;
	for (int i = 0; i < length; i++) {
		editstring[i] = string[length - i - 1];

	}
	printf("%s", editstring);
}

#endif



#if 0 // 1059 [week05] A반 실습 6 : 해당 bit만 무조건 1로 만들기


#include <stdio.h>

int makeDataOne(unsigned int _data, int _n) {
	unsigned int binary[32] = { 0 }, k = 31, data = _data, value = 0, m = 1;
	while (data) {
		binary[k] = data % 2;
		data = data / 2;
		k--;
	}
	binary[32 - _n] = 1;
	for (int k = 31; k >= 0; k--) {
		value += binary[k] * m;
		m = m * 2;
	}

	return value;



};


int main() {

	unsigned int data;
	int n;

	scanf("%X", &data);
	scanf("%d", &n);

	printf("%X", makeDataOne(data, n));

	return 0;
}

#endif




