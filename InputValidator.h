#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>

void clearInput();

int getInteger(std::string message);

double getAmount(std::string message);

std::string getMobile();

int getPINInput(std::string message);

#endif