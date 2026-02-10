# E-ATMSystem v1.0 – Console ATM Simulation in C++

**E-ATMSystem** is a console-based ATM simulator written in C++. It allows users to securely access their account, withdraw or deposit money, and check balances, all via a simple command-line interface.

---

## Features

* **User Authentication:** Login with account number and PIN code.
* **Quick Withdraw:** Predefined withdrawal options (20, 50, 100, 200, 400, 600, 800, 1000).
* **Normal Withdraw:** Custom withdrawal amount (must be multiple of 5).
* **Deposit:** Add funds to the account with confirmation.
* **Check Balance:** View current account balance.
* **Persistent Storage:** Client data is stored in `Clients.txt` and updated after each transaction.
* **Command-Line Interface (CLI):** User-friendly menus guide users through operations.

---

## How It Works

1. **Login:** Users provide their account number and PIN.
2. **Main Menu:** Options include Quick Withdraw, Normal Withdraw, Deposit, Check Balance, and Logout.
3. **Transactions:** All operations are performed in memory and then saved back to `Clients.txt`.
4. **Data Handling:**

   * Each client record contains: `AccountNumber`, `PinCode`, `Name`, `Phone`, `AccountBalance`.
   * Records use a custom separator: `#//#`.

---

## Project Structure

| File               | Description                                            |
| ------------------ | ------------------------------------------------------ |
| `E-ATMSystem.cpp`  | Main C++ source code implementing all functionalities. |
| `Clients.txt`      | Text file storing client records.                      |

---

## How to Run

1. Compile `E-ATMSystem.cpp` using any C++ compiler.
2. Run the program.
3. Login with example credentials:

   ```
   Account Number: admin
   PIN: 1234
   ```
4. Navigate the menu to perform transactions.

---

## Improvements & Notes

This version includes:

* **User Authentication** for security.
* **Quick and Normal Withdraw** for flexible withdrawals.
* **Deposit with confirmation** to prevent mistakes.
* **Persistent storage** in `Clients.txt` for all client data.
* **Structured CLI menus** for easy navigation.

---

## Learning Goals

* Practice **C++ file handling** using `fstream`.
* Implement **basic authentication and transactions** in a CLI.
* Learn **data persistence** without a real database.
* Understand **transaction validation** (e.g., withdraw limits, multiples of 5).

---

## License

Open-source. Free to use and modify.
