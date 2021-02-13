/////////////////////////////////////////////////////////////////////////////////////////////// 
///// Fichier CGeometricBrownian.h : Declaration de la classe CGeometricBrownian  ////////// 
/////////////////////////////////////////////////////////////////////////////////////////////// 

#pragma once
#ifndef CGeometricBrownian_h
#define CGeometricBrownian_h

///////////////////////////////////////////////////////////////////////////

#include "CBrownian.hpp"

///////////////////////////////////////////////////////////////////////////

class CGeometricBrownian : public CProcess
{
private:
	CBrownian Br;
	double    S0;
	double    r;
	double    sigma;
	double*   Scurr;

public:
	// Constructor
	CGeometricBrownian(double Si, double ri, double sigmai, double Ti = 1, long Ni = 100);

	// Constructor
	CGeometricBrownian(double Si, double ri, double sigmai, double Ti = 1, double Dti = 0.01);

	// Destructor
	virtual ~CGeometricBrownian();

	// Get variation process between today and maturity 
	double getIncrementProcessT() const ;

	// Get variation process between t(i) and t(i+1), Dt= t(i+1) - t(i)    
	double getIncrementProcessDt() const;

	// Get current spot simulated level
	double getSpotCurrent() const;
};

#endif
