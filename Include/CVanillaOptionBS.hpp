////////////////////////////////////////////////////////////////////////////////////////
///// Fichier CVanillaOptionBS.h : Declaration de la classe CVanillaOptionBS  ////////// 
////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef CVanillaOptionBS_h
#define CVanillaOptionBS_h

///////////////////////////////////////////////////////////////////////////

#include "CProbaLaw.hpp"
#include "CPayOff.hpp"
#include "CGeometricBrownian.hpp"

///////////////////////////////////////////////////////////////////////////

class CVanillaOptionBS : public CProbaLaw
{
    private:
        double              T ;
        double              r ;
        double              sigma ;
        double              S0 ;
        CGeometricBrownian  GB ;
        CPayOff*            PO ;

    public:
        // Contructor
        CVanillaOptionBS(CPayOff* POi, double Ti = 1, double ri = 0, double sigmai = 0.2, double S0i = 100, long Ni = 100) ;

        // Contructor
        CVanillaOptionBS(CPayOff* POi, double Ti = 1, double ri = 0, double sigmai = 0.2, double S0i = 100, double Dti = 100);

        // Destructor
        virtual ~CVanillaOptionBS() ;

        // Simulation of a random variable 
        double simule() const ;

        // Simulation of a delta random variable 
        double simuleDelta(double epsilon = 0.01) const ;

        // Simulation of a gamma random variable 
        double simuleGamma(double epsilon = 0.01) const;

        // Black Scholes price close formula at pricing date
        double price() const ;

        // Black Scholes delta close formula at pricing date
        double delta() const ;

        // Black Scholes gamma close formula at pricing date
        double gamma() const ;

} ;

#endif

