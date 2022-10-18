#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
/*
 Ajouter des instructions qui permettent de disposer sur cette fenêtre :
 Un objet de type QLabel alloué dynamiquement et dont l'adresse est stockée dans le pointeur noml de type
QLabel*. Cet objet sera initialisé respectivement avec la chaîne de caractères "Nom" et placé respectivement
à la position (10, 10).
 Un objet de type QLineEdit alloué dynamiquement et dont l'adresse est stockée dans le pointeur nom de
type QLineEdit*. Cet objet aura une largeur de 180 et sera positionné aux coordonnées (60, 10).
 Un objetde type QPushButton alloué dynamiquement dont l'adresse sera stockée dans le pointeur ok de
type QPushButton*. Le bouton sera initialisé avec le texte "ok", sa largeur sera 230 et il placé à la position
(10, 60).
Modifier le titre de la fenêtre avec la chaîne de caractères "Joueur".
 */

int exercice26_1(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget fenetre;
    fenetre.setWindowTitle("Joueur");
    fenetre.setFixedSize(250, 120);

    QLabel *noml = new QLabel(&fenetre);
    noml->setText("Nom");
    noml->move(10, 10);

    QLineEdit *nom = new QLineEdit(&fenetre);
    nom->setFixedWidth(180);
    nom->move(60, 10);


    QPushButton *ok = new QPushButton("ok", &fenetre);
    ok->setFixedWidth(230);
    ok->move(10, 60);
    //...
    fenetre.show();
    return app.exec();
}

/*
Recommencer la question 1, mais en utilisant des objets de types QVBoxLayout et QHBoxLayout alloués dynamiquement
pour positionner relativement les objets. Commentez l'instruction qui permet de fixer la taille du bouton
ok.
 */

int exercice26_2(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget fenetre;
    fenetre.setWindowTitle("Joueur");

    QVBoxLayout *layout = new QVBoxLayout(&fenetre);

    QHBoxLayout *ligne1 = new QHBoxLayout(&fenetre);

    QLabel *noml = new QLabel(&fenetre);
    noml->setText("Nom");
    noml->move(10, 10);

    QLineEdit *nom = new QLineEdit();
    nom->setFixedWidth(180);
    nom->move(60, 10);

    ligne1->addWidget(noml);
    ligne1->addWidget(nom);

    QHBoxLayout *ligne2 = new QHBoxLayout(&fenetre);

    QPushButton *ok = new QPushButton("ok", &fenetre);
    ok->setFixedWidth(230);
    ok->move(10, 60);

    ligne2->addWidget(ok);

    layout->addLayout(ligne1);
    layout->addLayout(ligne2);

    fenetre.show();
    return app.exec();
}
