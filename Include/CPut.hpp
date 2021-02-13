///////////////////////////////////////////////////////////////////////////
///// Fichier CPut.h : Declaration de la classe CPut  /////////////// 
///////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef CPut_h
#define CPut_h

///////////////////////////////////////////////////////////////////////////

#include "CPayOff.hpp"

///////////////////////////////////////////////////////////////////////////

class CPut : public CPayOff
{
private:
    double K;

public:
    // Constructor
    CPut(double Ki);

    // Destructor
    virtual ~CPut();

    // Evaluate the payoff for a spot S value
    double evaluation(double S) const;

    // Black Scholes price close formula at pricing date
    double price(double T, double r, double sigma, double S0) const;

    // Black Scholes delta close formula at pricing date
    double delta(double T, double r, double sigma, double S0) const;

    // Black Scholes gamma close formula at pricing date
    double gamma(double T, double r, double sigma, double S0) const;
};

#endif
