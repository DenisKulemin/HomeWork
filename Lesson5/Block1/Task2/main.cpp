#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct medicalCard {
        string residenceAddress;
        string firstName;
        string middleName;
        string lastName;
        string id;
        string phoneNumber;
        string post;
        int age;
    };

    medicalCard patientA;
    patientA.residenceAddress = "21 Jump Street";
    patientA.firstName = "Thomas";
    patientA.middleName = "Tom";
    patientA.lastName = "Hanson";
    patientA.id = "R2D2TEC";
    patientA.phoneNumber = "81235551234";
    patientA.post = "-";
    patientA.age = 28;

    cout << "The first patient was from " << patientA.residenceAddress << "." << endl;
    cout << "His name was " << patientA.firstName << " "
        << patientA.middleName << " "
        << patientA.lastName << "." << endl;
    cout << "He was " << patientA.age << " years old." << endl;


    cin.get();
    return 0;
}
