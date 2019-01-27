#pragma once
#include <iostream>

class Vec
{
public:
	float x;
	float y;

	Vec();
	Vec(float x, float y);

	Vec& Add(const Vec& vec);
	Vec& Subtract(const Vec& vec);
	Vec& Multiply(const Vec& vec);
	Vec& Divide(const Vec& vec);

	friend Vec& operator+(Vec& v1, const Vec& v2);
	friend Vec& operator-(Vec& v1, const Vec& v2);
	friend Vec& operator*(Vec& v1, const Vec& v2);
	friend Vec& operator/(Vec& v1, const Vec& v2);

	Vec& operator+=(const Vec& vec);
	Vec& operator-=(const Vec& vec);
	Vec& operator*=(const Vec& vec);
	Vec& operator/=(const Vec& vec);

	Vec& operator*(const float& i);
	Vec& Zero();

	friend std::ostream& operator<<(std::ostream& stream, const Vec& vec);
};