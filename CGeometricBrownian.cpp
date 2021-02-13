//////////////////////////////////////////////////////////////////////////////////////////////
///// Fichier CGeometricBrownian.cpp : Definition de la classe CGeometricBrownian  ///////// 
//////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <cstdlib>
#include <cmath>

///////////////////////////////////////////////////////////////////////////

#include "CGeometricBrownian.hpp"
#include "CBrownian.hpp"

///////////////////////////////////////////////////////////////////////////

CGeometricBrownian::CGeometricBrownian(double Si, double ri, double sigmai, double Ti, long Ni) : CProcess(Ti, Ni), Br(Ti, Ni)
{
    S0     = Si;
    r      = ri;
    sigma  = sigmai;
    Scurr  = new double;
    *Scurr = S0;
}

///////////////////////////////////////////////////////////////////////////

CGeometricBrownian::CGeometricBrownian(double Si, double ri, double sigmai, double Ti, double Dti) : CProcess(Ti, Dti), Br(Ti, Dti)
{
    S0     = Si;
    r      = ri;
    sigma  = sigmai;
    Scurr  = new double;
    *Scurr = S0;
}

///////////////////////////////////////////////////////////////////////////

CGeometricBrownian::~CGeometricBrownian()
{
    if(Scurr)
    {
        delete Scurr;
    } 
}

///////////////////////////////////////////////////////////////////////////

double CGeometricBrownian::getIncrementProcessT() const
{
    if(Scurr)
    {
        *Scurr = S0;
        *Scurr = *Scurr * exp((r - 0.5 * sigma * sigma) * T + sigma * Br.getIncrementProcessT());
        
        return *Scurr;
    }
    else
    {
        return S0 * exp((r - 0.5 * sigma * sigma) * T + sigma * Br.getIncrementProcessT());
    }
}


///////////////////////////////////////////////////////////////////////////

double CGeometricBrownian::getIncrementProcessDt() const
{
    *Scurr = *Scurr * exp((r - 0.5 * sigma * sigma) * Dt + sigma * Br.getIncrementProcessDt());

    return *Scurr;
}

///////////////////////////////////////////////////////////////////////////

double CGeometricBrownian::getSpotCurrent() const
{
    if (Scurr)
    {
        return *Scurr;
    }
    else
    {
        return S0;
    }
}

///////////////////////////////////////////////////////////////////////////
