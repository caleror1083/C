#include <stdio.h>

int main()
{
    int age = 0;

    printf("How old are you: ");
    scanf_s("%d", &age);

    printf("You are %d years old\n", age);

    system("pause");
    return 0;
}