#  حلقه‌ها

در زبان برنامه‌نویسی C، حلقه‌ها ابزاری برای اجرای تکراری مجموعه‌ای از دستورات هستند. به کمک حلقه‌ها می‌توان یک قطعه کد را برای تعداد مشخصی از دفعات یا تا زمانی که شرط خاصی برقرار است اجرا کرد. در ادامه به بررسی کامل و جزئیات حلقه‌ها در C می‌پردازیم:

> مراقب باشید تو دام حلقه های بی‌نهایت زندگی نیفتید!
  
####  انواع حلقه‌ها
+ حلقه for
+ حلقه while
+ حلقه do-while

این سه حلقه، بسته به نیاز و موقعیت، قابل استفاده هستند. در ادامه هر کدام را به همراه جزئیات و مثال‌های پیشرفته‌تر بررسی می‌کنیم.

---

## حلقه for

حلقه for برای زمانی مناسب است که می‌دانیم چند بار قرار است یک بخش از کد تکرار شود. ساختار کلی حلقه for به شکل زیر است:
```c
for (initialization; condition; increment/decrement) {
    // Code to be executed
}
```
اجزای حلقه for:
1. مقداردهی اولیه (initialization): معمولاً در این بخش، متغیری را برای شمارش دفعات اجرای حلقه تعریف و مقداردهی اولیه می‌کنیم.
2.  شرط (condition): در هر بار اجرای حلقه، این شرط بررسی می‌شود. تا زمانی که شرط برقرار باشد (یعنی True باشد) حلقه اجرا می‌شود.
3. دستور (expression): بعد از هر بار اجرای دستورات درون حلقه، این قسمت اجرا می‌شود تا متغیر شمارنده به‌روز رسانی شود.

#### مثال ساده از حلقه for:

```c
#include <stdio.h>

int main() {
    for (int i = 0; i < 5; i++) {
        printf("i = %d\n", i);
    }
    
    return 0;
}
```
#### خروجی:
```
i = 0
i = 1
i = 2
i = 3
i = 4
```

#### چند نکته در حلقه for

1. چندین مقداردهی اولیه و به‌روزرسانی:
 در حلقه for، می‌توان چندین متغیر را مقداردهی و به‌روزرسانی کرد.

```c
#include <stdio.h>

int main() {
    for (int i = 0, j = 10; i < j; i++, j--) {
        printf("i = %d, j = %d\n", i, j);
    }

    return 0;
}
```
#### خروجی:
```
i = 0, j = 10
i = 1, j = 9
i = 2, j = 8
i = 3, j = 7
i = 4, j = 6
```
2. حذف هر بخش از حلقه:

در C، می‌توان هرکدام از سه قسمت حلقه for را حذف کرد، به شرطی که ساختار باقی‌مانده منطقی باشد. برای مثال، می‌توان مقداردهی اولیه را بیرون از حلقه انجام داد و بخش افزایش را به صورت دستی داخل بدنه حلقه قرار داد.

#### مثال:
```c
#include <stdio.h>

int main() {
    int i = 0;

    for (; i < 5;) {
        printf("i = %d\n", i);
        i++;
    }

    return 0;
}
```
---

## حلقه while

حلقه while زمانی استفاده می‌شود که تعداد تکرار مشخص نیست، اما تا زمانی یک شرط که برقرار باشد، حلقه اجرا می‌شود.

ساختار کلی حلقه while:
```c
while (condition) {
    // Code to be executed
}
```
اجزای حلقه while:

1.  شرط (condition): شرطی که قبل از هر بار اجرای حلقه بررسی می‌شود. اگر شرط True=1 باشد، دستورات داخل حلقه اجرا می‌شوند؛ در غیر این صورت، حلقه متوقف می‌شود.

#### مثال ساده از حلقه while:
```c
#include <stdio.h>

int main() {
    int i = 0;

    while (i < 5) {
        printf("i = %d\n", i);
        i++;
    }

    return 0;
}
```
#### خروجی مشابه با حلقه for:
```
i = 0
i = 1
i = 2
i = 3
i = 4
```



## حلقه do-while

