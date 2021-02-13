///////////////////////////////////////////////////////////////////////////
///// Fichier CPayOff.h : Declaration de la classe CPayOff  /////////////// 
///////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef CPayOff_h
#define CPayOff_h

///////////////////////////////////////////////////////////////////////////

class CPayOff
{
    protected :

    static const double M_2;

    public:
        // Constructor
        CPayOff() ;

        // Destructor
        virtual ~CPayOff() ;

        // Evaluate the payoff for a spot S value
        virtual double evaluation(double S) const = 0 ;
    
        // Black Scholes price close formula at pricing date
        virtual double price(double T, double r, double sigma, double S0) const = 0 ;

        // Black Scholes delta close formula at pricing date
        virtual double delta(double T, double r, double sigma, double S0) const = 0;

        // Black Scholes gamma close formula at pricing date
        virtual double gamma(double T, double r, double sigma, double S0) const = 0;

        // Black Scholes d1 function
        double d1(double T, double r, double sigma, double S0, double K) const ;

        // Black Scholes d2 function
        double d2(double T, double r, double sigma, double S0, double K) const ;
} ;

#endif
