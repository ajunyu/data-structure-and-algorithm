#include <iostream>

using namespace std;

// 递归法
int func(int m, int n)
{
	if (n == 0)
		return m;
	else
	{
		int r = m % n;
		return func(n, r);
	}
}

// 辗转相除法
int gcd(int m, int n)
{
	int r = m % n;
	while (r)
	{
		m = n;
		n = r;
		r = m % n;
	}

	return n;
}

// 尼考曼彻斯法（辗转相减法）
int reduce(int m, int n)
{
	int r = abs(m - n);
	while (r)
	{
		m = n;
		n = r;
		r = abs(m - n);
	}

	return n;
}

int main()
{
	cout << func(16, 15) << endl;
	cout << gcd(9, 12) << endl;
	cout << reduce(10, 15) << endl;
	return 0;
}
