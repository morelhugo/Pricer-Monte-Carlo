/////////////////////////////////////////////////////////////////////////////////////////////// 
///// Fichier CProbawLawWithMoment.h : Declaration de la classe CProbaLawWithMonent  ////////// 
/////////////////////////////////////////////////////////////////////////////////////////////// 

#pragma once
#ifndef CProbawLawWithMoment_h
#define CProbawLawWithMoment_h

///////////////////////////////////////////////////////////////////////////

#include "CProbaLaw.hpp"

///////////////////////////////////////////////////////////////////////////

class CProbaLawWithMoment : public CProbaLaw
{
	public :
		// Constructor
		CProbaLawWithMoment() ;

		// Destructor
		virtual ~CProbaLawWithMoment();

		// Simulation of a random variable
		virtual double simule() const = 0 ;

		// Mean 
		virtual double mean() const = 0 ;
		
		// Variance
		virtual double variance() const = 0 ;
} ;

#endif
