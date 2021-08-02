#include <iostream>

using namespace std;

namespace NamespaceA {
	int sum(int a, int b) {
	    std::cout << "This is NamespaceA!" << std::endl;
		std::cout << "Ths sum of " << a << " and " << b << " is equal to " << a + b << std::endl;
		return a + b;
	};
}

namespace NamespaceB {
	int sum(int a, int b) {
	    std::cout << "This is NamespaceB!" << std::endl;
		std::cout << "Ths sum of " << a << " and " << b << " is equal to " << a + b << std::endl;
		return a + b;
	};
}


namespace NamespaceC {
	int sum(int a, int b) {
	    std::cout << "This is NamespaceC!" << std::endl;
		std::cout << "Ths sum of " << a << " and " << b << " is equal to " << a + b << std::endl;
		return a + b;
	};
}


namespace NamespaceD {
	int sum(int a, int b) {
	    std::cout << "This is NamespaceD!" << std::endl;
		std::cout << "Ths sum of " << a << " and " << b << " is equal to " << a + b << std::endl;
		return a + b;
	};
}

int main()
{
    cout << NamespaceA::sum(4, 5) << endl;
    cout << NamespaceB::sum(40, 50) << endl;
    cout << NamespaceC::sum(400, 500) << endl;
    cout << NamespaceD::sum(4000, 5000) << endl;
    return 0;
}
