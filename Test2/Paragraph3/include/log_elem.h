#ifndef LOG_ELEM_H
#define LOG_ELEM_H


class TLogElement
{
    private:
        TLogElement *FNextEl;
        int FNextIn;
        bool FIn1, FIn2;
    protected:
        bool FRes;
        virtual void calc() = 0;
        bool getIn2() { return FIn2; }
        void setIn2 ( bool newIn2 );
    public:
        TLogElement();
        bool getIn1() { return FIn1; }
        void setIn1 ( bool newIn1 );
        bool getRes() { return FRes; }
        void Link ( TLogElement *nextElement, int nextIn = 1 );
};

class TLog2In: public TLogElement
{
    public:
        TLogElement::setIn2;
        TLogElement::getIn2;
};

class TNot: public TLogElement
{
    protected:
        void calc();
};

class TAnd: public TLog2In
{
    protected:
        void calc();
};

class TOr: public TLog2In
{
    protected:
        void calc();
};

class TXor: public TLog2In
{
    protected:
        void calc();
};

class TAndNot: public TLog2In
{
    protected:
        void calc();
};

class TOrNot: public TLog2In
{
    protected:
        void calc();
};

class RSTrigger
{
    public:
        RSTrigger(TOrNot rElem, TOrNot sElem);
        void sSet();
        void sReset();
        TOrNot & getSElement();
        TOrNot & getRElement();
        void rSet();
        void rReset();
        bool getQDirectState();
        bool getQInventedState();

    private:
        TOrNot rElement;
        TOrNot sElement;
};

#endif // LOG_ELEM_H
