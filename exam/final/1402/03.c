#include <stdio.h>
#include <string.h>

// تابع بازگشتی برای بررسی پالیندروم بودن یک رشته
int isPalindrome(const char *str, int start, int end) {
    // پایه بازگشتی: اگر شروع و پایان به هم برخوردند یا شروع بیشتر از پایان شد، رشته پالیندروم است
    if (start >= end)
        return 1;

    // اگر کاراکترهای متناظر شروع و پایان با یکدیگر برابر نباشند، رشته پالیندروم نیست
    if (str[start] != str[end])
        return 0;

    // ادامه بررسی به کاراکترهای بعدی
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char input[101];
    scanf("%s", input);

    // فراخوانی تابع بازگشتی برای بررسی پالیندروم بودن رشته
    if (isPalindrome(input, 0, strlen(input) - 1))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
