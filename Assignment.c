/*
array[5][5]의 실제 구조는 array[0][0], array[0][1], array[0][2]... array[1][0],array[1][1].....array[4][4]처럼 구성되어있다
또한 int array이기 때문에 상대 주소는 array[0][0]이 1000이라고 가정했을때 array[0][1]은 1004, array[0][2]는 1008 형식으로 볼 수 있다.

여기서 unsigned char* pointer라는 포인터 변수는 0-255라는 값을 가지는 변수의 포인터이다. 즉 4바이트의 array값을 1바이트의 unsigned char에 넣는다는 것이다.
이렇게 되면 당연히 255라는 최댓값을 넘어가기때문에 0으로 돌아가는 오버플로우가 생긴다. 쉽게 보자면 Little Endian 방식을 따르기 때문에 하위 2비트만 가져온다고 볼 수 있다.

왜 통상적인 array[0], array[0][0]형태를 사용하지 않았냐면, 이 []은 결국 연산자라는 것을 배웠기 때문이다. int형태에서는 +4를, char 형태에서는 +1을 해주는 일종의 연산자라면
내가 필요한 값을 가져오기 위해서 연산자 이상의 것이 필요할 것이라 생각하여 for 루프에서 각 array값의 첫번째 값만 받아오는 형태로 프로그램을 짰다.
Overflow가 날 필요도, 이유도 없이 Little Endian 방식대로 잘라오면 된다.



두번째인 각 바이트 마다 순서대로 출력하는 것은 Intel Architecture 로 돌아가는 시스템이기 때문에 Little Endian 방식을 따른다.
즉 int는 0X12345678이라는 데이터가 주워졌을 때, [0X78],[0X56],[0X34],[0X12]형식으로 저장해 놓는다. 이것이 순서대로 출력되려면,
unsigned char 포인터가 data[3],data[2],data[1],data[0] 식으로 순서대로 출력을 해야한다. 아래의 코드는 이를 체계화시켜놓은 것이다.
for문전에 pointer가 array[0]의 주소를 가르키도록 설정해두고, 이를 기준으로 상대주소를 4씩 더하면서 3,2,1,0 형식으로 출력하는 루프를
생성하였다. 만약 이것이 RISC 기반의 시스템이었다면 그냥 data[0] data[1] data[2] data[3]으로 돌려야할 것이다.


*/

#define _CRT_SECURE_NO_WARNINGS
#if 1
#include <stdio.h>
int main() {
	int array[5][5] = { 0X12345678,0X23456789,0X34567890,0X45678901,0X56789012,0X67890123,0X78901234,0X89012345,0X90123456
		,0X012345670,0X12345678,0X23456789,0X34567890,0X45678901,0X56789012,0X67890123,0X78901234,0X89012345,0X90123456,0X90123456,
		0X12345678,0X23456789,0X34567890,0X45678901,0X56789012 }; //랜덤한 16진수 25개를 지정한다
	unsigned char* pointer = array; //array[0][0]의 주소를 포인터에 지정한다.
	printf("** Array without Corrections **\n");
	for (int k = 0; k < 100; k+=4) {
		printf("%u ", *(pointer + k)); //각 array의 가장 작은 바이트를 출력한다. 이상은 오버플로우를 하지 않고 생략한다.
	}

	printf("\n\n** Array with Little Endian Corrections **\n\n");
	for (int m = 0; m < 25; m++) {
		printf("Array Number [%d] : ", m); //array의 번호를 출력
		for (int i = 3; i >= 0; i--)
			printf("%u ", *(pointer + i)); //Little Endian을 Big Endian 형식으로 변환 과정
		printf("\n");
		pointer = pointer + 4; //다음 포인터로 이동하기 위해 4(int형식에 char 포인터이기 때문에 1이 아니라 4를 더한다.)
	}
}
#endif



#if 0

#include <stdio.h>

/*
먼저 swap이 해야할 것을 알아야 한다. swap은 i, j의 주소를 서로 바꾸는 함수임과 동시에 k라는 int array 형태의 정수 배열을
반대로 뒤집어야 한다.

i,j사이의 swap은 i의 포인터를 int*_i로, j의 포인터를 int*_j로 받아와서 temp라는 int 형태에 i의 값(*_i)를 저장한 후 i에
j의 값(*_j)를 대입하고, *_j에는 i의 값인 temp를 대입하여 i,j를 스왑하는 기능을 수행한다.

두번째는 int배열을 뒤집는 것이다. 먼저 -1을 건드리지 않기 위해서 k보다 하나 작은 int array 정수 배열의 값을 temparray로
받아왔다. 그리고 마지막에 for문을 통해 다시 _k로 대입하는 식으로 연산하고자 한다.

이 함수를 설명하자면, 앞의 swap과 같은 형태로 pointer 2와 buffer를 통해 작동한다. temparray [1,2,3,4,5] 5개 중
중간 3을 기점으로 1과 5를, 2와 4를, 3과 3을 바꾼 후 for문 밖으로 나오도록(즉 함수 작동을 종료하도록) 설계하였다.

이후 이 temparray값의 0-3부분을 _k에 대입함으로써 이 함수는 끝이 난다.
*/
void swap(int* _i, int* _j, int* _k) {
	int temp, m=0;
	int buffer = 0;
	int temparray[100] = { 0 };
	temp = *_i; //temp값에 *_i의 값을 넣어둔다.
	*_i = *_j;  //*_i값에 *_j값을 대입한다.
	*_j = temp; //*_j값에 temp,즉 *_i의 값을 대입한다. 1차적인 swap은 여기서 종료된다.

	while (_k[m] != -1)
		++m; //int array의 길이를 구하기 위해 m을 사용한다.

	for (int i = 0; i < m; i++)
		temparray[i] = _k[i]; // _k[5]의 corruption 방지를 위해 temparray에 _k[0-4] 까지 복사한다.

	for (int i = 0; i < m/2; i++) {
		buffer = temparray[i]; //buffer 세기기
		temparray[i] = temparray[m - i-1]; //대칭되는 값 대입
		temparray[m - i-1] = buffer; //temparray에 buffer 대입
	}


	for (int i = 0; i < m; i++)
		_k[i] = temparray[i]; // 따로 산출해낸 temparray값을 _k에 대입한다.

}
int main(void){

	int i = 3, j = 5, k[100] = { 1,2,3,4,5,-1 };
	int m = 0;
	scanf("%d %d", &i, &j); //i와 j값을 받아온다.
	for (int i = 0; i < 100; i++) {
		scanf("%d", &k[i]); //최대 100개의 k array값을 받아온다. -1이 있다면 종료한다.
		if (k[i] == -1)
			break;
	}


	swap(&i,&j,k); // i와 j를 맞바꾸고,  k의 순서를 뒤바꾼다(5,4,3,2,1,-1)

	printf("i : %d  j : %d \n",i,j); // i와 j값의 스왑을 출력
	printf("k : [");
	while (k[m-1] != -1) {
		printf("%d ", k[m]); //k 값을 차례로 출력
		m++;
	}
	printf("]");

}
#endif
