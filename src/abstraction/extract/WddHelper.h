#ifndef WDD_HELPER_H
#define WDD_HELPER_H

#include "formal/wdd/Term.h"
#include "formal/wdd/WddManager.h"
#include "utility/log/Log.h"
#include "verilog/vrexpr/VRExprTerm.h"
#include "verilog/vrexpr/VRExprExpression.h"
#include "protocol/pexpr/PExpr.h"
#if 0
VRExprExpression makeVRExprExpressionFromWddNodeHandle(VRExprTermManager termManager, VRExprTermManager::WddNodeHandle pWddNode);
#endif

VRExprPrimary makeVRExprPrimaryFromPExprBoolExpression(PExprBoolExpressionHandle pBoolExpression); 

VRExprExpression makeVRExprExpressionFromPExprBoolExpression(PExprBoolExpressionHandle pBoolExpression);

VRExprTermManager::WddNodeHandle makeTermHandleFromPExprBoolExpression(VRExprTermManager termManager, PExprBoolExpressionHandle pBoolExpression);

WddManager<TermHandle>::WddNodeHandle makeWddHandleFromPExprBoolExpression(WddManager<TermHandle> & wddManager, PExprBoolExpressionHandle pBoolExpression);

#endif // WDD_HELPER_H
