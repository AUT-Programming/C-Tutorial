### توضیح کامل کد فایل `menu.c` از پروژه:

---

### 1. **تعریف (Header files)**
```c
#include "menu.h"
```
این خط فایل هدر `menu.h` را وارد می‌کند که در آن توابع و تعاریف مورد نیاز برای منو تعریف شده است.

---

### 2. **تعریف مقادیر و ساختارهای منو**
```c
#define MPX (WIDTH / 2 - WIDTH / 3 / 2 - 100 - 20)
#define MPY (HEIGHT / 3 + 30 - 5)
#define MPM (90)
```
- **`MPX`** و **`MPY`**: مختصات شروع مکان‌نما (Pointer) منو را تنظیم می‌کنند. این مقادیر به‌صورت نسبتی از عرض و ارتفاع صفحه تعریف شده‌اند تا مکان‌نما در محل مناسبی قرار گیرد.
- **`MPM`**: فاصله بین گزینه‌های منو را مشخص می‌کند (90 پیکسل).

```c
SDL_Rect MenuPointer1 = {MPX, MPY, 100, 5};
SDL_Rect MenuPointer2 = {MPX + 100 + WIDTH / 3 + 20 * 2 - 5, MPY, 100, 5};
```
- **`MenuPointer1`** و **`MenuPointer2`**: این دو مستطیل مختصات و اندازه مکان‌نماهای منو را ذخیره می‌کنند. این مکان‌نماها در منو برای انتخاب گزینه‌ها استفاده می‌شوند.

```c
SDL_Color White = {255, 255, 255};
SDL_Color Blue = {0, 255, 255};
TTF_Font *mFont = NULL;
SDL_Surface *tmpMSGS, *GameBGS;
SDL_Texture *tmpMSGT, *GameBGT;
```
- **`SDL_Color White`** و **`Blue`**: این‌ها رنگ‌های سفید و آبی هستند که در نمایش متن‌ها و گرافیک‌ها در منو استفاده می‌شوند.
- **`TTF_Font *mFont`**: اشاره‌گری به فونت مورد استفاده در منو.
- **`tmpMSGS`, `tmpMSGT`, `GameBGS`, `GameBGT`**: این‌ها برای مدیریت سطوح و تکسچرهای گرافیکی که در منو نمایش داده می‌شوند استفاده می‌شوند.

---

### 3. **تابع `setupMenu` (تنظیم منو)**
```c
void setupMenu() {
    mFont = TTF_OpenFont(FONT_P, 100);

    GameBGS = SDL_LoadBMP(GAME_BGP);
    GameBGT = SDL_CreateTextureFromSurface(renderer, GameBGS);
}
```
- **`TTF_OpenFont`**: فونت مورد استفاده در منو را باز می‌کند. اندازه فونت 100 است.
- **`SDL_LoadBMP`**: پس‌زمینه بازی را از یک فایل BMP بارگذاری می‌کند.
- **`SDL_CreateTextureFromSurface`**: پس‌زمینه بارگذاری شده را به یک تکسچر تبدیل می‌کند تا در رندرر استفاده شود.

---

### 4. **تابع `RenderMenu` (رندر کردن منو)**
```c
void RenderMenu() {
    clearRenderer();

    SDL_Rect tmpMSGRect = {WIDTH / 2 - (WIDTH * 2 / 3) / 2, HEIGHT / 8, WIDTH * 2 / 3, 100};
    char tmpText[40] = {0};
    sprintf(tmpText, "SPACE  DANCE");
    renderMSG(tmpText, &tmpMSGRect, &Blue);
    
    tmpMSGRect.w = WIDTH / 3;
    tmpMSGRect.h = 50;
    tmpMSGRect.x = WIDTH / 2 - tmpMSGRect.w / 2;
    for (int i = 0; i < 3; i++) setMenuOptions(i, &tmpMSGRect);
    
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_RenderFillRect(renderer, &MenuPointer1);
    SDL_RenderFillRect(renderer, &MenuPointer2);

    tmpMSGRect.w = 380;
    tmpMSGRect.h = 18;
    tmpMSGRect.x = 10;
    tmpMSGRect.y = HEIGHT - 18 - 10;
    renderMSG("Keys : Esc, space, up, down, left, right", &tmpMSGRect, &White);

    tmpMSGRect.w = 120;
    tmpMSGRect.h = 18;
    tmpMSGRect.x = WIDTH - 120 - 10;
    tmpMSGRect.y = HEIGHT - 18 - 10;
    renderMSG("AUT University", &tmpMSGRect, &White);

    tmpMSGRect.w = 400;
    tmpMSGRect.h = 20;
    tmpMSGRect.x = WIDTH / 2 - 200;
    tmpMSGRect.y = HEIGHT * 4 / 5;
    renderMSG("Developed by mohammad Javad Akbari", &tmpMSGRect, &White);

    SDL_RenderPresent(renderer);
}
```
- **`clearRenderer`**: صفحه را تمیز می‌کند و پس‌زمینه بازی را تنظیم می‌کند.
- **`renderMSG`**: متنی را روی صفحه نمایش می‌دهد.
- **نمایش "SPACE DANCE"**: عنوان اصلی بازی با استفاده از `renderMSG` نمایش داده می‌شود.
- **`setMenuOptions`**: گزینه‌های منو (بازی، لاگ‌ها، خروج) را نمایش می‌دهد.
- **`SDL_RenderFillRect`**: مکان‌نماها را برای انتخاب گزینه‌ها در منو رسم می‌کند.
- **نمایش کلیدهای کنترل**: راهنمای کلیدهای کنترل نمایش داده می‌شود.
- **نمایش "AUT University"**: نام دانشگاه نمایش داده می‌شود.
- **نمایش توسعه‌دهنده**: نام توسعه‌دهنده نمایش داده می‌شود.

