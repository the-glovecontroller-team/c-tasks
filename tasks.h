#ifndef ROBBO_TASKS
#define ROBBO_TASKS

#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"

#define NOT_IMPLEMENTED 65535
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define RESET   "\033[0m"

typedef enum Weapon {
    CLUB,
    SWORD,
    MACE,
    GUN,
    MAGIC_FORK
} Weapon;

int dummy(int _i);
int min(int _i, int a, int b);
int isTriang(int _i, int a, int b, int c);

int meetEnum(int ignore);
int calcDamage(int ignore, Weapon weapon, int hits);

int firstPointer(int *result);
int whatsInside(int *p);
int ivestigating(int *start);

#endif