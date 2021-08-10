#include <iostream>
#include "MedicalCard.h"

MedicalCard::MedicalCard()
{
    std::cout << "Please, enter your data." << std::endl;
}

MedicalCard::~MedicalCard()
{
    std::cout << "Your data is deleted now!" << std::endl;
}

void MedicalCard::SetResidenceAddress(std::string ResidenceAddress) {
    MedicalCard::ResidenceAddress = ResidenceAddress;
}

void MedicalCard::SetPhoneNumber(std::string PhoneNumber) {
    MedicalCard::PhoneNumber = PhoneNumber;
}

void MedicalCard::SetPost(std::string Post) {
    MedicalCard::Post = Post;
}

std::string MedicalCard::GetResidenceAddress() {
    return MedicalCard::ResidenceAddress;
}

std::string MedicalCard::GetPhoneNumber() {
    return MedicalCard::PhoneNumber;
}

std::string MedicalCard::GetPost() {
    return MedicalCard::Post;
}
