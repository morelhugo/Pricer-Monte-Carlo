// EnsaeProjectCpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

using namespace std;
#include <iostream>
#include <fstream>

#include "CInterfacePricer.hpp"

int main()
{
    bool             pricing  = true ;
    string           again    = "";

    while (pricing)
    {
        CInterfacePricer Pricer = CInterfacePricer();

        if (!Pricer.getPricingParameters())
        {
            std::cout << std::endl;
            std::cout << "Wrong Parameters ! " << std::endl;
            std::cout << "Please try again ! " << std::endl;
        }
        else
        {
            if (!Pricer.pricing())
            {
                std::cout << "Pricing failed" << std::endl;
                return 0;
            }

            Pricer.displayResult();

            std::cout << "Would you like continue ?(Y/N) :" << std::endl;
            std::cin >> again;

            if (again == "Y" || again == "y")
            {
                pricing = true;
            }
            else
            {
                pricing = false;
            }
        }
    }

    return 0 ;
}

