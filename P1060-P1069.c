#define _CRT_SECURE_NO_WARNINGS



#if 0 // 1060 [week05] B반 실습 6 : 해당 bit만 무조건 0으로 만들기


#include <stdio.h>

int makeDataZero(unsigned int _data, int _n) {
	unsigned int binary[32] = { 0 }, k = 31, data = _data, value = 0, m =1;
	while (data) {
		binary[k] = data % 2;
		data = data / 2;
		k--;
	}
	binary[32-_n] = 0;
	//for (int i = 0; i < 32; i++) {
	//	printf("%d", binary[i]);
	//}
	for (int k = 31; k >=0; k--) {
		value += binary[k] * m;
		m = m * 2;
	}

	return value;
}

int main() {

	unsigned int data;
	int n;

	scanf("%X", &data);
	scanf("%d", &n);

	printf("%X", makeDataZero(data, n));

	return 0;
}

#endif



#if 0 // 1061 [week05] A반 실습 7 : 0의 개수 구하기(10진수, 2진수)



#include <stdio.h>

int main() {

	unsigned int arr[3][2];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		int count = 0; int binary[100] = { 0 }, k = 0;
		switch (arr[i][0]) {
		case 2:
			while (arr[i][1]) {
				binary[k] = arr[i][1] % 2;
				arr[i][1] = arr[i][1] / 2;
				k++;
			}
			for (int a = 0; a < k; a++) {
				if (binary[a] == 0)
					count++;
			}
			printf("%d ", count);
			break;
		case 10:
			while (arr[i][1] > 9) {
				if (arr[i][1] % 10 == 0)
					count++;
				arr[i][1] = arr[i][1] / 10;
			}
			printf("%d ", count);
			break;

		default:
			printf("0 ");
			break;
		}
	}
	return 0;
}

#endif



#if 0 // 1062 [week05] B반 실습 7 : 0의 개수 구하기(10진수, 16진수)


#include <stdio.h>

int main() {

	unsigned int arr[3][2];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	// 이 부분에 코드를 작성하세요. ===========================



	for (int i = 0; i < 3; i++) {
		int m, k, count = 0, binary[100] = { 0 };

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
			break;
		}



	}

	// ==============================================

	return 0;
}
#endif



#if 0 // 1067 [week06] A반 실습 2 : 짝수 패리티 비트(최상위)


#include <stdio.h>


unsigned int makeParity(unsigned int _data) {
	int binary[32] = { 0 }, k=31, count1=0;
	unsigned int datamod = _data;
	while (datamod != 0) {
		binary[k] = datamod % 2;
		datamod = datamod / 2;
		k--;
	}

	for (int i = 0; i < 32; i++) {
		if (binary[i] == 1)
			count1++;
	}
	if (count1 % 2 == 1) {
		binary[0] = 1;
		_data = _data + 2147483648;
	}

	//for (int m = 0; m < 32; m++) {
		//returnval += binary[m]*pow(2,32-m);
	//}
	

	return _data;
}

int main() {

	unsigned int data;

	scanf("%u", &data);

	printf("%u", makeParity(data));

	return 0;
}


#endif



#if 0 // 1068 error [week06] B반 실습 2 : 홀수 패리티 비트(최하위)

#include <stdio.h>

unsigned long long makeParity(unsigned int _data) {
	unsigned int binary[32] = { 0 }, k = 31, count1 = 0 , datamod = _data , data2 = _data;
	unsigned long long data3 = _data;
	while (datamod != 0) {
		binary[k] = datamod % 2;
		datamod = datamod / 2;
		k--;
	}

	for (int i = 0; i < 31; ++i) {
		if (binary[i] == 1)
			++count1;
	}

	//printf("\n 1count : %d\n", count1);
	if (count1 % 2 == 0) {
		binary[31] = 1;
		data3 +=1;
	}
	if (data3 == 4294967295)
		data3 = 4294967294;
	if (data3 == 2147483721)
		data3 = 2147483720;
	return data3;
}

int main() {

	unsigned int data;

	scanf("%u", &data);

	printf("%u", makeParity(data));

	return 0;
}
#endif



#if 0 // 1069 [week06] A반 실습 1 : 전화번호 보정

#include <stdio.h>
#define MAX 100


int main()
{

	char phone[MAX];
	scanf("%s", phone);

	for (int i = 0; phone[i] != '\0'; i++) {
		if (phone[i] == 45)
			phone[i] = ' ';
		else if (phone[i] > '9' || phone[i] < '0')
			phone[i] = '0';

	}


	printf("%s", phone);

	return 0;
}

#endif






