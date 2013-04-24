#include <iostream>
using namespace std;

int numk(int n, int k)
{
	int sum = 0;
	while(n){
		n /= k;
		sum += n;
	}
	return sum;
}

int main()
{
	cout << numk(10, 3) << endl;
}
