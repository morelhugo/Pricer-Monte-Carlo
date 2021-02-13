/////////////////////////////////////////////////////////////////////////////////////////////// 
///// Fichier CBrownian.h : Declaration de la classe CBrownian  ////////// 
/////////////////////////////////////////////////////////////////////////////////////////////// 

#pragma once
#ifndef CBrownian_h
#define CBrownian_h

///////////////////////////////////////////////////////////////////////////

#include "CProcess.hpp"
#include "CNormal.hpp"

///////////////////////////////////////////////////////////////////////////

class CBrownian : public CProcess
{
private:
	CNormal No ;		

public:
	// Constructor
	CBrownian(double Ti = 1, long Ni = 100);

	// Constructor
	CBrownian(double Ti = 1, double Dti = 0.01);

	// Destructor
	virtual ~CBrownian();

	// Get variation process between today and maturity 
	double getIncrementProcessT() const;

	// Get variation process between t(i) and t(i+1), Dt= t(i+1) - t(i)    
	double getIncrementProcessDt() const;
};

#endif
