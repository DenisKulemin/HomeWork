#include "log_elem.h"

TLogElement::TLogElement() { FNextEl = nullptr; }

void TLogElement::setIn1 ( bool newIn1 )
{
    FIn1 = newIn1;
    calc();
    if ( FNextEl )

        switch ( FNextIn ) {
            case 1: FNextEl->setIn1 ( getRes() ); break;
            case 2: FNextEl->setIn2 ( getRes() ); break;
        }
}

void TLogElement::setIn2 ( bool newIn2 ) {
    FIn2 = newIn2;
    calc();
    if ( FNextEl )
        switch ( FNextIn ) {
            case 1: FNextEl->setIn1 ( getRes() ); break;
            case 2: FNextEl->setIn2 ( getRes() ); break;
        }
}

void TNot::calc() { FRes = ! getIn1(); }

void TAnd::calc() { FRes=getIn1() && getIn2(); }

void TOr::calc() { FRes=getIn1() || getIn2(); }

void TXor::calc() { FRes=(getIn1() || getIn2()) && ! (getIn1() && getIn2()); }

void TAndNot::calc() { FRes= !(getIn1() && getIn2()); }

void TOrNot::calc() { FRes= !(getIn1() || getIn2()); }

void TLogElement::Link( TLogElement *nextElement, int nextIn )
{
    FNextEl = nextElement;
    FNextIn = nextIn;
}

RSTrigger::RSTrigger(TOrNot rElem, TOrNot sElem)
{
    rElement = rElem;
    rElement.setIn1(false);
    rElement.setIn2(false);
    sElement = sElem;
    sElement.setIn1(false);
    sElement.setIn2(false);
}

void RSTrigger::sSet()
{
    rElement.Link( &sElement, 2);
    sElement.setIn1(true);
    rElement.Link( nullptr, 0);
}

void RSTrigger::sReset()
{
    rElement.Link( &sElement, 2);
    sElement.setIn1(false);
    rElement.Link( nullptr, 0);
}

TOrNot & RSTrigger::getSElement()
{
    return sElement;
}

TOrNot & RSTrigger::getRElement()
{
    return rElement;
}

void RSTrigger::rSet()
{
    sElement.Link( &rElement, 2);
    rElement.setIn1(true);
    sElement.Link( nullptr, 0);
}

void RSTrigger::rReset()
{
    sElement.Link( &rElement, 2);
    rElement.setIn1(false);
    sElement.Link( nullptr, 0);
}

bool RSTrigger::getQDirectState()
{
    return rElement.getRes();
}

bool RSTrigger::getQInventedState()
{
    return sElement.getRes();
}
