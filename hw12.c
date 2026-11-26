#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stddef.h>
#include <wchar.h>
#include <locale.h>

int razmer(void* a, void* b);

int main()
{
    setlocale(LC_ALL, "Rus");
    char c[2];
    short int s[2];
    unsigned short int us[2];
    int i[2];
    unsigned char uc[2];
    wchar_t w[2];
    long long int ll[2];
    size_t st[2];
    float f[2];
    double d[2];
    signed int si[2];

    printf("1) char - %d\n", razmer(&c[0], &c[1]));
    printf("2) short int - %d\n", razmer(&s[0], &s[1]));
    printf("3) unsigned short int - %d\n", razmer(&us[0], &us[1]));
    printf("4) int - %d\n", razmer(&i[0], &i[1]));
    printf("5) unsigned char - %d\n", razmer(&uc[0], &uc[1]));
    printf("6) wchar_t - %d\n", razmer(&w[0], &w[1]));
    printf("7) long long int - %d\n", razmer(&ll[0], &ll[1]));
    printf("8) size_t - %d\n", razmer(&st[0], &st[1]));
    printf("9) float - %d\n", razmer(&f[0], &f[1]));
    printf("10) double - %d\n", razmer(&d[0], &d[1]));
    printf("11) signed int - %d\n", razmer(&si[0], &si[1]));

    return 0;
}

int razmer(void* a, void* b)
{
    return (int)((char*)b - (char*)a);
}