#if !defined(_EVENEMENT_H)
#define _EVENEMENT_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "timing.h"


namespace TIME{
    class Evt {
    private:
        std::string sujet;
    public:
        Evt(const std::string& sujet) : sujet(sujet){};
        virtual ~Evt() = default;
        virtual void afficher(std::ostream& f= std::cout) const = 0;
        const std::string& getDescription() const { return sujet; }
    };

    class Evt1j : public Evt{
        private:
            Date date;
        public:
            Evt1j(const Date& d, const std::string& s):date(d),Evt(s){
                std::cout << "construction d'un objet de la classe Evt1j" << std::endl;
            }

            virtual ~Evt1j(){
                std::cout << "destruction d'un objet de la classe Evt1j" << std::endl;
            }

            const Date& getDate() const { return date; }
            virtual void afficher(std::ostream& f= std::cout) const {
                f<<"******* Evt *******"<<"\n"<<"Date="<<date<<" sujet="<<getDescription()<<"\n";
            }
    };

    class EvtPj : public Evt {
    private:
        Date debut;
        Date fin;
    public:
        EvtPj(const std::string& sujet, Date debut, Date fin) : debut(debut), fin(fin), Evt(sujet){};
        virtual ~EvtPj() = default;
    };

    class Evt1jDur : public Evt1j{
    private:
        Horaire horaire;
        Duree duree;
    public:
        Evt1jDur(const Date& d, const std::string& s, const Horaire& h, const Duree& du): Evt1j(d, s), horaire(h), duree(du){
            std::cout << "construction d'un objet de la classe Evt1jDur" << std::endl;
        }

        virtual ~Evt1jDur(){
            std::cout << "destruction d'un objet de la classe Evt1jDur" << std::endl;
        }

        const Horaire& getHoraire() const { return horaire; }
        const Duree& getDuree() const { return duree; }
        virtual void afficher(std::ostream& f= std::cout) const {
            Evt1j::afficher(f);
            f << "Horaire="<<horaire<<" duree="<<duree<<"\n";
        }
    };

    class Rdv : public Evt1jDur{
    private:
        std::string lieu;
        std::string personnes;
    public:
        Rdv(const Date& d, const std::string& s, const Horaire& h, const Duree& du, const std::string& l, const std::string& p): Evt1jDur(d, s, h, du), lieu(l), personnes(p){
            std::cout << "construction d'un objet de la classe Rdv" << std::endl;
        }

        Rdv(const Rdv& r) : Evt1jDur(r.getDate(), r.getDescription(), r.getHoraire(), r.getDuree()), lieu(r.getLieu()), personnes(r.getpersonnes()){
            std::cout << "Recopie d'un objet de la classe Rdv" << std::endl;
        }

        virtual ~Rdv(){
            std::cout << "destruction d'un objet de la classe Rdv" << std::endl;
        }
        const std::string& getLieu() const { return lieu; }
        const std::string& getpersonnes() const { return personnes; }
        virtual void afficher(std::ostream& f= std::cout) const {
            Evt1jDur::afficher(f);
            f << "Lieu="<<lieu<<" Personnes="<<personnes<<"\n";
        }
    };
    class Agenda {
        std::vector<Evt*> tab;

    public:

        Agenda() =default;
        virtual ~Agenda();

        Agenda(const Agenda&) = delete;
        Agenda& operator=(const Agenda&) =delete;

        Agenda& operator<<(Evt &e);

        void afficher(std::ostream& f = std::cout) const;


        class iterator : public std::vector<Evt*>::iterator
        {
        public:
            Evt & operator*() const
            {
                return *std::vector<Evt*>::iterator::operator *();
            }
        private:
            friend class Agenda;
            iterator(const std::vector<Evt*>::iterator& it) : std::vector<Evt*>::iterator(it) {}

        };
        iterator begin() { return iterator(tab.begin()); }
        iterator end() { return iterator(tab.end()); }

        class const_iterator : public std::vector<Evt*>::const_iterator {
        public:
            const Evt& operator *() const
            {
                return *std::vector<Evt*>::const_iterator::operator *();
            }
        private:
            friend class Agenda;
            const_iterator(const std::vector<Evt*>::const_iterator& it) : std::vector<Evt*>::const_iterator(it) {}
        };
        const_iterator cbegin() const { return const_iterator(tab.begin()); }
        const_iterator cend() const { return const_iterator(tab.end()); }
        const_iterator begin() const { return const_iterator(tab.begin()); }
        const_iterator end() const { return const_iterator(tab.end()); }

    };
}

std::ostream& operator<<(std::ostream& f, const TIME::Evt1j& e);

#endif