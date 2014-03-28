#include <windows.h>

void presskey(int key){
    keybd_event(key,0, 0, 0);
}
void releasekey(int key){
    keybd_event(key,0, KEYEVENTF_KEYUP, 0);
}
void keystroke(int key){
    presskey(key);
    releasekey(key);
}

int main()
{
    ShellExecute(NULL, NULL, "control.exe", "mmsys.cpl", NULL, SW_SHOW);
    HWND applet = NULL;
    while ( IsWindow((applet=FindWindow(NULL,"Sound"))) == FALSE ){
        Sleep(10);
    }
    SetForegroundWindow(applet);
    keystroke(VK_DOWN);
    keystroke(VK_DOWN);
    presskey(VK_MENU);
    presskey(0x53);
    releasekey(VK_MENU);
    releasekey(0x53);
    presskey(VK_RETURN);
    return 0;
}
