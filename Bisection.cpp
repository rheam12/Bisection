//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include<limits>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;


// Sample function for which you need to find the root

float f(const float x) {
  return 3.2*x*x*x - 2.1*x - 23.0;
}

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

float bisectionHelper(const float left, const float right,
		      const float precision, const float minIntervalSize
		      ... );
float bisection(const float left, const float right,
		const float precision, const float minIntervalSize);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//
/**float power(int n, float x)
{
    float temp = x;
    while (n > 1) {
        x = x * temp;
        n--;
    }
    return x;
	}
**/

float bisectionHelper(const float left, const float right,
		      const float precision, const float minIntervalSize,int count){
			  float mid=(right+left)/2;
			  if((f(mid)<precision&&f(mid)>(precision*-1))||(right-left)<minIntervalSize||count>300)
				  return mid;
			  if(f(mid)*f(right)<0&&f(mid)*f(left)>0)
				  return bisectionHelper(mid,right,precision,minIntervalSize,count++);
			  if(f(mid)*f(right)>0&&f(left)*f(right)<0)
				  return bisectionHelper(left,mid,precision,minIntervalSize,count++);
			  else
				  return std::numeric_limits<float>::quiet_NaN();
			  }
float bisection(const float left, const float right,
		const float precision, const float minIntervalSize) {
			if(f(left)*f(right)>0)
				return std::numeric_limits<float>::quiet_NaN();
			if(precision<=0||minIntervalSize<=0)
				return std::numeric_limits<float>::quiet_NaN();
			if((right-left)<minIntervalSize)
				return std::numeric_limits<float>::quiet_NaN();
			int count=0;
			if(f(right)==0)
				return right;
			if(f(left)==0)
				return left;
		if(left>=right)
				return bisectionHelper(right,left,precision,minIntervalSize,count);
			return bisectionHelper(left,right,precision,minIntervalSize,count);

}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
	float left= 7;
	float right= -7;
	float minIntervalSize=0.01;
  	float precision=0.001;
	cout<<bisection(left,right,precision,minIntervalSize)<<endl;

  return 0;
}

#endif
