///////////////////////////////////////////////////////////////////////////////////////////////
///// Fichier CMonteCarloMethod.h : Declaration de la classe CMonteCarloMethod  /////////////// 
///////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef CMonteCarloMethod_h
#define CMonteCarloMethod_h

///////////////////////////////////////////////////////////////////////////

#include "CProbalaw.hpp"

///////////////////////////////////////////////////////////////////////////

class CMonteCarloMethod
{
    private :
        static const double quantile ;
        static const double delta_esp ;

    public :
        // Constructor
        CMonteCarloMethod() ;

        // Destructor
        virtual ~CMonteCarloMethod() ;

        // Empirical mean
        static double getEmpiricalMean(const CProbaLaw& P, long NMC) ;

        // Empirical variance 
        static double getEmpiricalVariance(const CProbaLaw& P, long NMC) ;

        // Error
        static double error(double variance, long NMC) ;

        // Get Monte Carlo method output
        static bool monteCarlo(const CProbaLaw& P, long NMC, double& empiricalMean, double& err, double& deltaEmpiricalMean, double& gammaEmpiricalMean) ;
} ;

#endif
