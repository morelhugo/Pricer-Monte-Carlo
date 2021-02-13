///////////////////////////////////////////////////////////////////////////
///// Fichier CProbawLaw.h : Declaration de la classe CProbaLaw  ////////// 
///////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef CProbaLaw_h
#define CProbaLaw_h

class CProbaLaw
{
    public :
        // Constructor
        CProbaLaw() ;

        // Destructor
        virtual ~CProbaLaw();

        // Simulation of a random variable 
        virtual double simule() const = 0 ;

        // Simulation of a delta random variable 
        virtual double simuleDelta(double epsilon = 0.01) const;

        // Simulation of a gamma random variable 
        virtual double simuleGamma(double epsilon = 0.01) const;
} ;

#endif

