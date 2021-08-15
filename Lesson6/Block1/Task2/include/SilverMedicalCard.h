#ifndef SILVERMEDICALCARD_H
#define SILVERMEDICALCARD_H
#include "BaseMedicalCard.h"


class SilverMedicalCard: public virtual BaseMedicalCard
{
    public:
        SilverMedicalCard();
        virtual void UpdateMedicalCard(BaseMedicalCard *);
        void UpdateToSilverTransferMessage();
        virtual void SetDiscount(double);
        virtual double GetDiscount();
        virtual ~SilverMedicalCard();

    protected:

    private:
        double discount = 0.1;
};

#endif // SILVERMEDICALCARD_H
