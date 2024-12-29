# مدیریت فایل‌ها در زبان C

## مقدمه
مدیریت فایل در C به شما کمک می‌کند داده‌ها را به‌طور دائم ذخیره کنید تا پس از بسته‌شدن برنامه، اطلاعات قابل دسترسی باقی بمانند. بدون استفاده از فایل‌ها، اطلاعات پس از پایان اجرای برنامه از دست می‌روند.

## انواع فایل‌ها
در زبان C، فایل‌ها به دو دسته اصلی تقسیم می‌شوند:

1. فایل‌های متنی (Text Files): حاوی داده‌های قابل خواندن برای انسان مانند فایل‌های .txt هستند.
2. فایل‌های باینری (Binary Files): داده‌ها در این فایل‌ها به‌صورت صفر و یک ذخیره شده و خواندن آن‌ها بدون برنامه دشوار است.

## مراحل کار با فایل‌ها
برای کار با فایل‌ها در زبان C، سه مرحله اصلی داریم:

1. باز کردن فایل با استفاده از `fopen` و تعیین حالت باز شدن (خواندن، نوشتن و غیره).
2. انجام عملیات روی فایل مانند خواندن یا نوشتن اطلاعات.
3. بستن فایل با استفاده از `fclose` تا منابع سیستم آزاد شوند.

### تابع `fopen`
برای باز کردن فایل از تابع fopen استفاده می‌کنیم. این تابع اشاره‌گری به فایل باز شده برمی‌گرداند. قالب کلی آن به این صورت است:
```c
FILE *file_pointer = fopen("filename.txt", "mode");
```
- **filename.txt**: نام فایل به همراه پسوند.
- **mode**: حالت باز کردن فایل، مثلاً `r` برای خواندن و `w` برای نوشتن.

### حالت‌های باز کردن فایل
| حالت | توضیح                                              |
|------|----------------------------------------------------|
| "r" | باز کردن فایل برای خواندن؛ خطا اگر فایل وجود نداشته باشد. |
| "w" | باز کردن فایل برای نوشتن؛ محتوا پاک می‌شود.               |
| "a" | باز کردن فایل برای افزودن به انتها؛ در صورت عدم وجود، ایجاد می‌شود. |
| "r+"| باز کردن فایل برای خواندن و نوشتن.                 |
| "w+"| باز کردن فایل برای خواندن و نوشتن؛ محتوا پاک می‌شود.       |
| "a+"| باز کردن فایل برای خواندن و افزودن.                |

### بستن فایل با `fclose`
هنگامی که کار شما با فایل تمام شد، باید فایل را ببندید. بستن فایل باعث می‌شود منابع سیستم آزاد شوند:
```c
fclose(file_pointer);
```
## نوشتن در فایل‌ها

### استفاده از `fprintf`
تابع `fprintf` مشابه `printf` است ولی به جای چاپ در صفحه، متن را در فایل می‌نویسد:
```c
FILE *fp = fopen("file.txt", "w");
if (fp != NULL) {
    fprintf(fp, "this is a text...");
    fclose(fp);
} else {
    printf("error");
}
```
### استفاده از `fputc` برای نوشتن کاراکتر
تابع `fputc` یک کاراکتر مشخص را در فایل می‌نویسد:
```c
fputc('A', fp);
```
### استفاده از `fputs` برای نوشتن رشته
تابع `fputs` یک رشته از کاراکترها را در فایل می‌نویسد:
```c
fputs("sample text...", fp);
```
## خواندن از فایل‌ها

### استفاده از `fscanf`
تابع `fscanf` مشابه `scanf` است و داده‌ها را از فایل به‌صورت فرمت‌بندی‌شده می‌خواند:
```c
FILE *fp = fopen("file.txt", "r");
if (fp != NULL) {
    char str[50];
    fscanf(fp, "%s", str);
    printf("text from the file: %s", str);
    fclose(fp);
} else {
    printf("error");
}
```
### استفاده از `fgetc` برای خواندن کاراکتر
تابع `fgetc` یک کاراکتر را از فایل می‌خواند:
```c
char ch = fgetc(fp);
```
### استفاده از `fgets` برای خواندن رشته
تابع `fgets` یک خط از فایل را می‌خواند و در رشته ذخیره می‌کند:
```c
fgets(buffer, sizeof(buffer), fp);
```
## توابع کاربردی دیگر

### بررسی انتهای فایل با `feof`
تابع `feof` بررسی می‌کند که آیا به انتهای فایل رسیده‌ایم:
```c
while (!feof(fp)) {
    char ch = fgetc(fp);
    printf("%c", ch);
}
```
### `fseek` و `ftell` برای جابجایی در فایل
برای جابجایی اشاره‌گر در فایل از `fseek` استفاده می‌شود، و `ftell` موقعیت فعلی اشاره‌گر را برمی‌گرداند:
```c
fseek(fp, 0, SEEK_END); // انتقال به انتهای فایل
long pos = ftell(fp);   // گرفتن موقعیت فعلی
```
### بازگشت به ابتدای فایل با `rewind`
تابع `rewind` اشاره‌گر فایل را به ابتدای فایل بازمی‌گرداند:
```c
rewind(fp);
```
## فایل‌های باینری
فایل‌های باینری داده‌ها را به‌صورت خام ذخیره می‌کنند. برای خواندن و نوشتن در این فایل‌ها از `fread` و `fwrite` استفاده می‌شود.

### `fwrite`
این تابع داده‌ها را به صورت باینری در فایل ذخیره می‌کند:
```c
fwrite(&data, sizeof(data), 1, fp);
```
### `fread`
این تابع داده‌ها را از فایل باینری می‌خواند:
```c
fread(&data, sizeof(data), 1, fp);
```


## مثال بیشتر: ذخیره و بازیابی ساختارها
در این مثال، داده‌های یک ساختار به‌صورت باینری ذخیره و سپس بازیابی می‌شود.

```c
#include <stdio.h>

struct Student {
    char name[50];
    int age;
};

int main() {
    struct Student student = {"Ali", 20};

    // نوشتن ساختار در فایل
    FILE *fp = fopen("student.dat", "wb");
    if (fp != NULL) {
        fwrite(&student, sizeof(student), 1, fp);
        fclose(fp);
    } else {
        printf("error!!!");
    }

    // خواندن ساختار از فایل
    fp = fopen("student.dat", "rb");
    if (fp != NULL) {
        fread(&student, sizeof(student), 1, fp);
        printf("name: %s\nage: %d", student.name, student.age);
        fclose(fp);
    } else {
        printf("error!!!");
    }

    return 0;
}
```
## نتیجه‌گیری
مدیریت فایل‌ها در C به شما امکان می‌دهد که داده‌ها را به‌طور دائم ذخیره و بازیابی کنید. این قابلیت به ویژه در برنامه‌های پیچیده بسیار مهم است. با تمرین و استفاده از توابع معرفی‌شده در این درسنامه، می‌توانید مهارت‌های خود را در کار با فایل‌ها در زبان C تقویت کنید.