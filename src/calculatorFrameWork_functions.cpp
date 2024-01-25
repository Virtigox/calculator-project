#include "calculatorFrameWork.h"


//function definitions for constructors and default constructors

CalculatorFrameWork::CalculatorFrameWork(vector<double> initInputNumbers, vector<char> initOperatorSigns, vector <char> initParetheses, 
        double initResult,string initUserInput, map<char,int> initParetheseMappingIndex)
{
    initUserInput = userInput;
    initParetheses = parentheses;
    initParetheseMappingIndex = parenthesesMappingIndex;
    initInputNumbers = inputNumbers;
    initOperatorSigns = operatorSigns;
    initResult = result;
}

CalculatorFrameWork::CalculatorFrameWork()
{
    userInput = "";
    parentheses = vector <char>();
    parenthesesMappingIndex = map<char,int>();
    inputNumbers = vector<double>();
    operatorSigns = vector<char>();
    result = 0;
}


// function definitions for mutator
void CalculatorFrameWork::addUserInput(string userValidatedPrompt)
{
    userInput = userValidatedPrompt;
}

void CalculatorFrameWork::addParentheses(char parenthese)
{
    parentheses.push_back(parenthese);
}

void CalculatorFrameWork::addParenthesesMappingIndex(char validParenthese, int parentheseIndex)
{
    parenthesesMappingIndex[validParenthese] = parentheseIndex;
}

void CalculatorFrameWork::addInputNumbers(double number)
{
    inputNumbers.push_back(number);  
}

void CalculatorFrameWork::addOperatorSigns(char operators)
{
    //  amount operator signs have to be less than amount of numbers
    if(operatorSigns.size() >= inputNumbers.size()){
        return;
    }
    else
        operatorSigns.push_back(operators);
}

void CalculatorFrameWork::addResult(double initResult) 
{
    result  = initResult;
}



// function definitions for helper functions

int CalculatorFrameWork::getValidIntInput(const std::string& prompt)
{
    int input;
    while(true)
    {
        std::cout << prompt;
        std::cin >> input;
        if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Invalid input. Please enter a number.\n";
            } else {
                    return input;
            }
        }
    }


// validating the paretheses are matched and even
void CalculatorFrameWork::parentheseValidation(string userPrompt)
{
    std::stack<char> parenthesesInCheck;

    for(char c : userPrompt){
        if( c == '(' || c == '[' || c == '{'){
            parenthesesInCheck.push(c);
        }else if ( c == ')' || c == ']' || c == '}'){
            if(parenthesesInCheck.empty()){
                std::cout <<"Unmatched closing parentheses.\n";
                std::exit(0);
            }
        
            char openingParentheses = parenthesesInCheck.top();
            if((openingParentheses == '(' && c == ')') ||(openingParentheses == '[' && c == ']') 
                || (openingParentheses == '{' && c == '}')){
                    parenthesesInCheck.pop();
                }else{
                    std::cout << "Ueven Parentheses.\n";
                }
        }
    }   
    if (!parenthesesInCheck.empty()){
            std::cout << "Parentheses are mismatched.\n";
            std::exit(0);
    }else{
        //std::cout << "Parentheses are valid\n";
        return;
    }
}

// formatting the sturcture of paretheses problem
// make sure there is a * symbol in between two scope if there is no other operation symbol
string  CalculatorFrameWork::formattingParetheses(string usrprmpt)
{ 
    string input = usrprmpt;
    for (size_t i = 0; i < input.size() - 1; ++i) {
        if (isdigit(input[i])) {
            size_t j = i + 1;
            while (j < input.size() && input[j] == ' ') {
                ++j; // Skip over spaces
            }
            if (j < input.size() && (input[i + 1] == '(' || input[i + 1] == '{' || input[i + 1] == '[')) {
                input.insert(i + 1, "*");
                i = j; // Move i to the position of the next digit
            }
        }
        if(input[i] == ')' || input[i] == '}' || input[i] == ']'){
            size_t k = i + 1;
            while ( k < input.size() && input[k] == ' ') {
                ++k; // Skip over spaces
            }
            //std::cout << input[i+1] << endl;
            if (k < input.size() && isdigit(input[k])){
                input.insert(i+1,"*");
                i = k; //Move i to the position of the next digit
            }
        }
    }
    return input;
}

// Whether the parentheses are still left to be solved
bool CalculatorFrameWork::checkingTheExistanceOfParetheses()
{
    for(char c : userInput)
        if( c == '(' || c == '[' || c == '{')
        return true;
    return false;
}

