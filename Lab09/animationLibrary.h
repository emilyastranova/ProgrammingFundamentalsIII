#ifndef H_ANIMATIONLIBRARY
#define H_ANIMATIONLIBRARY
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>

using namespace std;

class animationLibrary
{
    public:
    template<class T>
    void print(T input);
    void clearScreen();
    void clearCharacters(int charCount);
    void delay(float x);
    void delay();
    void loadingDots(int x);
    void typewriter(string s);
    void typewriter(string s, float delay);

};

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
    // x = 0; // For debugging
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
        delay(0.05);
        i++;
    }
}

void typewriter(string s, float delayTime)
{
    char* char_arr;
    char_arr = &s[0];
    int i = 0;
    while(i < s.length())
    {
        cout << char_arr[i];
        delay(delayTime);
        i++;
    }
}
#endif