حلقه do-while مشابه حلقه while است، اما با این تفاوت که پس از اجرای بدنه حلقه شرط آن بررسی می‌شود. بنابراین، این نوع حلقه حداقل یک بار اجرا خواهد شد، حتی اگر شرط نادرست باشد.

ساختار کلی حلقه do-while:
```c
do {
    // Code to be executed
} while (condition);
```
#### مثال ساده از حلقه do-while:
```
#include <stdio.h>

int main() {
    int i = 0;
    
    do {
        printf("i = %d\n", i);
        i++;
    } while (i < 5);

    return 0;
}
```
#### خروجی:
```
i = 0
i = 1
i = 2
i = 3
i = 4
```

### کاربرد do-while در ورودی‌گیری از کاربر:

یکی از کاربردهای متداول حلقه do-while، گرفتن ورودی معتبر از کاربر است. برای مثال، اگر بخواهیم کاربر تا زمانی که ورودی معتبر وارد نکرده، دوباره ورودی بگیرد:
```
#include <stdio.h>

int main() {
    int input;

    do {
        printf("یک عدد بین 1 تا 10 وارد کنید: ");
        scanf("%d", &input);
    } while (input < 1 || input > 10);

    printf("عدد وارد شده: %d\n", input);

    return 0;
}
```
---

## حلقه‌های بی‌نهایت

یک حلقه با شرطی که همیشه درست باشد (True)، تا بی‌نهایت اجرا خواهد شد. برای مثال:
```c
#include <stdio.h>

int main() {
    while (1) {
        printf("این حلقه بی‌نهایت است.\n");
    }

    return 0;
}
```
برای کنترل خروج از چنین حلقه‌هایی، معمولاً از دستورات کنترلی مثل break استفاده می‌شود که در ادامه بررسی می کنیم.

---
## دستورات کنترلی
در زبان C، دستورات break و continue دو دستور کنترلی مهم هستند که برای کنترل جریان اجرای حلقه‌ها استفاده می‌شوند. این دستورات به شما اجازه می‌دهند تا به صورت انتخابی از برخی تکرارهای حلقه‌ها بگذرید یا حلقه‌ها را زودتر از موعد پایان دهید. در ادامه به صورت کامل این دستورات را توضیح خواهیم داد.


### دستور break

دستور break باعث خروج فوری از حلقه می‌شود. زمانی که این دستور اجرا می‌شود، حلقه جاری بلافاصله متوقف شده و کنترل برنامه به اولین دستور بعد از حلقه منتقل می‌شود. این دستور را می‌توان در حلقه‌های for، while، do-while و همچنین در بلوک‌های switch استفاده کرد.

#### ساختار:
```c
for (initialization; condition; increment) {
    if (some_condition) {
        break;
    }

    // Code to be executed
}
```
#### مثال:
```c
#include <stdio.h>

int main() {
    int i;

    for (i = 0; i < 10; i++) {
        if (i == 5) {
            break;  // وقتی i برابر 5 شد، حلقه را متوقف کن
        }

        printf("i = %d\n", i);
    }

    return 0;
}
```

توضیح مثال:

در اینجا، حلقه for از مقدار i = 0 تا i = 9 اجرا می‌شود. اما به محض اینکه مقدار i به 5 رسید، دستور break اجرا می‌شود و حلقه به پایان می‌رسد، بنابراین مقادیر i بزرگ‌تر از 4 چاپ نخواهند شد.

#### خروجی:
```c
i = 0
i = 1
i = 2
i = 3
i = 4
```

### دستور continue

دستور continue باعث می‌شود که اجرای دستورات باقی‌مانده در آن تکرار از حلقه متوقف شود و کنترل برنامه به ابتدای حلقه بازگردد تا شرط حلقه دوباره بررسی شود. در واقع، این دستور باعث می‌شود که حلقه فعلی نیمه‌کاره رها شود و تکرار بعدی حلقه شروع شود.

ساختار:
```c
for (initialization; condition; increment) {
    if (some_condition) {
        continue;
    }

    // Code to be executed
}
```
#### مثال:
```c
#include <stdio.h>

int main() {
    int i;

    for (i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            continue;
        }

        printf("i = %d\n", i);
    }

    return 0;
}
```
توضیح مثال:

