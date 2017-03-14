#include <stdio.h>
#include <stdbool.h>

/* 个位数是否是5*/
bool Judge_5(int n)
{
	if (n%10 == 5)return true;
	else return false;

}

/*能否被3整除*/
bool Judge_3(int n)
{
	int i = n/3;
	if (i*3 == n)return true;
	else return false;

}


void main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		if (Judge_5(n) && Judge_3(n))
		{
			printf("%d\n", 1);
		}
		else printf("%d\n", 0);
	}
}

