//////////////////////////////////////////////////////////////////////////////////////
///// Fichier CInterfacePricer.h : Declaration de la classe CInterfacePricer  ////////// 
//////////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef CInterfacePricer_h
#define CInterfacePricer_h

//////////////////////////////////////////////////////////////////////////////////////

#include "CPayOff.hpp"
#include "CDiscountFactor.hpp"

//////////////////////////////////////////////////////////////////////////////////////

class CInterfacePricer
{
    private:
        long             NMC ;
        long             NbTimeDiscr ;
        double           T ;
        double           S0 ;
        double           r ;
        double           sigma ;
        double           K ;
        CPayOff*         PO ;
        double           priceMC ;
        double           errorMC ;
        double           deltaMC ;
        double           gammaMC ;
        double           priceBS;
        double           deltaBS;
        double           gammaBS;


    public:
        // Constructor
        CInterfacePricer() ;

        // Destructor
        virtual ~CInterfacePricer() ;

        // Get pricing parameters 
        bool getPricingParameters() ;

        // Pricing
        bool pricing();

        // Dipslay result
        void displayResult() const ;
};  

#endif
