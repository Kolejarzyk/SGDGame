#include "Vec.h"
Vec::Vec()
{
	x = 0;
	y = 0;
}

Vec::Vec(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vec& Vec::Add(const Vec& vec)
{
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}

Vec& Vec::Subtract(const Vec& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;

	return *this;
}

Vec& Vec::Multiply(const Vec& vec)
{
	this->x *= vec.x;
	this->y *= vec.y;

	return *this;
}

Vec& Vec::Divide(const Vec& vec)
{
	this->x /= vec.x;
	this->y /= vec.y;

	return *this;
}

Vec& operator+(Vec& v1, const Vec& v2)
{
	return v1.Add(v2);
}

Vec& operator-(Vec& v1, const Vec& v2)
{
	return v1.Subtract(v2);
}

Vec& operator*(Vec& v1, const Vec& v2)
{
	return v1.Multiply(v2);
}

Vec& operator/(Vec& v1, const Vec& v2)
{
	return v1.Divide(v2);
}

Vec& Vec::operator+=(const Vec& vec)
{
	return this->Add(vec);
}

Vec& Vec::operator-=(const Vec& vec)
{
	return this->Subtract(vec);
}

Vec& Vec::operator*=(const Vec& vec)
{
	return this->Multiply(vec);
}

Vec& Vec::operator/=(const Vec& vec)
{
	return this->Divide(vec);
}

Vec& Vec::operator*(const int& i)
{
	this->x *= i;
	this->y *= i;

	return *this;
}

Vec& Vec::Zero()
{
	this->x = 0;
	this->y = 0;

	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vec& vec)
{
	stream << "(" << vec.x << "," << vec.y << ")";
	return stream;
}
