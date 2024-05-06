# Some tips for xcpc contest

## Number range
### The range of different types of variable
|  types   | range | estimation|
|  ----  | ----  | ---- | 
| int  | $-2147483648 \thicksim 2147483647$ | $2^{31} \ 10^9$ |
| unsigned int | $0 \thicksim 4294967295$ | $2^{32} \ 10^9$ |
| long  | $-2147483648 \thicksim 2147483647$ | $2^{31} \ 10^9$ |
| unsigned long | $0 \thicksim 4294967295$ | $2^{32} \ 10^9$ |
| long long  | $-9223372036854775808 \thicksim 9223372036854775807$ | $2^{63} \ 10^{18}$ |
| unsigned long long | $0 \thicksim 18446744073709551615$ | $2^{64} \ 10^{18}$ |
| __int64 | $-9223372036854775808 \thicksim 9223372036854775807$ | $2^{63} \ 10^{18}$ |
| unsigned __int64 | $0 \thicksim 18446744073709551615$ | $2^{64} \ 10^{18}$ |
| __int128 | $−170141183460469231731687303715884105728 \thicksim 170141183460469231731687303715884105727$ | $2^{127} \ 10^{38}$ |
| unsigned __int128 | $0  \thicksim 340282366920938463463374607431768211455$ | $2^{128} \ 10^{38}$ |
| 0x3f3f3f3f | $1061109567$ | $10^9$ |

ps: __int128 is not included in c++98/03/11/14/17/20 and it needs gcc4.6 of above.

### The io of __int64
```
scanf("%I64d",&a);
printf("%I64d",a);
```

### The io of __int128
```
inline __int128 read()
{
    __int128 x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
inline void print(__int128 x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}

```

## Read char string
### read the line
```
cin.getline(s, 20);
//s指存储的数组, 20指可以存储19个字符
```

## IO optimization
### cin/cout optimization
```
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
```
