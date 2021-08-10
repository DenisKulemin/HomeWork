#ifndef MEDICALCARD_H
#define MEDICALCARD_H
#include <string>

class MedicalCard
{
    public:
        std::string FirstName;
        std::string MiddleName;
        std::string LastName;
        std::string Id;
        int Age;
        MedicalCard();
        void SetResidenceAddress(std::string);
        void SetPhoneNumber(std::string);
        void SetPost(std::string);
        std::string GetResidenceAddress();
        std::string GetPhoneNumber();
        std::string GetPost();
        ~MedicalCard();

    protected:

    private:
        std::string ResidenceAddress;
        std::string PhoneNumber;
        std::string Post;
};

#endif // MEDICALCARD_H
