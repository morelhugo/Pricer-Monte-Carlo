///////////////////////////////////////////////////////////////////////////
///// Fichier MonteCarloMethod.cpp : Definition de la classe MonteCarloMethod  ///////// 
///////////////////////////////////////////////////////////////////////////

#include "CMonteCarloMethod.hpp"

///////////////////////////////////////////////////////////////////////////

#include "CProbalawWithMoment.hpp"
#include "CUniform.hpp"
#include "CNormal.hpp"
#include <cmath>

///////////////////////////////////////////////////////////////////////////

const double CMonteCarloMethod::quantile  = 1.96 ;
const double CMonteCarloMethod::delta_esp = 0.01;

///////////////////////////////////////////////////////////////////////////

CMonteCarloMethod::CMonteCarloMethod()
{
}

///////////////////////////////////////////////////////////////////////////

CMonteCarloMethod::~CMonteCarloMethod()
{
}

///////////////////////////////////////////////////////////////////////////

double CMonteCarloMethod::getEmpiricalMean(const CProbaLaw& P, long NMC)
{
	double sum = 0 ;
	long   i   = 0 ;

	for(i = 0; i < NMC; i++)
	{
		sum += P.simule() ;
	}

	return sum / NMC ;
}

///////////////////////////////////////////////////////////////////////////

double CMonteCarloMethod::getEmpiricalVariance(const CProbaLaw& P, long NMC)
{
	double sum  = 0 ;
	double sum2 = 0 ;
	long   i    = 0 ;
	double Xi   = 0 ;

	for (i = 0; i < NMC; i++)
	{
		Xi    = P.simule() ; 
		sum  += Xi ;
		sum2 += Xi * Xi ;
	}

	return (NMC / (NMC - 1)) * (sum2 / NMC - (sum / NMC) * (sum / NMC)) ;
}

///////////////////////////////////////////////////////////////////////////

double CMonteCarloMethod::error(double variance, long NMC)
{
	return  quantile * sqrt(variance / NMC) ;
}

///////////////////////////////////////////////////////////////////////////

bool CMonteCarloMethod::monteCarlo(const CProbaLaw& P, long NMC, double& empiricalMean, double& err, double& deltaEmpiricalMean, double& gammaEmpiricalMean)
{
	if (NMC <= 0)
	{
		return false ;
	}

	double sum      = 0 ;
	double sum2     = 0 ;
	long   i        = 0 ;
	double Xi       = 0 ;
	double variance = 0 ;
	double XDeltai  = 0 ;
	double XGammai  = 0 ;
	double sumDelta = 0 ;
	double sumGamma = 0;

	for (i = 0; i < NMC; i++)
	{
		Xi       = P.simule() ;
		XDeltai += P.simuleDelta();
		XGammai += P.simuleGamma();
		sum     += Xi ;
		sum2    += Xi * Xi ;
	}

	empiricalMean      = sum / NMC ;
	deltaEmpiricalMean = XDeltai / NMC;
	gammaEmpiricalMean = XGammai / NMC;
	variance           = (NMC / (NMC - 1)) * (sum2 / NMC - (sum / NMC) * (sum / NMC)) ;
	err                = error(variance, NMC) ;

	return true ;
}

///////////////////////////////////////////////////////////////////////////
