//Игра "Угадай число". В данной игре вы должны угадать число, используя подсказки.
#include <locale.h>
#include <wchar.h>
int main(void)
    {
        setlocale(LC_CTYPE, "");
        wprintf(L"Приветствую вас в игре Угадай число.");
        return 0;
    } 
