#pragma once
// predeclare the class that the class needs to know about
class Vector3;
class Vector2;

//Matrix 3 is a 3x3 table of values each row represents an axis 
class Matrix3
{
public:

	float m[3][3]; // Xx (m[0][0]),  Xy (m[1][0]), Xz (m[2][0])
				   // Yx (m[0][1]),  Yy (m[1][1]), Yz (m[2][1])
				   // Yx (m[0][2]),  Yy (m[1][2]), Yz (m[2][2])

	// the default constructor creates a identity matrix which is the same as a 1 in decimal maths
	Matrix3();

	// the overload constructor builds a matrix4 with the values the user gives
	Matrix3(float a_Xx, float a_Xy,float a_Xz,float a_Yx,float a_Yy,float a_Yz,float a_Zx, float a_Zy, float a_Zz);

	//adds the values of all indexs together
	Matrix3 operator+(const Matrix3& rhs) const;

	//subtracts the values of all indexs together
	Matrix3 operator-(const Matrix3& rhs) const;

	//		   [4]		[12] [8]
	//[3][2] * [5]  =   [15] [10]

	//multiplys the rows of the new index aginst the column of the new index to create the index
	Matrix3 operator*(const Matrix3& rhs) const;


	//addition but it affects the orginal
	Matrix3& operator+=(const Matrix3& rhs);

	//subtration but it affects the orginal
	Matrix3& operator-=(const Matrix3& rhs);

	//multiplication but it affects the orginal
	Matrix3& operator*=(const Matrix3& rhs);

	//multiplys the vector by the matrix
	Vector3 operator*(const Vector3& other) const;

	//multiplys the vector by the matrix
	Vector2 operator*(const Vector2& other) const;

	//swaps the orginal matrix's rows and columns
	Matrix3& transpose(const Matrix3& b);

	//swaps the matrix's rows and columns
	Matrix3 transposed(const Matrix3& b) const;

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
	Vector3& operator[](int index);

	//prints the matrix
	void Print();


};

