<font size = 4 face = "黑体">


#### BC2

<img src = "https://img-blog.csdnimg.cn/20201121182134792.png">

找规律通过修改宏定义的常量LINE的值可以打印不同量级的V

```c
#include <stdio.h>
#define LINE 3
int main()
{
	int space_num = 1;
	for (int i = 0; i < LINE-2; ++i)
		space_num += 2;
	for (int i = 0; i < LINE; ++i) {
		for (int j = 0; j < i; ++j)
			printf(" ");
		printf("v");
		for (int j = 0; j < space_num; ++j)
			printf(" ");
		space_num -= 2;
		if(i != LINE -1)
			printf("v");
		printf("\n");
	}
	return 0;
}
```


<img src = "https://img-blog.csdnimg.cn/20201121182310467.png">

<img src = "https://img-blog.csdnimg.cn/20201121182325884.png">

<img src = "https://img-blog.csdnimg.cn/20201121182357777.png">


#### BC3有容乃大


![在这里插入图片描述](https://img-blog.csdnimg.cn/20201117122208395.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODA4NzAw,size_16,color_FFFFFF,t_70#pic_center)

暴力美学：

```c
#include <stdio.h>
int main()
{
    printf("The size of short is %d bytes.\n", sizeof(short));
    printf("The size of int is %d bytes.\n", sizeof(int));
    printf("The size of long is %d bytes.\n", sizeof(long));
    printf("The size of long long is %d bytes.\n", sizeof(long long));
    return 0;
}
```


<a id="BC6"></a>





#### BC6小飞机



![在这里插入图片描述](https://img-blog.csdnimg.cn/20201117121055101.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODA4NzAw,size_16,color_FFFFFF,t_70#pic_center)

暴力美学：

```c
#include <stdio.h>
int main()
{
    printf("     **     \n");
    printf("     **     \n");
    printf("************\n");
    printf("************\n");
    printf("    *  *    \n");
    printf("    *  *    \n");
    return 0;
}
```
函数指针数组代码方式：

```c
#include <stdio.h>
void func1(){
    printf("     **     \n");
}
void func2(){
    printf("************\n");
}
void func3(){
    printf("    *  *    \n");
}
int main()
{
    void (*p[3])() = {func1, func2, func3};
    for(int i=0; i<3; ++i){
        p[i]();
        p[i]();
    }
    return 0;
}
```


#### BC7缩短二进制

<img src="https://img-blog.csdnimg.cn/20201121183701775.png">

考printf的format

```c
#include <stdio.h>
int main() {
	printf("%#o %#0X\n", 1234, 1234);
	return 0;
}
```


#### BC8


<img src = "https://img-blog.csdnimg.cn/20201121164100795.png">


```c
#include <stdio.h>
int Hex2decimal(char* str) {
	int sum = 0;
	int num = 0;
	char* tmp = str;
	while (*tmp != '\0') {
		num++;
		tmp++;
	}
	int index = 1;
	for (int i = num - 1; i>=0; --i) {
		sum += index * (str[i] - 'A' + 10);
		index *= 16;
	}
	return sum;
}
int main() {
	char hex[8] = "ABCDEF";
	printf("%15d", Hex2decimal(hex));
	return 0;
}
```

#### BC9

<img src="https://img-blog.csdnimg.cn/2020112118402299.png">

考printf的返回值

```c
#include <stdio.h>
int main() {
	int x = printf("Hello world!");
    printf("\n");
	printf("%d\n", x);
	return 0;
}
```

#### BC11学生基本信息输入输出


<img src = "https://img-blog.csdnimg.cn/2020112118413524.png">

```c
#include <stdio.h>
int main() {
	long int No;
	float ch = 0, ma = 0, en = 0;
	scanf("%ld;%f,%f,%f", &No, &ch, &ma, &en);
	printf("The each subject score of  No. %ld is %.2f, %.2f, %.2f.\n", No, ch, ma, en);
	return 0;
}
```


#### BC12字符金字塔

<img src = "https://img-blog.csdnimg.cn/20201121185433796.png">

```c
#include <stdio.h>

int main(){
    char c = 0;
    scanf("%c", &c);
    for(int i=1; i<=5; ++i){
        for(int j=0; j<5-i; ++j)
            printf(" ");
        for(int j=0; j<i; ++j){
            if(j == i-1)
                printf("%c", c);
            else
                printf("%c ", c);
        }
        printf("\n");
    }
    return 0;
}
```


#### BC13ASCII码

<img src = "https://img-blog.csdnimg.cn/2020112119052392.png">

```c
#include <stdio.h>
int main(){
    char arrChar[] = {73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116 , 33, 0};
    printf("%s", arrChar);
    return 0;
}
```

#### BC14出生日期输入输出

<img src = "https://img-blog.csdnimg.cn/20201121192155711.png">


```c
#include <string.h>
#include <stdio.h>
int main() {
    char year[5] = { 0 };
    char month[3] = { 0 };
    char date[3] = { 0 };
    char Date[9] = { 0 };
    scanf("%s", Date);
    strncpy(year, Date, 4);
    strncpy(month, Date + 4, 2);
    strncpy(date, Date + 6, 2);
    printf("year=%s\nmonth=%s\ndate=%s\n", year, month, date);
    return 0;
}
```

####  BC15按照格式输入并交换输出

<img src = "https://img-blog.csdnimg.cn/20201122113021660.png">

交换两个数的值有两种情况，借助中间变量和不借助中间变量


1. 借助中间变量

```c
#include <stdio.h>
int main(){
    int a = 0, b = 0;
    scanf("a=%d,b=%d", &a, &b);
    int tmp = a;
    a = b;
    b = tmp;
    printf("a=%d,b=%d", a, b);
    return 0;
}
```



2. 不借助中间变量：使用异或

```c
#include <stdio.h>
int main(){
    int a = 0, b = 0;
    scanf("a=%d,b=%d", &a, &b);
    a = a^b;
    b = a^b;
    a = a^b;
    printf("a=%d,b=%d", a, b);
    return 0;
}
```





#### BC16字符转ASCII码

<img src = "https://img-blog.csdnimg.cn/20201122113638361.png">

```c
#include <stdio.h>
int main(){
    char c = getchar();
    printf("%d\n", c);
    return 0;
}
```

#### BC17计算表达式的值

<img src = "https://img-blog.csdnimg.cn/20201122113857938.png">

```c
#include <stdio.h>
int main(){
    int a = 40, c = 212;
    printf("%d\n", (-8+22)*a-10+c/2);
    return 0;
}
```

#### BC18计算带余除法

<img src = "https://img-blog.csdnimg.cn/2020112211411797.png">

考除法运算符和取模用算符

```c
#include <stdio.h>
int main(){
    int dividend = 0,divisor = 0;
    scanf("%d %d", &dividend, &divisor);
    printf("%d %d\n", dividend/divisor, dividend%divisor);
    return 0;
}
```

#### BC19反向输出一个四位数

<img src = "https://img-blog.csdnimg.cn/20201122114537877.png">

每次拿出个位数输出并除10

```c
#include <stdio.h>
int main(){
    int num = 0;
    scanf("%d", &num);
    while(num >0){
        printf("%d", num%10);
        num /=10;
    }
    return 0;
}
```

#### BC21浮点数的个位数字

<img src = "https://img-blog.csdnimg.cn/20201122115723766.png">

使用float可以通过，但是使用double通不过

强制类型转换的优先级大于取模%运算符优先级

```c
#include <stdio.h>
int main(){
    float f = 0;
    scanf("%f", &f);
    printf("%d", (int)f%10);
    return 0;
}
```

#### BC22你能活多少秒

<img src = "https://img-blog.csdnimg.cn/20201122115913875.png">

后台数据最大给年龄200，因此要使用long int来存放秒数结果，int只能通过80%测试用例

```c
#include <stdio.h>
#define OneYear 31560000
int main(){
    long int age = 0;
    scanf("%d", &age);
    printf("%ld", age*OneYear);
    return 0;
}
```

#### BC23时间转换

<img src = "https://img-blog.csdnimg.cn/20201122120329717.png">



```c
#include <stdio.h>
int main(){
    int n = 0;
    scanf("%d", &n);
    printf("%d %d %d", n/3600, (n%3600)/60, (n%3600)%60);
    return 0;
}
```

#### BC25计算体重指数

<img src = "https://img-blog.csdnimg.cn/20201122120811388.png">

BMI计算方法是：体重（kg）÷身高（m）的平方

```c
#include <stdio.h>
#include <math.h>
int main(){
    int weight = 0, height = 0;
    scanf("%d %d", &weight, &height);
    printf("%.2f", weight/pow((double)height/100, 2));
    return 0;
}
```

#### BC26计算三角形的周长和面积

<img src = "https://img-blog.csdnimg.cn/20201122121654190.png">

已知三角形的三边,应用海伦公式求面积
海伦公式：

S=√[p(p-a)(p-b)(p-c)]
p为半周长：　　p=(a+b+c)/2
a,b,c为三角形的三条边

```c
#include <stdio.h>
#include <math.h>
int main(){
    float a = 0, b = 0, c = 0;
    scanf("%f %f %f", &a, &b, &c);
    float p = (a+b+c)/2;
    printf("circumference=%.2f area=%.2f", a+b+c, sqrt(p*(p-a)*(p-b)*(p-c)));
    return 0;
}
```

#### BC27计算球体的体积

<img src = "https://img-blog.csdnimg.cn/20201122122305472.png">

```c
//3.0
#include <stdio.h>
#include <math.h>
#define pi 3.1415926
int main() {
    float r = 0;
    scanf("%f", &r);
    printf("%.3f", 4.0 / 3.0 * pi * pow(r, 3));
    return 0;
}
```

#### BC28大小写转换

<img src = "https://img-blog.csdnimg.cn/2020112212324055.png">

```c
#include <stdio.h>
int main() {
    char c = 0;
    while ((c = getchar())!=EOF) {
        getchar();
        printf("%c\n", c + 'a' - 'A'); //97-65
    }
    return 0;
}
```

改成下面的比较好，不然会打印'\n'+32的字符

```c
#include <stdio.h>
int main() {
    char c = 0;
    while ((c = getchar())!=EOF) {
        if (c == '\n')
            break;
        getchar();
        printf("%c\n", c + 'a' - 'A'); //97-65
    }
    return 0;
}
```



使用tolower函数

```c
#include <stdio.h>
#include <ctype.h>
int main()
{
    char ch;
    while (scanf("%c", &ch) == 1)
    {
        if (ch == '\n')
		    break;
        getchar();
        printf("%c\n", tolower(ch));
    }
    return 0;
}
```

可以不用加if (ch == '\n')break;因为tolower只会对26个英文字母转换如下：

```c
#include <stdio.h>
#include <ctype.h>
int main()
{
    char ch;
    while (scanf("%c", &ch) == 1)
    {
        getchar();
        printf("%c\n", tolower(ch));
    }
    return 0;
}
```



#### BC29二的n次方计算

<img src = "https://img-blog.csdnimg.cn/20201122130901613.png">

```c
#include <stdio.h>
#include <math.h>
int main(){
    int n = 0;
    while(scanf("%d", &n)== 1){
        printf("%d\n", (int)pow(2.0, (double)n));
    }
    return 0;
}
```

####  BC30KiKi和酸奶

<img src = "https://img-blog.csdnimg.cn/20201122131614133.png">

```c
#include <stdio.h>
#include <math.h>
int main(){
    int n = 0, h = 0, m = 0;
    while(scanf("%d %d %d", &n, &h, &m) == 3){
        if(m%h == 0)
            printf("%d\n", n-m/h);
        else
            printf("%d\n", n-m/h-1);
    }
    return 0;
}
```

#### BC31发布信息

<img src = "https://img-blog.csdnimg.cn/20201122132207766.png">

```c
#include <stdio.h>
int main(){
    printf("I lost my cellphone!");
    return 0;
}
```

####  BC32输出学生信息

<img src = "https://img-blog.csdnimg.cn/20201122132422822.png">

```c
#include <stdio.h>
int main(){
    printf("%-8s%-7s%-s\n", "Name", "Age", "Gender");
    printf("---------------------\n");
    printf("%-8s%-7s%-s", "Jack", "18", "man");
    return 0;
}
```

#### BC33计算平均成绩

<img src = "https://img-blog.csdnimg.cn/2020112213360854.png">

```c
#include <stdio.h>
int main(){
    int arrInt[5];
    int sum = 0;
    for(int i=0; i<5; ++i){
        scanf("%d", arrInt+i);
        sum += arrInt[i];
    }
    printf("%.1f", sum/5.0);
    return 0;
}
```

#### BC34进制A+B

<img src = "https://img-blog.csdnimg.cn/20201122134106287.png">

```c
#include <stdio.h>
int main() {
    int a = 0, b = 0;
    scanf("0x%x 0%o",&a,&b);
    printf("%d", a+b);
    return 0;
}
```

#### BC35判断字母

<img src = "https://img-blog.csdnimg.cn/20201122134325112.png">


```c
#include <stdio.h>
int main() {
    char ch = 0;
    while ((ch = getchar()) != EOF) {
        if(ch == '\n')
            break;
        getchar(); //吸收回车
        if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
```

不加if(ch == '\n')break;回车符也会被判断，并且程序不会停止

```c
#include <stdio.h>
int main() {
    char ch = 0;
    while ((ch = getchar()) != EOF) {
        getchar(); //吸收回车
        if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
```

#### BC37网购

<img src = "https://img-blog.csdnimg.cn/20201122140118697.png">

```c
#include <stdio.h>
int main() {
    float price = 0;
    int month = 0;
    int date = 0;
    int flag = 0;
    scanf("%f %d %d %d", &price, &month, &date, &flag);
    if (month == 11 && date == 11) {
        if (flag == 1)
            price = (price * 0.7 - 50)>0?price * 0.7 - 50:0;
        else
            price = price * 0.7;
    }
    if (month == 12 && date == 12) {
        if (flag == 1)
            price = (price * 0.8 - 50)>0?price * 0.8 - 50:0;
        else
            price = price * 0.8;
    }
    printf("%.2f\n", price);
    return 0;
}
```

```c
#include <stdio.h>
int main() {
    float price = 0;
    short month = 0;
    short date = 0;
    short flag = 0;
    scanf("%f %hd %hd %hd", &price, &month, &date, &flag);
    if (month == 11 && date == 11) {
        if (flag == 1)
            price = (price * 0.7 - 50)>0?price * 0.7 - 50:0;
        else
            price = price * 0.7;
    }
    if (month == 12 && date == 12) {
        if (flag == 1)
            price = (price * 0.8 - 50)>0?price * 0.8 - 50:0;
        else
            price = price * 0.8;
    }
    printf("%.2f\n", price);
    return 0;
}
```

```c
#include <stdio.h>
int main() {
    float price = 0;
    char month = 0;
    char date = 0;
    char flag = 0;
    int tmp = 0;
    scanf("%f", &price);
    scanf("%d", &tmp);    month = tmp;
    scanf("%d", &tmp);    date = tmp;
    scanf("%d", &tmp);    flag = tmp;
    if (month == 11 && date == 11) {
        if (flag == 1)
            price = (price * 0.7 - 50)>0?price * 0.7 - 50:0;
        else
            price = price * 0.7;
    }
    if (month == 12 && date == 12) {
        if (flag == 1)
            price = (price * 0.8 - 50)>0?price * 0.8 - 50:0;
        else
            price = price * 0.8;
    }
    printf("%.2f\n", price);
    return 0;
}
```

#### BC38变种水仙花

<img src = "https://img-blog.csdnimg.cn/20201122150225706.png">

```c
#include <stdio.h>
#include <math.h>
int main() {
    int sum = 0;
    for (int num = 10000; num < 100000; ++num) {
        sum = 0;
        for (int i = 1; i < 5; ++i) {
            sum += (num / (int)pow(10, 5 - i)) * (num % (int)pow(10, 5 - i));
        }
        if (sum == num)
            printf("%d ", num);
    }
    return 0;
}
```

#### BC39争夺前五名

<img src = "https://img-blog.csdnimg.cn/20201122180758176.png">

使用hash结构，利用空间换取时间复杂度的降低

```c
#include <stdio.h>
int main() {
    short arr[101] = { 0 };
    short n = 0;
    scanf("%hd", &n);
    short tmp = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%hd", &tmp);
        arr[tmp] += 1;
    }
    short count = 0;
    for (int i = 100; i > 0; --i) {
        for (int j = 0; j < arr[i]; ++j) {
            if (count == 5)
                break;
            printf("%d ", i);
            count++;
        }
    }
    return 0;
}
```

动态开辟空间存储成绩，选择排序得到成绩前五

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    short n = 0;
    scanf("%hd", &n);
    short* arr = (short*)malloc(sizeof(short) * n);
    for (int i = 0; i < n; ++i)
        scanf("%hd", arr + i);
    //选择排序
    short max = 0;
    short maxIndex = 0;
    for (int i = 0; i < n; ++i) {
        max = arr[i];
        maxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (max < arr[j]) {
                maxIndex = j;
                max = arr[j];
            }
        }
        if (maxIndex != i) {
            arr[i] ^= arr[maxIndex];
            arr[maxIndex] ^= arr[i];
            arr[i] ^= arr[maxIndex];
        }
    }
    for (int i = 0; i < 5; ++i)
        printf("%d ", arr[i]);
    return 0;
}
```

#### BC40竞选社长

<img src = "https://img-blog.csdnimg.cn/20201122185122223.png">

**注意当读取到EOF时，循环也会退出**

```c
#include <stdio.h>
int main(){
    short count[2] = {0};
    char res = 0;
    while((res = getchar())!= '0' && (res != EOF)){
        count[res-'A'] += 1;
    }
    res = count[0] > count[1] ? 'A' : 'B';
    if(count[0] == count[1])
        res = 'E';
    printf("%c\n", res);
    return 0;
}
```

#### BC41你是天才吗？

<img src = "https://img-blog.csdnimg.cn/20201122190311755.png">

```c
#include <stdio.h>
int main() {
    short IQ = 140;
    scanf("%hd", &IQ);
    if(IQ >= 140)
        printf("Genius\n");
    return 0;
}
```

#### BC42完美成绩

<img src = "https://img-blog.csdnimg.cn/20201122190516303.png">

```c
#include <stdio.h>
int main() {
    short score = 0;
    while(scanf("%hd", &score) == 1){
        if(score >= 90 && score <= 100)
            printf("Perfect\n");
    }
    return 0;
}
```

#### BC43及格分数

<img src = "https://img-blog.csdnimg.cn/20201122190811395.png">

```c
#include <stdio.h>
int main() {
    short score = 0;
    while(scanf("%hd", &score) == 1){
        if(score >= 60)
            printf("Pass\n");
        else
            printf("Fail\n");
    }
    return 0;
}
```

#### BC44判断整数奇偶性

<img src = "https://img-blog.csdnimg.cn/20201122191014791.png">

```c
#include <stdio.h>
int main() {
    short score = 0;
    while(scanf("%hd", &score) == 1){
        if(score%2 == 0)
            printf("Even\n");
        else
            printf("Odd\n");
    }
    return 0;
}
```

#### BC46判断是元音还是辅音

<img src = "https://img-blog.csdnimg.cn/20201122191819230.png">

```c
#include <stdio.h>
int main() {
    char ch = 0;
    while((ch = getchar())!=EOF){
        getchar();
        if(ch == 'A'||ch == 'a'||ch == 'E'||ch == 'e'
           ||ch == 'I'||ch == 'i'||ch == 'O'||ch == 'o'
           ||ch == 'U'||ch == 'u')
            printf("Vowel\n");
        else
            printf("Consonant\n");
    }
    return 0;
}
```

#### BC48字母大小写转换

<img src = "https://img-blog.csdnimg.cn/20201122192055461.png">

```c
#include <stdio.h>
#include <ctype.h>
int main(){
    char ch = 0;
    while((ch = getchar())!=EOF){
        getchar();
        if(islower(ch))
            printf("%c\n", toupper(ch));
        else
            printf("%c\n", tolower(ch));
    }
    return 0;
}
```

#### BC49判断两个数的大小关系

<img src = "https://img-blog.csdnimg.cn/2020112219214620.png">

```c
#include <stdio.h>
int main(){
    char ch = 0;
    int arr[2];
    while(scanf("%d %d", arr, arr+1) == 2){
        ch = arr[0] > arr[1] ? '>':'<';
        if(arr[0] == arr[1])
            ch = '=';
        printf("%d%c%d\n", arr[0], ch, arr[1]);
    }
    return 0;
}
```

#### BC50计算单位阶跃函数

<img src = "https://img-blog.csdnimg.cn/20201122192707961.png">

```c
#include <stdio.h>
int main(){
    int t = 0;
    while(scanf("%d", &t) == 1){
        if(t!=0)
            printf("%d\n", t>0?1:0);
        else
            printf("%.1f\n", 0.5);
    }
    return 0;
}
```

#### BC51三角形判断

<img src = "https://img-blog.csdnimg.cn/20201122193151805.png">

先判断是否构成三角形，然后判断是否是等边三角形，再判断是不是等腰三角形，最后判断是不是普通三角形

```c
#include <stdio.h>
int main(){
    int arr[3] = {0};
    while(scanf("%d %d %d", arr, arr+1, arr+2) == 3){
        if(!(arr[0]+arr[1]>arr[2]&&arr[0]+arr[2]>arr[1]&&arr[1]+arr[2]>arr[0]))
            printf("Not a triangle!\n");
        else if(arr[0]==arr[1] && arr[1]==arr[2])
            printf("Equilateral triangle!\n");
        else if(arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2])
            printf("Isosceles triangle!\n");
        else
            printf("Ordinary triangle!\n");
    }
    return 0;
}
```


#### BC53计算一元二次方程

<img src = "https://img-blog.csdnimg.cn/20201126203819566.png">

注意double要使用%lf输入

```c
#include <stdio.h>
#include <math.h>
int main() {
    double a = 0, b = 0, c = 0;
    while (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        double deta = b * b - 4 * a * c;
        double p1 = -b / (2 * a);
        double q2 = sqrt(fabs(deta)) / (2 * a);
        if (0 == a)
            printf("Not quadratic equation\n");
        else {
            if (deta == 0)
                printf("x1=x2=%.2lf\n", p1);
            else if (deta > 0)
                printf("x1=%.2lf;x2=%.2lf\n", p1 - q2, p1 + q2);
            else
                printf("x1=%.2lf-%.2lfi;x2=%.2lf+%.2lfi\n", p1, q2, p1, q2);
        }
    }
    return 0;
}
```

#### BC54	获得月份天数

<img src = "https://img-blog.csdnimg.cn/20201126212110763.png">

```c
#include <stdio.h>
int main(){
    int year, month;
    short months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while(scanf("%d %d", &year, &month) == 2){
        months[1] = 28;
        if(year%4 == 0 && year %100 !=0 || year %400 == 0)
            months[1] = 29;
        printf("%d\n", months[month-1]);
    }
    return 0;
}
```

#### BC55简单计算器

<img src = "https://img-blog.csdnimg.cn/20201126213511583.png">

当测试用例的小数部分不符合测试用例时，考虑将float换double

```c
#include <stdio.h>
int main() {
    char ch;
    double a, b;
    while(scanf("%lf%c%lf", &a, &ch, &b) == 3){
        if(ch != '+'&&ch != '-'&&ch != '*'&&ch != '/')
            printf("Invalid operation!\n");
        else{
            if(ch == '+')
                printf("%.4lf+%.4lf=%.4lf\n", a, b, a+b);
            else if(ch == '-')
                printf("%.4lf-%.4lf=%.4lf\n", a, b, a-b);
            else if(ch == '*')
                printf("%.4lf*%.4lf=%.4lf\n", a, b, a*b);
            else if(ch == '/'){
                if(b == 0)
                    printf("Wrong!Division by zero!\n");
                else
                    printf("%.4lf/%.4lf=%.4lf\n", a, b, a/b);
            }
        }
    }
    return 0;
}
```

#### BC56线段图案

<img src = "https://img-blog.csdnimg.cn/20201127182143419.png">

```c
#include <stdio.h>
int main() {
    short n = 0;
    while(scanf("%d", &n)==1){
        for(int i=0; i<n; ++i)
            printf("*");
        printf("\n");
    }
    return 0;
}
```

#### BC58直角三角形图案

<img src = "https://img-blog.csdnimg.cn/20201127184702943.png">

```c
#include <stdio.h>
int main() {
    short n = 0;
    while(scanf("%d", &n) == 1){
        for(int i=1; i<=n; ++i){
            for(int j=0; j<i; ++j)
                printf("* ");
            printf("\n");
        }
    }
    return 0;
}
```

####  BC59翻转直角三角形图案

<img src = "https://img-blog.csdnimg.cn/20201127184617268.png">

```c
#include <stdio.h>
int main() {
    short n = 0;
    while(scanf("%d", &n) == 1){
        for(int i=n; i>=1; --i){
            for(int j=i; j>0; --j)
                printf("* ");
            printf("\n");
        }
    }
    return 0;
}
```

#### BC60带空格直角三角形图案

<img src = "https://img-blog.csdnimg.cn/20201127185849576.png">

```c
#include <stdio.h>
int main() {
    short n = 0;
    while (scanf("%d", &n) == 1) {
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < i; ++j)
                printf("  ");
            for (int j = n - i; j > 0; --j)
                printf("* ");
            printf("\n");
        }
    }
    return 0;
}
```


#### BC61金字塔图案

<img src = "https://img-blog.csdnimg.cn/20201127190044835.png">

```c
#include <stdio.h>
int main() {
    short n = 0;
    while (scanf("%d", &n) == 1) {
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < i; ++j)
                printf(" ");
            for (int j = n - i; j > 0; --j)
                printf("* ");
            printf("\n");
        }
    }
    return 0;
}
```


#### BC62翻转金字塔图案

<img src = "https://img-blog.csdnimg.cn/20201127190300748.png">

```c
#include <stdio.h>
int main() {
    short n = 0;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i<n; ++i) {
            for (int j = 0; j < i; ++j)
                printf(" ");
            for (int j = n - i; j > 0; --j)
                printf("* ");
            printf("\n");
        }
    }
    return 0;
}
```


#### BC63菱形图案

<img src = "https://img-blog.csdnimg.cn/20201127191101593.png">

```c
#include <stdio.h>
int main() {
    short n = 0;
    while (scanf("%d", &n) == 1) {
        for (int i = n; i >= 0; --i) {
            for (int j = 0; j < i; ++j)
                printf(" ");
            for (int j = n - i+1; j > 0; --j)
                printf("* ");
            printf("\n");
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j)
                printf(" ");
            for (int j = n - i; j > 0; --j)
                printf("* ");
            printf("\n");
        }
    }
    return 0;
}
```


#### BC64K形图案

<img src = "https://img-blog.csdnimg.cn/20201127194807859.png">

有坑，不要忘记末尾的空格 

```c
#include <stdio.h>
int main() {
    short n = 0;
    while (scanf("%d", &n) == 1) {
        for (int i = n + 1; i > 0; --i) {  //3 2 1
            for (int j = 0; j < i; ++j)
                printf("* ");
            for (int j = n+1-i; j > 0; --j)
                printf(" ");
            printf("\n");
        }
        for (int i = 2; i <= n + 1; ++i) {
            for (int j = 0; j < i; ++j)
                printf("* ");
            for (int j = 0; j < n + 1 - i; ++j)
                printf(" ");
            printf("\n");
        }
    }
    return 0;
}

