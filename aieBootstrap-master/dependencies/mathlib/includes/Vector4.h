#pragma once

//vectors can be used as either a point (a postion in a 3d world) or a vector (a rotation and a magnitude)

class Vector4
{
	
public:

	float x;
	float y;
	float z;
	float w;

	//defult construtor makes a vector4 at (0,0,0,0)
	Vector4();

	//overloaded constructor builds a vector with the values 
	Vector4(float a_x, float a_y, float a_z, float a_w);

	//an operator overload changes what the operator do when using them 

	//adds the x and y and z value of the first vector with the second vector
	Vector4 operator+(const Vector4& rhs) const;

	//subtracts the x and y and z value of the first vector with the second vector
	Vector4 operator-(const Vector4& rhs) const;

	//multiplys the x and y and z value of the first vector with the second vector
	Vector4 operator*(float rhs) const;

	//divides the x and y and z value of the first vector with the second vector
	Vector4 operator/(float rhs) const;

	//adds the x and y and z value of the first vector with the second vector but effects the original vector
	Vector4& operator+=(const Vector4& rhs);

	//subtracts the x and y and z value of the first vector with the second vector but effects the original vector
	Vector4& operator-=(const Vector4& rhs);

	//multiplys the x and y and z value of the first vector with the second vector but effects the original vector
	Vector4& operator*=(float rhs);

	//divides the x and y and z value of the first vector with the second vector but effects the original vector
	Vector4& operator/=(float rhs);

	//checks the x values and the y values and the z values and returns true if they are the same
	bool operator==(Vector4& rhs);

	//checks the x values and the y values and returns true if they are not the same
	bool operator!=(Vector4& rhs);

	//returns the value of the index of a vector
	float& operator[](int index);

	//returns the memory address of the vector for making an array
	explicit operator float*();

	//magnitude returns the length of the vector3
	float Magnitude() const;

	//returns a vector3 that points in the same dirctrion but has a length of 1 
	Vector4 Normalised() const;

	//changes this vector to a length of 1
	void Normalise();

	//dot product is repersentation of a vector3
	float Dot(const Vector4& rhs) const;

	//the cross product is a respersentation of a vector3 multiplied together
	Vector4 Vector4::Cross(const Vector4& rhs) const;



};

// this means that you can swich the way you multiply vectors
Vector4 operator*(float lhs, const Vector4& rhs);


