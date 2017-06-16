#pragma once

//vectors can be used as either a point (a postion in a 3d world) or a vector (a rotation and a magnitude)

class Vector3
{

public:

	float x;
	float y;
	float z;


	//defult construtor makes a vector3 at (0,0,0)
	Vector3();

	//overloaded constructor builds a vector with the values 
	Vector3(float a_x, float a_y, float a_z);
	
	
	//an operator overload changes what the operator do when using them 

	//adds the x and y and z value of the first vector with the second vector
	Vector3 operator+(const Vector3& rhs) const;

	//subtracts the x and y and z value of the first vector with the second vector
	Vector3 operator-(const Vector3& rhs) const;

	//multiplys the x and y and z value of the first vector with the second vector
	Vector3 operator*(float rhs) const;

	//divides the x and y and z value of the first vector with the second vector
	Vector3 operator/(float rhs) const;

	//adds the x and y and z value of the first vector with the second vector but effects the original vector
	Vector3& operator+=(const Vector3& rhs);

	//subtracts the x and y and z value of the first vector with the second vector but effects the original vector
	Vector3& operator-=(const Vector3& rhs);

	//multiplys the x and y and z value of the first vector with the second vector but effects the original vector
	Vector3& operator*=(float rhs);

	//divides the x and y and z value of the first vector with the second vector but effects the original vector
	Vector3& operator/=(float rhs);

	//checks the x values and the y values and the z values and returns true if they are the same
	bool operator==(const Vector3& rhs);

	//checks the x values and the y values and returns true if they are not the same
	bool operator!=(const Vector3& rhs);

	//returns the value of the index of a vector
	float& operator[](int index);

	//returns the memory address of the vector for making an array
	explicit operator float*();

	//magnitude returns the length of the vector3
	float Magnitude()const;


	//returns a vector3 that points in the same dirctrion but has a length of 1 
	Vector3 Normalised()const;

	//changes this vector to a length of 1
	void Normalise();
	
	//dot product is repersentation of a vector3
	float Dot(const Vector3& rhs) const;

	//the cross product is a respersentation of a vector3 multiplied together
	Vector3 Vector3::Cross(const Vector3& rhs) const;

};

// this means that you can swich the way you multiply vectors
Vector3 operator*(float lhs, const Vector3& rhs);