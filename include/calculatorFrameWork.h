#ifndef CALCULATORFRAMEWORK_H //Gurd Clause to prevent unnecessary executions
#define CALCULATORFRAMEWORK_H

#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <sstream>  
#include <cmath>
#include <iomanip>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

//constant values
const int PARENTHESES_LIST = 6;
const char PARENTHESES[PARENTHESES_LIST] = {'[',']','{','}','(',')'};

// class CalculatorFrameWorks
class CalculatorFrameWork{
    public:
        // constructor to initialize the preset value
        CalculatorFrameWork(vector<double> initInputNumbers, vector<char> initOperatorSigns, vector <char> initParetheses, 
        double initResult,string initUserInput, map<char,int> initParetheseMappingIndex );
        // default constructor
        CalculatorFrameWork();

        //accessor
        double getResult() const { return result;};
        vector<double> getInputNumbers()const { return inputNumbers;};
        vector<char> getOperatorSigns() const {  return operatorSigns; };
        vector<char> getParentheses() const { return parentheses; }
        string getUserInput() const { return userInput; };
        map<char,int> getparenthesesMappingIndex() const { return parenthesesMappingIndex; };

        //mutator
        void addUserInput(string userValidatedPrompt);
        void addParentheses(char parenthese);
        void addParenthesesMappingIndex(char validParenthese, int parentheseIndex);
        void addInputNumbers(double number);
        void addOperatorSigns(char operators);
        void addResult(double result);
        

        //helper functions
        int getValidIntInput(const std::string& prompt);
        void calculatorDisplay();
        string formatNumber(double number);
        string formattingParetheses(string usrprmpt);
        void settingTheValues(string usrPrmpt);
        void resettingAndUpdatingtheValues(string processingPrmpt);
        void formattingInput();
        void precedenceHandling();
        void precedenceHandlingSecondStep();
        bool checkingTheExistanceOfParetheses();
        int precedenceForOperators(char op);
        void compute(std::stack<double>& numbers,std::stack<char>& operators);
        void parentheseValidation( string userPrompt);
        void splitngPromptByScope(string usrpmt, int startingIndex, int endingIndex);
        void recordProblemsAndAnswer(string useript, double result);
        void lookUpRecord();
        
        //resetter
        void reset();
        
        //first user Input
        string primaryUserInput;

         //recordOfProblemsAndAnswer struct and its member variable
        struct recordOfProblemsAndAnswer{
            vector<string> problems;
            vector<double> answers;
        };
        // creating a struct object to store the variable 
        recordOfProblemsAndAnswer record;

    
    private:
        
        vector<double> inputNumbers;
        vector<char> operatorSigns;
        vector<char> parentheses;
        map<char,int> parenthesesMappingIndex;
        string userInput;
        double result;
        
};

#endif