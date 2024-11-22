#include <stdio.h>
#include <string.h>
#include <locale.h>

void readline()
{
    char line[15];  
    printf("Введіть рядок: ");
    fgets(line, sizeof(line), stdin);
    printf("Ви ввели: %s\n", line);
}

int main()
{
    readline();
    printf("Мало шансів побачити це повідомлення.\n");
    return 0;
}
