// CS559 Utility Code
// - implementation of simple 3D point class
// see the header file for details
//
// file put together by Mike Gleicher, October 2008
//

#include "Pnt3f.H"
#include "math.h"

Pnt3f::Pnt3f() : x(0), y(0), z(0)
{
}
Pnt3f::Pnt3f(const float* iv) : x(iv[0]), y(iv[1]), z(iv[2])
{
}
Pnt3f::Pnt3f(const float _x, const float _y, const float _z) : x(_x), y(_y), z(_z)
{
}

float Pnt3f::dot(const Pnt3f& p2){
	return x * p2.x + y * p2.y + z * p2.z;
}

float Pnt3f::distance(Pnt3f& p2){
	float x1 = pow(p2.x - x, 2);
	float y1 = pow(p2.y - y, 2);
	float z1 = pow(p2.z - z, 2);
	return sqrt(x1 + y1 + z1);
}

void Pnt3f::abs(){
	x = std::abs(x);
	y = std::abs(y);
	z = std::abs(z);
}

void Pnt3f::normalize()
{
	float l = x*x + y*y + z*z;
	if (l<.000001) {
		x = 0;
		y = 1;
		z = 0;
	} else {
		l = sqrt(l);
		x /= l;
		y /= l;
		z /= l;
	}
}
// This code tells us where the original came from in CVS
// Its a good idea to leave it as-is so we know what version of
// things you started with
// $Header: /p/course/cs559-gleicher/private/CVS/Utilities/Pnt3f.cpp,v 1.3 2008/10/19 01:54:28 gleicher Exp $