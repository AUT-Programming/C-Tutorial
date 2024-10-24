### ساختار پروژه و ابزارهای ساخت

در این فصل، به شما خواهیم آموخت که چگونه ساختار پروژه را با پوشه‌های `src`، `include`، `assets` و فایل‌های Makefile و CMakeLists.txt ایجاد کنید. همچنین نحوه نصب ابزارها و دلایل استفاده از CMake به جای Makefile را بررسی می‌کنیم.

#### ۱. نصب ابزارها

قبل از شروع، باید اطمینان حاصل کنید که ابزارهای `make` و `cmake` بر روی سیستم شما نصب شده‌اند.

#### ۲. استفاده از Makefile

Makefile ابزاری است که به شما امکان می‌دهد تا فرآیند ساخت پروژه را به راحتی مدیریت کنید. در اینجا یک مثال از Makefile برای ساخت و اجرای برنامه در سیستم‌های لینوکس و ویندوز آورده شده است:

**محتوای Makefile:**

```makefile
executeLinux:
    gcc -Wall -std=c11 ./src/*.c -lSDL2 -lSDL2_ttf -lSDL2_mixer -o SpaceDanceLinux
    ./SpaceDanceLinux
    rm SpaceDanceLinux

executeWindows:
    gcc -std=c11 .\src\main.c .\src\menu.c .\src\gameLoop.c -Wall -mwindows -lmingw32-lSDL2 -lSDL2_ttf -lSDL2_mixer -o SpaceDanceWindows
    .\SpaceDanceWindows
    del "SpaceDanceWindows.exe"

buildLinux:
    gcc -Wall -std=c11 ./src/*.c -lSDL2 -lSDL2_ttf -lSDL2_mixer -o SpaceDanceLinux

buildWindows:
    gcc -std=c11 .\src\main.c .\src\menu.c .\src\gameLoop.c -Wall -mwindows -lmingw32-lSDL2 -lSDL2_ttf -lSDL2_mixer -o SpaceDanceWindows

```

**توضیحات:**

- `executeLinux` و `executeWindows`: این دستورات برای ساخت و اجرای برنامه در سیستم‌های لینوکس و ویندوز به ترتیب استفاده می‌شوند.

- `buildLinux` و `buildWindows`: این دستورات فقط برنامه را می‌سازند بدون اینکه آن را اجرا کنند.

برای ساخت پروژه، کافی است در دایرکتوری حاوی Makefile دستور `make executeLinux` یا `make executeWindows` را اجرا کنید.

#### ۳. چرا از CMake استفاده می‌کنیم؟

اگرچه Makefile می‌تواند برای پروژه‌های کوچک مفید باشد، CMake مزایای بیشتری برای پروژه‌های بزرگ و پیچیده‌تر دارد:

1. **قابلیت چندپلتفرمی**: CMake می‌تواند فایل‌های ساخت برای سیستم‌های مختلف تولید کند.

2. **مدیریت وابستگی‌ها**: CMake به شما کمک می‌کند تا کتابخانه‌های خارجی را به سادگی پیدا و به پروژه‌تان اضافه کنید.

3. **ساخت ساختار پیچیده**: CMake به شما این امکان را می‌دهد که به راحتی ساختارهای پیچیده‌ای ایجاد کنید.

4. **پیکربندی آسان**: CMake به شما اجازه می‌دهد تا با استفاده از فایل‌های پیکربندی ساده، پروژه‌تان را تنظیم کنید.

#### ۴. ایجاد فایل CMakeLists.txt

حالا بیایید یک فایل `CMakeLists.txt` بر اساس اطلاعاتی که ارائه کردید، بسازیم:

**محتوای CMakeLists.txt:**

```cmake
cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)

# Set The name of this Project.
project(Space-Dance)

# Optional: Configure /path/to in your system file directory if SDL is not found.
set(CMAKE_PREFIX_PATH "/path/to/SDL2;/path/to/SDL2_ttf" ${CMAKE_PREFIX_PATH})

# Add SDL2 CMake modules.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Add all C source files under the src directory.
file(GLOB SOURCES "src/*.c")
add_executable(${PROJECT_NAME} ${SOURCES})

# Add all headers files under the include directory.
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Add all assets under the assets directory.
target_include_directories(${PROJECT_NAME} PRIVATE assets)

# Add SDL2 libraries.
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::TTF SDL2::Mixer)

# Add run command.
add_custom_target(
    run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/assets
    COMMENT "Runnig Project..."
)
```

