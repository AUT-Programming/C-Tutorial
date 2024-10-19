امیدوارم درسنامه ۳.۱ را خوب یاد گرفته باشید. در این درسنامه با فرم دیگری از دستورات شرطی آشنا می شویم . دستور Conditional/Ternary Operator یا عملگر شرطی سه تایی فرم دیگری از تصیمم گیری در زبان c است که در ادامه توضیحات مربوط به آن آمده است .

> دستورات شرطی مانند چراغ‌های راهنمایی هستند که جریان کد را هدایت می‌کنند.


----------
### عملگر شرطی سه تایی Conditional/Ternary Operator in C
در بیشتر زبان های برنامه‌نویسی علامت سؤال جایگزینی برای گزاره if است و
 بهتر است در مواردی استفاده شود که یکی از دو مقدار بر اساس یک گزاره شرطی
 به یک متغیر انتساب می‌یابند. در واقع هدف از علامت سؤال (?) در کد بازگشت دادن یکی از دو مقدار بسته به شرایط است.


    condition ? exprIfTrue : exprIfFalse ;



‌
در نمونه بالا اگر شرط (condition) درست باشد عبارت بعد از علامت سوال (؟) اجرا خواهد شد و اگر عبارت شرطی نادرست باشد عبارت بعد از کالن (:) اجرا خواهد شد . عملگر شرطی سه تایی در واقع همان if و else است که قبلا یاد گرفتید .

#### مثال :
```C
#include <stdio.h>

int main()
{
    int m = 5, n = 4;

    (m > n) ? printf("m is greater than n that is %d > %d",
                     m, n)
            : printf("n is greater than m that is %d > %d",
                     n, m);

    return 0;
}

```
#### خروجی :
‍‍
```
m is greater than n that is 5 > 4
```
این مثال را با فرم if-else هم نشان میدهیم که متوجه تفاوت بین این دو شوید .
#### مثال :

```C
#include <stdio.h>

int main()
{
    int m = 5, n = 4;
    if (m > n) {
	printf("m is greater than n that is %d > %d",
                     m, n)
    }else{
	printf("n is greater than m that is %d > %d",
                     n, m);
	}
    return 0;
}

```


#### خروجی :

```
m is greater than n that is 5 > 4
```
#### مثال :
```c
#include <stdio.h>

int main()
{
    int a = 10, b = 20, c;

    c = (a < b) ? a : b;

    printf("%d", c);

    return 0;
}
```
#### خروجی :
```
10
```


----------


# عملگر شرطی سه تایی تو در تو
اگر تعداد شرط ها زیاد باشد استفاده از این حالت موجب ناخوانایی کد می شود و پیشنهاد می شود که از همان فرم if, else استفاده کنید .
```c
(condition1) ? (statement1) : (condition2) ? (statement2) : (statement3);
```
اگر condition1 درست باشد  statement1 اجرا می شود و در غیر اینصورت در حالتی که condition2 درست باشد statement2 اجرا میشود و در غیر اینصورت statement3 ران خواهد شد.
به مثال زیر دقت کنید .
#### مثال :
```c
#include <stdio.h>

int main()
{
    int a = 5, b = 10, c = 15;
    int result = (a > b) ? (a > c) ? a : c : (b > c) ? b : c;
    printf("%d", result);

    return 0;
}
```

#### خروجی :
```
15
```
