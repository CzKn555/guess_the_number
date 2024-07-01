//Игра "Угадай число". В данной игре вы должны угадать число, используя подсказки.
#include <locale.h>
#include <wchar.h>
void game(void);
int main(void)
    {
        wchar_t charm;
        setlocale(LC_CTYPE, "");
        wprintf(L"Приветствую вас в игре Угадай число!\n");
        while(1)
        {
            wprintf(L"Правила('?'). Выход('q').\nНачать игру?('y')\n");
            wscanf(L"%2lc", &charm);
            if(charm == 'q')
                //nothing to do and exit
                break;
            else if(charm == '?')
                wprintf(L"На этом месте должны быть правила.\n");
            else if(charm == 'y')
                game();
        }
        return 0;
    }
void game(void)
{
    wprintf(L"И так, начнём!\n");
}
