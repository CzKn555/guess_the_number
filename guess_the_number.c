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
int mathEngine(void)
{
    //empty
    // if(hiddenNumber == inter)
    return 0;
}
void game(void)
{
    wchar_t pseudoInt[5];
    int inter = 0, stage = 1, maxInt = 10, minInt = 0, countAttempts = 0;
    wprintf(L"Итак, начнём!\n");
    while(1)
    {
        int hiddenNumber = rand() % (maxInt - minInt) + minInt;
        wprintf(L"%d этап, значения от %d до %d. Угадайте число. Подсказка('h').\nПервая подсказка: %ls", stage, minInt, maxInt - 1, hintMessage());
        do
        {
        wscanf(L"%4ls", pseudoInt);
        for(wchar_t c; (c = getwchar()) != WEOF && c != '\n';);
        if(iswdigit(pseudoInt[0]))
            {
            if(inter == hiddenNumber)
                {
                wprintf(L"Правильно!\nИдём дальше!\n");
                stage ++;
                if(stage == 4)
                    {
                        maxInt = 100;
                        minInt = 10;
                    }
                else if (stage == 8) 
                {
                    maxInt = 1000;
                    minInt = 100;
                }
                break;
                }
            //inter = pseudoInt - '0';
            mathEngine();
            wprintf(L"%ls\n", pseudoInt);
            wprintf(L"%ld\n", hiddenNumber);
            }
        else if (pseudoInt[0] == 'h') 
        {
            wprintf(L"%ls", hintMessage());
        }
        else
            wprintf(L"Введите число!.\n");
        }
        while(1);
    }
}