// setting the parentheses,indexMapping paretheses, input numbers, and operator signs
void CalculatorFrameWork::settingTheValues( string usrPrpmt)
{
    // assigning parenthese into an array after validation
    for( int i = 0; i < usrPrpmt.length(); i++)
    {
        int j = 0;
        while(j < PARENTHESES_LIST)
        {
            if(usrPrpmt[i] == PARENTHESES[j])
            {
                addParentheses(usrPrpmt[i]);
                addParenthesesMappingIndex(usrPrpmt[i],i);
                break;
            }else{
                j++;
            }
        }
    }

    std::istringstream iss(usrPrpmt);
    double num;
    char op;

    while (iss >> num) {
        inputNumbers.push_back(num);
        if (iss >> op)
            operatorSigns.push_back(op);
    }
}

// clear out the old values and resetting the new values from the new user prompt
void CalculatorFrameWork::resettingAndUpdatingtheValues(string processingPrmpt)
{
    // restting all the values before updating the
    userInput.clear();
    parentheses.clear();
    parenthesesMappingIndex.clear();
    inputNumbers.clear();
    operatorSigns.clear();
    addUserInput(processingPrmpt);
    settingTheValues(processingPrmpt);
}

// Validating, and formatting the first user input
void CalculatorFrameWork::formattingInput()
{
    std::string input;
    std::cout << "Enter your calculation or enter 'done' to stop the calculation: ";
    getline(std::cin, input);
    // stopping the program according to user input
    if(input == "done" || input == "Done")
    {
        // look up all the problems user have prompted
        lookUpRecord();
        throw std::runtime_error("User requested to stop the calculation.");
    }

    //valiate the paretheses
    parentheseValidation(input);
    
    

    //making sure there is a multiplication sign between the two parethesese scope
    //what if they are not placed according to your index placing.
    input = formattingParetheses(input);
    
    // add the user input 
    addUserInput(input);
    
    //initial userInput
    primaryUserInput = input;

    std::cout << input << endl;

    // setting the values from user input
    settingTheValues(input);
    
    
    
}


//formatting and handling the trailing zeros from dobule return type computation
string CalculatorFrameWork::formatNumber(double number)
{
    std::ostringstream out;
    out << std::fixed << std::setprecision(6) << number;
    std::string str = out.str();

    // Check if there are significant numbers after the decimal point
    int decimalPos = str.find('.');
    //npos is the highest possible value of the element size_t
    // it also means until end of the string.
    // if decimal point is in the string and is there significant figure after decimal point
    if (decimalPos != std::string::npos && str.find_first_not_of('0', decimalPos + 1) == std::string::npos) {
        // Remove trailing zeros
        str.erase(str.find_last_not_of('0') + 1, std::string::npos);

        // Remove trailing decimal point, if any
        if (str.back() == '.') {
            str.pop_back();
        }
    }

    return str;

}

// slicing the user string into a substring
// getting values from that particular substring 
void CalculatorFrameWork::splitngPromptByScope(string usrpmt, int startingIndex, int endingIndex)
{
    string inputWithinScope;
    inputWithinScope = usrpmt.substr(startingIndex , endingIndex - startingIndex );
    //std::cout<< inputWithinScope << endl;
    inputNumbers.clear();
    operatorSigns.clear();

    settingTheValues(inputWithinScope);
}


// comptation are carried out according to the hierarchy of the operators
void  CalculatorFrameWork::precedenceHandlingSecondStep()
{
    std::stack<double> numbers;
    std::stack<char> operators;
    
    for( int i = 0; i < inputNumbers.size(); i++)
    {
        numbers.push(inputNumbers[i]);

        if (i < operatorSigns.size())
        {
            while (!operators.empty() && precedenceForOperators(operators.top()) >= precedenceForOperators(operatorSigns[i]))
            {
                try
                {   
                    compute(numbers,operators);
                } catch ( const std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                    std::exit(EXIT_FAILURE); // terminate the program
                    return;
                }
            }
            operators.push(operatorSigns[i]);
        }
    }
    
    while ( !operators.empty())
    {
        try
            {
                compute(numbers,operators);
            } catch ( const std::runtime_error& e) {
                std::cout << e.what() << std::endl;
                std::exit(EXIT_FAILURE); // terminate the program 
                return;
            }
    }

    if (!numbers.empty())
    {
        result = numbers.top();
    }

}

