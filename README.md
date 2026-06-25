# Credit Card Validator (C)

A command-line credit card validator written in C that verifies card numbers using the **Luhn Algorithm** and identifies the issuing network based on industry-standard prefixes and length rules.

## Features

* Validates user input
* Implements the Luhn checksum algorithm
* Detects multiple card issuers including:

  * Visa
  * Visa Electron
  * MasterCard
  * American Express
  * Discover
  * Maestro
  * RuPay
  * China UnionPay
  * Diners Club
  * JCB
* Uses dynamic memory allocation (`calloc`, `realloc`)
* Modular function-based design

## Technologies

* Language: C
* Standard Libraries:

  * stdio.h
  * stdlib.h
  * string.h
  * ctype.h

## Project Structure

```text
src/
└── main.c
```

## How It Works

1. Accepts a card number as input.
2. Validates that the input contains only digits and has a valid length.
3. Computes the Luhn checksum.
4. Identifies the issuing network using prefix and length rules.
5. Reports whether the card number is valid.

## Example

```
Number: 4111111111111111

Visa
Card is legit
```

## Concepts Practiced

* Dynamic memory allocation
* Pointer manipulation
* Strings
* Input validation
* Modular programming
* Function decomposition
* Prefix parsing
* Standard C library functions


## Author

Datyatreya Ray
