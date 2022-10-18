#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
/*
Question 1
Après avoir inclu le chier d'entête <QPushButton>, créer un objet QPushButton, juste avant l'exécution de
la méthode app.exec(), en utilisant le constructeur qui permet de l'initialiser avec le texte Quitter (voir la
documentation de QpushButton sur https://doc.qt.io/qt-5/qpushbutton.html). Envoyer le message
show() à cet objet. Compiler et exécuter le programme.
Question 2
À quoi sert la méthode show() ? Quelle est la nature de la méthode show() ? Dans quelle classe cette méthode
est-elle dénie ?
Question 3
Pour l'instant, cliquer sur le bouton n'a aucun eet visible. Faire en sorte que l'application s'arrête lorsque l'on
clique sur ce bouton.
Vous pouvez consulter les ressources suivantes pour quelques rappels sur les signaux et les slots :
https://zestedesavoir.com/articles/56/les-signaux-et-slots-dans-qt-5-4/,
https://doc.qt.io/qt-5/signalsandslots.html, ou https://qt.developpez.com/doc/4.7/signalsandslots/.
Question 4
Que se passe t-il si on ajoute un deuxième bouton initialisé avec le texte "coucou, ceci est un nouveau bouton à
déplacer" et qu'on lui applique la méthode show() ?
*/

int exercice25(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget fenetre;
    fenetre.setFixedSize(250, 120);
    //...
    fenetre.show();
    return app.exec();
}
