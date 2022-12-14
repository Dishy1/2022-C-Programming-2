#define _CRT_SECURE_NO_WARNINGS



#if 0 // 1080 [중간고사] 1번 : Leaky ReLU
//Leaky ReLU 인공지능 함수를 만듦. lf와 .4lf 사용을 주의하자
#include <stdio.h>
int main() {
	double arr[10] = { 0 };

	for (int i = 0; i < 10; i++)
		scanf("%lf", &arr[i]);

	for (int i = 0; i < 10; i++) {
		if (arr[i] < 0)
			arr[i] = arr[i] * 0.01;
	}
	for (int j = 0; j < 10; j++)
		printf("%.4f ", arr[j]);
}
#endif 



#if 0 // 1081 주소체계 테스트용
#include <stdio.h>

int main(){
printf("1234");
}
#endif



#if 0 // 1082 [중간고사] 3번 : 여러 bit 를 0으로 만들기
//Unsigned Int 형태의 16진수 숫자를 받아와 0으로 만들 하위 비트의 개수 n을 받아 0으로 바꾸어 16진수로 출력

#include <stdio.h>

int main() {
	unsigned int data;
	int num = 0;
	int arr[100] = { 0 };
	int bin[32] = { 0 };
	int k = 31;
	int count = 1;
	int no;
	unsigned int data2 = 0;
	scanf("%x", &data);
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);
	//scanf, good;



	while (data > 0) {
		bin[k] = data % 2;
		data /= 2;
		k--;
	}
	//hex to bin good;


	
		for(int j =0; j< num; j++){
			no = arr[j]-1;
				
			bin[31 - no] = 0;
		}

		//for (int i = 0; i < 32; i++)
		//printf("%d", bin[i]);









	for (int k = 31; k >= 0; k--) {
		data2 += bin[k] * count;
		count *= 2;
	}

	printf("%X", data2);


	//bin to hex, good.
}
#endif



#if 0 // 1083 [week08] 예비고사 1 : 문자열에서 특정 문자 개수 구하기
#include <stdio.h>
int main() {
	char string[100];
	int count = 0;

	scanf("%s", string);

	for (int i = 0; string[i] != '\0'; i++) {
		if (string[i] == '!')
			count++;
	}
	printf("%d", count);
}

#endif



#if 0 // 1084 [week08] 예비고사 3 : 문자열 역순 + 영문 대소문자 바꾸기
#include <stdio.h>

int main() {
	char string[100], rev[100]={0};
	int count = 0;
	scanf("%s", string);
	for (int i = 0; string[i] != '\0'; i++)
		count++;

	for (int i = 0; i < count; i++) {
		if (string[i] >= 'A' && string[i] <= 'Z') {
			string[i] += 32;
		}
		else if (string[i] >= 'a' && string[i] <= 'z') {
			string[i] -= 32;
		}
	}
	//printf("%s", string);
	for (int i = 0; i < count; i++) {
			rev[i] = string[count-i-1];
	}

	printf("%s", rev);
}

#endif 



#if 0 // 1085 [중간고사] 4번 : zero padding
//배열의 가로, 세로, 패딩할 개수를 받고 이 를 0으로 Padding 하여 출력
//Malloc을 사용하여 동적 메모리로 바꾸는 방법 찾아보기
#include <stdio.h>
int main() {
	int array[100][100] = { 0 };
	int newarray[100][100] = { 0 };
	int x, y, n;
	int zero = 0;
	scanf("%d", &n);
	scanf("%d %d", &x, &y);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			scanf("%d", &array[i][j]);
		}
	}

	for (int i = n; i < x + n; i++) {
		for (int j = n; j < y + n; j++) {
			newarray[i][j] = array[i - n][j - n];
		}
	}



	for (int i = 0; i < x + n * 2; i++) {
		for (int j = 0; j < y + n * 2; j++)
			printf("%d ", newarray[i][j]);
		printf("\n");
	}
}
#endif



#if 0 // 1086 [week08] 예비고사 5 : 알파벳 개수 카운트
#include <stdio.h>

int main() {
	char string[100];
	int arr[26] = { 0 };
	scanf("%s", string);
	for (int i = 0; string[i] != '\0'; i++) {
		int m = string[i] - 'a' ;
		arr[m]++;
	}

	for (int j = 0; j < 26; j++) {
		printf("%d ", arr[j]);
	}
}
#endif



#if 0 // 1087 [중간고사] 2번 : 대소문자 구분없이 알파벳 카운트
//스트링을 받아 나온 알파벳의 개수를 대소문자 구분 없이 출력
//함수로 받거나 2차원 배열, 혹은 복잡한 배열에 출력하는 것으로 재탕 가능
#include <stdio.h>
int main() {
	int count[26] = { 0 };
	char string[100];

	scanf("%s", string);

	for (int k = 0; string[k] != '\0'; k++) {
		if (string[k] <= 'Z' && string[k] >= 'A')
			count[string[k] - 65]++;
		else if (string[k] >= 'a' && string[k] <= 'z')
			count[string[k] - 97]++;
	}


	for (int i = 0; i < 26; i++)
		printf("%d ", count[i]);
}



#endif



#if 0 // 1088 [중간고사] 6번 : 각 바이트 별 parity bit
unsigned int 16진수 하나를 받아와 1바이트 내의 1의 개수가 홀수라면 첫번째 바이트를 1, 짝수라면 0으로 만드는 패리티 비트
//1바이트의 수를 바꾸는 것은 있었으나 4바이트의 첫번째 숫자를 바꾸는 형태는 처음.


#include <stdio.h>

unsigned int MIDTERM(unsigned int _data) {
	unsigned int data2 = 0;
	int count = 1;
	int bin[32] = { 0 };
	int k = 31;
	int count1[4] = { 0 };
	while (_data > 0) {
		bin[k] = _data % 2;
		_data /= 2;
		k--;
	}

	for (int i = 0; i < 4; i++) {
		for (int m = i * 8+1; m < i * 8 + 8; m++) {
			if (bin[m])
				count1[i]++;
		}
		if (count1[i] % 2 == 1)
			bin[i * 8] = 1;
		else if (count1[i] % 2 == 0)
			bin[i * 8] = 0;
	}

	for (int k = 31; k >= 0; k--) {
		data2 += bin[k] * count;
		count *= 2;
	}
	return data2;
}

int main() {

	unsigned int data;

	scanf("%X", &data);

	printf("%X", MIDTERM(data));

	return 0;
}
#endif



#if 0 // 1089 부재

#endif

