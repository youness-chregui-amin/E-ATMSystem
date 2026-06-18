# **E-ATMSystem v2.0**

**E-ATMSystem** is a console-based ATM simulation system developed in **C++** using **Object-Oriented Programming (OOP)** principles.

The project simulates the core functionalities of a real Automated Teller Machine (ATM), including secure authentication, deposits, withdrawals, balance inquiries, session receipts, and persistent data storage using text files.

The application was refactored from a procedural implementation into a modular OOP architecture to improve maintainability, readability, and scalability.

---

# **Table of Contents**

1. Features
2. Login Information
3. Database Structure
4. How It Works
5. Project Structure
6. System Architecture
7. System Diagrams
8. Learning Goals
9. Changes from Previous Version
10. Author

---

# **Features**

## **Authentication**

* Secure login using Account Number and PIN Code
* Maximum of **3 login attempts**
* Automatic session logout
* Return to Login Screen after Logout

---

## **ATM Operations**

* Quick Withdraw
* Normal Withdraw
* Deposit
* Check Balance
* Logout

---

## **Session Receipt**

* Records all successful transactions during the current session
* Generates a receipt when logging out
* Receipt is saved as **Receipt.txt**
* Previous receipt is automatically replaced

---

## **Persistent Storage**

* Clients are stored inside `Clients.txt`
* Account balances are updated immediately
* Data is preserved between executions

---

## **Command-Line Interface (CLI)**

* Login Screen
* ATM Main Menu
* Quick Withdraw Screen
* Normal Withdraw Screen
* Deposit Screen
* Check Balance Screen

---

# **Login Information**

Example account:

| Account Number | PIN Code |
| -------------- | -------- |
| AD100          | 1234     |

> Client accounts can be modified directly inside **Clients.txt**.

---

# **Database Structure**

## **Clients.txt**

Stores all client information.

| Field           |
| --------------- |
| Account Number  |
| PIN Code        |
| Client Name     |
| Phone           |
| Account Balance |

---

Each record uses the custom separator:

```text
#//#
```

Example:

```text
AD100#//#1234#//#Youness Chergui Amin#//#0600000000#//#3500
```

---

# **How It Works**

1. Client enters Account Number and PIN Code.
2. Credentials are validated.
3. ATM Main Menu is displayed.
4. Client performs one or more banking operations.
5. Every successful transaction is recorded in the current session.
6. Client logs out.
7. The system asks whether to generate a receipt.
8. Receipt is saved to **Receipt.txt**.

---

# **Project Structure**

```text
ATM.cpp

├── Core
│   ├── Person.h
│   ├── ATMClient.h
│   └── Global.h
│
├── Screens
│   ├── Screen.h
│   ├── LoginScreen.h
│   ├── ATMMainScreen.h
│   ├── QuickWithdrawScreen.h
│   ├── NormalWithdrawScreen.h
│   ├── DepositScreen.h
│   └── CheckBalanceScreen.h
│
├── Utilities
│   ├── StringLib.h
│   ├── DateLib.h
│   └── InputValidation.h
│
├── System
│   ├── Receipt.h
│   └── Session.h
│
├── Data
│   ├── Clients.txt
│   └── Receipt.txt
│
└── README.md
```

---

# **System Architecture**

```text
Login System
      │
      ▼
 ATM Main Menu
 ├── Quick Withdraw
 ├── Normal Withdraw
 ├── Deposit
 ├── Check Balance
 └── Logout
        │
        ▼
 Session Receipt
        │
        ▼
 Receipt.txt
```

---

# **System Diagrams**

## Complete System Architecture

```mermaid
flowchart TD

    Login["Login Screen"] --> Auth{"Valid Login?"}

    Auth -- No --> Login
    Auth -- Yes --> Main["ATM Main Menu"]

    Main --> Quick["Quick Withdraw"]
    Main --> Normal["Normal Withdraw"]
    Main --> Deposit["Deposit"]
    Main --> Balance["Check Balance"]

    Quick --> Session["Session Transactions"]
    Normal --> Session
    Deposit --> Session

    Session --> Logout["Logout"]

    Logout --> Receipt["Generate Receipt"]

    Receipt --> File["Receipt.txt"]

    Main --> Client["ATMClient"]

    Client --> Clients["Clients.txt"]
```

## Navigation Flow

```mermaid
flowchart TD

Start((Start))

Start --> Login

Login --> Check{"Login Success?"}

Check -- No --> Login
Check -- Yes --> Main

Main --> QuickWithdraw
Main --> NormalWithdraw
Main --> Deposit
Main --> CheckBalance
Main --> Logout

QuickWithdraw --> Main
NormalWithdraw --> Main
Deposit --> Main
CheckBalance --> Main

Logout --> End((End))
```

## UML Class Diagram

```mermaid
classDiagram

class Person

class ATMClient
class Screen
class LoginScreen
class ATMMainScreen
class QuickWithdrawScreen
class NormalWithdrawScreen
class DepositScreen
class CheckBalanceScreen
class Receipt

Person <|-- ATMClient

Screen <|-- LoginScreen
Screen <|-- ATMMainScreen
Screen <|-- QuickWithdrawScreen
Screen <|-- NormalWithdrawScreen
Screen <|-- DepositScreen
Screen <|-- CheckBalanceScreen
```

---

# **Learning Goals**

This project was created to practice:

* Object-Oriented Programming (OOP)
* Classes & Objects
* Encapsulation
* Inheritance
* Modular Design
* File Handling
* Data Persistence
* ATM Simulation
* Authentication Systems
* Session Management
* Receipt Generation

---

# **Changes from Previous Version**

| Feature             | v1.0                   | v2.0                              |
| ------------------- | ---------------------- | --------------------------------- |
| Programming Style   | Procedural Programming | Object-Oriented Programming (OOP) |
| Authentication      | Basic                  | Improved                          |
| Login Attempts      | Unlimited              | Maximum 3 Attempts                |
| Quick Withdraw      | Available              | Refactored                        |
| Normal Withdraw     | Available              | Refactored                        |
| Deposit             | Available              | Refactored                        |
| Check Balance       | Available              | Refactored                        |
| Session Receipt     | Not Available          | Added                             |
| Receipt.txt         | Not Available          | Added                             |
| Screen Architecture | Not Available          | Added                             |
| Code Organization   | Single File            | Multi-file OOP                    |
| Documentation       | Basic                  | Professional                      |

---

# **Author**

**Youness Chergui Amin**

**ATM Simulation System – C++ / Object-Oriented Programming**
