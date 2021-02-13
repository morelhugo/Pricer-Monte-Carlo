///////////////////////////////////////////////////////////////////////////
///// Fichier CCall.h : Declaration de la classe CCall  /////////////// 
///////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef CCall_h
#define CCall_h

///////////////////////////////////////////////////////////////////////////

#include "CPayOff.hpp"

///////////////////////////////////////////////////////////////////////////

class CCall : public CPayOff
{
    private :
        double K ;

    public:
        // Constructor
        CCall(double Ki);

        // Destructor
        virtual ~CCall();

        // Evaluate the payoff for a spot S value
        double evaluation(double S) const ;

        // Black Scholes price close formula at pricing date
        double price(double T, double r, double sigma, double S0) const ;

        // Black Scholes delta close formula at pricing date
        double delta(double T, double r, double sigma, double S0) const ;

        // Black Scholes gamma close formula at pricing date
        double gamma(double T, double r, double sigma, double S0) const ;
};

#endif
