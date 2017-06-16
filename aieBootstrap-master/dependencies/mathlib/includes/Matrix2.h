#pragma once


//predeclare vector2 so the h file knows that your using a vector2
class Vector2;

//Matrix 2 is a 2x2 table of values each row represents an axis 
class Matrix2
{
public:
	
	float m[2][2]; // Xx (m[0][0]),  Xy (m[0][1])
				   // Yx (m[1][0]),  Yy (m[1][1])

	// the default constructor creates a identity matrix which is the same as a 1 in decimal maths
	Matrix2();

	// the overload constructor builds a matrix4 with the values the user gives
	Matrix2(float a_Xx, float a_Xy, float a_Yx, float a_Yy);

	//adds the values of all indexs together
	Matrix2 operator+(const Matrix2& rhs) const;

	//subtracts the values of all indexs together
	Matrix2 operator-(const Matrix2& rhs) const;

	//		   [4]		[12] [8]
	//[3][2] * [5]  =   [15] [10]

	//multiplys the rows of the new index aginst the column of the new index to create the index
	Matrix2 operator*(const Matrix2& b) const;

	//addition but it affects the orginal
	Matrix2& operator+=(const Matrix2& rhs);

	//subtration but it affects the orginal
	Matrix2& operator-=(const Matrix2& rhs);

	//multiplication but it affects the orginal
	Matrix2& operator*=(const Matrix2& b);

	//multiplys the vector by the matrix
	Vector2 operator*(const Vector2& other) const;

	//swaps the orginal matrix's rows and columns
	Matrix2& transpose(const Matrix2& b);

	//swaps the matrix's rows and columns
	Matrix2 transposed(const Matrix2& b) const;

	//scales the matrix by the argument
	void setScaleXY(float x, float y);

	//scales the matrix by the argument
	void setScale(float scale);

	//changes the index for rotation
	void setRotate(float rot);

	//turns a matrix into a 2d array of floats
	explicit operator float*();

	//turns a matrix to a vector 2
	Vector2& operator[](int index);

	//prints the matrix
	void Print();
};

