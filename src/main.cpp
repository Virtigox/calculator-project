#include "calculatorFrameWork.h"

int main()
{   
    CalculatorFrameWork calculator;
    bool flag = true;
    while(flag)
    {
        try{
            calculator.formattingInput();
            calculator.precedenceHandling();
            //calculator.calculatorDisplay();
            std::cout << "\nANS = " << calculator.getResult() << endl;
            calculator.recordProblemsAndAnswer(calculator.primaryUserInput,calculator.getResult());
            calculator.reset();
        } catch (const std::runtime_error& e){ // catching the exception from user to terminate the program.
            std::cout << e.what() << std:: endl;
            break;
        }
        std::cout << endl;
    }
    return 0;
}

