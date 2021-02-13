//////////////////////////////////////////////////////////////////////////////////////////////
///// Fichier CVanillaOptionBS.cpp : Definition de la classe CVanillaOptionBS  ///////// 
//////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <cstdlib>
#include <cmath>

///////////////////////////////////////////////////////////////////////////

#include "CVanillaOptionBS.hpp"

///////////////////////////////////////////////////////////////////////////

CVanillaOptionBS::CVanillaOptionBS(CPayOff* POi, double Ti, double ri, double sigmai, double S0i, long Ni) : GB(S0i, ri, sigmai, Ti = 1, Ni)
{
    PO    = POi ;
    T     = Ti ;
    r     = ri ;
    sigma = sigmai ;
    S0    = S0i ;
}

///////////////////////////////////////////////////////////////////////////

CVanillaOptionBS::CVanillaOptionBS(CPayOff* POi, double Ti, double ri, double sigmai, double S0i, double Dti) : GB(S0i, ri, sigmai, Ti = 1, Dti)
{
    PO    = POi;
    T     = Ti;
    r     = ri;
    sigma = sigmai;
    S0    = S0i;
}

///////////////////////////////////////////////////////////////////////////

CVanillaOptionBS::~CVanillaOptionBS()
{
}

///////////////////////////////////////////////////////////////////////////

double CVanillaOptionBS::simule() const
{
    double ST = GB.simule() ;

    if(PO)
    {
        return PO->evaluation(ST) ;
    }
    else
    { 
        return 0.0 ; 
    }
}

///////////////////////////////////////////////////////////////////////////

double CVanillaOptionBS::simuleDelta(double epsilon) const
{
    double ST    = GB.getSpotCurrent() ;
    double STup  = ST + epsilon;//ST * (1 + epsilon);
    double STdwn = ST - epsilon;//ST * (1 - epsilon);

    if (PO)
    {
        return (PO->evaluation(STup) - PO->evaluation(STdwn)) / (2 * epsilon) ;
    }
    else
    {
        return 0.0;
    }
}

///////////////////////////////////////////////////////////////////////////

double CVanillaOptionBS::simuleGamma(double epsilon) const
{
    double ST    = GB.getSpotCurrent();
    double STup  = ST + epsilon ;//ST * (1 + epsilon);
    double STdwn = ST - epsilon;//ST * (1 - epsilon);

    if (PO)
    {
        return (PO->evaluation(STup) + PO->evaluation(STdwn) - 2 * PO->evaluation(ST)) / (epsilon * epsilon) ;
    }
    else
    {
        return 0.0;
    }
}

///////////////////////////////////////////////////////////////////////////

double CVanillaOptionBS::price() const
{    
    if(PO)
    {
        return PO->price(T, r, sigma, S0) ;
    }
    else
    {
        return 0.0 ;
    }
}

///////////////////////////////////////////////////////////////////////////

double CVanillaOptionBS::delta() const
{
    if (PO)
    {
        return PO->delta(T, r, sigma, S0);
    }
    else
    {
        return 0.0;
    }
}

///////////////////////////////////////////////////////////////////////////

double CVanillaOptionBS::gamma() const
{
    if (PO)
    {
        return PO->gamma(T, r, sigma, S0);
    }
    else
    {
        return 0.0;
    }
}


///////////////////////////////////////////////////////////////////////////
