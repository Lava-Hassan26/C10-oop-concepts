#include <iostream>
using namespace std;

class clsPerson
{
private:
    short _id = 0;
    string _firstName = "";
    string _lastName = "";
    string _email = "";
    string _phone = "";

public:

    clsPerson(short id, string firstName, string lastName, string email, string phone)
    {
        _id = id;
        _firstName = firstName;
        _lastName = lastName;
        _email = email;
        _phone = phone;
    }

    void SetId(short id)
    {
        _id = id;
    }

    short GetId()
    {
        return _id;
    }

    void SetFirstName(string firstName)
    {
        _firstName = firstName;
    }

    string GetFirstName()
    {
        return _firstName;
    }

    void SetLastName(string lastName)
    {
        _lastName = lastName;
    }

    string GetLastName()
    {
        return _lastName;
    }

    string GetFullName()
    {
        return _firstName + " " + _lastName;
    }

    void SetEmail(string email)
    {
        _email = email;
    }

    string GetEmail()
    {
        return _email;
    }

    void SetPhone(string phone)
    {
        _phone = phone;
    }

    string GetPhone()
    {
        return _phone;
    }

    void SendEmail(string subject, string body)
    {
        cout << "\nThe following message send to email: " << GetEmail() << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << body << endl;
    }

    void SendSMS(string sms)
    {
        cout << "\nThe following message send to email: " << GetPhone() << endl;
        cout << "SMS: " << sms << endl;
    }

    void Print()
    {
        cout << "\n======================================\n";
        cout << "Id        : " << GetId() << endl;
        cout << "First Name: " << GetFirstName() << endl;
        cout << "Last Name : " << GetLastName() << endl;
        cout << "Full Name : " << GetFullName() << endl;
        cout << "Email     : " << GetEmail() << endl;
        cout << "Phone     : " << GetPhone() << endl;
        cout << "======================================\n";
    }
};

class clsEmployee : public clsPerson
{
    string _title = "";
    float _salary = 0.0;
    string _department = "";

public:
    clsEmployee(short id, string firstName, string lastName, string email, string phone,
        string title, float salary, string department) : clsPerson(id, firstName, lastName, email, phone)
    {
        _title = title;
        _salary = salary;
        _department = department;
    }

    void SetTitle(string title)
    {
        _title = title;
    }

    string GetTitle()
    {
        return _title;
    }

    void SetSalary(float salary)
    {
        _salary = salary;
    }

    float GetSalary()
    {
        return _salary;
    }

    void SetDepartment(string department)
    {
        _department = department;
    }

    string GetDepartment()
    {
        return _department;
    }

    void Print()
    {
        cout << "\n======================================\n";
        cout << "Id        : " << GetId() << endl;
        cout << "First Name: " << GetFirstName() << endl;
        cout << "Last Name : " << GetLastName() << endl;
        cout << "Full Name : " << GetFullName() << endl;
        cout << "Title     : " << GetTitle() << endl;
        cout << "Department: " << GetDepartment() << endl;
        cout << "Salary    : " << GetSalary() << endl;
        cout << "Email     : " << GetEmail() << endl;
        cout << "Phone     : " << GetPhone() << endl;
        cout << "======================================\n";
    }
};

int main()
{
    clsEmployee employee(10, "Lava", "Hassan", "lavah27@gmail.com", "089786756", "Developer", 5000, "Web");
    employee.Print();

    employee.SendEmail("bug", "Hi, did you fix the bug?");
    employee.SendSMS("Where are you now?");  
    system("Pause>0");
    return 0;
}