#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>

using namespace std;

template<class T>
void print(T input)
{
    cout << input << flush;
}

void clearScreen() {
    #ifdef _WIN32
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
    #else
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
    #endif
}



void clearCharacters(int charCount)
{
    for (int x = 0; x < charCount; x++)
        cout<< "\b";
    for (int x = 0; x < charCount; x++)
        cout << " ";
    for (int x = 0; x < charCount; x++)
        cout << "\b";
}

void delay(float x) // Cannot believe the sleep function is not
{                   // cross-platform. Rediculous.
    #ifdef _WIN32
    Sleep(x*1000);
    #else
    sleep(x);
    #endif
}

void delay()
{                   
    #ifdef _WIN32
    Sleep(5000);
    #else
    sleep(0.5);
    #endif
}

void loadingDots(int x)
{
    for(int i = 0; i < x; i++)
    {
        delay(0.5);
        print(".");
        delay(0.5);
        print(".");
        delay(0.5);
        print(".");
        delay(0.5);
        clearCharacters(3);
    }
    print("...");
}

void typewriter(string s)
{
    char* char_arr;
    char_arr = &s[0];
    int i = 0;
    while(i < s.length())
    {
        cout << char_arr[i];
        delay(0.1);
        i++;
    }
}

int main()
{

    print("Initializing SolarOS");
    loadingDots(1);
    print("\n");
    print("Done\n...\n\n$ "); delay(1);
    typewriter("whoami"); delay(2);
    print("\nflynn\n\n$ "); delay(1);
    typewriter("uname -a"); delay(1);
    print("\nSolarOS 4.0.1 Generic_50203-02 sun4m i386 \nUnknown.Unknown\n\n$ "); delay(1);
    typewriter("login -n root"); delay(1);
    print("\nLogin incorrect\n\n$ "); delay(1);
    typewriter("login: backdoor"); delay(2);
    print("\nNo home directory specified in password file!\nLogging in with home*/\n\n# "); delay(1);
    typewriter("bin/history"); delay(1);
    print("\n");
    loadingDots(2);
    print("\b\b\b   488 cd /opt/LLL/controller/laser/\n"); delay(0.3);
    print("   489 vi LLLSDLaserControl.c\n"); delay(0.3);
    print("   490 make\n"); delay(0.3);
    print("   491 make install\n"); delay(0.3);
    print("   492 ./sanity_check\n"); delay(0.3);
    print("   493 ./configure -o test.cfg\n"); delay(0.3);
    print("   494 vi test.cfg\n"); delay(0.3);
    print("   495 vi `/last_will_and_testament.txt\n"); delay(0.3);
    print("   496 cat /proc/meminfo\n"); delay(0.3);
    print("   497 ps -a -x -u\n"); delay(0.3);
    print("   498 kill -9 2207\n"); delay(0.3);
    print("   499 kill 2208\n"); delay(0.3);
    print("   500 ps -a -x -u\n"); delay(0.3);
    print("   501 touch /opt/LLL/run/ok\n"); delay(0.3);
    print("   502 LLLSDLaserControl -ok 1\n"); delay(0.3);
    print("\n# "); delay(2);
    typewriter("./LLLSDLaserControl -ok 1"); delay(2);
    clearScreen();

}