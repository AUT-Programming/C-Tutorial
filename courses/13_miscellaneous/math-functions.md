# توابع ریاضی در زبان C

زبان C شامل مجموعه‌ای از توابع ریاضی است که در کتابخانه **`math.h`** قرار دارند. این توابع به شما امکان می‌دهند تا عملیات مختلف ریاضی مانند محاسبه توابع مثلثاتی، لگاریتم‌ها، جذر و غیره را انجام دهید. برای استفاده از این توابع، ابتدا باید کتابخانه **`math.h`** را در برنامه خود وارد کنید.

## توابع ریاضی متداول

در اینجا تعدادی از توابع رایج موجود در **`math.h`** معرفی می‌شوند:

| تابع          | توضیحات                                 | تعریف تابع                                 |
|:--------------:|:-----------------------------------------:|:--------------------------------------------:|
| `sin()`        | محاسبه سینوس یک زاویه (بر حسب رادیان) | `double sin(double x);`                     |
| `cos()`        | محاسبه کسینوس یک زاویه (بر حسب رادیان) | `double cos(double x);`                     |
| `tan()`        | محاسبه تانژانت یک زاویه (بر حسب رادیان)| `double tan(double x);`                     |
| `sqrt()`       | محاسبه جذر یک عدد                       | `double sqrt(double x);`                    |
| `pow()`        | محاسبه توان یک عدد                     | `double pow(double base, double exponent);` |
| `log()`        | محاسبه لگاریتم طبیعی (e)      | `double log(double x);`                     |
| `log10()`      | محاسبه لگاریتم بر پایه ۱۰               | `double log10(double x);`                   |
| `round()`      | گرد کردن عدد به نزدیک‌ترین عدد صحیح   | `double round(double x);`                   |
| `ceil()`       | گرد کردن عدد به بالاترین عدد صحیح      | `double ceil(double x);`                    |
| `floor()`      | گرد کردن عدد به پایین‌ترین عدد صحیح    | `double floor(double x);`                   |
| `sinh()`       | محاسبه سینوس هایپربولیک یک عدد        | `double sinh(double x);`                    |
| `cosh()`       | محاسبه کسینوس هایپربولیک یک عدد      | `double cosh(double x);`                    |
| `tanh()`       | محاسبه تانژانت هایپربولیک یک عدد      | `double tanh(double x);`                    |
| `asin()`       | محاسبه معکوس سینوس (آرک‌سینوس)         | `double asin(double x);`                    |
| `acos()`       | محاسبه معکوس کسینوس (آرک‌کوسینوس)     | `double acos(double x);`                    |
| `atan()`       | محاسبه معکوس تانژانت (آرک‌تانژانت)    | `double atan(double x);`                    |
| `fmod()`       | محاسبه باقی‌مانده تقسیم دو عدد         | `double fmod(double x, double y);`         |
## ثوابت ریاضی

کتابخانه **`math.h`** همچنین شامل چندین ثابت ریاضی است که می‌توانند مفید باشند، از جمله:

| ثابت     | توضیحات                                       |
|----------|-----------------------------------------------|
| `M_PI`   | مقدار عدد پی که تقریباً برابر با ۳.۱۴۱۵۹ است |
| `M_E`    | مقدار عدد اویلر که تقریباً برابر با ۲.۷۱۸۲۸ است |

### مثال:

```c
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {

   double x, sn, cs, tn, val;

   x = 45.0;
   val = PI / 180;

   sn = sin(x*val);
   cs = cos(x*val);
   tn = tan(x*val);

   printf("sin(%f) : %f\n", x, sn);
   printf("cos(%f) : %f\n", x, cs);
   printf("tan(%f) : %f\n", x, tn);

   return(0);
}
```
```
sin(45.000000) : 0.707107
cos(45.000000) : 0.707107
tan(45.000000) : 1.000000
```

```c
#include <stdio.h>
#include <math.h>

int main() {

   float val1, val2, val3, val4;

   val1 = 1.2;
   val2 = 1.6;
   val3 = 2.8;
   val4 = -2.3;

   printf ("ceil(%lf) = %.1lf\n", val1, ceil(val1));
   printf ("floor(%lf) = %.1lf\n", val2, floor(val2));
   printf ("ceil(%lf) = %.1lf\n", val3, ceil(val3));
   printf ("floor(%lf) = %.1lf\n", val4, floor(val4));

   printf("round(%lf) = %.1lf\n", val1, round(val1));
   printf("round(%lf) = %.1lf", val4, round(val4));

   return(0);
}
```
```
ceil(1.200000) = 2.0
floor(1.600000) = 1.0
ceil(2.800000) = 3.0
floor(-2.300000) = -3.0
round(1.200000) = 1.0
round(-2.300000) = -2.0
```
```c
#include <stdio.h>
#include <math.h>

int main () {

   float a, b;
   int c;
   a = 9.2;
   b = 3.7;
   c = 2;
   
   printf("Remainder of %f / %d is %lf\n", a, c, fmod(a,c));
   printf("Remainder of %f / %f is %lf\n", a, b, fmod(a,b));

   return(0);
}
```
```
Remainder of 9.200000 / 2 is 1.200000
Remainder of 9.200000 / 3.700000 is 1.800000
```

## استفاده از توابع ریاضی

برای استفاده از توابع ریاضی، باید کتابخانه **`math.h`** را به کد خود اضافه کنید. همچنین، برای پیاده‌سازی موفقیت‌آمیز توابع ریاضی، در برخی از سیستم‌ها ممکن است نیاز باشد که هنگام کامپایل کد، از گزینه `-lm` برای لینک کردن کتابخانه ریاضی استفاده کنید.

### مثال کامپایل:
```bash
gcc -o my_program my_program.c -lm
