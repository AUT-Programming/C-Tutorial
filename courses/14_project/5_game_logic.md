این کد که در فایل `gameloop.c` قرار دارد، اجزای اصلی حلقه بازی را پیاده‌سازی می‌کند. در ادامه به توضیح جزئیات هر بخش کد پرداخته خواهد شد:

### 1. شامل کردن هدرها و تعریف متغیرها

```c
#include "gameLoop.h"

// GameLoop Essentials
int EnemyCount, score, ShownScore, shownHealth, shownLevel, MaxEnemy, timer;
float cameraSpeed;

SDL_Surface *JetSurface, *MineSurface, *BomberSurface, *DroneSurface, *FighterSurface,
*ShipSurface, *bombSurface, *bulletUpSurface, *explodeSurface, *healthSurface;

SDL_Texture *JetTexture, *MineTexture, *BomberTexture, *DroneTexture, *FighterTexture,

*ShipTexture, *bombTexture, *bulletUpTexture, *explodeTexture, *healthTexture;

#define MAX_VECTOR 20
```

- **متغیرها**:

  - `EnemyCount`: تعداد دشمنان در بازی.

  - `score`: امتیاز کنونی بازیکن.

  - `ShownScore`: امتیاز نمایش داده شده.

  - `shownHealth`: سلامت نمایش داده شده.

  - `shownLevel`: سطح نمایش داده شده.

  - `MaxEnemy`: حداکثر تعداد دشمنان که می‌تواند در بازی وجود داشته باشد.

  - `timer`: زمان سپری شده بازی.

  - `cameraSpeed`: سرعت دوربین در بازی.

- **متغیرهای گرافیکی**:

  - `SDL_Surface` و `SDL_Texture` برای ذخیره و مدیریت بافت‌ها و تصویرهای مختلف بازی (هواپیما، مین، بمب‌افکن، و غیره).

### 2. ساختار Jet

```c
struct {

    int bulletLevel;
    int Health;
    int lastShot;
    SDL_Rect JetBulletRect[MAX_VECTOR];
    int JetBulletActive[MAX_VECTOR];
    SDL_Rect JetRect;
    int move[2]; // Number of pixels to move left-right, up-down
} Jet;
```

این ساختار برای ذخیره اطلاعات مربوط به جت (هواپیما) استفاده می‌شود:

- `bulletLevel`: سطح گلوله‌ها.

- `Health`: سلامت جت.

- `lastShot`: زمان آخرین شلیک.

- `JetBulletRect`: مستطیل‌های گلوله‌ها.

- `JetBulletActive`: وضعیت فعال بودن گلوله‌ها.

- `JetRect`: مستطیل موقعیت جت.

- `move`: حرکت جت در دو بعد افقی و عمودی.

### 3. بارگذاری بافت‌ها

```c

void loadBmp() {

    JetSurface = SDL_LoadBMP(JET_PP);

    SDL_SetColorKey(JetSurface, SDL_TRUE, SDL_MapRGB(JetSurface->format, 0, 0, 0));

    JetTexture = SDL_CreateTextureFromSurface(renderer, JetSurface);

    // بارگذاری بافت‌های دیگر... //

}

```

این تابع وظیفه بارگذاری تصاویر (بافت‌ها) را از فایل‌های BMP و تنظیم رنگ‌های شفاف را بر عهده دارد. این فرایند برای تمامی انواع دشمنان و اشیاء بازی تکرار می‌شود.

### 4. راه‌اندازی بازی

