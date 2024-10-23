> “برنامه‌نویسی یعنی آموزش دادن به کامپیوتر که چگونه تصمیم بگیرد.” – استیو جابز



# ‌دستور switch :


دستور Switch محتوای یک متغیر را تست کرده و آن را با چندین مقدار دیگر 
مقایسه می کند. هرگاه که مورد مطابق پیدا شود، بلوک دستور مربوط به آن 
مورد(کیس) اجرا می شود. هر کیس(case) در هر بلوک از switch یک نام/عدد 
متفاوت داشته که برای آن به منزله شناسه هم حساب می شود. مقدار مورد نظر 
کاربر با همه کیس های درون بلوک switch مقایسه شده تا یک مورد مطابق پیدا 
شود. اگر مورد مطابق پیدا نشود، آنگاه دستور پیش فرض اجرا شده و کنترل 
برنامه به خارج از بلوک switch منتقل می شود.



```c
switch(expression){
case value1: 
	statement_1;
        break;
case value2:
	statement_2;
        break;
.
.
.
case value_n:
	statement_n;
	break;
default:
	default_statement;
}
```
درواقع اگر دنبال یافتن یک تساوی بودیم میتوانیم از switch استفاده کنیم اما اگر شرط های متعدد و یا پیچیده داشتیم همان دستور if کارساز تر است.

ابتدا یک مثال از if برایتان آورده ایم و بلافاصله پس از آن همان مثال را با  switch بیان میکنیم تا به خوبی متوجه کاربرد switch-case بشوید .

#### مثال :

```c
#include <stdio.h>

int main(){

   /* local variable definition */
   char ch = 'e';

   if (ch == 'm')
      printf("Good Morning");

   else if (ch == 'a')
      printf("Good Afternoon");
   else
      printf("Good Evening");

   return 0;
}
```
‍
#### خروجی :

```c
Good Evening
```

#### مثال :
```c
#include <stdio.h>

int main (){

   // local variable definition
   char ch = 'e';

   switch (ch){

      case 'm':
         printf("Good Morning\n");
         break ;

      case 'a':
         printf("Good Afternoon\n");
         break;

      default:
         printf("Good Evening\n");
         break;

   }
   return 0;
}
```
#### خروجی :
‍‍
```c
Good Evening
```

## نکات switch-case :

+ در پرانتز جلوی switch میتوانید یک متغیر بذارید که کامپایلر دنبال case ای بگردد که مقدار درست در آن قرار دارد .
+  دستور default معادل else می باشد .
 
## تفاوت های بین if و switch-case : 
+ 1.  **نوع شرایط**:
	+ **if**: می‌تواند برای هر نوع شرطی استفاده شود. برای مقادیر بولی، مقایسه‌ها و ترکیب‌های پیچیده از شرایط مختلف مناسب است.
	+ **switch-case**: معمولاً برای مقایسه متغیرها با 
		مجموعه‌ای از مقادیر ثابت (مانند اعداد یا رشته‌ها) استفاده می‌شود. 
		محدودیت در نوع داده‌ای که می‌توانید با آن کار کنید، دارد.

2.  **ساختار و خوانایی**:
	+ **if**: ممکن است چندین `if` و `else if` داشته باشد که می‌تواند منجر به کد پیچیده‌تر و دشوارتر برای خواندن شود.
	+ **switch-case**: اغلب به کاربران کمک می‌کند تا کد را مرتب‌تر و خواناتر ببینند، به‌خصوص زمانی که شرایط زیادی وجود دارد.

3.  **عملکرد**:
	+ بسته به زبان برنامه‌نویسی و پیاده‌سازی، عملکرد `switch-case`
		 ممکن است بهتر باشد زیرا برخی زبان‌ها از تکنیک‌هایی مثل جدول جستجو 
		استفاده می‌کنند که باعث می‌شود جستجو بین کیس‌ها سریع‌تر انجام شود.

4.  **تداوم اجرا (Fall-through)**:
	+ **switch-case**: اگر در یک case دستور `break` را نداشته باشید، اجرا به case‌های بعدی نیز ادامه می‌یابد که این ویژگی می‌تواند هم مزیت و هم معایب خاص خود را داشته باشد.
	+ **if**: همیشه با اولین بلاک متناظر با شرط صحیح متوقف می‌شود و به سایر بلاک‌ها ادامه نمی‌دهد.

5.  **محدودیت‌ها**:
	+ **if**: هیچ محدودیتی در تعداد شرایط ندارد و می‌تواند شرایط پیچیده را در خود جای دهد.
	+ **switch-case**: باید برای صورت‌های خاص (مانند درست کردن case برای هر عدد درست یا رشته) محدودیت‌هایی وجود داشته باشد. 

 
 #### دستور کنترلی break :
 با این دستور در درسنامه ۴.۲ بهتر آشنا می شوید اما در ساختار switch-case اگر انتهای هر case این دستور نوشته نشود آن دستور و تمام دستور های بعد از آن به ترتیب اجرا خواهند شد .

#### مثال :
‍
```c
#include <stdio.h>

int main (){

   char ch = 'a';
   
   switch (ch){
      case 'a':
         printf("Good Afternoon\n");
         // break;

      case 'e':
         printf("Good Evening\n");
         // break;

      case 'm':
         printf("Good Morning\n");
   }
   return 0;
}
```

#### خروجی :
```c
Good Afternoon
Good Evening
Good Morning
```

#### مثال :
‍
```c
#include <stdio.h>
int main()
{

    int var = 2;

    // switch case without break
    switch (var)
    {
    case 1:
        printf("Case 1 is executed.\n");
    case 2:
        printf("Case 2 is executed.\n");
    case 3:
        printf("Case 3 is executed.");
    case 4:
        printf("Case 4 is executed.");
    }
    return 0;
}
```

#### خروجی :
```c
Case 2 is executed.
Case 3 is executed.Case 4 is executed.
```

> الان که دستورات شرطی را به خوبی یاد گرفته اید سراغ تمرینات این بخش در صفحه اصلی کلاس بروید .
