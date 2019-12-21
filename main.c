#include <stdio.h>
#include <stdarg.h>
#include "tasks.h"

/*
 * Тестирующая функция. 
 * Первый аргумент (task) - указатель на тестируемую функцию
 * Второй аргумент (argSize) - количество аргументов тестируемой функции (не считая _i)
 * Третий аргумент (expected) - ожидаемый результат
 * Дальнейшие аргументы (от 1 до 3) - целочисленные аргументы тестируемой функции
 */
int testTask(int (*task)(int _i, ...), int argSize, int expected, ...);

int checkResult(int result, int expected);


int main()
{
    // Проверка tasks
    printf("Проверяем вашу работу...\n");
    
    printf("\nЗадание №0\n");
    testTask(dummy, 0, 42);
    
    printf("\nЗадание №1\n");
    if (testTask(min, 2, 1, 10, 1)) {  // Если задание не решено, дальше первого теста идти бессмысленно
        testTask(min, 2, -42, -42, 100);
        testTask(min, 2, -10, -5, -10);
        testTask(min, 2, 0, 0, 0);
    }
    
    printf("\nЗадание №2\n");
    if (testTask(isTriang, 3, 1, 1, 1, 1)) {
        testTask(isTriang, 3, 1, 60, 34, 44);
        testTask(isTriang, 3, 0, 0, 10, 20);
        testTask(isTriang, 3, 1, 100, 100, 100);
    }
    
    printf("\nЗадание №3\n");
    testTask(meetEnum, 0, GUN);
    
    printf("\nЗадание №4\n");
    if (testTask(calcDamage, 2, 0, CLUB, 0)) {
        testTask(calcDamage, 2, 20, GUN, 2);
        testTask(calcDamage, 2, 42, SWORD, 14);
        testTask(calcDamage, 2, 50, MAGIC_FORK, 1);
        testTask(calcDamage, 2, 10, MACE, 2);
    }
    
    // Проверка pointerTasks
    printf("\n-----Задания на указатели-----\n");
    
    printf("\nЗадание №1\n");
    int arg = 0;
    int *pArg = &arg;
    int res = firstPointer(pArg);
    arg = (res == NOT_IMPLEMENTED) ? NOT_IMPLEMENTED: arg;
    checkResult(arg, 42);
    
        
    printf("\nЗадание №2\n");
    res = whatsInside(pArg);
    checkResult(res, (int)&arg);
        
        
    printf("\nЗадание №3\n");
    int quest[5] = { 100, 39, 44, 2, 569};
    res = investigating(quest);
    checkResult(res, 1138);

    return 0;
}

int checkResult(int result, int expected) {
    switch (result) {
        case NOT_IMPLEMENTED:
            printf("> %sЭто задание вы еще не решили.%s\n", YELLOW, RESET);
            return 0;
        case -1:
            printf("> %sОшибка проверяющей системы.%s\n", RED, RESET);
            return 1;
        default:
            if (result != expected) {
                printf("> %sРезультат: %d, ожидалось: %d%s\n", RED, result, expected, RESET);
            } else {
                printf("> Результат: %d, ожидалось: %d\n", result, expected);
            }
            return 1;
    }
}

int testTask(int (*task)(int _i, ...), int argSize, int expected, ...) {
    va_list args;
    va_start(args, expected);
    int a1, a2, a3;
    
    int result;
    switch (argSize) {
        case 0:
            result = (*task)(-1);
            break;
        case 1:
            a1 = va_arg(args, int);
            result = (*task)(-1, a1);
            break;
        case 2:
            a1 = va_arg(args, int);
            a2 = va_arg(args, int);
            result = (*task)(-1, a1, a2);
            break;
        case 3:
            a1 = va_arg(args, int);
            a2 = va_arg(args, int);
            a3 = va_arg(args, int);
            result = (*task)(-1, a1, a2, a3);
            break;
        default:
            result = -1;
    }
    checkResult(result, expected);
}
