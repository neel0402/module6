#include <iostream>
using namespace std;

class Account { 

protected:
	
    string name;
    int account_number;
    float balance;
    
public:
	
    Account(string n, int a, float b) : name(n), account_number(a), balance(b) {}
    
    virtual void deposit(float amount) {
    	
        balance += amount;
        
        
    }
    virtual void withdraw(float amount) {
    	
        if (amount > balance) {
            cout << "Insufficient balance." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal of " << amount << " successful." << endl;
        }
    }
    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Account number: " << account_number << endl;
        cout << "Balance: rupee" << balance << endl;
    }
};

class SavingsAccount : public Account {
	
private:
	
    float interest_rate;
    
public:
	
    SavingsAccount(string n, int a, float b, float r) : Account(n, a, b), interest_rate(r) {}
    
    void deposit(float amount) override {
    	
        Account::deposit(amount);
        
        balance += amount * interest_rate;
        
    }
};

class CurrentAccount : public Account {
	
private:
	
    float minimum_balance;
    
public:
	
    CurrentAccount(string n, int a, float b, float m) : Account(n, a, b), minimum_balance(m) {}
    
    void withdraw(float amount) override {
    	
        if (balance - amount < minimum_balance) {
        	
            cout << "Insufficient balance. A service charge of 100rupee will be imposed." << endl;
            
            balance -= 10;
            
        } else {
        	
            Account::withdraw(amount);
        }
    }
};

int main() {
    SavingsAccount sa("neel", 202310162, 1200, 0.05);
    CurrentAccount ca("yagnik", 202411173, 6000, 1000);

    sa.deposit(300);
    ca.deposit(1200);

    sa.display();
    ca.display();

    sa.withdraw(250);
    ca.withdraw(1200);

    sa.display();
    ca.display();

    return 0;
}
