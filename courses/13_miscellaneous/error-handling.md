# مدیریت خطا در زبان C

مدیریت خطا در زبان برنامه‌نویسی C به روش‌های مختلفی انجام می‌شود، زیرا زبان C از امکانات مستقیم برای مدیریت خطا پشتیبانی نمی‌کند. با این حال، می‌توان از متغیر `errno` و تابع های مختلفی مانند `perror` و `strerror` برای مدیریت خطا استفاده کرد.

## متغیر `errno`

شما می توانید با استفاده از مقادیر بازگشتی از توابع خطاها را مدیریت کنید. اکثر توابع موجود در زبان C در صورت بوجود آمدن خطا مقدار -1 یا NULL را باز میگردانند و شماره خطا را در متغیر errno تنظیم می کنند.  این یک متغیر جهانی است که نشان دهنده بوجود آمدن خطا در هنگام فراخوانی یک تابع است. شماره خطاهای (error code) مختلفی در هدر فایل <error.h> وجود دارد.

بنابراین یک برنامه نویس C می تواند با بررسی مقادیر بازگشتی، خطاهای بوجود آمده را کنترل کند. بهتر است در ابتدا برنامه مقدار متغیر errno را 0 تنظیم کنید. مقدار 0 نشان دهنده این است که هیچ خطایی رخ نداده است.



| **کد خطا (errno)** | **عدد خطا** | **نام خطا**        | **معنی**                           |
|:--------------------:|:-------------:|:--------------------:|:------------------------------------------------:|
| `EPERM`            | 1           | Operation not permitted | عملیات مجاز نیست                                |
| `ENOENT`           | 2           | No such file or directory | فایل یا دایرکتوری وجود ندارد                    |
| `ESRCH`            | 3           | No such process     | فرآیند مورد نظر وجود ندارد                       |
| `EINTR`            | 4           | Interrupted system call | سیستم فراخوانی قطع شده است                      |
| `EIO`              | 5           | I/O error           | خطای ورودی/خروجی                               |
| `ENXIO`            | 6           | No such device or address | دستگاه یا آدرس مورد نظر وجود ندارد               |
| `E2BIG`            | 7           | Argument list too long | لیست آرگومان‌ها بسیار طولانی است                |
| `ENOEXEC`          | 8           | Exec format error    | فرمت اجرای فایل نامعتبر است                     |
| `EBADF`            | 9           | Bad file number      | شماره فایل نامعتبر است                          |
| `ECHILD`           | 10          | No child processes   | هیچ فرآیند فرزندی وجود ندارد                    |
| `EAGAIN`           | 11          | Try again            | دوباره تلاش کنید (منبع موقتاً در دسترس نیست)   |
| `ENOMEM`           | 12          | Out of memory        | حافظه کافی موجود نیست                           |
| `EACCES`           | 13          | Permission denied    | دسترسی غیرمجاز                                  |
| `EFAULT`           | 14          | Bad address          | آدرس نامعتبر                                    |
| `EBUSY`            | 16          | Device or resource busy | دستگاه یا منبع مشغول است                        |
| `EEXIST`           | 17          | File exists          | فایل از قبل وجود دارد                           |
| `EXDEV`            | 18          | Cross-device link    | لینک دستگاه متقاطع                              |
| `ENODEV`           | 19          | No such device       | دستگاه مورد نظر وجود ندارد                      |
| `ENOTDIR`          | 20          | Not a directory      | دایرکتوری نیست                                  |
| `EISDIR`           | 21          | Is a directory       | یک دایرکتوری است                                |
| `EINVAL`           | 22          | Invalid argument     | آرگومان نامعتبر                                 |
| `ENFILE`           | 23          | File table overflow  | جدول فایل‌ها پر شده است                         |
| `EMFILE`           | 24          | Too many open files  | تعداد زیادی فایل باز است                        |
| `ENOTTY`           | 25          | Not a typewriter     | دستگاه تایپ‌نویسی نیست                         |
| `ETXTBSY`          | 26          | Text file busy       | فایل متنی مشغول است                             |
| `EFBIG`            | 27          | File too large       | فایل بیش از حد بزرگ است                        |
| `ENOSPC`           | 28          | No space left on device | فضای کافی در دستگاه موجود نیست                |
| `ESPIPE`           | 29          | Illegal seek         | عملیات جستجوی نامعتبر                           |
| `EROFS`            | 30          | Read-only file system | فایل فقط خواندنی است                     |
| `EMLINK`           | 31          | Too many links       | تعداد زیادی لینک                                |
| `EPIPE`            | 32          | Broken pipe          | پایپ خراب است                                  |
| `EDOM`             | 33          | Math argument out of domain | آرگومان ریاضی خارج از دامنه مجاز است        |
| `ERANGE`           | 34          | Math result not representable | نتیجه ریاضی قابل نمایش نیست                |



