#pragma once

// predeclare the class that the class needs to know about
class Vector3;
class Vector4;
class Vector2;




//Matrix 4 is a 4x4 table of values each row represents an axis 


class Matrix4
{
public:

	float m[4][4]; // Xx (m[0][0]),  Xy (m[1][0]), Xz (m[2][0]), Tz (m[3][0])
				   // Yx (m[0][1]),  Yy (m[1][1]), Yz (m[2][1])  Tz (m[3][1])
				   // Zx (m[0][2]),  Zy (m[1][2]), Zz (m[2][2])  Tz (m[3][2])
				   // Tx (m[0][3]),  Ty (m[1][3]), Tz (m[2][3])  Tz (m[3][3])
	
	// the default constructor creates a identity matrix which is the same as a 1 in decimal maths
	Matrix4();	   


	// the overload constructor builds a matrix4 with the values the user gives
	Matrix4(
		float a_Xx, float a_Xy, float a_Xz, float a_Xt,
		float a_Yx, float a_Yy, float a_Yz,float a_Yt,
		float a_Zx, float a_Zy, float a_Zz, float a_Zt,
		float a_Tx, float a_Ty, float a_Tz, float a_Tt);


	//adds the values of all indexs together
	Matrix4 operator+(const Matrix4& rhs) const;

	//subtracts the values of all indexs together
	Matrix4 operator-(const Matrix4& rhs) const;

	//		   [4]		[12] [8]
	//[3][2] * [5]  =   [15] [10]
	
	//multiplys the rows of the new index aginst the column of the new index to create the index
	Matrix4 operator*(const Matrix4& rhs) const;


	//addition but it affects the orginal
	Matrix4& operator+=(const Matrix4& rhs);

	//subtration but it affects the orginal
	Matrix4& operator-=(const Matrix4& rhs);

	//multiplication but it affects the orginal
	Matrix4& operator*=(const Matrix4& b);

	//swaps the orginal matrix's rows and columns
	Matrix4& transpose(const Matrix4& b);

	//swaps the matrix's rows and columns
	Matrix4 transposed(const Matrix4& b) const;

	//multiplys the vector by the matrix
	Vector3 operator*(const Vector3& other) const;

	//multiplys the vector by the matrix
	Vector4 operator*(const Vector4& other) const;

	//sets the scale index of the axis to the values of the arguments
	void setScaleXYZ(float x, float y, float z);

	//scales the matrix by the argument
	void setScale(float scale);

	//changes the z index for rotation
	void setRotateZ(float rot);
	//changes the x index for rotation
	void setRotateX(float rot);
	//changes the y index for rotation
	void setRotateY(float rot);

	//changes the traslate indexs
	void setTraslate(float x, float y);

	//turns a matrix into a 2d array of floats
	explicit operator float*();

	//turns a matrix to a vector 4
	Vector4& operator[](int index);


	//prints the matrix
	void Print();

};

