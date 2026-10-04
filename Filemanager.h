#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "ATM.h"

void saveUsers(
    const std::vector<ATM>& users
);

void loadUsers(
    std::vector<ATM>& users
);

int findUser(
    const std::vector<ATM>& users,
    long long accountNo
);

#endif