**توضیحات:**

- `project`: نام پروژه را تعیین می‌کند.

- `set(CMAKE_PREFIX_PATH ...)`: مسیرهای کتابخانه‌های SDL را مشخص می‌کند.

- `file(GLOB SOURCES "src/*.c")`: تمام فایل‌های منبع در پوشه `src` را جمع‌آوری می‌کند.

- `add_executable`: برنامه را با نام مشخص شده ایجاد می‌کند.

- `find_package`: کتابخانه‌های SDL2 را پیدا کرده و به پروژه اضافه می‌کند.

- `list(...)`: از ماژول های آماده در پوشه cmake برای پیدا کردن کتابخانه ها استفاده می کند.

## 5. ایجاد یک پنجره خالی با SDL2

در این قسمت، به شما خواهیم آموخت که چگونه با استفاده از ساختار پروژه‌ خود، یک پنجره خالی با SDL2 ایجاد کنید. همچنین نحوه نصب کتابخانه‌های SDL2، SDL2_ttf و SDL2_mixer را در سیستم‌عامل‌های مختلف بررسی خواهیم کرد.

## نصب SDL2 و کتابخانه‌های وابسته

##### نصب بر روی اوبونتو

برای نصب SDL2 و کتابخانه‌های وابسته در اوبونتو، از دستورات زیر استفاده کنید:

```bash
sudo apt update
sudo apt install libsdl2-dev libsdl2-ttf-dev libsdl2-mixer-dev
```

##### نصب بر روی ویندوز

برای نصب SDL2 و کتابخانه‌های وابسته در ویندوز، مراحل زیر را دنبال کنید:

1. به وب‌سایت [SDL](https://www.libsdl.org/download-2.0.php) بروید و نسخه‌های مورد نیاز (SDL2، SDL2_ttf، SDL2_mixer) را دانلود کنید.

2. فایل‌های ZIP را استخراج کنید و محتوای آن‌ها را به دایرکتوری پروژه خود اضافه کنید.

3. در پروژه‌ خود، مسیر کتابخانه‌ها را در Makefile یا CMakeLists.txt مشخص کنید.

##### نصب بر روی macOS

برای نصب SDL2 و کتابخانه‌های وابسته در macOS، از Homebrew استفاده کنید:

```bash
brew install sdl2 sdl2_ttf sdl2_mixer
```

#### ساختار پروژه

ساختار پروژه به صورت زیر خواهد بود:

```

SpaceDance/
├── assets/
├── include/
├── src/
│   └── main.c
├── CMakeLists.txt
└── Makefile
```

#### کدنویسی پنجره خالی

حال بیایید یک کد ساده برای ایجاد یک پنجره خالی در فایل `main.c` بنویسیم. محتوای `src/main.c` به شکل زیر خواهد بود:

```c
#define SDL_MAIN_HANDLED	

#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    // create a window
    SDL_Window *window = SDL_CreateWindow("window",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	800, 600,
	SDL_WINDOW_SHOWN);

    if (window == NULL) {

        printf("Unable to create window: %s\n",SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // main loop
    SDL_Event event;
    int running = 1;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                running = 0;
            }
        }
    }

    // clear up
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
```

#### 6. ساخت و اجرای پروژه

حالا می‌توانید پروژه را بسازید و اجرا کنید. مراحل زیر را دنبال کنید:

1. اجرای CMake:

```bash
cmake .
```

2. ساخت پروژه:

```bash
make
```

3. اجرای پروژه:

```bash
make run
```

#### نتیجه‌گیری

در این فصل، با استفاده از Makefile و CMake آشنا شدید و دلایل انتخاب CMake به جای Makefile را بررسی کردیم. همچنین نحوه نصب این ابزارها و نحوه استفاده از آنها را یاد گرفتید. با تسلط بر این ابزارها، می‌توانید پروژه‌های خود را به راحتی مدیریت و بسازید. در فصل‌های بعدی، به بررسی جزئیات بیشتری از توسعه بازی و استفاده از SDL2 خواهیم پرداخت.