### مثال:

```c
#include <stdio.h>
#include <errno.h>

int main() {

   FILE* fp;

   // opening a file which does not exist
   fp = fopen("nosuchfile.txt", "r");
   printf("Value of errno: %d\n", errno);

   return 0;
}
```
```
Value of errno: 2
```

---

## استریم stderr

(مخفف standard error) یکی از سه جریان استاندارد (standard streams) میباشد.  این جریان مخصوص نمایش و ثبت خطاهای برنامه است. به عبارت دیگر، هر پیغامی که به عنوان خطا یا هشدار در برنامه رخ دهد، می‌تواند به stderr ارسال شود تا به کاربر نمایش داده شود یا در فایل‌های لاگ ثبت گرد

### جریان‌های استاندارد در C:

- stdin: برای ورودی استاندارد (مثل ورودی از کیبورد)
- stdout: برای خروجی استاندارد (مثل نمایش نتایج در صفحه نمایش)
- stderr: برای خطای استاندارد (نمایش پیغام‌های خطا)

برخلاف stdout که معمولاً نتایج برنامه را نشان می‌دهد، stderr مخصوص پیغام‌های خطا است تا کاربر بتواند آن‌ها را از خروجی‌های معمولی جدا کند.

> چه شکلی اصلا می‌تونیم stderr رو ببینیم؟
تو سیستم‌های مدرن، معمولاً stderr همون خروجی معمول (مثل ترمینال) هست. یعنی وقتی برنامه‌ای رو اجرا می‌کنید و خطایی رخ می‌ده، پیغام‌های خطا مستقیماً تو همون پنجره نمایش داده می‌شن. اما stderr رو می‌تونیم به فایل جداگانه‌ای هم هدایت کنیم.

### مثال:
در این مثال، با استفاده از تابع fprintf، یک پیغام خطا به stderr فرستاده می‌شود:


```c
#include <stdio.h>

int main() {
    fprintf(stderr, "This is an error message.\n");
    return 0;
}
```
```
This is an error message.
```
وقتی این برنامه اجرا شود، پیغام خطا به جای نمایش در stdout، در stderr نمایش داده می‌شود

---

## تابع perror
تابع perror یک پیغام خطا را همراه با توضیحی که به طور پیش‌فرض برای آن خطا در سیستم تعریف شده است، در stderr چاپ می‌کند. این تابع معمولاً برای نمایش خطای یک تابع سیستم‌عامل مانند باز کردن فایل یا ایجاد فرآیند استفاده می‌شود.

### تعریف تابع:
```c
void perror(const char *s);
```
- s: این آرگومان یک رشته است که به عنوان توضیح اختیاری قبل از پیام خطا نمایش داده می‌شود
- stderr: پیغام خطا در این جریان چاپ می‌شود

مثال:
```c
#include <stdio.h>
#include <errno.h>

int main() {
    FILE *file;

    // تلاش برای باز کردن یک فایل که وجود ندارد
    file = fopen("nonexistent_file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
    }
    return 0;
}
```
خروجی احتمالی:
```yaml
Error opening file: No such file or directory
```
در این مثال، تابع fopen سعی می‌کند فایلی با نام nonexistent_file.txt را باز کند. چون فایل وجود ندارد، fopen مقدار NULL برمی‌گرداند و سپس تابع perror پیغام خطا را نمایش می‌دهد.


---

## تابع strerror
تابع strerror یک رشته توصیفی از پیغام خطایی که با errno مشخص شده است را برمی‌گرداند. این تابع زمانی مفید است که بخواهیم پیغام خطا را به شکل یک رشته دریافت و آن را در جاهای دیگر مثل لاگ سیستم استفاده کنیم.

