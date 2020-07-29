# Compound-Interest
Determines the balance of a savings account using the average daily balance

A C++ progam for a Data Structues Course that determines the balance of a compound interest savings account using the average daily balance and a dynamic array as the data type that store the daily balance. 

The user can use the following functions:
`deposit` Deposits amount and adds to the current balance
`withdraw` Withdraws amount from current balance
`advanceDay` skips a head a number of days. If it's skipped more than 30 days, it adds compounded interest using the average daily balance
`getDayNumber` returns the current day
`getPreviousBalance` returns the balance of a specific previous date
`getCurrentBalance` returns the balance of the current day
`setAPR` sets the interest rate (compounded monthly)
