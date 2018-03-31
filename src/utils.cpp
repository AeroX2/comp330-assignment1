#include "utils.hpp"

mt19937& Utils::random_engine() {
	static mt19937 engine { (unsigned int) 347 };
	return engine;
}

float Utils::random_range_float(float min, float max) {
	//Probably not such a great idea to recreate the distribution every time
	//But neither is using it incorrectly
	uniform_real_distribution<float> distribution { min, max };
	return distribution(random_engine());
}

int Utils::random_range_int(int min, int max) {
	//static uniform_int_distribution<> distribution{};
	//using parm_t = decltype(distribution)::param_type;
	//return distribution(random_engine(), parm_t{min, max});

	//Probably not such a great idea to recreate the distribution every time
	//But neither is using it incorrectly
	uniform_int_distribution<> distribution { min, max };
	return distribution(random_engine());
}

float Utils::random_normalised() {
	return random_range_float(0, 1);
}

float Utils::random_clamped() {
	return random_range_float(-1, 1);
}

float Utils::constrain(float num, float min, float max) {
	if (num < min)
		return min;
	if (num > max)
		return max;
	return num;
}

void Utils::draw_circle(float radius) {
	glBegin(GL_TRIANGLE_FAN);
		for (int i = 0; i < 360; i++) {
			float degInRad = i*M_PI/180;
			glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
		}
	glEnd();
}
