#ifndef MEDICALCARDINTERFACE_H
#define MEDICALCARDINTERFACE_H
#include <string>
#include <iostream>

class MedicalCardInterface
{
    public:
        virtual void SetResidenceAddress(std::string) = 0;
        virtual void SetPhoneNumber(std::string) = 0;
        virtual void SetPost(std::string) = 0;
        virtual std::string GetResidenceAddress() = 0;
        virtual std::string GetPhoneNumber() = 0;
        virtual std::string GetPost() = 0;

    protected:

    private:
};

#endif // MEDICALCARDINTERFACE_H
