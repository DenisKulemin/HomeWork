#include "GoldMedicalCard.h"

GoldMedicalCard::GoldMedicalCard()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << std::endl;
}

GoldMedicalCard::~GoldMedicalCard()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << std::endl;
}

void GoldMedicalCard::UpdateMedicalCard(BaseMedicalCard *baseMedicalCard)
{
    // Create new parent (n - 1 level) class object and call its upfate function
    SilverMedicalCard *tempMedicalCard = new SilverMedicalCard();
    tempMedicalCard->UpdateMedicalCard(baseMedicalCard);

    // After several iteration (till the function parameter class (BaseMedicalCard in our case))
    // tempMedicalCard will be ready for the last update
    GoldMedicalCard::UpdateMedicalCard(tempMedicalCard);

}

void GoldMedicalCard::UpdateMedicalCard(SilverMedicalCard *silverMedicalCard)
{
    std::cout << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    // Transfer data
    GoldMedicalCard::Age = silverMedicalCard->Age;
    GoldMedicalCard::FirstName = silverMedicalCard->FirstName;
    GoldMedicalCard::MiddleName = silverMedicalCard->MiddleName;
    GoldMedicalCard::LastName = silverMedicalCard->LastName;
    GoldMedicalCard::Id = silverMedicalCard->Id;
    GoldMedicalCard::SetPhoneNumber(silverMedicalCard->GetPhoneNumber());
    GoldMedicalCard::SetResidenceAddress(silverMedicalCard->GetResidenceAddress());
    GoldMedicalCard::SetPost(silverMedicalCard->GetPost());

    GoldMedicalCard::UpdateToGoldTransferMessage();
    silverMedicalCard->~SilverMedicalCard();
}

void GoldMedicalCard::UpdateToGoldTransferMessage()
{
    std::cout << "*** Silver medical card was transfer to gold level." << std::endl;
    std::cout << "Now information is saved in gold level medical card." << std::endl;
    std::cout << "Silver medical card was deleted ***" << std::endl;
    std::cout << std::endl;
}

void GoldMedicalCard::SetPrivateDoctorId(std::string privateDoctorId)
{
    GoldMedicalCard::privateDoctorId = privateDoctorId;
}

std::string GoldMedicalCard::GetPrivateDoctorId()
{
    return GoldMedicalCard::privateDoctorId;
}


void GoldMedicalCard::SetDiscount(double discount)
{
    GoldMedicalCard::discount = discount;
}

double GoldMedicalCard::GetDiscount()
{
    return GoldMedicalCard::discount;
}
