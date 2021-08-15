#include "SilverMedicalCard.h"

SilverMedicalCard::SilverMedicalCard()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << std::endl;
}

SilverMedicalCard::~SilverMedicalCard()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << std::endl;
}

void SilverMedicalCard::UpdateMedicalCard(BaseMedicalCard *baseMedicalCard)
{
    // Transfer info from Base to Silver medical card
    std::cout << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    SilverMedicalCard::Age = baseMedicalCard->Age;
    SilverMedicalCard::FirstName = baseMedicalCard->FirstName;
    SilverMedicalCard::MiddleName = baseMedicalCard->MiddleName;
    SilverMedicalCard::LastName = baseMedicalCard->LastName;
    SilverMedicalCard::Id = baseMedicalCard->Id;
    SilverMedicalCard::SetPhoneNumber(baseMedicalCard->GetPhoneNumber());
    SilverMedicalCard::SetResidenceAddress(baseMedicalCard->GetResidenceAddress());
    SilverMedicalCard::SetPost(baseMedicalCard->GetPost());
    SilverMedicalCard::UpdateToSilverTransferMessage();
    baseMedicalCard->~BaseMedicalCard();
}

void SilverMedicalCard::UpdateToSilverTransferMessage()
{
    std::cout << "*** Base medical card was transfer to silver level." << std::endl;
    std::cout << "Now information is saved in silver level medical card." << std::endl;
    std::cout << "Base medical card was deleted ***" << std::endl;
    std::cout << std::endl;
}

void SilverMedicalCard::SetDiscount(double discount)
{
    SilverMedicalCard::discount = discount;
}

double SilverMedicalCard::GetDiscount()
{
    return SilverMedicalCard::discount;
}

std::ostream& operator << (std::ostream &s, const SilverMedicalCard &silverMedicalCard)
{
    s << "!!!! Preaty output for parameters: " << silverMedicalCard.discount << std::endl;
    return s;
}
