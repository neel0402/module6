#include <iostream>
#include <string>

class BankAccount 
{
	
private:
	
    std::string depositorName;
    int accountNumber;
    std::string accountType;
    double balanceAmount;

public:
	
    BankAccount() {}

    BankAccount(std::string name, int accNumber, std::string accType, double balance) 
    
        : depositorName(name), accountNumber(accNumber), accountType(accType), balanceAmount(balance) {}

    void setName(std::string name)
	 {
        depositorName = name;
    }

    void setAccountNumber(int accNumber)
	 {
        accountNumber = accNumber;
    }

    void setAccountType(std::string accType)
    
	 {
        accountType = accType;
    }

    void setBalance(double balance) 
	{
        balanceAmount = balance;
    }

    std::string getName() const 
	{
        return depositorName;
    }

    int getAccountNumber() const
	 {
        return accountNumber;
    }

    std::string getAccountType() const 
	{
        return accountType;
    }

    double getBalance() const
	 {
        return balanceAmount;
    }

    void deposit(double amount)
	 {
        balanceAmount += amount;
    }

    void withdraw(double amount)
	 {
        if (balanceAmount >= amount) 
		{
            balanceAmount -= amount;
        } else {
            std::cout << "Insufficient balance." << std::endl;
        }
    }

    void display() const {
        std::cout << "Name: " << depositorName << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Type: " << accountType << std::endl;
        std::cout << "Balance: " << balanceAmount << std::endl;
    }
};

int main()
 {
    BankAccount myAccount("John Doe", 12345, "Checking", 1000.0);

    myAccount.deposit(500.0);

    myAccount.withdraw(200.0);

    myAccount.display();

    return 0;
}

