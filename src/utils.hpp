#ifndef UTILS_H
#define UTILS_H

//#include <time.h>
#include <cmath>
#include <random>

using namespace std;

class Utils {
	public:
		static mt19937& random_engine();
		static float random_range_float(float min, float max);
		static int random_range_int(int min, int max);
		static float random_normalised();
		static float random_clamped();
		static float constrain(float num, float min, float max);
};

#endif
