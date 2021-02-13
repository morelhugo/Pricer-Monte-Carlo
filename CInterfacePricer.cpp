//////////////////////////////////////////////////////////////////////////////////////////////
///// Fichier CInterfacePricer.cpp : Definition de la classe CInterfacePricer  ///////// 
//////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include "CUniform.hpp"
#include "CNormal.hpp"
#include "CCall.hpp"
#include "CPut.hpp"
#include "CVanillaOptionBS.hpp"
#include "CDiscountFactor.hpp"
#include "CMonteCarloMethod.hpp"

///////////////////////////////////////////////////////////////////////////

#include "CInterfacePricer.hpp"

///////////////////////////////////////////////////////////////////////////

CInterfacePricer::CInterfacePricer()
{
    T           = 1.0;
    S0          = 100;
    r           = 0.0;
    sigma       = 0.20;
    K           = 100;
    NMC         = 10000;
    NbTimeDiscr = 365; 
    errorMC     = 0.0;
    priceMC     = 0.0;
    deltaMC     = 0.0;
    gammaMC     = 0.0;
    priceBS     = 0.0;
    deltaBS     = 0.0;
    gammaBS     = 0.0;
    PO          = NULL;
}

///////////////////////////////////////////////////////////////////////////

CInterfacePricer::~CInterfacePricer()
{
    if (PO)
    {
        delete PO;
        PO = NULL;
    }
}

///////////////////////////////////////////////////////////////////////////

bool CInterfacePricer::getPricingParameters()
{
    string typeOption = "";

    cout << endl;
    cout << " ----------- LET'S PRICING ! ----------------";
    cout << endl;
    cout << "Pricing Option - Call (C) or Put (P) : ";
    cin >> typeOption;

    if(typeOption == "C")
    { 
        PO = new CCall(K);
    }
    else if (typeOption == "P")
    {
        PO = new CPut(K);
    }
    else
    {
        return false;
    }

    cout << "Maturity T                           : ";
    cin >> T;

    cout << "Spot value S0                        : ";
    cin >> S0;

    cout << "Rate value r                         : ";
    cin >> r;

    cout << "Volatility value Sigma               : ";
    cin >> sigma;

    cout << "Strike value K                       : ";
    cin >> K;

    cout << "Number of Monte Carlo's simulation   : ";
    cin >> NMC;

    if ((T < 0) || (S0 <= 0) || (r < 0) || (sigma <= 0) || (K < 0) || (NMC <= 0))
    {
        return false;
    }

    return true;
}

///////////////////////////////////////////////////////////////////////////

bool CInterfacePricer::pricing()
{
    cout << endl;
    cout << "Pricing progress..." << endl;

    CVanillaOptionBS  VC                 = CVanillaOptionBS(PO, T, r, sigma, S0, NbTimeDiscr);
    CMonteCarloMethod MC                 = CMonteCarloMethod();
    CDiscountFactor   ZC                 = CDiscountFactor(r);
    double            EmpiricalMeanPrix  = 0.0;
    double            EmpiricalMeanDelta = 0.0;
    double            EmpiricalMeanGamma = 0.0;
    double            error              = 0.0;

    if (!MC.monteCarlo(VC, NMC, EmpiricalMeanPrix, error, EmpiricalMeanDelta, EmpiricalMeanGamma))
    {
        return false;
    }

    priceMC = ZC.eval(T) * EmpiricalMeanPrix;
    errorMC = (ZC.eval(T) * ZC.eval(T)) * error;

    deltaMC = ZC.eval(T) * EmpiricalMeanDelta ;
    gammaMC = ZC.eval(T) * EmpiricalMeanGamma ;

    priceBS = VC.price();
    deltaBS = VC.delta();
    gammaBS = VC.gamma();

    cout << "Pricing OK!" << endl;

    return true;
}

///////////////////////////////////////////////////////////////////////////

void CInterfacePricer::displayResult() const
{
    cout << endl;
    cout << "-------------RESULTS------------------";
    cout << endl;
    cout << "--------------------------------------";
    cout << endl;
    cout << "* Using Black Scholes closed formula :"<<endl;
    cout << "Price = " << priceBS << endl;
    cout << "Delta = " << deltaBS << endl;
    cout << "Gamma = " << gammaBS << endl;
    cout << "--------------------------------------";
    cout << endl;
    cout << "* Using Monte Carlo method's :" << endl;
    cout << "Price = " << priceMC << endl;
    cout << "Delta = " << deltaMC << endl;
    cout << "Gamma = " << gammaMC << endl;
    cout << "--------------------------------------";
    cout << endl;
}

///////////////////////////////////////////////////////////////////////////

