#include "includes.h"


using namespace std;

class CalculationException : public exception {
public:
    virtual const char* what() const noexcept {
        return "������ ��������!";
    }
};

class MemoryException : public CalculationException {
public:
    virtual const char* what() const noexcept {
        return "������! �� ������� �������� ������";
    }
};

class NegativeValueException : public CalculationException {
public:
    virtual const char* what() const noexcept {
        return "��������� �������������� ��������!";
    }
};