در این مثال، هر زمان که مقدار i زوج باشد، دستور continue اجرا می‌شود. این به این معناست که وقتی i زوج است، از آن تکرار حلقه عبور می‌شود و دستور printf اجرا نمی‌شود. به این ترتیب، تنها مقادیر فرد i چاپ می‌شوند.

خروجی:
```
i = 1
i = 3
i = 5
i = 7
i = 9
```


#### تفاوت‌های کلیدی بین break و continue:

1. دستور break:
+ حلقه را به طور کامل خاتمه می‌دهد و اجرای حلقه متوقف می‌شود.
+ کنترل به دستور بعد از حلقه منتقل می‌شود.
+ در همه انواع حلقه‌ها (for، while، do-while) و همچنین بلوک‌های switch کاربرد دارد.

2. دستور continue:
+ تنها تکرار فعلی حلقه را متوقف می‌کند و به جای خاتمه حلقه، کنترل به ابتدای حلقه برمی‌گردد تا تکرار بعدی آغاز شود.
+فقط برای حلقه‌ها (نه بلوک‌های switch) استفاده می‌شود.

#### مثال ترکیبی از break و continue:

در این مثال، از هر دو دستور break و continue استفاده شده است تا تفاوت آن‌ها به خوبی مشخص شود:
```c
#include <stdio.h>

int main() {
    int i;

    for (i = 0; i < 10; i++) {
        if (i == 7) {
            break;  
        }

        if (i % 2 == 0) {
            continue;  
        }

        printf("i = %d\n", i);
    }

    return 0;
}
```
توضیح مثال:

اگر مقدار i برابر 7 شود، دستور break اجرا شده و حلقه فوراً پایان می‌یابد.

اگر مقدار i زوج باشد، دستور continue اجرا شده و آن تکرار خاص حلقه بدون چاپ مقدار i عبور می‌شود.

بنابراین فقط مقادیر فرد i تا قبل از 7 چاپ می‌شوند.

#### خروجی:
```
i = 1
i = 3
i = 5
```
در اینجا:

وقتی i = 0 است، دستور continue اجرا می‌شود و تکرار اول حلقه نادیده گرفته می‌شود.

وقتی i = 2، 4، 6 هستند، دستور continue باعث عبور از آن‌ها می‌شود.

وقتی i = 7 می‌شود، دستور break باعث توقف کامل حلقه می‌شود.

---
## جمع‌بندی

1. حلقه for: برای زمانی مناسب است که تعداد تکرارها از پیش مشخص باشد. ساختار آن شامل مقداردهی اولیه، شرط و افزایش یا کاهش است.

2. حلقه while: برای زمانی که شرط مشخصی برای ادامه تکرار وجود دارد و ممکن است تعداد دفعات تکرار از قبل مشخص نباشد.

3. حلقه do-while: مشابه while است، با این تفاوت که بدنه حلقه حداقل یک بار اجرا می‌شود، حتی اگر شرط اولیه برقرار نباشد.

4. همچنین، دستورات کنترلی مانند break و continue می‌توانند کنترل دقیق‌تری بر اجرای حلقه‌ها ایجاد کنند.

---

## تمرین

برنامه‌ای بنویسید که یک عدد صحیح n را از ورودی بگیرد و یک مثلث متساوی‌الاضلاع با ارتفاع n را با استفاده از کاراکتر * چاپ کند.

اگر ورودی n = 5 باشد، خروجی به شکل زیر است:

```
    *
   ***
  *****
 *******
*********
```

#### پاسخ:
```c
#include <stdio.h>

int main() {
    int n;
    printf("ارتفاع مثلث را وارد کنید: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
```

توضیح کد:

حلقه اول (for (int i = 1; i <= n; i++)) برای چاپ هر ردیف از مثلث استفاده می‌شود.

حلقه دوم فاصله‌ها را چاپ می‌کند تا ستاره‌ها در وسط قرار بگیرند.

حلقه سوم تعداد مناسبی از ستاره‌ها را برای هر ردیف چاپ می‌کند. تعداد ستاره‌ها در هر ردیف برابر است با 2 * i - 1 ، که به شکل متساوی‌الاضلاع می‌انجامد.