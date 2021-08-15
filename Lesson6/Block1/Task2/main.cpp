#include "GoldMedicalCard.h"
#include "PrivateDoctorMedicalCard.h"
using namespace std;

int main()
{
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

    return 0;
}
