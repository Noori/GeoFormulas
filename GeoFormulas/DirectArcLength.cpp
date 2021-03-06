/** \file DirectArcLength.cpp
*   \brief
*/

/****************************************************************************/
/*  DirectArcLength.cpp                                                     */
/****************************************************************************/
/*                                                                          */
/*  Copyright 2008 - 2016 Paul Kohut                                        */
/*  Licensed under the Apache License, Version 2.0 (the "License"); you may */
/*  not use this file except in compliance with the License. You may obtain */
/*  a copy of the License at                                                */
/*                                                                          */
/*  http://www.apache.org/licenses/LICENSE-2.0                              */
/*                                                                          */
/*  Unless required by applicable law or agreed to in writing, software     */
/*  distributed under the License is distributed on an "AS IS" BASIS,       */
/*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or         */
/*  implied. See the License for the specific language governing            */
/*  permissions and limitations under the License.                          */
/*                                                                          */
/****************************************************************************/

#include "Conversions.h"
#include "GeoFormulas.h"


namespace GeoCalcs {
    /**
    *
    */
    double DirectArcLength(const LLPoint &center, double dRadius, double dStartCrs, double dEndCrs,
                           int nOrient, double dTol)
    {
        const double dSubtendedAngle = GetArcExtent(dStartCrs, dEndCrs, nOrient, dTol);
        const double R = sqrt(GeometricMeanMeridional(center.latitude) * PrimeVerticalCurvature(center.latitude));
        return fabs(dSubtendedAngle * R * sin(dRadius / R));
    }
}
