/////////////////////////////////////////////////////////////////////////////////////////////// 
///// Fichier CProcess.h : Declaration de la classe CProcess  ////////// 
/////////////////////////////////////////////////////////////////////////////////////////////// 

#pragma once
#ifndef CProcess_h
#define CProcess_h

///////////////////////////////////////////////////////////////////////////

#include "CProbaLaw.hpp"

///////////////////////////////////////////////////////////////////////////

class CProcess : public CProbaLaw
{
	protected:		
		double T ;    // Maturity of the processus		
		long   N ;    // Number of time discretization on [0,T]
		double Dt;    // Size of time step 

	public:
		// Constructor
		CProcess(double Ti = 1, long Ni = 100);

		// Constructor
		CProcess(double Ti = 1, double Dti = 0.01);

		// Destructor
		virtual ~CProcess();

		// Simulation of a process at maturity T
		double simule() const;

		// Get variation process between today and maturity 
		virtual double getIncrementProcessT() const = 0;

		// Get variation process between t(i) and t(i+1), Dt= t(i+1) - t(i)    
		virtual double getIncrementProcessDt() const = 0;
};

#endif

