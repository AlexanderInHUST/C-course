#include <stdio.h>

//转换为二进制补码
void DecToBin(int dec,  int* bin)
{
    int i = 0;
    int j;
    int flag;
    flag = (dec>=0)?0:1;
    dec = (dec>=0)?dec:(-dec);
    while(i < 32)
    {
        bin[i++] = dec%2;
        dec = dec/2;
    }
     //负数求补码//
    if(flag == 1)
    {
        j = 0;
        while(bin[j] == 0)j++;
        for(i = j+1 ; i < 32-1 ; i++)
        {
            bin[i] = (bin[i]==0)?1:0;
        }
    }
    bin[31]=flag;
}


//转换为二进制后再进行翻转操作
void RotateBin(int* originBin, int* rotateBin, int p, int n)
{
    int i;
    for(i = 0 ; i < 32 ; i++)
    {
        if(i >= p && i < p+n) rotateBin[i] = (originBin[i]==0)?1:0;
        else rotateBin[i] = originBin[i];
    }
}


//x^((~0)<<(p+1-n) & ((unsigned int)~0)>>(32-p-1)) 或：x^(~0>>(32-n)<<(p+1-n)) 
//异或翻转
int rotate(int x, int p, int n)
{
    return x^((~0)<<(p+1-n) & ((unsigned int)~0)>>(32-p-1));
}

int main()
{
    int x,p,n;
    scanf("%d %d %d", &x, &p, &n);

    int originBin[32];
    int rotateBin[32];
    int i,j;

    DecToBin(x, originBin);
    RotateBin(originBin, rotateBin, p, n);

    // DecToBin(x, originBin);
    // DecToBin(rotate(x, p, n), rotateBin);
 
    for(i = 31 , j = 1; i >= 0 ; i--, j++)
    {
        printf("%d", originBin[i]);
        if(j%8==0 && j != 32) printf(" ");

    }
    printf("\n");
    for(i = 31 , j = 1; i >= 0 ; i--, j++)
    {
        printf("%d", rotateBin[i]);
        if(j%8==0 && j != 32) printf(" "); 
    }
 
    printf("\n");   
    return 0;
}