```


#### BC65箭形图案

<img src = "https://img-blog.csdnimg.cn/20201128113001365.png">

```c
#include <stdio.h>
int main() {
    short n = 0;
    while(scanf("%d", &n) == 1){
        for(int i=0; i<=n; ++i){  //0 1 2 2 1 0
            //4 2 0
            for(int j=2*(n-i); j>0; --j)
                printf(" ");
            for(int j=0; j<=i; ++j)
                printf("*");
            printf("\n");
        }
        for(int i=0; i<n; ++i){  // 0 1
            for(int j=2*(i+1); j>0; --j)
                printf(" ");
            for(int j=n-i; j>0; --j)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}
```


#### BC66反斜线形图案

<img src = "https://img-blog.csdnimg.cn/20201128114017290.png">

```c
#include <stdio.h>
int main() {
    short n = 0;
    while (scanf("%d", &n) == 1) {
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < j; ++i) //0 1 2 3
                printf(" ");
            printf("*");
            // 3 2 1 0
            for (int i = n - j - 1; i > 0; --i)
                printf(" ");
            printf("\n");
        }
    }
    return 0;
}
```


#### BC67正斜线形图案

<img src = "https://img-blog.csdnimg.cn/20201128120756299.png">

```c
#include <stdio.h>
int main() {
    short n = 0;
    while (scanf("%d", &n) == 1) {
        for (int j = 0; j < n; ++j) {
            for (int i = n - j - 1; i > 0; --i)
                printf(" ");
            printf("*");
            for (int i = 0; i < j; ++i) //0 1 2 3
                printf(" ");
            printf("\n");
        }
    }
    return 0;
}
```


#### BC68X形图案

<img src = "https://img-blog.csdnimg.cn/20201128121236345.png">

```c
#include <stdio.h>
int main() {
    //printf("%d\n", 2 * ((5 >> 1) - 2));
    short n = 0;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < (n >> 1) + n % 2; ++i) {  //0 1 2
            for (int j = 0; j < i; ++j)
                printf(" ");
            printf("*");
            for (int j = n-2*(i+1); j > 0; --j) {
                printf(" ");
            }
            if(!(n%2 != 0 && i == (n >> 1)))
                printf("*");
            // 0 1 2
            for (int j = i; j > 0; --j)
                printf(" ");
            printf("\n");
        }
        for (int i = 0; i < n >> 1; ++i) {  //0 1
            for (int j = 0; j < (n >> 1)-i-1; ++j)  // 1 0
                printf(" ");
            printf("*");
            // 0 2
            for (int j = 2*i+(n%2); j > 0; --j) {
                printf(" ");
            }
            if (!(n % 2 != 0 && i == (n >> 1)))
                printf("*");
            // 2 1 0
            for (int j = (n>>1)-i-1; j > 0; --j)
                printf(" ");
            printf("\n");
        }
    }
    return 0;
}
```


#### BC69 空心正方形图案

<img src = "https://img-blog.csdnimg.cn/20201128125816460.png">

```c
#include <stdio.h>
int main() {
    short n = 0;
    while(scanf("%d", &n) == 1){
        for(int i=0; i<n; ++i)
            printf("* ");
        printf("\n");
        for(int i=0; i<n-2; ++i){
            printf("* ");
            for(int i=0; i<n-2; ++i)
                printf("  ");
            printf("* ");
            printf("\n");
        }
        for(int i=0; i<n; ++i)
            printf("* ");
        printf("\n");
    }
    return 0;
}
```



#### BC72平均身高

<img src = "https://img-blog.csdnimg.cn/20201128145604386.png">

```c
#include <stdio.h>
int main() {
    float heigths[5] = {0};
    float sum = 0;
    while(scanf("%f %f %f %f %f", heigths, heigths+1, heigths+2, heigths+3, heigths+4) == 5){
        for(int i=0; i<5; ++i)
            sum+=heigths[i];
        printf("%.2f\n", sum/5.0);
    }
    return 0;
}
```


#### BC74HTTP状态码

<img src = "https://img-blog.csdnimg.cn/20201128145956850.png">

```c
#include <stdio.h>
int main() {
    int status = 0;
    char statuses[7][22] = { "OK", "Accepted", "Bad Request", "Forbidden",
                 "Not Found", "Internal Server Error", "Bad Gateway" };
    while (scanf("%d", &status) == 1) {
        short index = 0;
        switch (status) {
        case 200:
            index = 0;
            break;
        case 202:
            index = 1;
            break;
        case 400:
            index = 2;
            break;
        case 403:
            index = 3;
            break;
        case 404:
            index = 4;
            break;
        case 500:
            index = 5;
            break;
        case 502:
            index = 6;
            break;
        }
        printf("%s\n", statuses[index]);
    }
    return 0;
}
```


#### BC75数字三角形

<img src = "https://img-blog.csdnimg.cn/20201128151119181.png">

```c
#include <stdio.h>
int main() {
    short n = 0;
    while(scanf("%d", &n) == 1){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=i; ++j){
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    return 0;
}
```


#### BC76公务员面试

<img src = "https://img-blog.csdnimg.cn/20201128152131678.png">

```c
#include <stdio.h>
int main() {
    short score[7];
    for(int i=0; i<7; ++i)
        scanf("%d", score+i);
    short max_index = 0, min_index = 0;
    short max = 0, min = 100;
    short sum = 0;
    for(int i=0; i<7; ++i){
        sum+=score[i];
        if(score[i] > max){
            max = score[i];
            max_index = i;
        }
        if(score[i] < min){
            min = score[i];
            min_index = i;
        }
    }
    sum -= score[max_index];
    sum -= score[min_index];
    printf("%.2f", sum/5.0);
    return 0;
}
```

<p id="BC77"></p>

#### BC77有序序列插入一个数

<img src = "https://img-blog.csdnimg.cn/20201128152231120.png">

如果插入的数，比所有已有的数都大要进行尾插  

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n = 0, insert_num = 0;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int)*(n+1));
    for(int i=0; i<n; ++i)
        scanf("%d", arr+i);
    scanf("%d", &insert_num);
    for(int i=0; i<n; ++i){
        if(arr[i] >= insert_num){
            for(int j=n; j>i; --j)
                arr[j] = arr[j-1];
            arr[i] = insert_num;
            break;
        }
        if(i == n-1){
            arr[n] = insert_num;
            break;
        }
    }
    for(int i=0; i<=n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
```


#### BC78筛选法求素数

<img src = "https://img-blog.csdnimg.cn/20201128155319809.png">

```c
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
bool isprime(int num) {
    if (num == 2 || num == 3)
        return true;
    //不和6的倍数相邻的数不是素数
    if (num % 6 != 1 && num % 6 != 5)
        return false;
    //6i+1和6i+5是num的因子,就不为素数
    int half = (unsigned int)sqrt(num);
    for (int i = 5; i <= half; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}
int main() {
    short n = 0, sum = 0;
    while(scanf("%d", &n) == 1){
        sum = 0;
        for(short i=2; i<n; ++i){
            if(isprime(i)){
                printf("%d ", i);
                ++sum;
            }
        }
        printf("\n%d\n", n-1-sum);
    }
    return 0;
}
```


#### BC79图像相似度

<img src = "https://img-blog.csdnimg.cn/20201128171405622.png">

```c
#include <stdlib.h>
#include <stdio.h>
int main() {
    int m = 0, n = 0;
    while (scanf("%d %d", &m, &n) == 2) {
        int** arr1 = (int**)malloc(sizeof(int**) * m);
        for (int i = 0; i < m; ++i)
            arr1[i] = (int*)malloc(sizeof(int*) * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                scanf("%d", arr1[i] + j);
        }
        int** arr2 = (int**)malloc(sizeof(int) * m);
        for (int i = 0; i < m; ++i)
            arr2[i] = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                scanf("%d", arr2[i] + j);
        }
        int same_count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr1[i][j] == arr2[i][j])
                    same_count++;
            }
        }
        printf("%.2f", same_count / (1.0 * m * n)*100.0);
    }
    return 0;
}

```


#### BC80登录验证

<img src = "https://img-blog.csdnimg.cn/20201128184426418.png">

```c
#include <stdio.h>
#include <string.h>
int main() {
    char name[20];
    char pwd[20];
    while(scanf("%s %s", name, pwd) == 2){
        if(strcmp(name, pwd) || strcmp("admin", name)|| strcmp("admin", pwd))
            printf("Login Fail!\n");
        else if(!strcmp(name, pwd) && !strcmp("admin", pwd))
            printf("Login Success!\n");
    }
    return 0;
}
```




#### BC82(a+b-c)*d的计算问题

<img src = "https://img-blog.csdnimg.cn/20201128185859455.png">

```c
#include <stdio.h>
int main() {
    int arr_short[4];
    for(int i=0; i<4; ++i)
        scanf("%d", arr_short+i);
    printf("%d", (arr_short[0]+arr_short[1]-arr_short[2])*arr_short[3]);
    return 0;
}
```


#### BC83被5整除问题

<img src = "https://img-blog.csdnimg.cn/20201128185953730.png">

**!逻辑反的优先级高于取模运算符%的优先级**

```c
#include <stdio.h>
int main() {
    short n = 0;
    while(scanf("%d", &n) == 1){
        if(!(n%5))
            printf("YES");
        else
            printf("NO");
    }
    return 0;
}
```


#### BC84计算y的值

<img src = "https://img-blog.csdnimg.cn/20201128190557628.png">

```c
#include <stdio.h>
int main() {
    short x = 0;
    while(scanf("%d", &x) == 1){
        short y = 0;
        if(x < 0)
            y = 1;
        else if(x > 0)
            y = -1;
        printf("%d\n", y);
    }
    return 0;
}
```


#### BC85包含数字9的数

<img src = "https://img-blog.csdnimg.cn/20201128190626949.png">

```c
#include <stdio.h>
int main() {
    short tmp = 0;
    short sum = 0;
    for(short i=9; i<=2019; ++i){
        tmp = i;
        while(tmp){
            if(tmp%10 == 9){
                sum++;
                break;
            }
            tmp /= 10;
        }
    }
    printf("%d\n", sum);
    return 0;
}
```


#### BC86奇偶统计

<img src = "https://img-blog.csdnimg.cn/20201128191238416.png">

+的运算符优先级高于>>

```c
#include <stdio.h>
int main() {
    int n = 0;
    scanf("%d", &n);
    if (!(n % 2))
        printf("%d %d", n >> 1, n >> 1);
    else
        printf("%d %d", (n >> 1) + (n % 2), n >> 1);
    return 0;
}
```


#### BC87统计成绩

<img src = "https://img-blog.csdnimg.cn/2020112819182427.png">

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n = 0;
    scanf("%d", &n);
    float* arr = (float*)malloc(sizeof(float)*n);
    for(int i=0; i<n; ++i)
        scanf("%f", arr+i);
    float max = 0, min = 101;
    float sum = 0;
    for(int i=0; i<n; ++i){
        sum += arr[i];
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    printf("%.2f %.2f %.2f", max, min, sum/n);
    return 0;
}
```

<p id='BC88'></p>

#### BC88有序序列插入一个数

<img src = "https://img-blog.csdnimg.cn/20201128192749838.png">



题目一样，请参考<a href="#BC77">BC77有序序列插入一个数</a>

也可以使用柔性数组

```c
#include <stdio.h>
#include <stdlib.h>
typedef struct flexible_arr
{
	int i;
	int a[0];//柔性数组成员
}flexible_arr;
int main() {
    int n = 0, insert_num = 0;
    scanf("%d", &n);
    flexible_arr* fa = (int*)malloc(sizeof(flexible_arr) + sizeof(int)*(n+1));
    for(int i=0; i<n; ++i)
        scanf("%d", (fa->a)+i);
    scanf("%d", &insert_num);
    for(int i=0; i<n; ++i){
        if(fa->a[i] >= insert_num){
            for(int j=n; j>i; --j)
                fa->a[j] = fa->a[j-1];
            fa->a[i] = insert_num;
            break;
        }
        if(i == n-1){
            fa->a[n] = insert_num;
            break;
        }
    }
    for(int i=0; i<=n; ++i)
        printf("%d ", fa->a[i]);
    printf("\n");
    return 0;
}
```

对比学习C++的堆空间管理

```c
#include <iostream>
using namespace std;
int main(){
    int n = 0, insert_num = 0;
    cin >> n;
    int* arr = new int[n];
    for(int i=0; i<n; ++i)
        cin >> arr[i];
    cin >> insert_num;
    for(int i=0; i<n; ++i){
        if(arr[i] >= insert_num){
            for(int j=n; j>i; --j)
                arr[j] = arr[j-1];
            arr[i] = insert_num;
            break;
        }
        if(i == n-1){
            arr[n] = insert_num;
            break;
        }
    }
    for(int i=0; i<=n; ++i)
        cout<<arr[i]<<" ";
    cout << endl;
    return 0;
}
```

使用C++的容器，利用set具有自动排序的特性

```cpp
#include <iostream>
#include <set>
using namespace std;
int main(){
    int N;
    set<int> s;
    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        s.insert(num);
    }
    int Num;
    cin >> Num;
    s.insert(Num);
    for(auto i : s){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
```


#### BC89密码验证

<img src = "https://img-blog.csdnimg.cn/20201128195134191.png">

```c
#include <stdio.h>
#include <string.h>
int main(){
    char pwd[20];
    char pwd_repeat[20];
    while(scanf("%s %s", pwd, pwd_repeat) == 2){
        if(!strcmp(pwd, pwd_repeat))
            printf("same\n");
        else
            printf("different\n");
    }
    return 0;
}
```


#### BC90矩阵计算

<img src = "https://img-blog.csdnimg.cn/20201128195815591.png">

```c
#include <stdio.h>
#include <stdlib.h>
int main(){
    int N, M, sum = 0;
    scanf("%d %d", &N, &M);
    int** arr = (int **)malloc(sizeof(int*)*N);
    for(int i=0; i<N; ++i)
        arr[i] = (int*)malloc(sizeof(int)*M);
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            scanf("%d", arr[i]+j);
            if(arr[i][j] > 0)
                sum += arr[i][j];
        }
    }
    printf("%d\n", sum);
    return 0;
}
```


#### BC91成绩输入输出问题

<img src = "https://img-blog.csdnimg.cn/20201128195856712.png">

```c
#include <stdio.h>
int main(){
    short arr[10] = {0};
    for(int i=0; i<10; ++i)
        scanf("%d", arr+i);
    for(int i=0; i<10; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
```


#### BC93统计数据正负个数

<img src = "https://img-blog.csdnimg.cn/20201128200618485.png">

没必要用数组保存这10个数，只需要用一个临时变量边输入边判断并使用正负数的计数器计数就可以得到想要的结果

```c
#include <stdio.h>
int main() {
    int tmp = 0;
    short negitive_size = 0, positive_size = 0;
    for(int i=0; i<10; ++i){
        scanf("%d", &tmp);
        if(tmp < 0)
            negitive_size++;
        else if(tmp > 0)
            positive_size++;
    }
    printf("positive:%d\n", positive_size);
    printf("negative:%d\n", negitive_size);
    return 0;
}
```


#### BC94N个数之和

<img src = "https://img-blog.csdnimg.cn/20201128201138869.png">

```c
#include <iostream>
int main(){
    int N = 0, input = 0, sum = 0;
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        scanf("%d", &input);
        sum += input;
    }
    printf("%d\n", sum);
    return 0;
}
```


#### BC95最高分与最低分之差

<img src = "https://img-blog.csdnimg.cn/20201128201635658.png">

```c
#include <iostream>
int main(){
    int n = 0, max = 0, min = 101, tmp = 0;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d", &tmp);
        if(max < tmp)
            max = tmp;
        if(min > tmp)
            min = tmp;
    }
    printf("%d", max-min);
    return 0;
}
```


#### BC96有序序列判断

<img src = "https://img-blog.csdnimg.cn/20201128201736978.png">

开辟N个整形空间，将输入的数据存储，先判断是不是是升序，若是升序就直接输出，如果不是升序就继续判断是不是降序，最终输出结果

```c
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
int main(){
    int N = 0;
    scanf("%d", &N);
    int* arr = (int*)malloc(sizeof(int)*N);
    bool flag = true;
    for(int i=0; i<N; ++i)
        scanf("%d", arr+i);
    for(int i=0; i<N-1; ++i){  //判升
        if(arr[i]>arr[i+1]){
            flag = false;
            break;
        }
    }
    if(!flag){
        flag = true;
        for(int i=0; i<N-1; ++i){  //判降
            if(arr[i]<arr[i+1]){
                flag = false;
                break;
            }
        }
    }
    if(flag)
        printf("sorted\n");
    else
        printf("unsorted\n");
    return 0;
}
```

不需要存储数据的空间，一边输入一边判断是升序或者升序

小知识点：使用整形的最大值 INT_MAX 最小值 MNT_MIN 要引limits.h库

```c
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
int main(){
    int N = 0;
    scanf("%d", &N);
    int* arr = (int*)malloc(sizeof(int)*N);
    int asc_before = INT_MIN, des_before = INT_MAX,after = 0;
    bool asc_flag = true, des_flag = true;
    for(int i=0; i<N; ++i){
        scanf("%d", &after);
        if(after < asc_before)  //判升序
            asc_flag = false;
        if(after > des_before)  //判降序
            des_flag = false;
        des_before = after;
        asc_before = after;
    }
    if(asc_flag || des_flag)
        printf("sorted\n");
    else
        printf("unsorted\n");
    return 0;
}
```

#### BC97有序序列插入一个整数

<img src = "https://img-blog.csdnimg.cn/20201128205552386.png">

请参考:

<a href="#BC77">BC77有序序列插入一个数</a>

<a href="#BC88">BC88有序序列插入一个数</a>



#### BC98序列中删除指定数字

<img src = "https://img-blog.csdnimg.cn/20201129144234155.png">

```c
#include <stdio.h>
int main() {
    int n = 0;
    int* arr = (int*)malloc(sizeof(int) * n);
    int delete = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);
    scanf("%d", &delete);
    short end_index = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != delete)
            arr[end_index++] = arr[i];
    }
    for (int i = 0; i < end_index; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
```


#### BC99序列中整数去重

<img src = "https://img-blog.csdnimg.cn/20201129151320636.png">

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main() {
    int n = 0;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);
    int i = 0;
    for(int j = 0; j < n; ++j) {
        int flag = false;
        for (int k = 0; k < j; ++k) {
            if (arr[k] == arr[j]) {
                flag = true;
                break;
            }
            else
                flag = false;
        }
        if(!flag)
            arr[i++] = arr[j];
    }
    for (int j = 0; j < i; ++j)
        printf("%d ", arr[j]);
    return 0;
}
```


#### BC100有序序列合并

<img src = "https://img-blog.csdnimg.cn/20201208191931469.png">

```c
#include <stdio.h>
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int* arr1 = (int*)malloc(sizeof(int) * n);
    int* arr2 = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr1 + i);
    for (int i = 0; i < m; ++i)
        scanf("%d", arr2 + i);
    int* arr = (int*)malloc(sizeof(int) * (m + n));
    int j = 0, k = 0;
    for (int i = 0; i < m + n; ++i) {
        if (j < n && k < m)
            arr[i] = arr1[j] <= arr2[k] ? arr1[j++] : arr2[k++];
        else
            arr[i] = j < n ? arr1[j++] : arr2[k++];
    }
    for (int i = 0; i < n + m; ++i)
        printf("%d ", arr[i]);
    return 0;
}
```


#### BC101班级成绩输入输出

<img src = "https://img-blog.csdnimg.cn/20201208193343495.png">

```c
#include <stdio.h>
int main() {
    float scores[5][5] = {0};
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            scanf("%f", *(scores + i) + j);
    }
    for (int i = 0; i < 5; ++i) {
        float sum = 0.0;
        for (int j = 0; j < 5; ++j) {
            sum += scores[i][j];
            printf("%.1f ", scores[i][j]);
        }
        printf("%.1f\n", sum);
    }
    return 0;
}
```


#### BC102	矩阵元素定位

<img src = "https://img-blog.csdnimg.cn/20201208194344645.png">

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    int** arr = (int **)malloc(sizeof(int*)*n);
    for(int i=0; i<n; ++i)
        arr[i] = (int*)malloc(sizeof(int)*m);
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j)
            scanf("%d", arr[i]+j);
    }
    scanf("%d%d", &x, &y);
    printf("%d\n", arr[x-1][y-1]);
    return 0;
}
```


#### BC103序列重组矩阵

<img src = "https://img-blog.csdnimg.cn/20201208194959529.png">

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int* arr = (int*)malloc(sizeof(int)*(n*m));
    for(int i=0; i<n*m; ++i)
        scanf("%d", arr+i);
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j)
            printf("%d ", arr[i*m+j]);
        printf("\n");
    }
    return 0;
}
```


