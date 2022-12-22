#if !defined(LOG_H)
#define LOG_H
#include "timing.h"
#include<iostream>
#include "fonction.h"
#include <exception>

using namespace TIME;
using namespace std;

class Log {
public:
    virtual void addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string& s)=0;
    virtual void displayLog(std::ostream& f) const=0;
};
#endif

class MyLogException : public exception {
public:
    MyLogException(const std::string& i) : info(i){}
    const char* what() const noexcept
    {
        return info.c_str();
    }
private:
    string info;
};

namespace AC {
    class MyLog : public Log, private TIME::Agenda {
        void addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string& s)
        {
            Evt1jDur e(d, s, h, Duree(0));
            *this << e;
            //Agenda::operator<<(e)
            // this->operator<<(e)
        }
        void displayLog(std::ostream& f) const{
            for (auto& e: *this)
            {
                const Evt1jDur * pt = dynamic_cast<const Evt1jDur*>(&e);
                f << pt->getDate() << " - " << pt->getHoraire() << " " << e.getDescription() << endl;
            }
        }
    };
}

namespace AO{
    class MyLog : public Log {
    private:
        Agenda A; // objet qui est adapté
    public:
        void addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string& s)
        {
            Evt1jDur e(d, s, h, Duree(0));
            if (A.begin() != A.end())
            {
                auto it = A.end();
                --it;
                auto &dernier = *it;
                if (e < dernier) throw MyLogException("Erreur : ajout evt antérieur");
                A << e;
                //Agenda::operator<<(e)
                // this->operator<<(e)
            }
        }
        void displayLog(std::ostream& f) const{
            for (auto& e : A)
            {
                const Evt1jDur * pt = dynamic_cast<const Evt1jDur*>(&e);
                f << pt->getDate() << " - " << pt->getHoraire() << " " << e.getDescription() << endl;
            }
        }
    };
}

void essai_log(){
    AO::MyLog log;
    log.addEvt(Date(12, 01, 2023), Horaire(12, 23), "Rien");
    log.addEvt(Date(11, 01, 2023), Horaire(12, 23), "Rien");

}