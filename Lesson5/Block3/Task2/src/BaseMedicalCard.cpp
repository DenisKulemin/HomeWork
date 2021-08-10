#include "BaseMedicalCard.h"

BaseMedicalCard::BaseMedicalCard()
{
    std::cout << "Please, enter your data." << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << std::endl;
}

BaseMedicalCard::~BaseMedicalCard()
{
    std::cout << "Your data is deleted now!" << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << std::endl;
}

void BaseMedicalCard::SetResidenceAddress(std::string ResidenceAddress) {
    BaseMedicalCard::ResidenceAddress = ResidenceAddress;
}

void BaseMedicalCard::SetPhoneNumber(std::string PhoneNumber) {
    BaseMedicalCard::PhoneNumber = PhoneNumber;
}

void BaseMedicalCard::SetPost(std::string Post) {
    BaseMedicalCard::Post = Post;
}

std::string BaseMedicalCard::GetResidenceAddress() {
    return BaseMedicalCard::ResidenceAddress;
}

std::string BaseMedicalCard::GetPhoneNumber() {
    return BaseMedicalCard::PhoneNumber;
}

std::string BaseMedicalCard::GetPost() {
    return BaseMedicalCard::Post;
}
