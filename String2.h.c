#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include <string.h>


int strlen2(char* _str) {
	int length = 0;
	while (_str[length] != '\0') {
		length++;
	}

	return length;
}

char* strcpy2(char* _str1, char* _str2) {
	int k = 0;
	while (_str2[k] != '\0') {
		_str1[k] = _str2[k];
		k++;
	}
	_str1[k] = '\0';
	return _str1;
}

char* strncpy2(char* _str1, char* _str2, int m) {
	int k = 0;
	while (k < m) {
		_str1[k] = _str2[k];
		k++;
	}
	return _str1;
}
char* strchr2(char* _str1, int m) {
	for (int i = 0; i < sizeof(_str1); i++) {
		if (_str1[i] == m)
			return &_str1[i];
	}
	return 0;
}

char* strrchr2(char* _str1, int m) {
	for (int i = sizeof(_str1) - 1; i >= 0; i--) {
		if (_str1[i] == m)
			return &_str1[i];
	}
	return 0;
}
int* strstr2(char* _str1, char* _str2) {
	int* ptr = 0;
	int k = 0;
	for (int i = 0; i < sizeof(_str1); i++) {
		if (_str1[i] == _str2[0]) {
			
			while (_str2[k] != '\0') {
				if (_str1[i + k] != _str2[k])
					break;
				ptr = &_str1[i];
				k++;
			}
			
		}
	}
	return ptr;
}

char* strcat2(char* _str1, char* _str2) {
	int length = 0;
	while (_str1[length] != '\0') {
		length++;
	}
	for (int i = 0; _str2[i]!= '\0'; i++) {
		_str1[length + 1 + i] = _str2[i];
	}
	return _str1;
}

char* strncat2(char* _str1, char* _str2, int n) {
	int length = 0;
	while (_str1[length] != '\0')
		length++;

	for (int i = 0; i < n; i++) {
		_str1[length + i] = _str2[i];
	}
	return _str1;
}

int strcmp2(char* _str1, char* _str2) {
	int length1 = 0, length2 = 0;
	while (_str1[length1] != '\0')
		length1++;
	while (_str2[length2] != '\0')
		length2++;
	if (length1 > length2)
		return -1;
	else if (length1 == length2)
		return 0;
	else if (length1 < length2)
		return 1;
}
int strspn2(char* _str1, char* _str2) {
	int count = 0;
	for (int i = 0; _str1[i] != '\0'; i++) {
		if (_str1[i] == _str2[i])
			count++;
	}
	return count;
}
int strcspn2(char* _str1, char* _str2) {
	for (int i = 0; _str1[i] != '\0'; i++) {
		for (int j = 0; _str2[j] != '\0'; j++) {
			if (_str2[j] == _str1[i])
				return i;
		}
	}
	return 0;
}

char* strpbrk2(char* _str1, char* _str2) {
	for (int i = 0; _str1[i] != 0; i++) {
		for (int j = 0; _str2[j] != 0; j++) {
			if (_str1[i] == _str2[j])
				return &_str2[j];
		}
	}

	return NULL;
}



int main() {
	char string1[100] ,string2[100], dest1[100], dest2[100],m;
	int num = 0;
	char s = " ";
	char* token;
	scanf("%s %s %d %c",string1,string2, &num, &m);

	printf("STRLEN : %d\t STRLEN2 : %d\n", strlen(string1), strlen2(string1));
	printf("STRSTR : %p\t STRSTR2 : %p\n", strstr(string1, string2),strstr2(string1, string2));
	
	printf("STRCPY : %s\t STRCPY2 : %s\n", strcpy(dest1, string1), strcpy2(dest2, string1));
	printf("STRNCPY : %s\t STRNCPY2 : %s\n", strncpy(dest1, string1,num), strncpy2(dest2, string1,num));
	printf("STRCHR : %p\t STRCHR2 : %p\n", strchr(string1, m), strchr2(string1, m));
	printf("STRRCHR : %p\t STRRCHR2 : %p\n", strrchr(string1, string2), strrchr2(string1, string2));
	printf("STRCMP : %d\t STRCMP2 : %d\n", strcmp(string1, string2), strcmp2(string1, string2));
	printf("STRSPN : %d\t STRSPN2 : %d\n", strspn(string1, string2), strspn2(string1, string2));
	printf("STRCSPN : %d\t STRCSPN2 : %d\n", strcspn(string1, string2), strcspn(string1, string2));
	printf("STRPBRK : %c\t STRPBRK2 : %c\n", *strpbrk(string1, string2), *strpbrk2(string1, string2));
	printf("STRCAT : %s\t STRCAT2 : %s\n", strcat(string1, string2), strcat2(string1, string2));
	printf("STRNCAT : %s\t STRNCAT2 : %s\n", strncat(string1, string2, num), strncat2(string1, string2, num));

}
