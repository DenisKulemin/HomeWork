#include <iostream>
#include <log_elem.h>

using namespace std;

int main()
{
    TOrNot orNot1;
    TOrNot orNot2;
    RSTrigger trigger(orNot1, orNot2);
    cout << "R and S - inputs in logic elements. Q(d) and Q(i) - direct output and inverted output." << endl;
    cout << " S R Q(d) Q(i)" << endl;
    cout << "--------------- " << endl;
    // In1 of TOrNot element is used for controlling, In2 - for transfering the information to another element.
    // So, for creation a truth table, we use as R ans S - In1 values
    cout << " " << trigger.getSElement().getIn1() << " " << trigger.getRElement().getIn1() << "  " << trigger.getQDirectState() <<
        "    " << trigger.getQInventedState() << endl;

    trigger.sSet();
    cout << " " << trigger.getSElement().getIn1() << " " << trigger.getRElement().getIn1() << "  " << trigger.getQDirectState() <<
        "    " << trigger.getQInventedState() << endl;
    trigger.sReset();

    trigger.rSet();
    cout << " " << trigger.getSElement().getIn1() << " " << trigger.getRElement().getIn1() << "  " << trigger.getQDirectState() <<
        "    " << trigger.getQInventedState() << endl;
    trigger.rReset();

    trigger.sSet();
    trigger.rSet();
    cout << " " << trigger.getSElement().getIn1() << " " << trigger.getRElement().getIn1() << "  " << trigger.getQDirectState() <<
        "    " << trigger.getQInventedState() << endl;
    trigger.sReset();
    trigger.rReset();

    cin.get();
    return 0;
}
