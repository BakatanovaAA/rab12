#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

long sdvig(void* p1, void* p2);
unsigned char bait(void* p, int k);
int little(void);

int main()
{
    setlocale(LC_ALL, "Rus");
    int i;

    printf("Задание 1\n");
    char* pc;
    int* pi;
    double* pd;
    printf("char* - %d байт, int* - %d байт, double* - %d байт\n",
        (int)sizeof(pc), (int)sizeof(pi), (int)sizeof(pd));

    printf("\nЗадание 2\n");
    float PI = 3.14159f, * p1, * p2;
    p1 = p2 = &PI;
    printf("По адресу p1=%p хранится *p1=%g\n", (void*)p1, *p1);
    printf("По адресу p2=%p хранится *p2=%g\n", (void*)p2, *p2);
    printf("p1 = %llx, p2 = %llx\n", (unsigned long long)p1, (unsigned long long)p2);

    printf("\nЗадание 3\n");
    int x = 5, * pa = &x, * st;
    st = pa;
    printf("int: по адресу %p хранится %d\n", (void*)pa, *pa);
    pa++;
    printf("int: по адресу %p хранится %d, сдвиг %ld байт\n", (void*)pa, *pa, sdvig(st, pa));
    pa--;
    printf("int: по адресу %p хранится %d\n", (void*)pa, *pa);

    double xd = 5, * pda = &xd, *sd = pda;
    pda++;
    printf("double: сдвиг после ++ %ld байт, ", sdvig(sd, pda));
    pda--;
    printf("после -- %ld байт, *pda=%g\n", sdvig(sd, pda), *pda);

    char xc = 'A', * pca = &xc, * stc = pca;
    pca++;
    printf("char: сдвиг после ++ %ld байт, ", sdvig(stc, pca));
    pca--;
    printf("после -- %ld байт, *pca=%c\n", sdvig(stc, pca), *pca);

    long double xl = 5, * pl = &xl, * stl = pl;
    pl++;
    printf("long double: сдвиг %ld байт\n", sdvig(stl, pl));
    unsigned short int xs = 5, * ps = &xs, * sts = ps;
    ps++;
    printf("short unsigned int: сдвиг %ld байт\n", sdvig(sts, ps));
    _Bool xb = 1, * pb = &xb, * stb = pb;
    pb++;
    printf("_Bool: сдвиг %ld байт\n", sdvig(stb, pb));

    printf("\nЗадание 4\n");
    float array[10] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.1f };
    float* ptr_a;
    printf("array=%p &array[0]=%p &array=%p\n", (void*)array, (void*)&array[0], (void*)&array);
    ptr_a = array;
    printf("ptr_a=%p *ptr_a=%g\n", (void*)ptr_a, *ptr_a);
    ptr_a++;
    printf("ptr_a++: %p %g\n", (void*)ptr_a, *ptr_a);
    printf("ptr_a+4: %p %g\n", (void*)(ptr_a + 4), *(ptr_a + 4));
    printf("ptr_a-2: %p\n", (void*)(ptr_a - 2));
    printf("через 2: ");
    for (ptr_a = array; ptr_a < array + 10; ptr_a += 2)
        printf("%g ", *ptr_a);
    printf("\nобратно: ");
    for (ptr_a = array + 9; ptr_a >= array; ptr_a--)
        printf("%g ", *ptr_a);
    printf("\n");

    printf("\nЗадание 5\n");
    int x5 = 0x12345678;
    for (i = 0; i < 4; i++)
        printf("байт %d: %.2x\n", i, bait(&x5, i));
    if (little()) printf("порядок little-endian (младший байт по меньшему адресу)\n");
    else printf("порядок big-endian\n");

    int ci = 12345;
    float cf = 12345.0f;
    double cd = 12345.0;
    printf("int:    ");
    for (i = (int)sizeof(ci) - 1; i >= 0; i--) printf("%.2x ", bait(&ci, i));
    printf("\nfloat:  ");
    for (i = (int)sizeof(cf) - 1; i >= 0; i--) printf("%.2x ", bait(&cf, i));
    printf("\ndouble: ");
    for (i = (int)sizeof(cd) - 1; i >= 0; i--) printf("%.2x ", bait(&cd, i));
    printf("\n");

    return 0;
}

long sdvig(void* p1, void* p2)
{
    return (long)((char*)p2 - (char*)p1);
}

unsigned char bait(void* p, int k)
{
    return *((unsigned char*)p + k);
}

int little(void)
{
    int t = 1;
    return bait(&t, 0) == 1;
}