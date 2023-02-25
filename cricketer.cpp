#include <iostream>
#include <string>
using namespace std;

class Cricketer
 {
 	
protected:
	
    string name;
     int age;
     
    string country;
    
public:
	
    Cricketer(string n, int a, string c) : name(n), age(a), country(c) {}
};

class Batsman : public Cricketer 
{
	
private:
	
    int total_runs;
    float average_runs;
    int best_performance;
    
public:
	
    Batsman(string n, int a, string c) : Cricketer(n, a, c), total_runs(0), average_runs(0), best_performance(0) {}
    
    void inputdata() 
	{
        cout << "Enter total runs: ";
        cin >> total_runs;
        cout << "Enter best performance: ";
        cin >> best_performance;
    }
    
    void calculateaverageruns()
	 {
        average_runs = (float) total_runs / 10;
    }
    
    void displaydata() 
	{
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Country: " << country << endl;
        cout << "Total Runs: " << total_runs << endl;
        cout << "Average Runs: " << average_runs << endl;
        cout << "Best Performance: " << best_performance << endl;
    }
};

int main() {
    Batsman batsman("virat kohli", 31, "india");
    batsman.inputdata();
    batsman.calculateaverageruns();
    batsman.displaydata();
    return 0;
}