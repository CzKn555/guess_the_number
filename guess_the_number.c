//Игра "Угадай число". В данной игре вы должны угадать число, используя подсказки.
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <stdlib.h>
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
                return 0;
            else if(charm == '?')
                wprintf(L"На этом месте должны быть правила.\n");
            else if(charm == 'y')
                game();
        }
        return 0;
    }
wchar_t * hintMessage(void)
{
    return L"mess\n";
}
void mathEngine(int inter)
{
    //empty
}
void game(void)
{
    wchar_t pseudoInt;
    int inter = 0, stage = 1, a = 0, b = 9;
    wprintf(L"Итак, начнём!\n");
    while(1)
    {

        wprintf(L"%d этап, значения от %d до %d. Угадайте число. Подсказка('h').\nПервая подсказка: %ls", stage, a, b, hintMessage());

        do
        {
        wscanf(L"%2lc", &pseudoInt);
        if(iswdigit(pseudoInt))
            {
            
            inter = pseudoInt - '0';
            wprintf(L"%d\n", inter);
            wprintf(L"%d\n", rand() % 90 + 10);
            }
        else if (pseudoInt == 'h') 
        {
            wprintf(L"%ls", hintMessage());
        }
        else
            wprintf(L"Введите число!.\n");
        }
        while(1);
    }
}
