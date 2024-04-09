#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findingLengthOfArray(char hexaArray[]) {
	int length = 0;
	while(hexaArray[length] != '\0') {
		length++;
	}
	return length;
}

int convertingArrayToNumber(char hexaChar) {
	int newValue = 0;
	switch (hexaChar)
	{
		case 'F':
			newValue = 15;
			break;
		case 'E':
			newValue = 14;
			break;
		case 'D':
			newValue = 13;
			break;
		case 'C':
			newValue = 12;
			break;
		case 'B':
			newValue = 11;
			break;
		case 'A':
			newValue = 10;
			break;
		default:
			break;
	}
	return newValue;
}

int convertingNumberToArray(int hexaValue) {
	char newValue;
	switch (hexaValue)
	{
		case 15:
			newValue = 'F';
			break;
		case 14:
			newValue = 'E';
			break;
		case 13:
			newValue = 'D';
			break;
		case 12:
			newValue = 'C';
			break;
		case 11:
			newValue = 'B';
			break;
		case 10:
			newValue = 'A';
			break;
		default:
			break;
	}
	return (int)newValue;
} 

int convertingNumberToASCII(int numberValue) {
	int asciiValue;
	switch (numberValue)
	{
		case 0:
			asciiValue = 48;
			break;
		case 1:
			asciiValue = 49;
			break;
		case 2:
			asciiValue = 50;
			break;
		case 3:
			asciiValue = 51;
			break;
		case 4:
			asciiValue = 52;
			break;
		case 5:
			asciiValue = 53;
			break;
		case 6:
			asciiValue = 54;
			break;
		case 7:
			asciiValue = 55;
			break;
		case 8:
			asciiValue = 56;
			break;
		case 9:
			asciiValue = 57;
			break;
		default:
			break;
	}
	return asciiValue;
}

int main() {
	char hexaArray1[150];
    char hexaArray2[150];
    char resultArray[170];
    
    printf("\n 1. Hexadecimal degeri giriniz : "); 
    gets(hexaArray1);
    printf("\n 2. Hexadecimal degeri giriniz : ");
    gets(hexaArray2);

	int lengthOfArray1 = findingLengthOfArray(hexaArray1);
	int lengthOfArray2 = findingLengthOfArray(hexaArray2);

	int over = 0, i = 169, hexaValue1 = 0, hexaValue2 = 0, sum = 0;
	while(1) {
		if(lengthOfArray1 > (-1) && 47 < hexaArray1[--lengthOfArray1] && hexaArray1[lengthOfArray1] < 58) {
			hexaValue1 = hexaArray1[lengthOfArray1] - '0';
		}
		else if(lengthOfArray1 > (-1) && 64 < hexaArray1[lengthOfArray1] && hexaArray1[lengthOfArray1] < 71) {
			hexaValue1 = convertingArrayToNumber(hexaArray1[lengthOfArray1]);
		}

		if(lengthOfArray2 > (-1) && 47 < hexaArray2[--lengthOfArray2] && hexaArray2[lengthOfArray2] < 58) {
			hexaValue2 = hexaArray2[lengthOfArray2] - '0';
		}
		else if(lengthOfArray2 > (-1) && 64 < hexaArray2[lengthOfArray2] && hexaArray2[lengthOfArray2] < 71) {
			hexaValue2 = convertingArrayToNumber(hexaArray2[lengthOfArray2]);
		}

		sum = hexaValue1 + hexaValue2 + over;
		over = sum / 16;

		if(sum > 15) {
			sum -= 16;
		}

		if(sum > 9) {
			resultArray[i] = convertingNumberToArray(sum);
		}
		else {
			resultArray[i] = convertingNumberToASCII(sum);
		}
		hexaValue1 = 0;
		hexaValue2 = 0;
		i--;
		if((lengthOfArray1 > lengthOfArray2 && lengthOfArray2 == 0 && over == 1) 
		|| (lengthOfArray2 > lengthOfArray1 && lengthOfArray1 == 0 && over == 1)) {
			continue;
		}
		if(lengthOfArray1 == (0) || lengthOfArray2 == (0)) {
			break;
		}
	}

	if(over == 1) {
		resultArray[i--] = '1';
	}

	if(lengthOfArray1 > lengthOfArray2) {
		while(lengthOfArray1 != 0) {
			resultArray[i--] = hexaArray1[--lengthOfArray1];
		}
	}
	else {
		while(lengthOfArray2 != 0) {
			resultArray[i--] = hexaArray2[--lengthOfArray2];
		}
	}

	printf("\n Sonuc : ");
	while(i != 169) {
		printf("%c", resultArray[++i]);
	}
}