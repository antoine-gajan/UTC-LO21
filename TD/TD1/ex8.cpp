//Exercice pour apprendre les espaces de nom

#include <iostream>

namespace chine
{
   void bonjour()
   {
        std::cout<<"nichao\n";
   }
}

namespace anglais
{
    void bonjour()
    {
        std::cout<<"hello\n";
    }
}

int main()
{
    //En chinois
    chine::bonjour();
    //En anglais
    anglais::bonjour();
    return 0;
}