// the scope of paretheses are carried out innermost to outter scope
void  CalculatorFrameWork::precedenceHandling()
{
    std::vector<double> numbers;
    std::vector<char> operators;
    std::stack<char> parenthesesStack;
    std::string inputWithinScope;
    char openingParentheses[] = {'(','{','['};
    int  scopeOfParentheses = parentheses.size() / 2;
    int finishingAllTheParentheses = 0;
    string answerInString;
    double answer = 0;
    string updatedUserInput; 

    while(finishingAllTheParentheses < scopeOfParentheses){
        bool flag = true;
        int i = 0;


        while(flag)
        {
            if(std::find(std::begin(openingParentheses), std::end(openingParentheses),parentheses[i]) != std::end(openingParentheses))
            {
                i++;
            }else{
                flag = false;
            }
        }
        char innermostOpeningParenthese = parentheses[i-1];
        int  indexOfInnermostOpeningParenthese = parenthesesMappingIndex.at(innermostOpeningParenthese);
        int  indexOfInnermostClosingParenthese;

        if( innermostOpeningParenthese == '(')
            indexOfInnermostClosingParenthese = parenthesesMappingIndex.at(')');
        if( innermostOpeningParenthese == '[')
            indexOfInnermostClosingParenthese = parenthesesMappingIndex.at(']');
        if( innermostOpeningParenthese == '{')
            indexOfInnermostClosingParenthese = parenthesesMappingIndex.at('}');

        inputWithinScope = userInput;

        std::cout << "\nStep "<< finishingAllTheParentheses+1 << ":" << endl;
        splitngPromptByScope(inputWithinScope,indexOfInnermostOpeningParenthese + 1, indexOfInnermostClosingParenthese);

        //succecssfully implemented the precendence in a scope
        //std::cout << updatedUserInput << endl;
        precedenceHandlingSecondStep();
        answer = result;
        answerInString = formatNumber(answer);


        // after finding the innermost scope put it into formating and do the second precedence.
        updatedUserInput = userInput.erase(indexOfInnermostOpeningParenthese, indexOfInnermostClosingParenthese - indexOfInnermostOpeningParenthese + 1);
        updatedUserInput = userInput.insert(indexOfInnermostOpeningParenthese, answerInString);
        
        std::cout << updatedUserInput << endl;
        // updating the parentheses until the opening parentheses are exhausted
        resettingAndUpdatingtheValues(updatedUserInput);

        finishingAllTheParentheses += 1;
    }
    
    std::cout << "\nFinal Solution : \n" << userInput << endl; 
    precedenceHandlingSecondStep();

}


// cases for operator hierarchy
int CalculatorFrameWork::precedenceForOperators(char op)
{
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
        case '%':
            return 3;
        default:
            return 0;
    }

}


// processing the computation
void  CalculatorFrameWork::compute(std::stack<double>& numbers,std::stack<char>& operators)
{
    double res;

    if(numbers.empty() || operators.empty())
    {
        std::cout << "Error: Numbers or operators Stack is empty!" << endl;
        std::exit(0);
    }
    if(numbers.size() == 1)
    { 
        std::cout << "There is only one number" << endl;
        std::exit(0);
    }else{
        // get the top of the element from the stack and pop it out from the stack
        double b = numbers.top(); numbers.pop();
        double a = numbers.top(); numbers.pop();
        char op = operators.top(); operators.pop();
        switch (op)
        {
            case '+' : res = a + b; break;
            case '-' : res = a - b; break;
            case '*' : res = a * b; break;
            case '/' : 
                if ( b != 0)
                {
                    res = a / b; break;
                }    
                else{
                    throw std::runtime_error("Undefined: Divsion by Zero");   
                }
            case '%' :
                if ( b != 0)
                {
                    res = std::fmod(a,b); break;
                }    
                else{
                    throw std::runtime_error("Undefined: Divsion by Zero"); 
                }
        }
        if (a && b && op && res)
            std::cout << a << " " << op << " " << b << " = " << res << endl;
        numbers.push(res);
    }

}
void CalculatorFrameWork::recordProblemsAndAnswer(string useript, double result)
{
    record.problems.push_back(useript);
    record.answers.push_back(result);
}
void CalculatorFrameWork::lookUpRecord()
{
    if (!record.problems.empty()){
        for(int i = 0; i < record.problems.size(); i++){
            std::cout << "Problem " << i+1 << endl;
            std::cout <<record.problems[i] << "  :  " << record.answers[i] << endl; 
            std::cout << endl;
        }
    }
}
  
// portraying the layout of a calculator
// not interactive
void CalculatorFrameWork::calculatorDisplay()
{
    std::cout << endl;
    std::cout <<" "<<primaryUserInput<< endl;
    std::cout <<" |---------------|" << endl;
    std::cout <<" | 1 | 2 | 3 | + |" << endl;
    std::cout <<" | 4 | 5 | 6 | - |" << endl;
    std::cout <<" | 7 | 8 | 9 | * |" << endl;
    std::cout <<" |     0     | / |" << endl;
    std::cout <<" |-----------| % |" << endl;
    std::cout <<" ANS = " << result << endl;
}
 
// resetting the necessary values after each and every computation
void CalculatorFrameWork::reset()
{
    result = 0;
    inputNumbers.clear();
    operatorSigns.clear();
    userInput = "";
    primaryUserInput = "";
}
