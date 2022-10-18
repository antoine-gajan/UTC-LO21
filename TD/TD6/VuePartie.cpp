#include "VuePartie.h"
#include <QLabel>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QGridLayout>
#include <QProgressBar>
#include <QMessageBox>
#include "vuecarte.h"
#include "set.h"

VuePartie::VuePartie(QWidget *parent):  vuecartes(20, nullptr)
{
    controleur.distribuer();
    score = new QLabel(parent);
    score->setFixedHeight(30);
    score->setText("0");
    scoreJoueur = new QLCDNumber(parent);
    scoreJoueur->setFixedHeight(30);
    couche = new QVBoxLayout();
    layoutCartes = new QGridLayout(parent);
    layoutInformations = new QHBoxLayout();
    nbCartesPioche = new QProgressBar(parent);
    nbCartesPioche->setFixedHeight(30);
    nbCartesPioche->setRange(0, Set::Jeu::getInstance().getNbCartes());
    nbCartesPioche->setValue(controleur.getPioche().getNbCartes());
    nbCartesPioche->setTextVisible(false);
    pioche = new QLabel("Pioche");

    for (int i = 0 ; i<20; i++) vuecartes[i] = new VueCarte;
    for (int i = 0 ; i<20; i++)
    {
        layoutCartes->addWidget(vuecartes[i], i/4,i%4);
        //QObject::connect()
    }


    int pos = 0;
    for (auto i = controleur.getPlateau().begin(); i != controleur.getPlateau().end(); ++i)
    {
        vuecartes[pos]->setCarte(*i);
        pos++;
   }


    layoutInformations->addWidget(pioche);
    layoutInformations->addWidget(nbCartesPioche);
    layoutInformations->addWidget(score);
    layoutInformations->addWidget(scoreJoueur);
    couche->addLayout(layoutInformations);
    couche->addLayout(layoutCartes);
    setLayout(couche);
}

void VuePartie::carteClique(VueCarte* vc)
{
    if (!vc->cartePresente()){
            if (controleur.getPioche().getNbCartes()==0){
                QMessageBox message(QMessageBox::Icon::Warning, "Attention","La pioche est vide !");
                message.exec();
            }
            controleur.distribuer(); // ajout d’une carte
            // mise à jour des affectations des cartes aux vues des cartes
            size_t i=0;
            for(auto it=controleur.getPlateau().begin(); it!=controleur.getPlateau().
            end();++it){
                vuecartes[i]->setCarte(*it);
                i++;
            }
            nbCartesPioche->setValue(controleur.getPioche().getNbCartes());
        }
        else{
            if (vc->isChecked()){ // une nouvelle carte est sélectionnée
                selectionCartes.insert(&vc->getCarte()); // on l’insère dans l’ensemble des cartes sélectionnées
                if (selectionCartes.size()==3){ // c’est une combinaison qui peut être un set
                    // on crée et on teste la combinaison
                    vector<const Set::Carte*> c(selectionCartes.begin(),selectionCartes.end());
                    Set::Combinaison comb(*c[0],*c[1],*c[2]);
                    if (comb.estUnSET()) { // c’est un set => il faut mettre à jour le plateau
                        // retirer les cartes du plateau
                        controleur.getPlateau().retirer(*c[0]);

                        controleur.getPlateau().retirer(*c[1]);
                        controleur.getPlateau().retirer(*c[2]);
                        selectionCartes.clear(); // il n’y a plus de cartes sélectionnées
                        // s’il n’y a pas au moins 12 cartes, il faut en remettre
                        while (controleur.getPlateau().getNbCartes()<12 && controleur.getPioche().getNbCartes()==0) controleur.
                                          distribuer();
                        // mise à jour du score
                        scoreValue++;
                        scoreJoueur->display(scoreValue);
                        // mise à jour de la vue du plateau
                        // => nettoyage et mise à jour des vues des cartes
                        for(size_t i=0; i<vuecartes.size();i++)
                            vuecartes[i]->setNoCarte();
                        size_t i=0;
                        for(auto it=controleur.getPlateau().begin(); it!=controleur.
                    getPlateau().end();++it){
                            vuecartes[i]->setCarte(*it);
                            i++;
                        }
                        // mise à jour de la vue de la pioche
                        nbCartesPioche->setValue(controleur.getPioche().getNbCartes());
                    }else {
                        QMessageBox message(QMessageBox::Icon::Warning, "Attention","Ce n’est pas un set !");
                        message.exec();
                        // déselection des cartes
                        for(size_t i=0; i<vuecartes.size();i++) vuecartes[i]->
                                    setChecked(false);
                        selectionCartes.clear(); // l’ensemble des cartes sélectionnées est vide
                    }
                }
            }else {
                // la carte cliquée est déselectionnée
                selectionCartes.erase(&vc->getCarte());
            }
        }
        update(); // mise à jour de la vue
}
