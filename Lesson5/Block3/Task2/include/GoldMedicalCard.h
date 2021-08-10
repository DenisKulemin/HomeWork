#ifndef GOLDMEDICALCARD_H
#define GOLDMEDICALCARD_H
#include "SilverMedicalCard.h"


class GoldMedicalCard: public SilverMedicalCard
{
    public:
        GoldMedicalCard();

        // Need to create a set of function for update for each parent class
        virtual void UpdateMedicalCard(BaseMedicalCard *);
        virtual void UpdateMedicalCard(SilverMedicalCard *);

        virtual void SetDiscount(double) override;
        virtual double GetDiscount() override;
        virtual void SetPrivateDoctorId(std::string);
        void UpdateToGoldTransferMessage();
        virtual std::string GetPrivateDoctorId();
        virtual ~GoldMedicalCard();

    protected:

    private:
        std::string privateDoctorId;
        double discount = 0.15;
};

#endif // GOLDMEDICALCARD_H
