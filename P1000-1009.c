#if 0 // 1000 [week03] 연습 1 : 함수와, 함수의 인자로서의 변수(add)
#include <stdio.h>

// ===============================================
// 이 부분에 필요한 코드를 작성하시오.



int add(int a, int b){
    return a+b;
}


// ===============================================

int main() {

    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d", add(a, b));

    return 0;
}


#endif


#if 0 // 1001 [week03] 실습 2 : (두자리수) x (두자리수) 의 연산 과정 출력하기

#include <stdio.h>

void printCalc(int _input1, int _input2) {
// 이 부분을 구현하라 =====================
	printf("%d\n",_input1 * (_input2%10));
	printf("%d\n",_input1 * (_input2/10));
	printf("%d\n",_input1 * _input2);
// ========================================
}


int main() {
    int input1, input2;
    scanf("%d %d", &input1, &input2);

    printCalc(input1, input2);

    return 0;
}



#endif 



#if 0 // 1002 [week03] 실습 3 : 10진수를 2진수로 출력하기
#include <stdio.h>
int a[10],i;
void printBinary(unsigned int x) {
	if (x < 128) {
		printf("0");
		if (x < 64) {
			printf("0");
			if (x < 32) {
				printf("0");
				if (x < 16) {
					printf("0");
					if (x < 8) {
						printf("0");
						if (x < 4) {
							printf("0");
							if (x < 2) {
								printf("0");
								if (x < 1) {
									printf("0");
								}
							}
						}
					}
				}
			}
		}
	}

	for (i = 0; x > 0; i++)
	{
		a[i] = x % 2;
		x = x / 2;
	}
	for (i = i - 1; i >= 0; i--)
	{
		printf("%d", a[i]);
	}
}


int main() {
	unsigned int x;
	scanf("%d", &x);
	printBinary(x);
	return 0;
}

#endif



#if 0 // 1003 [week03] 실습 4 : 2진수로 나타낸 표현에서 1의 개수 구하기
int a[20], i;
int countBinaryOne(unsigned int data) {
	int count = 0;
	for (i = 0; data > 0; i++)
	{
		if(data % 2!=0)
			count++;
		data = data / 2;
	}

	return count;
}

int main() {
	unsigned int data;
	scanf("%d", &data);
	printf("%d", countBinaryOne(data));
	return 0;
}
#endif



#if 0 // 1004 [week03] 실습 5 : 비트 값 조작하기
#include <stdio.h>
char k[8], m=0;
void printModifiedData(unsigned int a, int N) {
	for (int i = 0; i <= 7; i++) {
		k[i] = a%10^i;
	}
	while (N != 0) {
		k[7 - N] = 0;
		N--;
	}
	for (int j = 0; j <= 7; j++) {
		printf("%X", k[j]);
	}
}
int main()
{
	unsigned int a = 0X12345678; //예시
	int N = 0;

	scanf("%X", &a); // 16진수 형태의 숫자 입력
	scanf("%d", &N); // 1~4의 숫자

	printModifiedData(a, N);

	return 0;
}
#endif



#if 0 // 1005 [week03] 실습 6 : Table 값을 문자로 출력하기


#include <stdio.h>

void drawBox(unsigned char _data[]) {
	int bin[100]={0,}, k = 0;
	for (int i = 3; i >=0 ; i--) {
		int num = _data[i];
		k = i * 8;
		while (num != 0) {
			bin[k] = num % 2;
			num = num / 2;
			k++;
		}

		}

	for(int m =0; m<25; m+=8){
		for (int j = 7 + m; j >= m; j--) {
			//printf("%d ", bin[j]);
			if (bin[j] == 0)
				printf(" ");
			else if (bin[j] == 1)
				printf("*");
		}
		printf("\n");
}
	
}

int main() {

	unsigned char data[4] = { 0XFF, 0X12, 0X34, 0X01 }; // 예시
	int input = 0;

	for (int i = 0; i < 4; i++)
	{
		scanf("%X", &input);
		data[i] = (char)input;
	}

	drawBox(data);

	return 0;
}
#endif

// 1006 - 1009 부재
