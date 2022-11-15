#define _CRT_SECURE_NO_WARNINGS



#if 0 // 1039 [week03] 실습 7 : MBTI 결과 출력하기
#include <stdio.h>
void printMBTI(unsigned char _data) {
    int binary[8] = { 0, };
    int k = 7;
    while (_data > 0) {
        binary[k] = _data % 2;
        _data = _data / 2;
        k--;
    }
    if (binary[4] == 0)
        printf("E");
    else if (binary[4])
        printf("I");
    if (binary[5] == 0)
        printf("S");
    else if (binary[5])
        printf("N");
    if (binary[6] == 0)
        printf("T");
    else if (binary[6])
        printf("F");
    if (binary[7] == 0)
        printf("J");
    else if (binary[7])
        printf("P");
    //for(int i=0;i<=7;i++)
    //printf("\n%d", binary[i]);
}


int main()
{

    int input;
    unsigned char data;

    scanf("%d", &input);
    data = (unsigned char)input;
    printMBTI(data);
    //printf("%d", data);
    return 0;
}

for (int i = 0; i < 4; i++) {
    switch (_data[i]) {
    case '0':
        newdata[i] = 0000;
        break;
    case '1':
        newdata[i] = 0001;
        break;
    case '2':
        newdata[i] = 0010;
        break;
    case '3':
        newdata[i] = 0011;
        break;
    case '4':
        newdata[i] = 0100;
        break;
    case '5':
        newdata[i] = 0101;
        break;
    case '6':
        newdata[i] = 0110;
        break;
    case '7':
        newdata[i] = 0111;
        break;
    case '8':
        newdata[i] = 1000;
        break;
    case '9':
        newdata[i] = 1001;
        break;
    case 'A':
        newdata[i] = 1010;
        break;
    case 'B':
        newdata[i] = 1011;
        break;
    case 'C':
        newdata[i] = 1100;
        break;
    case 'D':
        newdata[i] = 1101;
        break;
    case 'E':
        newdata[i] = 1110;
        break;
    case 'F':
        newdata[i] = 1111;
        break;
    }

#endif
