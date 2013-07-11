#include <cstdio>
#include <cstdlib>
#include <assert.h>
#include <iostream>
#include <time.h>
using namespace std;

struct matrix
{
	int a,b,c,d;
	matrix():a(0), b(1), c(1), d(1){}
};

matrix multiple(matrix x, matrix y)
{
	matrix temp;
	temp.a = x.a * y.a + x.b * y.c;
	temp.b = x.a * y.b + x.b * y.d;
	temp.c = x.c * y.a + x.d * y.c;
	temp.d = x.c * y.b + x.d * y.d;
	return temp;
}

matrix power(matrix x, int n)
{
	if(n == 1)
		return x;
	else if(n % 2 == 0){
		matrix temp = power(x, n / 2);
		return multiple(temp, temp);
	}else{
		matrix temp = power(x, n - 1);
		return multiple(temp, x);
	}
}

int fib1(int n)
{
	if(n == 0 || n == 1)
		return n;
	else
		return fib1(n - 1)+ fib1(n - 2);
}

int fib2(int n)
{
	int i = 0, a = 0, b = 1, temp = 0;
	for(i = 0; i < n; i++){
		temp = b;
		b = a + b;
		a = temp;
	}
	return a;
}

int fib3(int n)
{
	matrix x;
	x = power(x, n - 1);
	return x.d;
}

int main()
{
	clock_t t;
	int n;
	while(cin >> n){
		t = clock();
		printf("fib%d============%d\n", n, fib1(n));
		t = clock() - t;
		printf("---------%fs----------\n", (float)t / CLOCKS_PER_SEC);

		t = clock();
		printf("fib%d============%d\n", n, fib2(n));
		t = clock() - t;
		printf("---------%fs----------\n", (float)t / CLOCKS_PER_SEC);

		t = clock();
		printf("fib%d============%d\n", n, fib3(n));
		t = clock() - t;
		printf("---------%fs----------\n", (float)t / CLOCKS_PER_SEC);
	}
	return 0;
}

