#include <conio.h>
#include <stdio.h>

void print(int pass)
{
    printf("Hello there, the number is %d", pass);
}
int main()
{
    print(0x8BADF00D);
    return 0;
}
