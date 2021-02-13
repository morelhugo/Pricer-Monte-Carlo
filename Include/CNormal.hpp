////////////////////////////////////////////////////////////////////////
///// Fichier CNormal.h : Declaration de la classe CNormal  ////////// 
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef CNormal_h
#define CNormal_h

///////////////////////////////////////////////////////////////////////////

#include "CProbaLawWithMoment.hpp"
#include "CUniform.hpp"

///////////////////////////////////////////////////////////////////////////

class CNormal : public CProbaLawWithMoment
{
    static const double M_2 ;

    private :
        CUniform U ;
        double   mean_normal ;
        double   variance_normal ;

    public :

        // Constructor
        CNormal(double meani = 0, double variancei = 1) ;
        
        // Destructor
        virtual ~CNormal() ;

        // Simulation of a random variable
        double simule() const ;

        // Mean
        double mean() const ;
        
        // Variance
        double variance() const ;

        // Distribution function 
        double distribution_fonction(double x) const ; 
} ;

#endif

