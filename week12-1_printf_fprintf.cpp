///Week12-1_printf_fprintf.cpp

///�n�}�ɮ׫���  fopen()

#include <stdio.h>

int main()

{///�ɮ׫��� fout = fopen("�ɦW", "�Ҧ�"); �n�}��

    FILE * fout = fopen("file.txt", "w");///w:write

    printf("Hello World\n");

    fprintf(fout, "Hello World�b�ɮ׸�\n");

}
