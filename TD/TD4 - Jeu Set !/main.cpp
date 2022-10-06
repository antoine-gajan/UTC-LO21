#include "set.h"
using namespace Set;

int main() {
	try {

		printCouleurs();
		printNombres();
		printFormes();
		printRemplissages();
	}
	catch (SetException& e) {
		std::cout << e.getInfo() << "\n";
	}
	
	system("pause");
	return 0;
}