#include "PrivateDoctorMedicalCard.h"

PrivateDoctorMedicalCard::PrivateDoctorMedicalCard()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << std::endl;
}

PrivateDoctorMedicalCard::~PrivateDoctorMedicalCard()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << std::endl;
}

void PrivateDoctorMedicalCard::UpdateMedicalCard(BaseMedicalCard *baseMedicalCard)
{
    // Transfer info from Base to Silver medical card
    std::cout << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    PrivateDoctorMedicalCard::Age = baseMedicalCard->Age;
    PrivateDoctorMedicalCard::FirstName = baseMedicalCard->FirstName;
    PrivateDoctorMedicalCard::MiddleName = baseMedicalCard->MiddleName;
    PrivateDoctorMedicalCard::LastName = baseMedicalCard->LastName;
    PrivateDoctorMedicalCard::Id = baseMedicalCard->Id;
    PrivateDoctorMedicalCard::SetPhoneNumber(baseMedicalCard->GetPhoneNumber());
    PrivateDoctorMedicalCard::SetResidenceAddress(baseMedicalCard->GetResidenceAddress());
    PrivateDoctorMedicalCard::SetPost(baseMedicalCard->GetPost());
    PrivateDoctorMedicalCard::UpdateToPrivateDoctorMedicalCardTransferMessage();
    baseMedicalCard->~BaseMedicalCard();
}

void PrivateDoctorMedicalCard::UpdateToPrivateDoctorMedicalCardTransferMessage()
{
    std::cout << "*** Base medical card was transfer to private doctor level." << std::endl;
    std::cout << "Now information is saved in private doctor level medical card." << std::endl;
    std::cout << "Base medical card was deleted ***" << std::endl;
    std::cout << std::endl;
}

void PrivateDoctorMedicalCard::SetPrivateDoctorId(std::string privateDoctorId)
{
    PrivateDoctorMedicalCard::privateDoctorId = privateDoctorId;
}

std::string PrivateDoctorMedicalCard::GetPrivateDoctorId()
{
    return PrivateDoctorMedicalCard::privateDoctorId;
}