---

### 5. **تابع `setMenuOptions` (تنظیم گزینه‌های منو)**
```c
void setMenuOptions(int ind, SDL_Rect *tmpMSGRect) {
    char tmpText[40] = {0};
    tmpMSGRect->y = HEIGHT / 3 + ind * MPM;
    switch (ind) {
        case 0:
            sprintf(tmpText, "Play");
            break;
        case 1:
            sprintf(tmpText, "Logs");
            break;
        case 2:
            sprintf(tmpText, "Exit");
            break;
    }
    renderMSG(tmpText, tmpMSGRect, &White);
}
```
- این تابع سه گزینه منوی "Play"، "Logs"، و "Exit" را در مکان مناسب نمایش می‌دهد.

---

### 6. **تابع `processMenu` (پردازش منو)**
```c
void processMenu() {
    SDL_Event event;
    SDL_WaitEvent(&event);

    if (event.type == SDL_QUIT)
        isMenuActive = FALSE;
    else if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
                isMenuActive = FALSE;
                exit(0);
            case SDLK_DOWN:
                if (MenuPointer1.y < MPY + 2 * MPM) {
                    MenuPointer1.y += MPM;
                    MenuPointer2.y += MPM;
                }
                break;
            case SDLK_UP:
                if (MenuPointer1.y > MPY) {
                    MenuPointer1.y -= MPM;
                    MenuPointer2.y -= MPM;
                }
                break;
            case SDLK_RETURN:
                if (MenuPointer1.y == MPY) {
                    setupGame();
                } else if (MenuPointer1.y == MPY + 1 * MPM) {
                    showScores();
                } else if (MenuPointer1.y == MPY + 2 * MPM) {
                    isMenuActive = FALSE;
                }
                break;
        }
    }
}
```
- **پردازش رویدادهای منو**: با دریافت ورودی‌های کلید (بالا، پایین، اینتر و ESC)، مکان‌نما جابجا می‌شود یا اقدامات مناسب (شروع بازی، نمایش امتیازها، خروج از منو) انجام می‌گیرد.

---

### 7. **تابع `showScores` (نمایش امتیازات)**
```c
void showScores() {
    clearRenderer();

    SDL_Rect tmpMSGRect = {WIDTH / 10, HEIGHT / 10, 350, 30};
    renderMSG("Your Scores List", &tmpMSGRect, &White);

    tmpMSGRect.w = 420;
    tmpMSGRect.h = 20;
    tmpMSGRect.y += 50;
    tmpMSGRect.x += 50;

    FILE *list = fopen(LIST_P, "rb");
    if (list == NULL) {
        renderMSG("File is not found !", &tmpMSGRect, &Blue);
    } else {
        if (getc(list) == EOF){
            renderMSG("Empty            ", &tmpMSGRect, &Blue);
        }
        else {
            rewind(list);
            fseek(list, -97, SEEK_END);

            for (int i = 0; i <= (HEIGHT - 200) / 40 / 2; i++) {
                char tmpText[60] = {0};
                fread(tmpText, 42, 1, list);
                renderMSG(tmpText, &tmpMSGRect, &Blue);

                fread(tmpText

, 55, 1, list);
                tmpMSGRect.y += 30;
                renderMSG(tmpText, &tmpMSGRect, &Blue);

                tmpMSGRect.y += 40;

                fseek(list, -194, SEEK_CUR);
                if (ftell(list) == SEEK_SET) i = (HEIGHT - 200) / 40 / 2 - 1;
            }
        }
    }

    if (list != NULL) fclose(list);
    SDL_RenderPresent(renderer);

    waitClick();
}
```
- **نمایش لیست امتیازات**: این تابع امتیازات کاربر را از فایل لیست امتیازات بارگذاری و نمایش می‌دهد. 

---

### 8. **توابع کمکی دیگر**
- **`secondMenu`**: منوی دوم برای انتخاب مجدد بازی یا بازگشت به منوی اصلی را مدیریت می‌کند.
- **`renderMSG`**: متن را در موقعیت و با رنگ مشخص شده روی صفحه نمایش می‌دهد.
- **`clearRenderer`**: صفحه را تمیز می‌کند و پس‌زمینه را مجدداً نمایش می‌دهد.
- **`waitClick`**: منتظر یک کلیک از کاربر می‌ماند.

---

