#include <iostream>
using namespace std;

class Account 
{
	
protected:
	
    string name;
    int account_number;
    string account_type;
    float balance;
    
public:
	
    Account(string n, int a, string t, float b) : name(n), account_number(a), account_type(t), balance(b) {}
    
    virtual void deposit(float amount) {
    	
        balance += amount;
    }
    
    virtual void display() 
	{
        cout << "Name: " << name << endl;
        cout << "Account number: " << account_number << endl;
        cout << "Account type: " << account_type << endl;
        cout << "Balance: " << balance << endl;
    }
    
    virtual void compute_interest() {}
    
    virtual void withdraw(float amount) {}
};

class CurrentAccount : public Account 

{
	
private:
	
    float min_balance;
    float penalty;
public:
	
    CurrentAccount(string n, int a, float b) : Account(n, a, "Current", b), min_balance(1000), penalty(50) {}
    
    void withdraw(float amount) override {
    	
        if (balance - amount < min_balance) 
		{
        	
            cout << "Insufficient balance. A penalty of " << penalty << " will be imposed." << endl;
            balance -= penalty;
            
        }
        if (amount > balance)
		 {
		 	
            cout << "Insufficient balance." << endl;
        }
		
		 else
		
		 {
            balance -= amount;
            cout << "Withdrawal of " << amount << " successful." << endl;
            
        }
    }
};

class SavingsAccount : public Account {
	
private:
	
    float interest_rate;
    
public:
	
    SavingsAccount(string n, int a, float b) : Account(n, a, "Savings", b), interest_rate(0.05) {}
    
    void compute_interest() override {
    	
        float interest = balance * interest_rate;
        
        balance += interest;
        
        cout << "Interest of " << interest << " deposited." << endl;
    }
};

int main() {
    SavingsAccount sa("jethalal", 200100300, 10000);
    CurrentAccount ca("mehtasahab", 1423557890, 500000);

    sa.deposit(500);
    ca.deposit(1000);

    sa.display();
    ca.display();

    sa.compute_interest();
    ca.withdraw(4502);

    sa.display();
    ca.display();

    return 0;
}
