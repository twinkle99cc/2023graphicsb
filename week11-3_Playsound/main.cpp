#include <windows.h>
#include<stdio.h>
int main()
{
    ///������| Absolute Path
    ///PlaySound("C:\\Users\\user\\Desktop\\do-re-mi\\do.wav",NULL,SND_SYNC);
    ///PlaySound("C:\\Users\\user\\Desktop\\do-re-mi\\re.wav",NULL,SND_SYNC);
    ///PlaySound("C:\\Users\\user\\Desktop\\do-re-mi\\mi.wav",NULL,SND_SYNC);
    ///�۹���| Relative Path
    PlaySound("do-re-mi/do.wav",NULL,SND_SYNC);
    printf("Hello World\n");
}
