#ifndef BASEMEDICALCARD_H
#define BASEMEDICALCARD_H
#include "MedicalCardInterface.h"


class BaseMedicalCard : MedicalCardInterface
{
    public:
        std::string FirstName;
        std::string MiddleName;
        std::string LastName;
        std::string Id;
        int Age;
        BaseMedicalCard();
        virtual void SetResidenceAddress(std::string) override;
        virtual void SetPhoneNumber(std::string);
        virtual void SetPost(std::string);
        virtual std::string GetResidenceAddress();
        virtual std::string GetPhoneNumber();
        virtual std::string GetPost();
        int GetPatientID() const;
        virtual ~BaseMedicalCard();

    protected:

    private:
        static int PatientID;
        std::string ResidenceAddress;
        std::string PhoneNumber;
        std::string Post;
};

#endif // BASEMEDICALCARD_H
