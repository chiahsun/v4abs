#ifndef VREXPR_TYPES_H
#define VREXPR_TYPES_H

#include "nstl/shared_ptr/SharedPtr.h"

class VRExprNumber;
typedef SharedPtr<VRExprNumber> VRExprNumberHandle;
class VRExprIdentifier;
typedef SharedPtr<VRExprIdentifier> VRExprIdentifierHandle;
class VRExprBitSelect;
typedef SharedPtr<VRExprBitSelect> VRExprBitSelectHandle;
class VRExprBinaryExpression;
typedef SharedPtr<VRExprBinaryExpression> VRExprBinaryExpressionHandle;
class VRExprUnaryExpression;
typedef SharedPtr<VRExprUnaryExpression> VRExprUnaryExpressionHandle;
class VRExprPrimary;
typedef SharedPtr<VRExprPrimary> VRExprPrimaryHandle;
class VRExprExpressionImpl;
typedef SharedPtr<VRExprExpressionImpl> VRExprExpressionImplHandle;
class VRExprExpression;
typedef SharedPtr<VRExprExpression> VRExprExpressionHandle;


#endif // VREXPR_TYPES_H
