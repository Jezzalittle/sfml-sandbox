#pragma once

//vectors can be used as either a point (a postion in a 2d world) or a vector (a postion and a magnitude)

class Vector2
{
public:

	//defult construtor makes a vector2 at (0,0)
	Vector2();

	//overloaded constructor builds a vector with the values 
	Vector2(float a_x, float a_y);

	
	float x;
	float y;


	//an operator overload changes what the operator do when using them 


	//adds the x and y value of the first vector with the second vector
	Vector2 operator+(const Vector2& rhs) const;

	//subtracts the x and y value of the first vector with the second vector
	Vector2 operator-(const Vector2& rhs) const;

	//multiplys the x and y value of the first vector with the second vector
	Vector2 operator*(float rhs) const;

	//divides the x and y value of the first vector with the second vector
	Vector2 operator/(float rhs) const;

	//adds the x and y value of the first vector with the second vector but effects the original vector
	Vector2& operator+=(const Vector2& rhs);

	//subtracts the x and y value of the first vector with the second vector but effects the original vector
	Vector2& operator-=(const Vector2& rhs);

	//multiplys the x and y value of the first vector with the second vector but effects the original vector
	Vector2& operator*=(float rhs);

	//divides the x and y value of the first vector with the second vector but effects the original vector
	Vector2& operator/=(float rhs);

	//checks the x values and the y values and returns true if they are the same
	bool operator==(const Vector2& rhs);

	//checks the x values and the y values and returns true if they are not the same
	bool operator!=(const Vector2& rhs);

	//returns the value of the index of a vector
	float& operator[](int index);

	//returns the memory address of the vector for making an array
	explicit operator float*();

	//magnitude returns the length of the vector2
	float Magnitude() const;
	
	//returns a vector2 -90 degrees from the orginal
	Vector2 LeftPerp() const;

	//returns a vector2 90 degrees from the orginal
	Vector2 RightPerp() const;

	//returns a vector2 that points in the same dirctrion but has a length of 1 
	Vector2 Normalised() const;
	
	//changes this vector to a length of 1
	void Normalise();

	//dot product is repersentation of 2 vector2
	float Dot(const Vector2& rhs) const;

};

//this means that you can swich the way you multiply vectors 
Vector2 operator*(float lhs, const Vector2& rhs);
