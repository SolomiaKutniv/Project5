#include <iostream>
#include <cmath> 

using namespace std;

class Progression 
{
public:
    virtual double sum(int n) const = 0; 

};


class ArithmeticProgression : public Progression 
{
private:
    double firstElement; 
    double difference;    

public:
    ArithmeticProgression(double first, double diff) : firstElement(first), difference(diff) {}

    double sum(int n) const override 
    {
        double s = 0;
        for (int i = 0; i < n; i++)
        {
            s += firstElement + i * difference; 
        }
        return s;
    }
};

class GeometricProgression : public Progression 
{
private:
    double firstElement; 
    double ratio;        

public:

    GeometricProgression(double first, double r) : firstElement(first), ratio(r) {}

    double sum(int n) const override 
    {
        double s = 0;
        for (int i = 0; i < n; i++)
        {
            s += firstElement * pow(ratio, i); 
        }
        return s;
    }
};

int main() 
{
    setlocale(LC_ALL, "Ukrainian");
    Progression* arithProg = new ArithmeticProgression(2.0, 3.0); 
    Progression* geoProg = new GeometricProgression(3.0, 2.0);    

    int n = 5;
    cout << "Сума арифметичної прогресії: " << arithProg->sum(n) << endl;
    cout << "Сума геометричної прогресії: " << geoProg->sum(n) << endl;

    delete arithProg;
    delete geoProg;

    return 0;
}