#### BC104最高身高

<img src = "https://img-blog.csdnimg.cn/20201208195719526.png">

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, m, x = 0, y = 0, max;
    scanf("%d %d", &n, &m);
    int* heights = (int*)malloc(sizeof(int)*n*m);
    for(int i=0; i<n*m; ++i)
        scanf("%d", heights+i);
    max = heights[0];
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(max < heights[i*m+j]){
                max = heights[i*m+j];
                x = i;
                y = j;
            }
        }
    }
    printf("%d %d\n", x+1, y+1);
    return 0;
}
```


#### BC105矩阵相等判定

<img src = "https://img-blog.csdnimg.cn/20201208202246357.png">

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main() {
    int n, m;
    bool flag = true;
    scanf("%d%d", &n, &m);
    int* arr1 = (int*)malloc(sizeof(int)*n*m);
    int* arr2 = (int*)malloc(sizeof(int)*n*m);
    for(int i=0; i<n*m; ++i)
        scanf("%d", arr1+i);
    for(int i=0; i<n*m; ++i)
        scanf("%d", arr2+i);
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(arr1[i*m+j] != arr2[i*m+j])
                flag = false;
        }
    }
    if(flag)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
```

#### BC106上三角矩阵判定

<img src = "https://img-blog.csdnimg.cn/20201208202340473.png">

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main() {
    int n = 0;
    bool flag = true;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int)*n*n);
    for(int i=0; i<n*n; ++i)
        scanf("%d", arr+i);
    for(int i=1; i<n; ++i){
        for(int j=0; j<i; ++j){
            if(0 != arr[i*n+j]){
                flag = false;
                break;
            }
        }
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
```

#### BC107矩阵转置

<img src = "https://img-blog.csdnimg.cn/20201208204206598.png">

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int* arr = (int*)malloc(sizeof(int) * n * m);
    for (int i = 0; i < n * m; ++i)
        scanf("%d", arr + i);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", arr[j * m + i]);
        printf("\n");
    }
    return 0;
}
```



#### BC108矩阵交换

<img src = "https://img-blog.csdnimg.cn/2020120821293523.png">

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int** arr = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; ++i)
        arr[i] = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", arr[i] + j);

    int changes = 0;
    scanf("%d", &changes);
    char* chs = (char*)malloc(sizeof(char) * changes);
    int* r_c1 = (int*)malloc(sizeof(int) * changes);
    int* r_c2 = (int*)malloc(sizeof(int) * changes);
    for (int i = 0; i < changes; ++i) {
        getchar();
        scanf("%c %d %d", chs+i, r_c1 + i, r_c2 + i);
    }
    for (int i = 0; i < changes; ++i) {
        if (*(chs + i) == 'r') {
            for (int j = 0; j < m; ++j) {
                arr[*(r_c1 + i) - 1][j] ^= arr[*(r_c2 + i) - 1][j];
                arr[*(r_c2 + i) - 1][j] ^= arr[*(r_c1 + i) - 1][j];
                arr[*(r_c1 + i) - 1][j] ^= arr[*(r_c2 + i) - 1][j];
            }
        }
        else if (*(chs + i) == 'c') {
            for (int j = 0; j < n; ++j) {
                arr[j][*(r_c1 + i) - 1] ^= arr[j][*(r_c2 + i) - 1];
                arr[j][*(r_c2 + i) - 1] ^= arr[j][*(r_c1 + i) - 1];
                arr[j][*(r_c1 + i) - 1] ^= arr[j][*(r_c2 + i) - 1];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    return 0;
}
```

<a id="BC109杨辉三角"></a>

#### BC109杨辉三角

<img src = "https://img-blog.csdnimg.cn/20201209125425125.png">

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    int** arr = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; ++i)
        arr[i] = (int*)malloc(sizeof(int) * (i+1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i)
                arr[i][j] = 1;
            else
                arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j)
            printf("%5d", arr[i][j]);
        printf("\n");
    }
    return 0;
}
```

#### BC110井字棋

<img src = "https://img-blog.csdnimg.cn/20201209134647151.png">

```c
#include <stdio.h>
#include <stdbool.h>
char func(char ar[3][3]) {
    //行
    char tmp = 0;
    bool flag = true;
    for (int i = 0; i < 3; ++i) {
        tmp = ar[i][0];
        flag = true;
        for (int j = 1; j < 3; ++j) {
            if (tmp != ar[i][j]) {
                flag = false;
                break;
            }
        }
        if (flag)
            return tmp;
    }
    //列
    tmp = 0;
    flag = true;
    for (int i = 0; i < 3; ++i) {
        tmp = ar[0][i];
        flag = true;
        for (int j = 1; j < 3; ++j) {
            if (tmp != ar[j][i]) {
                flag = false;
                break;
            }
        }
        if (flag)
            return tmp;
    }
    //主对角线
    tmp = ar[0][0];
    flag = true;
    for (int i = 1; i < 3; ++i) {
        if (tmp != ar[i][i]) {
            flag = false;
            break;
        }
    }
    if (flag)
        return tmp;
    //副对角线
    tmp = ar[0][2];
    flag = true;
    for (int i = 1; i < 3; ++i) {
        if (tmp != ar[i][2 - i]) {
            flag = false;
            break;
        }
    }
    if (flag)
        return tmp;
    return 'N';
}
int main() {
    char ar[3][3];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            scanf("%c", ar[i] + j);
            getchar();
        }
    if (func(ar) == 'N'||func(ar) == 'O')
        printf("No winner!\n");
    else if (func(ar) == 'B')
        printf("BoBo wins!\n");
    else if(func(ar) == 'K')
        printf("KiKi wins!\n");
    return 0;
}
```

#### BC111小乐乐与进制转换

<img src = "https://img-blog.csdnimg.cn/20201209134736400.png">

```c
#include <stdio.h>
void func(int n){
    if(n <= 0)
        return;
    func(n/6);
    printf("%d", n%6);
}
int main(){
    int n;
    scanf("%d", &n);
    func(n);
    return 0;
}
```

#### BC112小乐乐求和

<img src = "https://img-blog.csdnimg.cn/20201209140617145.png">

等差数列求和公式

```c
#include <stdio.h>
int main() {
    long long int n = 0;
    scanf("%lld", &n);
    if (n == 1)
        printf("1\n");
    else
        printf("%lld\n", (n * (n + 1)) >> 1);
    return 0;
}
```


```c
#include<stdio.h>
int main()
{
    long int n;
    scanf("%ld",&n);
    long int sum;
    sum=n*(n+1)/2;
    printf("%ld",sum);
}
```

#### BC113小乐乐定闹钟

<img src = "https://img-blog.csdnimg.cn/20201209140706577.png">

```c
#include <stdio.h>
int main() {
    int hours, minutes, n;
    scanf("%d:%d %d", &hours, &minutes, &n);
    n %= 24 * 60;
    printf("%02d:%02d\n", (hours + (n / 60) + ((minutes + n%60) / 60)) % 24, (minutes + n%60) % 60);
    return 0;
}
```

#### BC114小乐乐排电梯

<img src = "https://img-blog.csdnimg.cn/20201209141930171.png">

```c
#include <stdio.h>
int main(){
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", (n/12) * 4 + 2);
    return 0;
}
```

#### BC115小乐乐与欧几里得

<img src = "https://img-blog.csdnimg.cn/20201209144835164.png">

快速求最小公因式：

int max_divisor(int n, int m) {
    int tmp = 0;
    while (n % m != 0) {
        tmp = n % m;
        n = m;
        m = tmp;
    }
    return m;
}

两数之积除以最大公因数就是两数的最小公倍数



```c
#include <stdio.h>
int max_divisor(int n, int m) {
    int tmp = 0;
    while (n % m != 0) {
        tmp = n % m;
        n = m;
        m = tmp;
    }
    return m;
}
int main() {
    long long int n, m;
    scanf("%lld%lld", &n, &m);
    printf("%lld\n", n * (m / max_divisor(n, m)) + max_divisor(n, m));
    return 0;
}
```

#### BC116小乐乐改数字

<img src = "https://img-blog.csdnimg.cn/20201209144929886.png">

```c
#include <stdio.h>
int main() {
    int n, res = 0, index = 1;
    scanf("%d", &n);
    while (n > 0) {
        res += ((n % 10) % 2) * index;
        index *= 10;
        n /= 10;
    }
    printf("%d\n", res);
    return 0;
}
```

<font color=#F001111F>

#### BC117小乐乐走台阶 ^[递归、迭代、动规]

</font>

<img src = "https://img-blog.csdnimg.cn/202012091516392.png ">

递归：

```c
#include <stdio.h>
int f(int n)//递归思想
{
    if(n==1||n==0) return 1;
    else return f(n-1)+f(n-2);
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", f(n));
    return 0;
}
```

迭代：

```c
#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int first = 1;
    int second = 2;
    for(int i = 3; i <= n; i++){
        int third = first + second;
        first = second;
        second = third;
    }
    printf("%d", second);
    return 0;
}
```

动态规划：

```c
//动态规划：
#include <stdio.h>
int stage[30];
int main() {
    int n;
    scanf("%d", &n);
    stage[1] = 1;
    stage[2] = 2;
    for (int i = 3; i <= n; i++) {
        stage[i] = stage[i - 1] + stage[i - 2];
    }
    printf("%d\n", stage[n]);
    return 0;
}
```

#### BC118小乐乐与序列

<img src = "https://img-blog.csdnimg.cn/20201209163338866.png">

```c
#include <stdio.h>
int main() {
    int n = 0, in = 0;
    int arr[100001] = { 0 };
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &in);
        arr[in] = 1;
    }
    for (int i = 1; i < 100001; ++i) {
        if (arr[i])
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
```

#### 

<img src = "">

```c

```

#### 

<img src = "">

```c

```

#### 

<img src = "">

```c

```

#### 

<img src = "">

```c

```

#### 

<img src = "">

```c

```

#### 

<img src = "">

```c

```

#### 

<img src = "">

```c

```

#### 

<img src = "">

```c

```

#### 

<img src = "">

```c

```

#### 

<img src = "">

```c

```

#### 

<img src = "">

```c

```

#### 

<img src = "">

```c

```

#### 

<img src = "">

```c

```

#### 

<img src = "">

```c

```




</font>