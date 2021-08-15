#ifndef PRIVATEDOCTORMEDICALCARD_H
#define PRIVATEDOCTORMEDICALCARD_H
#include "BaseMedicalCard.h"

class PrivateDoctorMedicalCard: public virtual BaseMedicalCard
{
    public:
        PrivateDoctorMedicalCard();
        virtual void UpdateMedicalCard(BaseMedicalCard *);
        void UpdateToPrivateDoctorMedicalCardTransferMessage();
        virtual void SetPrivateDoctorId(std::string);
        virtual std::string GetPrivateDoctorId();
        virtual ~PrivateDoctorMedicalCard();

    protected:

    private:
        std::string privateDoctorId;
};

#endif // PRIVATEDOCTORMEDICALCARD_H
