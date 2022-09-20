#ifndef TD2_EX18_H
#define TD2_EX18_H

struct personne {
    string nom;
    unsigned int age;
};

void initialiser(personne& p);
void affiche_struct(const personne &p);
void affiche_tab(personne * tab, int taille);
void init_struct(personne &p, char *nom, int age);
void copy_struct(personne &p1, personne &p2);
void copy_tab(personne *tabdes, personne *tabsource, size_t n)


#endif //TD2_EX18_H
