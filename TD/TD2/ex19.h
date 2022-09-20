#ifndef TD2_EX19_H
#define TD2_EX19_H

#include <string>

struct compte {
    std::string id;
    int solde;
};

int& operation(compte * tab, std::string id);
void essai_comptes();
#endif //TD2_EX19_H
