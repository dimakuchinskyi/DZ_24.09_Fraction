#include <iostream>
using namespace std;

class Fraction 
{
    int _numerator;
    int _denominator;
public:
    Fraction() 
    {
        _numerator = 0;
        _denominator = 1;
    }

    Fraction(int num) : Fraction()
    {
        SetNumerator(num);
    }
    Fraction(int num, int den) : Fraction(num)
    {
        SetDenominator(den);
    }

    void SetNumerator(int num) {
        _numerator = num;
    }
    void SetDenominator(int den) {
        if (den == 0) {
            cout << "Denominator cannot be zero. Setting to 1 by default." << endl;
            _denominator = 1;
        }
        else {
            _denominator = den;
        }
    }

    int GetNumerator() const {
        return _numerator;
    }

    int GetDenominator() const {
        return _denominator;
    }

    void Print() const 
    {
        cout << "Fraction: " << _numerator << "/" << _denominator << endl;
    }

    Fraction operator+(Fraction& other) const 
    {
        int num = _numerator * other._denominator + other._numerator * _denominator;
        int den = _denominator * other._denominator;
        return Fraction(num, den);
    }

    Fraction operator-(Fraction& other) const 
    {
        int num = _numerator * other._denominator - other._numerator * _denominator;
        int den = _denominator * other._denominator;
        return Fraction(num, den);
    }

    Fraction operator*(const Fraction& other) const {
        int num = _numerator * other._numerator;
        int den = _denominator * other._denominator;
        return Fraction(num, den);
    }

    Fraction operator/(const Fraction& other) const {
        int num = _numerator * other._denominator;
        int den = _denominator * other._numerator;
        return Fraction(num, den);
    }
};

int main() {
    Fraction frac1, frac2;
    Fraction result;

    frac1.SetNumerator(2);
    frac1.SetDenominator(5);

    frac2.SetNumerator(3);
    frac2.SetDenominator(7);

    result = frac1 + frac2;
    cout << "Add result: ";
    result.Print();

    result = frac1 - frac2;
    cout << "Subtract result: ";
    result.Print();

    result = frac1 * frac2;
    cout << "Multiply result: ";
    result.Print();

    result = frac1 / frac2;
    cout << "Divide result: ";
    result.Print();

    return 0;
}