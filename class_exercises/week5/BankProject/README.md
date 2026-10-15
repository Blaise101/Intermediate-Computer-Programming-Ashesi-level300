## Compile with GCC (MSYS2 UCRT64)

To check the outputs, run these commands from the `BankProject` directory:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src/Account.cpp src/SavingsAccount.cpp src/CheckingAccount.cpp src/main.cpp -o BankProject.exe
```

Then run:

```bash
./BankProject.exe
```
