#ifndef BASEMEDICALCARD_H
#define BASEMEDICALCARD_H
#include <string>
#include <iostream>

class BaseMedicalCard
{
    public:
        std::string FirstName;
        std::string MiddleName;
        std::string LastName;
        std::string Id;
        int Age;
        BaseMedicalCard();
        virtual void SetResidenceAddress(std::string);
        virtual void SetPhoneNumber(std::string);
        virtual void SetPost(std::string);
        virtual std::string GetResidenceAddress();
        virtual std::string GetPhoneNumber();
        virtual std::string GetPost();
        virtual ~BaseMedicalCard();

    protected:

    private:
        std::string ResidenceAddress;
        std::string PhoneNumber;
        std::string Post;
};

#endif // BASEMEDICALCARD_H
