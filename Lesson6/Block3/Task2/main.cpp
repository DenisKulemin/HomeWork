#include "GoldMedicalCard.h"
#include "UniversalContainer.h"
using namespace std;

int BaseMedicalCard::PatientID = 0;

struct Cards {
    BaseMedicalCard *pBaseMedicalCard;
    SilverMedicalCard *pSilverMedicalCard;
};

/*
Don't have enough time to finish this task. push(), pop(), front() and container for bool
*/



int main()
{
    //Create container
    UniversalContainer<Cards> * container = new UniversalContainer<Cards>();
    cout << "Create new Base patient." << endl << endl;
    Cards cards;
    cards.pBaseMedicalCard = new BaseMedicalCard();

    // Create base medical card
    //BaseMedicalCard *pPatient = new BaseMedicalCard();
    cards.pBaseMedicalCard->SetResidenceAddress("21 Jump Street");
    cards.pBaseMedicalCard->FirstName = "Thomas";
    cards.pBaseMedicalCard->MiddleName = "Tom";
    cards.pBaseMedicalCard->LastName = "Hanson";
    cards.pBaseMedicalCard->Id = "R2D2TEC";
    cards.pBaseMedicalCard->SetPhoneNumber("81235551234");
    cards.pBaseMedicalCard->SetPost("-");
    cards.pBaseMedicalCard->Age = 28;
    (*container)[0] = cards;

    cout << "BaseMedicalCard PatientID " << (*container)[0].pBaseMedicalCard->GetPatientID() << endl;

    cout << "The first patient was from " << cards.pBaseMedicalCard->GetResidenceAddress() << "." << endl;
    cout << "His name was " << cards.pBaseMedicalCard->FirstName << " "
        << cards.pBaseMedicalCard->MiddleName << " "
        << cards.pBaseMedicalCard->LastName << "." << endl;
    cout << "He was " << cards.pBaseMedicalCard->Age << " years old." << endl;
    cout << "PatientID " << cards.pBaseMedicalCard->GetPatientID() << endl;
    cout << "-----------------------------------------" << endl << endl;

    cout << "Create new Silver patient." << endl << endl;
    // Create new card silver level
    Cards new_card;
    new_card.pSilverMedicalCard = new SilverMedicalCard();
    (*container)[1] = new_card;

    // Check that it's empty
    cout << "This is a empty silver medical card" << endl;
    cout << "New patient (silver level): age " << new_card.pSilverMedicalCard->Age
        << " \nfirst name: " << new_card.pSilverMedicalCard->FirstName
        << " \nmiddle name: " << new_card.pSilverMedicalCard->MiddleName
        << " \nlast name: " << new_card.pSilverMedicalCard->LastName
        << " \nid: " << new_card.pSilverMedicalCard->Id
        << " \nphone number: " << new_card.pSilverMedicalCard->GetPhoneNumber()
        << " \nDiscount: " << new_card.pSilverMedicalCard->GetDiscount() << endl;
    cout << "PatientID " << new_card.pSilverMedicalCard->GetPatientID() << endl;

     // Transfer information from base medical card to silver medical card
    new_card.pSilverMedicalCard->UpdateMedicalCard(cards.pBaseMedicalCard);

    // Check transfer result
    cout << "Update medical card to silver level." << endl;
    cout << "New patient (silver level): age " << new_card.pSilverMedicalCard->Age
        << " \nfirst name: " << new_card.pSilverMedicalCard->FirstName
        << " \nmiddle name: " << new_card.pSilverMedicalCard->MiddleName
        << " \nlast name: " << new_card.pSilverMedicalCard->LastName
        << " \nid: " << new_card.pSilverMedicalCard->Id
        << " \nphone number: " << new_card.pSilverMedicalCard->GetPhoneNumber()
        << " \nDiscount: " << new_card.pSilverMedicalCard->GetDiscount() << endl;
    cout << "PatientID " << new_card.pSilverMedicalCard->GetPatientID() << endl << endl;
    cout << "-----------------------------------------" << endl << endl;

    // Check if PatientID still the same in one struct. (it's not change after update
    // from Base to Silver clsaa
    cout << "BaseMedicalCard PatientID " << (*container)[1].pBaseMedicalCard->GetPatientID() << endl;
    cout << "SilverMedicalCard PatientID " << (*container)[1].pSilverMedicalCard->GetPatientID() << endl;
    cout << "SilverMedicalCard Discount " << (*container)[1].pSilverMedicalCard->GetDiscount() << endl;


    return 0;
}
