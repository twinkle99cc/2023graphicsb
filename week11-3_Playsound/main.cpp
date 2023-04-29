#include <windows.h>
#include<stdio.h>
int main()
{
    ///絕對路徑 Absolute Path
    ///PlaySound("C:\\Users\\user\\Desktop\\do-re-mi\\do.wav",NULL,SND_SYNC);
    ///PlaySound("C:\\Users\\user\\Desktop\\do-re-mi\\re.wav",NULL,SND_SYNC);
    ///PlaySound("C:\\Users\\user\\Desktop\\do-re-mi\\mi.wav",NULL,SND_SYNC);
    ///相對路徑 Relative Path
    PlaySound("do-re-mi/do.wav",NULL,SND_SYNC);
    printf("Hello World\n");
}
