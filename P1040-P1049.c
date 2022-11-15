#define _CRT_SECURE_NO_WARNINGS



#if 0 // 1040 [week 08] 예비고사 6 : 리틀 엔디안 - 빅 엔디안 조작하기
#include <stdio.h>

int main() {
	unsigned int a, mod=0;
	unsigned int arr[8] = { 0 };
	scanf("%u", &a);


	//unsigned int mult = 1;
	for (int i = 0; i < 4; i++) {
		arr[i] = a % 256;
		a /= 256;
	}




	//for (int j = 0; j < 4; j++) {
	//printf("%d ", arr[j]);
	//}


	mod = arr[0] * 16777216 + arr[1] * 65536 + arr[2]*256 + arr[3];




	printf("%u", mod);
}
#endif



//1041-1046 부재



#if 0 // 1047 [week03] 연습 2 : 입출력, 조건/반복문의 활용
#include <stdio.h>
int main(){
	int n=0;
	scanf("%d",&n);
	if(n<0)
		printf("negative");
	else{
		for(int i=0;i<=n;i++){
			printf("%d ",i);
		}
	}
}
#endif



#if 0 // 1048 [week03] 실습 1 : 함수와, 함수의 인자로서의 변수(sub)


#include <stdio.h>


// ===============================================
// 이 부분에 필요한 코드를 작성하시오.
int sub(int a, int b){
	return a-b;
}


// ===============================================


int main() {


    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", sub(a, b));


    return 0;
}


#endif



#if 0 // 1049 [week05] A반 실습 2 : 배열 인덱스 계산 2

#include <stdio.h>
#include <stdlib.h>

int diffMaxMin(int arr[], int n) {
	int min = arr[0], minindex = 0, maxindex = 0, max = arr[0];

	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
			minindex = i;
		}
		if (arr[i] > max) {
			max = arr[i];
			maxindex = i;
		}
	}
	return abs(maxindex - minindex);
}


int main() {

	int n;
	int arr[100];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("%d", diffMaxMin(arr, n));
	return 0;


}
#endif



#if 0 // 1049 [week05] A반 실습 2 : 배열 인덱스 계산 2
//array 내 최대/최소값 찾아 차 구하기
#include <stdio.h>
#include <stdlib.h>

int diffMaxMin(int arr[], int n) {
    // 이 부분에 코드를 작성하시오. ===========================

    int max = 0;
    int min = arr[0];
    for (int i = n; i > 0; i--) {
        if (max(arr[i], arr[i - 1])==0)
            max = arr[i];
    }
    for (int j = n; j > 0; j--) {
        if (min(arr[j],arr[j-1]))
            min = arr[j];
    }


    return (max-min);
    // ========================================================
}


int main(){

    int n;
    int arr[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d", diffMaxMin(arr, n));
    return 0;
}


#endif
