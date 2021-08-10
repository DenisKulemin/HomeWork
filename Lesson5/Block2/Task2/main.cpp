#include <iostream>
#include "MedicalCard.h"
#include <string>
using namespace std;

int main()
{
    MedicalCard patientA;
    patientA.SetResidenceAddress("21 Jump Street");
    patientA.FirstName = "Thomas";
    patientA.MiddleName = "Tom";
    patientA.LastName = "Hanson";
    patientA.Id = "R2D2TEC";
    patientA.SetPhoneNumber("81235551234");
    patientA.SetPost("-");
    patientA.Age = 28;

    cout << "The first patient was from " << patientA.GetResidenceAddress() << "." << endl;
    cout << "His name was " << patientA.FirstName << " "
        << patientA.MiddleName << " "
        << patientA.LastName << "." << endl;
    cout << "He was " << patientA.Age << " years old." << endl;

    return 0;
}
