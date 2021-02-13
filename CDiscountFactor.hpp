//////////////////////////////////////////////////////////////////////////////////////
///// Fichier CDiscountFactor.h : Declaration de la classe CDiscountFactor  ////////// 
//////////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef CDiscountFactor_h
#define CDiscountFactor_h

class CDiscountFactor
{
    private :
        double r ;

    public:
        // Constructor
        CDiscountFactor(double ri) ; 

        // Destructor
        virtual ~CDiscountFactor() ;

        // Simulation of a random variable 
        double eval(double T) const ;
} ;

#endif

