#define _CRT_SECURE_NO_WARNINGS



#if 0 // 1070 [week06] B반 실습 1 : 대소문자 바꾸기

#include <stdio.h>

void changeUpDown(char data[]) {
    int count;
    for ( count = 0; data[count] != '\0'; ++count) {

    }
    for (int i = 0; i<count; i++) {
        if (data[i] >= 'a' && data[i] <= 'z')
            data[i] -= 32;
        else if (data[i] >= 'A' && data[i] <= 'Z')
            data[i] +=32;
        else
        {
            data[i] = '*';
        }
    }
}

int main() {

    char data[100];
    scanf("%s", data);

    changeUpDown(data);
    printf("%s", data);

    return 0;
}

#endif



#if 1 // 1071 [week06] A반 실습 4 : 작은 것 부터 쌓아나가면서 오름차순 정렬
#include <stdio.h>
#define SIZE 100

void swap(int *pa, int *pb) {
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}


void printSort(int list[], int n) {
    int min, i,j, com;
    int flag = 0;
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if (list[min] > list[j]) {
                min = j;
                
                flag = 1;
            }
            swap(&list[min], &list[j]);
        }
        if (flag) {
            for (int k = 0; k < n; k++) {
                printf("%d ", list[k]);
                flag = 0;
            }
            printf("\n");
        }
        
    }


}

int main()
{
    int list[SIZE];

    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }

    printSort(list, n);

    return 0;
}


#endif



#if 0 // 1073 [week06] B반 실습 4 :큰 것 부터 쌓아나가면서 내림차순 정렬
#include <stdio.h>
#define SIZE 100
void swap(int* pa, int* pb) {
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}
void printSort(int list[], int n) {
	int  max = list[0], maxnum = 0, m = 0;
	while (m < n - 1) {
		max = list[m], maxnum = m;
		for (int i = m; i < n; i++) {
			if (list[i] > max) {
				max = list[i];
				maxnum = i;
			}
		}
		swap(&list[maxnum], &list[m]);
		m++;
		for (int k = 0; k < n; k++)
			printf("%d ", list[k]);
		printf("\n");
	}
}

int main()
{
	int list[SIZE];

	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &list[i]);
	}

	printSort(list, n);

	return 0;
}

#endif



#if 0 // 1074 [week06] A반 실습 3 : 0의 개수 세기 (2,10,16), 1075 [week06] B반 실습 3 : 0의 개수 세기 (2,10,16)


#include <stdio.h>
#define MAX 100

int main() {

	unsigned int arr[MAX][2];
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		int m,k, count = 0, binary[100] = { 0 };

		switch (arr[i][0]) {
		case 10:
			while (arr[i][1] > 9) {
				if (arr[i][1] % 10 == 0)
					count++;
					arr[i][1] = arr[i][1] / 10;
			}
			printf("%d ", count);
			count = 0;
			break;
		case 2:
			count = 0, k = 0;
			while (arr[i][1]) {
				binary[k] = arr[i][1] % 2;
				arr[i][1] = arr[i][1] / 2;
				k++;
			}
			for (int a = 0; a <k; a++) {
				if (binary[a] == 0)
					count++;
			}
			printf("%d ", count);
			break;
		case 16:
			count = 0;
			while (arr[i][1] > 15) {
				if (arr[i][1] % 16 == 0)
					count++;
				arr[i][1] = arr[i][1] / 16;
			}
			printf("%d ", count);
			break;
		default:
			printf("0 ");
		}
	}

	return 0;
}

#endif



#if 0 // 1077 [중간고사] 5번 : 이메일 보정하기 (@ -> AT)
//String 내에 @이 나온다면 AT로 바꿔서 출력
//AT를 A로 바꾸는 것을 하면 ATT => AT => A로 바뀔 수 있으므로 어려움
#include <stdio.h>

void MIDTERM(char* text) {
	int count = 0;
	int len = 0;
	int j;
	for (int i = 0; text[i] != '\0'; i++)
		len++;



	for (int i = 0; text[i] != '\0'; i++) {
		if (text[i] == '@') {
			count++;
			j = len+count;
			while (j>=i+1) {
				text[j + 1] = text[j];
				j--;
			}
			text[i] = 'A';
			text[i + 1] = 'T';
			
		}
	}
	text[len + count] = '\0';
}

int main()
{
	char text[101];
	scanf("%s", text); // 문자열 입력 받아 저장 (최대 50자)

	MIDTERM(text); // 문자열에 조건에 맞게 조작을 가함

	printf("%s", text); // 변형된 문자열 출력

	return 0;
}
#endif



#if 0 // 1078 [week08] 예비고사 2 : 지그재그로 출력하기
#include <stdio.h>
int main() {
	int array[50][50] = { 0 }, m = 0, k = 1,flag = 0;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		if (!flag) {
			for (int j = 0; j < m; j++) {
				array[i][j] = k;
				k++;
				flag = 1;
			}
		}
		else if (flag) {
			for (int j = m - 1; j >= 0; j--) {
				array[i][j] = k;
				k++;
				flag = 0;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

#endif
