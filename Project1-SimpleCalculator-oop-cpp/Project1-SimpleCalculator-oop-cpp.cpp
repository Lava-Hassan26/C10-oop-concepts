#include <iostream>
using namespace std;

class clsSimpleCalculator
{
    float _number = 0.0;
    float _result = 0.0;
    string _lastOperation = "";

public:
    void Add(float number)
    {
        _lastOperation = "Adding";
        _number = number;
        _result += _number;
    }

    void Subtract(float number)
    {
        _lastOperation = "Subtracting";
        _number = number;
        _result -= _number;
    }

    void Divide(float number)
    {
        _lastOperation = "Dividing On";
        _number = number;
        if (_number == 0)
        {
            _number = 1;
        }
        _result /= _number;
    }

    void Multiply(float number)
    {
        _lastOperation = "Multiplying By";
        _number = number;
        _result *= _number;
    }

    void Clear()
    {
        _lastOperation = "Clear";
        _number = 0;
        _result = 0;
    }

    float GetFinalResults()
    {
        return _result;
    }

    void PrintResult()
    {
        cout << "Result After " << _lastOperation << " " << _number << " is: " << _result << endl;
    }
};

int main()
{
    clsSimpleCalculator Calculator;

    Calculator.Add(10);
    Calculator.PrintResult();

    Calculator.Add(100);
    Calculator.PrintResult();

    Calculator.Subtract(10);
    Calculator.PrintResult();

    Calculator.Divide(10);
    Calculator.PrintResult();

    Calculator.Divide(0);
    Calculator.PrintResult();

    Calculator.Multiply(10);
    Calculator.PrintResult();

    Calculator.Clear();
    Calculator.PrintResult();

    return 0;
}