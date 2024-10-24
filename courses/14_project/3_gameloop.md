برای توضیح دقیق پروژه **SPACE DANCE**، هر بخش از کد را قدم به قدم بررسی می‌کنیم. از ‍‍`main.c` شروع می کنیم.

### 1. **بخش (Headers) و تعریف‌ها**

```c

#define SDL_MAIN_HANDLED

#include "menu.h"

#include "gameLoop.h"

#include "essentials.h"

```

- **`#define SDL_MAIN_HANDLED`**: این خط تضمین می‌کند که SDL تابع `main` را خودش مدیریت نمی‌کند و ما کنترل کاملی روی تابع `main` داریم.

- **`#include "menu.h"`**: این فایل هدر شامل توابع و ساختارهای لازم برای مدیریت منوی بازی است.

- **`#include "gameLoop.h"`**: این فایل هدر شامل توابع مربوط به حلقه‌ی اصلی بازی و مدیریت جریان بازی است.

- **`#include "essentials.h"`**: این فایل شامل تعاریف مهمی مانند ابعاد صفحه نمایش (`WIDTH` و `HEIGHT`)، تنظیمات صدا، و سایر مقادیر ثابت مورد نیاز در بازی است.

### 2. **تعریف متغیرها و اشاره‌گرها**

```c

SDL_Rect ScreenRect = {0, 0, WIDTH, HEIGHT};

SDL_Window *window = NULL;

SDL_Renderer *renderer = NULL;

Mix_Music* backgroundMusic = NULL;

int isMenuActive = FALSE, isGameActive = FALSE, LastTick;

```

- **`SDL_Rect ScreenRect`**: مستطیلی که ابعاد صفحه نمایش را با استفاده از مقادیر ثابت `WIDTH` و `HEIGHT` مشخص می‌کند.

- **`SDL_Window *window`**: اشاره‌گری به پنجره‌ی اصلی بازی که توسط SDL مدیریت می‌شود.

- **`SDL_Renderer *renderer`**: اشاره‌گری به رندرر، که برای کشیدن گرافیک‌ها و اشیاء روی صفحه استفاده می‌شود.

- **`Mix_Music* backgroundMusic`**: اشاره‌گری به موسیقی پس‌زمینه که توسط SDL_mixer برای پخش موسیقی استفاده می‌شود.

- **`isMenuActive` و `isGameActive`**: متغیرهایی که وضعیت فعال بودن منو و بازی را مدیریت می‌کنند.

- **`LastTick`**: برای ذخیره‌ی زمانی که آخرین فریم بازی پردازش شد، به منظور کنترل نرخ فریم‌ها.

### 3. **تعریف توابع `init` و `ShutDown`**

```c

int init();

void ShutDown();

```

- **`init`**: تابعی که برای مقداردهی اولیه‌ی SDL و اجزای مختلف بازی استفاده می‌شود.

- **`ShutDown`**: تابعی که برای آزادسازی منابع استفاده‌شده در پایان بازی کاربرد دارد.

### 4. **تابع اصلی `main`**

```c
int main() {
    atexit(ShutDown);
    isMenuActive = init();

    // main loop to run the game
    setupMenu();
    while (isMenuActive) {

        RenderMenu();

        processMenu();

        // GameLoop and frame rate controller
        while (isMenuActive && isGameActive) {
            renderGame();
            processGame();
            updateGame();

            int wait = FRAME_TIME - (SDL_GetTicks() - LastTick);

            if (wait > 0 && wait <= FRAME_TIME) SDL_Delay(wait);

            LastTick = SDL_GetTicks();
        }
    }

    return 0;
}
```

- **`atexit(ShutDown)`**: این خط تابع `ShutDown` را ثبت می‌کند تا هنگام پایان بازی به صورت خودکار منابع آزاد شوند.

- **`isMenuActive = init();`**: تابع `init` فراخوانی شده و وضعیت منو تنظیم می‌شود.

#### حلقه‌ی اصلی بازی

- **`setupMenu();`**: منوی بازی آماده می‌شود.

- **`while (isMenuActive)`**: تا زمانی که منو فعال است، تابع‌های `RenderMenu` و `processMenu` برای رندر و پردازش منو اجرا می‌شوند.

#### حلقه‌ی بازی

