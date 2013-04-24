#include <iostream>
#include <stdio.h>
using namespace std;

int count1(unsigned char v)
{
	int num = 0;
	while(v){
		num += v & 0x01;
		v >>= 1;
	}
	return num;
}

int count2(unsigned char v)
{
	int num = 0;
	while(v){
		v &= (v-1);
		printf("%x\n", v);
		num++;
	}
	return num;
}

int main()
{
	cout << count2(0x87) << endl;
	return 0;
}
