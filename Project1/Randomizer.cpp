#include "Randomizer.h"

int GenerateId()
{
    return rand() % 9999999999;
}

string GenerateEmployeeId(string department)
{
    char id[11] = { 0 };
    if (department == MANAGER) {
        id[0] = 'M';
    }
    else if (department == CASHIER) {
        id[0] = 'C';
    }
    for (int i = 1; i < 10; i++) {
        id[i] = (rand() % (57 - 48 + 1)) + 48;
    }
    id[10] = '\0';
    return id;
}