- **`while (isMenuActive && isGameActive)`**: این حلقه زمانی اجرا می‌شود که هم منو و هم بازی فعال باشند. در اینجا:

    - **`renderGame()`**: محتوای گرافیکی بازی روی صفحه نمایش داده می‌شود.

    - **`processGame()`**: ورودی‌های کاربر و پردازش‌های بازی اجرا می‌شوند.

    - **`updateGame()`**: وضعیت بازی به‌روزرسانی می‌شود.

#### کنترل نرخ فریم

- **`SDL_Delay`**: برای ثابت نگه داشتن نرخ فریم‌ها، زمان انتظار محاسبه می‌شود و در صورت نیاز، بازی به تأخیر می‌افتد تا نرخ فریم پایدار بماند.

- **`LastTick`**: به‌روزرسانی زمان آخرین تیک (فریم) برای محاسبه زمان سپری‌شده از فریم قبلی.

### 5. **تابع `init` (مقداردهی اولیه)**

```c
int init() {
    TTF_Init();

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "window error");
        return FALSE;
    }

    if (SDL_Init(SDL_INIT_EVENTS) != 0) {
        fprintf(stderr, "window error");
        return FALSE;
    }

    if (SDL_Init(SDL_INIT_TIMER) != 0) {
        fprintf(stderr, "window error");
        return FALSE;
    }

    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return FALSE;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return FALSE;
    }

    window = SDL_CreateWindow(
            "Space Dance",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WIDTH,
            HEIGHT,
            SDL_WINDOW_SHOWN
    );

    if (window == NULL) {
        fprintf(stderr, "window error");
        return FALSE;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL) {
        fprintf(stderr, "render error");
        return FALSE;
    }

    backgroundMusic = Mix_LoadMUS(MUSIC_P);

    if (backgroundMusic == NULL) {
        printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
        return FALSE;
    }

    // Play the music indefinitely (-1 means loop)

    Mix_PlayMusic(backgroundMusic, -1);

    return TRUE;
}
```

- این تابع، تمام اجزای لازم برای اجرای بازی را مقداردهی می‌کند:

    - **`TTF_Init()`**: مقداردهی برای استفاده از فونت‌های TrueType.

    - **`SDL_Init`**: ماژول‌های مختلف SDL (ویدیو، رویدادها، تایمرها و صدا) مقداردهی می‌شوند.

    - **`Mix_OpenAudio`**: کتابخانه SDL_mixer برای پخش صدا مقداردهی می‌شود.

    - **`SDL_CreateWindow`**: یک پنجره جدید برای بازی ایجاد می‌شود.

    - **`SDL_CreateRenderer`**: یک رندرر برای رسم اشیاء گرافیکی روی پنجره ایجاد می‌شود.

    - **`Mix_LoadMUS`**: موسیقی پس‌زمینه بازی بارگذاری می‌شود.

    - **`Mix_PlayMusic`**: موسیقی پس‌زمینه به صورت مداوم (بی‌نهایت بار) پخش می‌شود.

### 6. **تابع `ShutDown` (پایان برنامه و آزادسازی منابع)**

```c

void ShutDown() {

    if (tmpMSGT != NULL) SDL_DestroyTexture(tmpMSGT);

    if (tmpMSGS != NULL) SDL_FreeSurface(tmpMSGS);

    if (GameBGT != NULL) SDL_DestroyTexture(GameBGT);

    if (GameBGS != NULL) SDL_FreeSurface(GameBGS);

    if (renderer != NULL) SDL_DestroyRenderer(renderer);

    if (window != NULL) SDL_DestroyWindow(window);

    TTF_CloseFont(mFont);

    TTF_Quit();

    Mix_FreeMusic(backgroundMusic);

    Mix_CloseAudio();

    SDL_Quit();

}

```

- این تابع برای آزادسازی تمام منابعی که در طول بازی استفاده شده‌اند استفاده می‌شود:

    - تخریب **تکسچرها** و **سطوح** (Textures و Surfaces) ایجادشده.

    - تخریب رندرر و پنجره.

    - آزادسازی موسیقی و بستن سیستم صدا.

    - بستن و پایان دادن به SDL.

این فایل main.c، اسکلت اصلی بازی را پیاده‌سازی می‌کند که در آن حلقه‌های منو و بازی به طور مداوم اجرا می‌شوند و ورودی‌های کاربر پردازش می‌گردند.
