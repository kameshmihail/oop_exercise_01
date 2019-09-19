/*Камеш М.А. М80-207Б-18
Вариант 9.
Создать класс BritishMoney для работы с денежными суммами в старой британской система. Сумма
денег должна быть представлено тремя полями: типа unsigned long long для фунтов стерлингов, типа
unsigned char – для шиллингов, unsigned char – для пенсов (пенни). Реализовать сложение сумм,
вычитание, деление сумм, деление суммы на дробное число, умножение на дробное число и операции
сравнения. 1 фунт = 20 шиллингов, 1 шиллинг = 12 пенни. */

#include <iostream>
#include <cmath>
using namespace std;


class BritishMoney
{
private:
    double a,b,c;
    double d,e;
    unsigned long long funts;
    unsigned char shillings;
    unsigned char pennies;
public:
    void readBritishMoney(void);
    void printBritishMoney(void);
    void calAddition(void);
    void calDivision(void);
    void Initialize(void);
    void ConvertToPennies(void);
    void ConvertToPennies2(void);
    void ConvertToBasicSum(void);
    void DivisionOperation(void);
    void calcSum(void);
    void calDivisionByNumber(void);
    void MultOperation(void);
    void calMultByNumber(void);
    void calDifference(void);
    void calcDiff(void);
    void divideBySum(void);
    void Compare(void);
};

void BritishMoney::Initialize(void)
{
    funts = 0;
    shillings = 0;
    pennies = 0;
}

void BritishMoney::readBritishMoney(void)
{
    cout << " Enter the sum" << endl;
    cout<<"Enter amount of funts: ";
    cin>>a;
    cout<<"Enter amount of shillings: ";
    cin>>b;
    cout<<"Enter amount of pennies: ";
    cin>>c;
    if (b > 255 || c > 255)
    {
        cout << "Error, shillings and pennies can't be above 255, try again" << endl;
        readBritishMoney();
    }
}

void BritishMoney::calcSum(void)
{
    ConvertToPennies();
    ConvertToPennies2();
    d += e;
    ConvertToBasicSum();
}

void BritishMoney::calcDiff(void)
{
    ConvertToPennies();
    ConvertToPennies2();
    if (d < e)
    {
        d = e - d;
        ConvertToBasicSum();
        cout << "Negative ";
    }
    if (d >= e)
    {
        d -= e;
        ConvertToBasicSum();
    }

}

void BritishMoney::printBritishMoney(void)
{
    a = funts;
    b = shillings;
    c = pennies;
    cout << "funts = " << a << ", shillings = " << b << ", pennies = " << c << endl;
}

void BritishMoney::calAddition(void)
{
    readBritishMoney();
    calcSum();
    printBritishMoney();
}

void BritishMoney::calDifference(void)
{
    readBritishMoney();
    calcDiff();
    printBritishMoney();
}

void BritishMoney::ConvertToPennies(void)
{
    d = (int)pennies + (int)shillings * 12 + funts * 12 * 20;
}

void BritishMoney::ConvertToPennies2(void)
{
    e = c + b * 12 + a * 12 * 20;
}
void BritishMoney::MultOperation(void)
{
    d *= a;
    round(d);
    ConvertToBasicSum();
}
void BritishMoney::DivisionOperation(void)
{
    d /= a;
    round(d);
    ConvertToBasicSum();
}

void BritishMoney::calDivisionByNumber(void)
{
    cout << "Enter number to divide sum by: ";
    cin >> a;
    while (a <= 0)
    {
        cout << "Can't divide by 0 or negative number" << endl;
        cin >> a;
    }
    ConvertToPennies();
    DivisionOperation();
    printBritishMoney();
}

void BritishMoney::calMultByNumber(void)
{
    cout << "Enter number to multiply sum by: ";
    cin >> a;
    ConvertToPennies();
    MultOperation();
    printBritishMoney();
}



void BritishMoney::ConvertToBasicSum(void)
{
    Initialize();
    while(d >= 12*20)
    {
        d -= 12*20;
        funts++;
    }
    while (d >= 12)
    {
        d -= 12;
        shillings ++;
    }
    pennies += d;
}

void BritishMoney::Compare(void)
{
    readBritishMoney();
    ConvertToPennies();
    ConvertToPennies2();
    if (d > e)
    {
        cout << "First sum is larger than second one" << endl;
    }
    else if (d == e)
    {
        cout << "First sum and second one are equal" << endl;
    }
    else if (d < e)
    {
        cout << "First sum is smaller than second one" << endl;
    }
}

void BritishMoney::divideBySum(void)
{
    readBritishMoney();
    ConvertToPennies();
    ConvertToPennies2();
    cout << "First sum divided by second sum equals" << d/e << endl;
}

int main()
{
    cout << " This is a program to work with British Money : "<< endl;
    cout << " It can add, substract, divide, multiply and compare sums." << endl;
    BritishMoney num;
    num.Initialize();
    num.readBritishMoney();
    num.calcSum();
    int k = 1;
    while (k)
    {
        printf("===================================="
               "\n||              MENU              ||"
               "\n||--------------------------------||"
               "\n|| 0 - exit                       ||"
               "\n|| 1 - Add to another sum         ||"
               "\n|| 2 - Find a difference          ||"
               "\n|| 3 - Multiply by number         ||"
               "\n|| 4 - Divide by number           ||"
               "\n|| 5 - Divide by another sum      ||"
               "\n|| 6 - Compare with another sum   ||"
               "\n|| 7 - Reset the sum              ||"
               "\n===================================="
               "\n ==>");
        scanf("%d", &k);
        if (k == 1)
        {
            num.calAddition();
        }
        if (k == 2)
        {
            num.calDifference();
        }
        if (k == 3)
        {
            num.calMultByNumber();
        }
        if (k == 4)
        {
            num.calDivisionByNumber();
        }
        if (k == 5)
        {
            num.divideBySum();
        }
        if (k == 6)
        {
            num.Compare();
        }
        if (k == 7)
        {
            num.Initialize();
            num.readBritishMoney();
            num.calcSum();
        }

    }

    return 0;
}
