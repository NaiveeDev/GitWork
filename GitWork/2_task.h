#include "includes.h"


using namespace std;

class CalculationException : public exception {
public:
    virtual const char* what() const noexcept {
        return "Ошибка рассчёта!";
    }
};

class MemoryException : public CalculationException {
public:
    virtual const char* what() const noexcept {
        return "Ошибка! Не удалось выделить память";
    }
};

class NegativeValueException : public CalculationException {
public:
    virtual const char* what() const noexcept {
        return "Факториал отрицательного значения!";
    }
};

