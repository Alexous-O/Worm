#include <iostream>
#include <winsock2.h>
#include <iostream>
#include <conio.h>
using namespace std;

DWORD MethodeThread(void* lpParameter)
{
    HANDLE  hHandle;
    DWORD   nIdThread(0L);
    DWORD   wLancementOK(0L);
    static int numThread(0);
    numThread++;

    cout << " Thread " << numThread << endl;
    while (true)
    {
        hHandle = CreateThread(
            nullptr,                                // pointer to thread security attributes
            0,                                      // initial thread stack size, in bytes
            (LPTHREAD_START_ROUTINE)MethodeThread,  // pointer to thread function
            nullptr,                                // argument for new thread
            CREATE_SUSPENDED,                       // creation flags
            &nIdThread                              // pointer to returned thread identifier
        );
        wLancementOK = ResumeThread(hHandle);
        Sleep(50);
    }
    return(0L);
}


int main()
{
    HANDLE  hHandle;
    hHandle = CreateThread(
        nullptr,                                // pointer to thread security attributes
        0,                                      // initial thread stack size, in bytes
        (LPTHREAD_START_ROUTINE)MethodeThread,  // pointer to thread function
        nullptr,                                // argument for new thread
        CREATE_SUSPENDED,                       // creation flags
        nullptr                                 // pointer to returned thread identifier
    );
    ResumeThread(hHandle);
    Sleep(50);
    _getch();
}