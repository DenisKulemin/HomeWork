#include "GoldMedicalCard.h"
#include "PrivateDoctorMedicalCard.h"
using namespace std;

int BaseMedicalCard::PatientID = 0;

int main()
{
    cout << "Create new Base patient." << endl << endl;
    // Create base medical card
    BaseMedicalCard *pPatient = new BaseMedicalCard();
    pPatient->SetResidenceAddress("21 Jump Street");
    pPatient->FirstName = "Thomas";
    pPatient->MiddleName = "Tom";
    pPatient->LastName = "Hanson";
    pPatient->Id = "R2D2TEC";
    pPatient->SetPhoneNumber("81235551234");
    pPatient->SetPost("-");
    pPatient->Age = 28;

    cout << "The first patient was from " << pPatient->GetResidenceAddress() << "." << endl;
    cout << "His name was " << pPatient->FirstName << " "
        << pPatient->MiddleName << " "
        << pPatient->LastName << "." << endl;
    cout << "He was " << pPatient->Age << " years old." << endl;
    cout << "PatientID " << pPatient->GetPatientID() << endl;
    cout << "-----------------------------------------" << endl << endl;

    cout << "Create new Silver patient." << endl << endl;
    // Create new card silver level
    SilverMedicalCard * pNewPatient = new SilverMedicalCard();

    // Check that it's empty
    cout << "This is a empty silver medical card" << endl;
    cout << "New patient (silver level): age " << pNewPatient->Age
        << " \nfirst name: " << pNewPatient->FirstName
        << " \nmiddle name: " << pNewPatient->MiddleName
        << " \nlast name: " << pNewPatient->LastName
        << " \nid: " << pNewPatient->Id
        << " \nphone number: " << pNewPatient->GetPhoneNumber()
        << " \nDiscount: " << pNewPatient->GetDiscount() << endl;
    cout << "PatientID " << pNewPatient->GetPatientID() << endl;
    cout << *pNewPatient << endl;

     // Transfer information from base medical card to silver medical card
    pNewPatient->UpdateMedicalCard(pPatient);

    // Check transfer result
    cout << "Update medical card to silver level." << endl;
    cout << "New patient (silver level): age " << pNewPatient->Age
        << " \nfirst name: " << pNewPatient->FirstName
        << " \nmiddle name: " << pNewPatient->MiddleName
        << " \nlast name: " << pNewPatient->LastName
        << " \nid: " << pNewPatient->Id
        << " \nphone number: " << pNewPatient->GetPhoneNumber()
        << " \nDiscount: " << pNewPatient->GetDiscount() << endl;
    cout << "PatientID " << pNewPatient->GetPatientID() << endl << endl;
    cout << "-----------------------------------------" << endl << endl;

    cout << "Create new Base patient." << endl << endl;
    // Create new base medical card (previous should be deleted after transfer)
    pPatient = new BaseMedicalCard();
    pPatient->SetResidenceAddress("21 Jump Street");
    pPatient->FirstName = "Thomas";
    pPatient->MiddleName = "Tom";
    pPatient->LastName = "Hanson";
    pPatient->Id = "R2D2TEC";
    pPatient->SetPhoneNumber("81235551234");
    pPatient->SetPost("-");
    pPatient->Age = 28;

    cout << "Create new patient with private doctor." << endl << endl;
    PrivateDoctorMedicalCard *pNewPatientWithPrivateDoctor = new PrivateDoctorMedicalCard();
    pNewPatientWithPrivateDoctor->SetPrivateDoctorId("New ID");

    cout << "This is a empty private doctor medical card" << endl;
    cout << "New patient (silver level): age " << pNewPatientWithPrivateDoctor->Age
        << " \nfirst name: " << pNewPatientWithPrivateDoctor->FirstName
        << " \nmiddle name: " << pNewPatientWithPrivateDoctor->MiddleName
        << " \nlast name: " << pNewPatientWithPrivateDoctor->LastName
        << " \nid: " << pNewPatientWithPrivateDoctor->Id
        << " \nphone number: " << pNewPatientWithPrivateDoctor->GetPhoneNumber()
        << " \nPrivate doctor id: " << pNewPatientWithPrivateDoctor->GetPrivateDoctorId() << endl;
    cout << "PatientID " << pNewPatientWithPrivateDoctor->GetPatientID() << endl << endl;

    // Transfer information from base medical card to private doctor medical card
    pNewPatientWithPrivateDoctor->UpdateMedicalCard(pPatient);

    cout << "Update base medical card to private doctor level." << endl;
    cout << "New patient (silver level): age " << pNewPatientWithPrivateDoctor->Age
        << " \nfirst name: " << pNewPatientWithPrivateDoctor->FirstName
        << " \nmiddle name: " << pNewPatientWithPrivateDoctor->MiddleName
        << " \nlast name: " << pNewPatientWithPrivateDoctor->LastName
        << " \nid: " << pNewPatientWithPrivateDoctor->Id
        << " \nphone number: " << pNewPatientWithPrivateDoctor->GetPhoneNumber()
        << " \nPrivate doctor id: " << pNewPatientWithPrivateDoctor->GetPrivateDoctorId() << endl;
    cout << "PatientID " << pNewPatientWithPrivateDoctor->GetPatientID() << endl << endl;
    cout << "-----------------------------------------" << endl << endl;

    cout << "Create new Base patient." << endl << endl;
    // Create new base medical card (previous should be deleted after transfer)
    pPatient = new BaseMedicalCard();
    pPatient->SetResidenceAddress("21 Jump Street");
    pPatient->FirstName = "Thomas";
    pPatient->MiddleName = "Tom";
    pPatient->LastName = "Hanson";
    pPatient->Id = "R2D2TEC";
    pPatient->SetPhoneNumber("81235551234");
    pPatient->SetPost("-");
    pPatient->Age = 28;

    GoldMedicalCard *pNewGoldPatient = new GoldMedicalCard();
    pNewGoldPatient->SetPrivateDoctorId("Some ID");

    cout << "This is a empty gold medical card" << endl;
    cout << "New patient (silver level): age " << pNewGoldPatient->Age
        << " \nfirst name: " << pNewGoldPatient->FirstName
        << " \nmiddle name: " << pNewGoldPatient->MiddleName
        << " \nlast name: " << pNewGoldPatient->LastName
        << " \nid: " << pNewGoldPatient->Id
        << " \nphone number: " << pNewGoldPatient->GetPhoneNumber()
        << " \nDiscount: " << pNewGoldPatient->GetDiscount()
        << " \nPrivate doctor id: " << pNewGoldPatient->GetPrivateDoctorId() << endl;
    cout << "PatientID " << pNewGoldPatient->GetPatientID() << endl;

    // Transfer information from base medical card to gold medical card
    pNewGoldPatient->UpdateMedicalCard(pPatient);

    cout << "Update medical card to gold level." << endl;
    cout << "New patient (gold level): age " << pNewGoldPatient->Age
        << " \nfirst name: " << pNewGoldPatient->FirstName
        << " \nmiddle name: " << pNewGoldPatient->MiddleName
        << " \nlast name: " << pNewGoldPatient->LastName
        << " \nid: " << pNewGoldPatient->Id
        << " \nphone number: " << pNewGoldPatient->GetPhoneNumber()
         << " \nDiscount: " << pNewGoldPatient->GetDiscount()
        << " \nPrivate doctor id: " << pNewGoldPatient->GetPrivateDoctorId() << endl;
    cout << "PatientID " << pNewGoldPatient->GetPatientID() << endl;
    // I haven't overrided << for child class, so it shows discount from parent class
    cout << *pNewGoldPatient << endl;

    return 0;
}
