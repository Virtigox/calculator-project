# Advanced Calculator

This calculator program is designed to handle complex mathematical expressions with multiple levels of parentheses and different types of operators.

## Features

- Validating the parentheses structures,unmatched or not even
- Formatting the trailing zeros after computation
- Supports addition, subtraction, multiplication, modulo and division operations.
- Handles parentheses of different types: (), [], {}.
- Restructure the parethense as there is no multiplication sign between two different scope of paretheses
- Evaluates expressions based on the correct mathematical precedence rules:
  - Parentheses are evaluated first, starting from the innermost level.
  - Multiplication and division are evaluated next, from left to right.
  - Addition and subtraction are evaluated last, from left to right.
- Storing the problems along with answers to look up.

## Usage

Enter your mathematical expression at the prompt. Use the following symbols for operations:

- Addition: +
- Subtraction: -
- Multiplication: *
- Division: /
- Modulo: %

You can also use parentheses to group operations. The calculator supports the following types of parentheses: (), [], {}.


## Troubleshooting

-If you're having trouble with the calculator, make sure you're using the correct symbols for operations. The calculator uses the / symbol for division, not the ÷ symbol.

-Retyping the prompt will help somehow solve the "There is only one number" error. The mod symbol, "%" is one of the reason if you copied from other sources.


## Bugs

- "%" sign is not read correctly 
- ld: warning: ignoring duplicate libraries: '-lc++', the Makefile problem.

## Future Implementation

- input validation & error handling (words or numeric)
- expoenets ( treat ^x as the operator and fix it's precedance)
- roots
- trigonometry
- summation signs
- graphical interface
- learn more about headerfiles,implementation of Gurd Clause and  software developments

## Compilation
https://www.onlinegdb.com/
Online compiler will be much easier to compile the program to check whether program is functioning well.
If not, 
- installing MinGW or Cygwin, which are software packages that provide a collection of GNU software, including the GCC compiler, for Windows.
- installing Xcode in Mac for g++ compiler
- After that, typing 'make' to compile the program

## Contributing

If you'd like to contribute to this project, please open an issue or submit a pull request.
Comments, advices and harsh critism are much appreciated!!!
