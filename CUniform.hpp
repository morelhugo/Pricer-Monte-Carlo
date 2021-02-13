////////////////////////////////////////////////////////////////////////
///// Fichier CUniform.h : Declaration de la classe CUniform  ////////// 
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef CUniform_h
#define CUniform_h

///////////////////////////////////////////////////////////////////////////

#include "CProbaLawWithMoment.hpp"

///////////////////////////////////////////////////////////////////////////

class CUniform : public CProbaLawWithMoment
{
	static const double Epsilon;

    private :
		double a ;
		double b ;
		int    seed ;

	public :
		// Constructor
		CUniform(double ai = 0, double bi = 1, int seedi = 1) ;

		// Destructor
		virtual ~CUniform() ;

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


