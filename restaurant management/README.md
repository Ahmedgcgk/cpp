# Restaurant Management System

A simple **C++ console-based Restaurant Management System** that allows customers to select food, specify servings, and pay using either cash or credit card.

## Features

- Customer name and seat number input
- Food menu divided into:
  - Starters
  - Main Courses
  - Drinks
- Displays food names and prices
- Allows customers to select an item by number
- Allows customers to choose the number of servings
- Automatically calculates the total price
- Cash payment option
- Credit card payment option
- Credit card validation using a `cards.txt` file
- PIN verification
- Checks for sufficient funds
- Displays the customer's order and payment information
- Input validation for menu choices

## Menu

### Starters
| Item | Price |
|------|------:|
| Soup | 1.5 |
| Nuggets | 2.0 |
| Fish | 3.5 |
| Cracker | 1.0 |

### Main Courses
| Item | Price |
|------|------:|
| Biryani | 3.0 |
| Pulao | 3.0 |
| Burger | 4.0 |
| Pizza | 5.0 |
| Karahi | 2.0 |
| Shawarma | 2.0 |

### Drinks
| Item | Price |
|------|------:|
| Pepsi | 1.0 |
| Seven Up | 1.0 |
| Mirinda | 1.0 |

## How It Works

1. The program asks the customer for their name.
2. The customer enters their seat number.
3. The customer chooses a food category.
4. The available items in that category are displayed.
5. The customer selects an item by entering its number.
6. The customer enters the number of servings.
7. The program calculates the total price.
8. The customer chooses a payment method:
   - Cash
   - Credit Card
9. For cash payment, the customer enters the amount they want to pay.
10. For credit card payment, the program checks the card number, PIN, and available balance.
11. The order information is displayed.

## Technologies Used

- **Language:** C++
- **Libraries:**
  - `<iostream>` — Input and output
  - `<cmath>` — Mathematical functions
  - `<ctime>` — Time-related functions
  - `<string>` — String handling
  - `<fstream>` — File handling

## Main Components

### `fooditem` Structure

The program uses a structure to store information about each food item:

```cpp
struct fooditem {
    string Name;
    double price;
};
