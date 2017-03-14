#include <stdio.h>
#include <malloc.h>
#include <math.h>

const int length = sizeof(int)*8;

/*有符号数转换为机器储存的二进制数（补码形式）*/
void DecToBin(int dec, int* bin)
{
    int i = 0;
    int j;
    int flag;
    flag = (dec>=0)?0:1;
    dec = (dec>=0)?dec:(-dec);
    while(i < length-1)
    {
        bin[i++] = dec%2;
        dec = dec/2;
    }
    //负数求补码
    if(flag == 1)
    {
        j = 0;
        while(bin[j] == 0)j++;
        for(i = j+1 ; i < length-1 ; i++)
        {
            bin[i] = (bin[i]==0)?1:0;
        }
    }

    bin[length-1]=flag;
}

/*循环右移*/
void circle_shift_right(int* bin, int n)
{
    int bin_tmp;
    int i,j;
    n = n%length;
    for(i = 0 ; i < n ; i++)//n次右移
    {
        bin_tmp = bin[0];//低位
        for(j = 0 ; j < length-1 ; j++)//右移
        {
            bin[j] = bin[j+1];
        }
        bin[length-1] = bin_tmp;
    }
}

/* 二进制补码转换为十进制整数*/
int BinToDec(int* bin)
{
    int flag = bin[length-1];
    int i,j;
    int result = 0;
    //负数二进制补码转为原码
    if(flag == 1)
    {
        j = 0;
        while(bin[j] == 0)j++;
        for(i = j+1 ; i < length-1 ; i++)
        {
            bin[i] = (bin[i]==0)?1:0;
        }
    }
    for(i = 0 ; i < length-1 ; i++)
    {  
        result += bin[i]*( pow(2.0, i) );
    }

    return (flag==0)?result:(-result);
}

int main()
{

    int bin[length];
    int x,n;
    scanf("%d %d", &x, &n);
    DecToBin(x, bin);
    // int i;
    // for(i = length-1 ; i >=0 ; i--)
    // {
    //     printf("%d",bin[i]);
    // }
    // printf("\n");
    circle_shift_right(bin, n);
    // for(i = length-1 ; i >=0 ; i--)
    // {
    //     printf("%d",bin[i]);
    // }  
    // printf("\n");

    printf("%d" , BinToDec(bin)); 
    printf("\n");

}