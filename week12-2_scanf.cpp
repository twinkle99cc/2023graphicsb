///Week12-2_scanf.cpp
#include <stdio.h>
int main()
{
    char line[20];
    ///scanf("%s", line);
    FILE * fin = fopen("file.txt", "r");///r:readŪ
    fscanf(fin, "%s", line);
    printf("Ū��F:%s\n", line);///���W�L
    fscanf(fin, "%s", line);
    printf("Ū��F:%s\n", line);///���W�L
}
