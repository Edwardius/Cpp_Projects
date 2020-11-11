//Written By Eddy Zhou
#include <iostream>
#include <cmath>
#include <iomanip>

class Fraction 
{
private:
    int numerator = 1, dinominator = 1;

public:
    Fraction(int num, int din) 
    {
        if (din == 0) 
        {
            std::cout << "Cannot Divide by Zero, Fraction set to 1/1.\n";
            return;
        }
        else if (din < 0) 
        {
            num *= -1;
            din *= -1;
        }
        numerator = num;
        dinominator = din;
    }

    double valueToDecimalPlace(int decimalPlace) 
    {
        double decimal = 0;
        decimal = (double(numerator) / double(dinominator)) * pow(10, decimalPlace);
        decimal = round(decimal);
        decimal = decimal / pow(10, decimalPlace);
        return decimal;
    }

    bool isExactlySame(Fraction const& other)const 
    {
        if (other.getNum() == numerator && other.getDin() == dinominator) 
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

    void output() 
    {
        std::cout << numerator << "/" << dinominator;
    }

    //accessors
    int getNum()const 
    {
        return numerator;
    }
    int getDin()const 
    {
        return dinominator;
    }

    //mutators
    void setNum(int num) 
    {
        if (num > dinominator) 
        {
            std::cout << "Numerator is larger than Dinominator.\n";
        }
        else 
        {
            numerator = num;
        }
    }
    void setDin(int din) 
    {
        if (din == 0) 
        {
            std::cout << "Cannot Divide by Zero\n";
            return;
        }
        else if (din < 0) 
        {
            numerator *= -1;
            din *= -1;
        }
        dinominator = din;
    }
};

int main()
{
    Fraction fraction1(1, -7), fraction2(2, 9), fraction3(3, 0);
    //output fractions
    std::cout << "Fraction1: ";
    fraction1.output();
    std::cout << " Fraction2: ";
    fraction2.output();
    std::cout << " Fraction3: ";
    fraction3.output();
    std::cout << std::endl;

    //accessors
    std::cout << "Fraction1: Numerator, " << fraction1.getNum() 
        << " Dinominator, " << fraction1.getDin() << std::endl;
    std::cout << "Fraction2: Numerator, " << fraction2.getNum()
        << " Dinominator, " << fraction2.getDin() << std::endl;

    //value to decimal place
    std::cout << "Fraction1 to 2 decimal places: " << fraction1.valueToDecimalPlace(2)
        << std::endl;
    //Note: cout output stream truncates the value to max 6 decimals by default, iomanip is used
    //to show entire decimal value calulated
    std::cout << "Fraction2 to 10 decimal places: " << std::setprecision(10) 
        << fraction2.valueToDecimalPlace(10) << std::endl;
    
    //check if the same 
    if (fraction1.isExactlySame(fraction2)) 
    {
        std::cout << "Fraction1 and Fraction2 are exactly the same.\n";
    }
    else 
    {
        std::cout << "Fraction1 and Fraction 2 are different.\n";
    }

    //mutate fraction 2
    fraction2.setNum(-1);
    fraction2.setDin(7);

    //check
    std::cout << "Fraction2: Numerator, " << fraction2.getNum()
        << " Dinominator, " << fraction2.getDin() << std::endl;

    //check if the same 
    if (fraction1.isExactlySame(fraction2)) 
    {
        std::cout << "Fraction1 and Fraction2 are exactly the same.\n";
    }
    else 
    {
        std::cout << "Fraction1 and Fraction 2 are different.\n";
    }

    return 0;
}
/*
OUTPUT:

Cannot Divide by Zero, Fraction set to 1/1.
Fraction1: -1/7 Fraction2: 2/9 Fraction3: 1/1
Fraction1: Numerator, -1 Dinominator, 7
Fraction2: Numerator, 2 Dinominator, 9
Fraction1 to 2 decimal places: -0.14
Fraction2 to 10 decimal places: 0.2222222222
Fraction1 and Fraction 2 are different.
Fraction2: Numerator, -1 Dinominator, 7
Fraction1 and Fraction2 are exactly the same.

*/