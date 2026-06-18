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

# **System Architecture**

```mermaid
flowchart TD
    Start((Start)) --> Login["Login Screen"]

    Login --> Input["Enter Account Number & PIN"]
    Input --> Auth{"Valid Login?"}

    Auth -- "No" --> Attempts{"Failed Attempts = 3?"}
    Attempts -- "No" --> Login
    Attempts -- "Yes" --> Exit["Exit Application"]

    Auth -- "Yes" --> CurrentClient["Load CurrentClient"]
    CurrentClient --> Main["ATM Main Menu"]

    Main --> QW["Quick Withdraw"]
    Main --> NW["Normal Withdraw"]
    Main --> DP["Deposit"]
    Main --> CB["Check Balance"]
    Main --> LO["Logout"]

    QW --> Save1["Update Clients.txt"]
    NW --> Save2["Update Clients.txt"]
    DP --> Save3["Update Clients.txt"]

    Save1 --> Session["Add Transaction to Session"]
    Save2 --> Session
    Save3 --> Session

    CB --> Main
    Session --> Main

    LO --> ReceiptChoice{"Save Session Receipt?"}
    ReceiptChoice -- "Yes" --> Receipt["Generate Receipt.txt"]
    ReceiptChoice -- "No" --> Clear["Clear Session"]

    Receipt --> Clear
    Clear --> Reset["Clear CurrentClient"]
    Reset --> Login
```

---

# **System Diagrams**

## **UML Class Diagram**

```mermaid
classDiagram
    class clsPerson {
        +Name()
        +Phone()
    }

    class clsATMClient {
        +AccountNumber()
        +PinCode()
        +AccountBalance()
        +Find()
        +Deposit()
        +Withdraw()
        +Save()
        +IsEmpty()
    }

    class clsScreen {
        +_DrawScreenHeader()
        +_DrawScreenHeaderMain()
    }

    class clsLoginScreen {
        +ShowLoginScreen()
    }

    class clsATMMainScreen {
        +ShowATMMainMenu()
    }

    class clsQuickWithdrawScreen {
        +ShowQuickWithdrawScreen()
    }

    class clsNormalWithdrawScreen {
        +ShowNormalWithdrawScreen()
    }

    class clsDepositScreen {
        +ShowDepositScreen()
    }

    class clsCheckBalanceScreen {
        +ShowCheckBalanceScreen()
    }

    class clsReceipt {
        +AddTransaction()
        +SaveReceipt()
    }

    clsPerson <|-- clsATMClient

    clsScreen <|-- clsLoginScreen
    clsScreen <|-- clsATMMainScreen
    clsScreen <|-- clsQuickWithdrawScreen
    clsScreen <|-- clsNormalWithdrawScreen
    clsScreen <|-- clsDepositScreen
    clsScreen <|-- clsCheckBalanceScreen
```

## **Login Flow**

```mermaid
flowchart TD
    A((Start)) --> B["Login Screen"]
    B --> C["Enter Account Number"]
    C --> D["Enter PIN Code"]
    D --> E{"Valid Client?"}

    E -- "Yes" --> F["Open ATM Main Menu"]

    E -- "No" --> G["Increase Failed Attempts"]
    G --> H{"Attempts = 3?"}

    H -- "No" --> B
    H -- "Yes" --> I["Exit Application"]
```

## **ATM Operations Flow**

```mermaid
flowchart TD
    Main["ATM Main Menu"] --> QW["Quick Withdraw"]
    Main --> NW["Normal Withdraw"]
    Main --> DP["Deposit"]
    Main --> CB["Check Balance"]
    Main --> LO["Logout"]

    QW --> W1{"Enough Balance?"}
    NW --> W2{"Enough Balance?"}

    W1 -- "Yes" --> Update1["Withdraw Amount"]
    W1 -- "No" --> Main

    W2 -- "Yes" --> Update2["Withdraw Amount"]
    W2 -- "No" --> Main

    DP --> Update3["Deposit Amount"]

    Update1 --> Save1["Save to Clients.txt"]
    Update2 --> Save2["Save to Clients.txt"]
    Update3 --> Save3["Save to Clients.txt"]

    Save1 --> Session["Add to Session Transactions"]
    Save2 --> Session
    Save3 --> Session

    Session --> Main
    CB --> Main
    LO --> Receipt["Ask for Session Receipt"]
```

## **File Storage Diagram**

```mermaid
flowchart LR
    clsATMClient["clsATMClient"] --> ClientsTxt[("Clients.txt")]
    clsReceipt["clsReceipt"] --> ReceiptTxt[("Receipt.txt")]

    ClientsTxt --> ClientData["Account Number<br/>PIN Code<br/>Name<br/>Phone<br/>Balance"]

    ReceiptTxt --> ReceiptData["Client Info<br/>Session Transactions<br/>Final Balance"]
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