### تعریف تابع:
```c
char *strerror(int errnum);
```
### خروجی:
این تابع یک اشاره‌گر به رشته‌ای برمی‌گرداند که توضیح خطا را به زبان محلی سیستم ارائه می‌دهد.

### مثال:
```c
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    FILE *file;

    // تلاش برای باز کردن یک فایل که وجود ندارد
    file = fopen("nonexistent_file.txt", "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
    }
    return 0;
}
```
### خروجی احتمالی:
```yaml
Error opening file: No such file or directory
```
در این مثال، وقتی fopen ناموفق می‌شود، مقدار errno تنظیم شده و تابع strerror پیغام خطای مربوط به مقدار errno را برمی‌گرداند که سپس در تابع printf چاپ می‌شود.


> پس فرق بین perror و strerror اینه که perror پیغام خطا رو مستقیماً تو stderr چاپ می‌کنه ولی strerror رشته توصیفی از خطا رو برمی‌گردونه که میتونیم اون رو تو جاهای دیگه برنامه هم استفاده کنیم

---

## تابع ferror
تابع ferror برای بررسی این که آیا خطایی در جریان فایل رخ داده است یا خیر، استفاده می‌شود. این تابع بررسی می‌کند که آیا عمل باز کردن، خواندن یا نوشتن فایل با خطا مواجه شده است.

### تعریف تابع:
```c
int ferror(FILE *stream);
```

### خروجی:
اگر خطایی رخ داده باشد، مقدار غیر صفر برمی‌گرداند و در غیر این صورت، مقدار صفر برمی‌گرداند.

### مثال:
```c
#include <stdio.h>

int main() {
    FILE *file = fopen("nonexistent_file.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
    } else {
        // بررسی خطا در فایل
        if (ferror(file)) {
            printf("Error occurred while reading the file.\n");
        }
        fclose(file);
    }
    return 0;
}
```
در این مثال، ferror بررسی می‌کند که آیا در جریان خواندن فایل خطایی رخ داده است یا خیر

---


## تابع clearerr
تابع clearerr برای پاک کردن نشانه‌های خطا و یا رسیدن به انتهای فایل (EOF) استفاده می‌شود. اگر یک خطا یا EOF در جریان فایل رخ دهد، با استفاده از این تابع می‌توان وضعیت خطا را ریست کرد تا عملیات بعدی فایل به درستی انجام شود.

### تعریف تابع:
```c
void clearerr(FILE *stream);
```
این تابع هیچ مقداری برنمی‌گرداند

### مثال:
``` c
#include <stdio.h>

int main() {
    FILE *file = fopen("nonexistent_file.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
    } else {
        // شبیه‌سازی یک خطا
        fgetc(file);  // تلاش برای خواندن از فایل
        if (ferror(file)) {
            printf("Error occurred! Clearing the error.\n");
            clearerr(file);  // پاک کردن وضعیت خطا
        }
        fclose(file);
    }
    return 0;
}
```

در این مثال، پس از بروز خطا، تابع clearerr وضعیت خطا را پاک می‌کند تا بتوان از فایل دوباره استفاده کرد.

---



## مدیریت تقسیم بر صفر (Division by Zero)
تقسیم بر صفر یک خطای ریاضی و منطقی در بسیاری از زبان‌های برنامه‌نویسی از جمله C است. اگر تلاش کنید که یک عدد را بر صفر تقسیم کنید، این عملیات منجر به رفتار نامشخص (undefined behavior) خواهد شد. در زبان C، می‌توان از شرط‌ها و بررسی‌ها برای جلوگیری از بروز این خطا استفاده کرد.

### مثال ساده برای بررسی تقسیم بر صفر:
```c
#include <stdio.h>

int main() {
    int numerator = 10;
    int denominator = 0;
    int result;

    if (denominator == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        result = numerator / denominator;
        printf("Result: %d\n", result);
    }

    return 0;
}
```

در این مثال، قبل از انجام عملیات تقسیم، برنامه بررسی می‌کند که آیا مخرج (denominator) صفر است یا خیر. اگر صفر باشد، پیغام خطا نمایش داده می‌شود و از انجام تقسیم جلوگیری می‌شود.

> تقسیم به صفر از سوتی های رایج برنامه نویس های تازه کاره!