```c
void setupGame() {

    if (!isGameActive) loadBmp();

    cameraSpeed = 2 * 60 / FPS;

    MaxEnemy = 10;

    EnemyCount = 0;

    isGameActive = TRUE;

    score = 0;

    ShownScore = score;

    EnemyHead = NULL;

    Jet.bulletLevel = 1;

    shownLevel = Jet.bulletLevel;

    Jet.Health = 5;

    shownHealth = Jet.Health;

    Jet.lastShot = 0;

    Jet.JetRect.x = WIDTH / 2 - 70 / 2;

    Jet.JetRect.y = HEIGHT - 180;

    Jet.JetRect.w = 70;

    Jet.JetRect.h = 100;

    Jet.move[0] = 0;

    Jet.move[1] = 0;

    for (int i = 0; i < MAX_VECTOR; i++) {
        Jet.JetBulletActive[i] = FALSE;
        Jet.JetBulletRect[i].w = 3;
        Jet.JetBulletRect[i].h = 10;
    }

    timer = SDL_GetTicks();
}
```

این تابع تنظیمات اولیه بازی را انجام می‌دهد:

- بارگذاری بافت‌ها در صورت فعال نبودن بازی.

- تنظیمات اولیه برای دوربین، دشمنان و جت.

- مقداردهی اولیه به متغیرهای مربوط به گلوله‌ها.

### 5. رندر کردن بازی

```c

void renderGame() {

    clearRenderer();

    enemyStruct *current = EnemyHead;

    while (current != NULL) {

        // رندر کردن دشمنان با توجه به نوع آن‌ها... //

        current = current->next;

    }

    // رندر کردن گلوله‌ها و جت... //

    SDL_RenderPresent(renderer);

}

```

این تابع تمام عناصر بازی را برای نمایش در صفحه آماده می‌کند. شامل رندر کردن دشمنان، گلوله‌ها و جت و همچنین نمایش امتیاز، سلامت و سطح.

### 6. پردازش ورودی

```c

void processGame() {

    SDL_Event event;

    while (SDL_PollEvent(&event) != 0) {

        //بررسی ورودی‌ها و حرکت جت بر اساس کلیدهای فشرده شه... //

    }

    // بروزرسانی موقعیت جت... //

}

```

این تابع ورودی‌های کاربر را پردازش می‌کند و حرکات جت را بر اساس کلیدهای فشرده شده به‌روزرسانی می‌کند.

### 7. تولید دشمنان

```c

void SpawnEnemy() {

    if (EnemyCount > MaxEnemy) return;

    srand(SDL_GetTicks());

    int randSpawn = rand() % 30;

    switch (randSpawn) {

        case mineT:

            dropMine();

            break;

        // سایر نوع دشمنان... //

    }

}

```

این تابع دشمنان را بر اساس یک عدد تصادفی تولید می‌کند و تعداد دشمنان را بررسی می‌کند.

### 8. بروزرسانی وضعیت بازی

```c

void updateGame() {

    // بررسی امتیاز و تغییرات سرعت و حداکثر دشمنان... //

    SpawnEnemy();

    // بروزرسانی گلوله‌ها و برخوردها... //

}

```

این تابع وضعیت بازی را بروزرسانی می‌کند، از جمله بررسی امتیاز، تولید دشمن جدید و بروزرسانی سلامت جت و دشمنان.

### 9. دیگر توابع

تابع‌های دیگر مانند `dropExplode`، `updateMine`، و `delNode` وظایف خاصی را برای بروزرسانی یا حذف دشمنان، رندر کردن انفجارها و مدیریت لیست دشمنان انجام می‌دهند.

### 10. پایان بازی

```c

void ShowGameOver() {

    timer = (SDL_GetTicks() - timer) / 1000;

    freeNodes();

    storeLogs();

    secondMenu();

    if (!isGameActive) terminateGame();

}

```

این تابع زمانی که بازی به پایان می‌رسد، کارهای مربوط به ذخیره‌سازی و نمایش نتیجه را انجام می‌دهد.

### جمع‌بندی

کد `gameloop.c` حلقه اصلی بازی را مدیریت می‌کند و شامل بارگذاری بافت‌ها، پردازش ورودی، رندر کردن صحنه، و بروزرسانی وضعیت بازی می‌باشد. این ساختار و عملکرد کد به بازی اجازه می‌دهد تا با کاربر تعامل داشته باشد و در محیطی پویا به نمایش درآید.
