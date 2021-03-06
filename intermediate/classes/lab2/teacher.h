#include <string>

using namespace std;

class Teacher{
  //The Teacher and Teacher classes need to have private member variables for first and last names, age, address, city, and phone along with public accessors for these.
  private:
    string firstName;
    string lastName;
    int age;
    string address;
    string phone;
    
  public:
  
    // Each class needs to have a default constructor and one that sets the values of the member variables when the object is created.  Each class should also have a destructor.
    Teacher();
    Teacher(string fistName, string lastName, int age, string address, string phone);
    ~Teacher();

    void setFirstName(string n);
    string getFirstName();
    
    void setLastName(string n);
    string getLastName();

    void setAge(int a);
    int getAge();
    
    void setAddress(string a);
    string getAddress();

    void setPhone(string p);
    string getPhone();

    void GradeStudent();
    void SitInClass();

};