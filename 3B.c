#include <stdio.h>
#include<math.h>
 typedef  struct fraction {
    int numerator;
    int denominator;
};
int find_gcd(int n1,int n2)
{
    int k,g;
    if (n1>n2)
    {
        k=n2;   /* code */
    }
    else
    {
        k=n1;
    }
    for (int  i = 1; i <=k; i++)
    {
        if(n1%i==0&&n2%i==0)
            g=i;
    }
    return g;    
}
float xiaoshu(struct fraction f)
{
    float t;
    t=(float)f.numerator/f.denominator;
    return t;
}
struct fraction reduce_fraction(struct fraction f)
{
    if (f.denominator<0)
    {
     f.denominator=-f.denominator;
     f.numerator=-f.numerator;   
    }
    if (f.numerator==0)
    {
     f.denominator=1;   /* code */
    }
    else
    {
        int gcd=find_gcd(abs(f.numerator),abs(f.denominator));
        f.numerator/=gcd;
        f.denominator/=gcd;
    }
    return f;
}
struct fraction add_fraction(struct fraction f1,struct fraction f2)
{
    int k;
    f1.numerator*=f2.denominator;
    f2.numerator*=f1.denominator;
    k=f1.denominator*f2.denominator;
    struct fraction f={
f1.numerator+f2.numerator,
 k
    };
    return reduce_fraction(f);
}
struct fraction minus_fraction(struct fraction f1,struct fraction f2)
{
    int k;
    f1.numerator*=f2.denominator;
    f2.numerator*=f1.denominator;
    k=f1.denominator*f2.denominator;
    struct fraction f={
f1.numerator-f2.numerator,
 k
    };
    return reduce_fraction(f);
}
struct fraction multiply_fraction(struct fraction f1,struct fraction f2)
{
    int k;
    k=f1.denominator*f2.denominator;
    struct fraction f={
f1.numerator*f2.numerator,k
 
    };
    return reduce_fraction(f);
}
struct fraction divide_fraction(struct fraction f1,struct fraction f2)
{
    struct fraction f={
f1.numerator*f2.denominator,
f1.denominator*f1.numerator
  };
    return reduce_fraction(f);
}
void main()
{
    struct fraction f1,f2,f;
    printf("请选择你要实现的功能：\n");
    printf("    1.加法\n    2.减法\n    3.乘法\n    4.除法\n    5.化简\n    6.转化为浮点数");
    int k;
    scanf("%d",&k);
    struct fraction result;
    if (k!=5&&k!=6)
    {
    printf("请输入分数1（f1），格式为分子/分母，请按照格式输入:\n");
    scanf("%d/%d",&f1.numerator,&f1.denominator);
    printf("请输入分数2（f2），格式为分子/分母，请按照格式输入:\n");
    scanf("%d/%d",&f2.numerator,&f2.denominator);
    switch(k)
    {
    case 1:
    {
        result=add_fraction(f1,f2);
        printf("结果为%d/%d",result.numerator,result.denominator);
        break;
    } 
        case 2:
    {
        result=minus_fraction(f1,f2);
        printf("结果为%d/%d",result.numerator,result.denominator);
        break;
    } 
        case 3:
    {
        result=multiply_fraction(f1,f2);
        printf("结果为%d/%d",result.numerator,result.denominator);
        break;
    }    
     case 4:
    {
        result=divide_fraction(f1,f2);
        printf("结果为%d/%d",result.numerator,result.denominator);
        break;
    } 
   }

 }
 else
 {
     if (k==5)
     {
     printf("请输入分数，格式为分子/分母，请按照格式输入:\n");
    scanf("%d/%d",&f.numerator,&f.denominator);
    result=reduce_fraction(f);
    printf("化简结果为%d/%d：\n",result.numerator,result.denominator);
 }
 if (k==6)
 {
       printf("请输入分数，格式为分子/分母，请按照格式输入:\n");
        scanf("%d/%d",&f.numerator,&f.denominator);
       printf("结果为%f：\n",xiaoshu(f));
 }
 
     }
     
   
 
}
