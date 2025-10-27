# Numerical-Bases-Project
Project that takes a value in a certain numerical base inputted by the user. It then applies the arithmetic function chosen by the user and does the operation in the base specified by the user. 

## Information on debugging and fixing logic in code 
The initial numericalBases.c program failed to execute the Lab 5 objectives due to three critical errors: flawed numerical base conversion, deficient input validation, and incorrect output formatting. 

The primary logic flaw resided in the baseConversion function, which incorrectly applied variables, resulting in Base 10 values that were simply the decimal representation of the input numeral rather than its true mathematical value. Furthermore, the input handling was structurally poor, with the numInput digit check failing to reliably run and baseChoice being too complicated, violating the lab's required error handling (Operator > Base > Operands). 

Correction involved revising the baseConversion function to correctly implement the Base N (user decided variable) to Base 10 polynomial method and fixing the output logic in printResult to properly convert the Base 10 result to the desired Base N (user decided variable) numeral using repeated division. 

These corrections ensured that the program now executes the arithmetic operations accurately on correctly converted values and adheres to the structural and validation requirements of the assignment.
