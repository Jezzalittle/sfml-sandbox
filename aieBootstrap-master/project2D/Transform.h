#pragma once

#include "Matrix3.h"
#include "Vector2.h"

//A Transform form class is a object that discribes everything to do with moveing an object



class Transform
{
public:

	// defualt constrator
	Transform();


	void UpdateTransforms();
	Matrix3 GetLocalMatrix() const;

	//moves to that postion
	void Translate( Vector2& a_pos);
	//scales to that size
	void Scale(Vector2& a_scale);
	//rotates to that rotation
	void Rotate(float a_angle);

	//sets

	//sets the postion of the object on the screen
	void SetPosition(const Vector2& a_pos);

	//sets the scale of the object on the screen
	void SetScale(const Vector2& a_scale);

	//sets the rotations of the object on the screen
	void SetRotation(float angle);

	
	//gets

	//gets the postion of the object on the screen
	Vector2 GetPosition() const;
	
	//gets the scale of the object on the screen
	Vector2 GetScale() const;

	//gets the rotations of the object on the screen
	float GetRotation();

	//gets the world the gloabl matrix 
	Matrix3 getglobalMat() const;

	//sets the parent of 
	void setParent(Transform* a_parent);

	//returns the parent
	Transform* getParent();
	
private:

	Vector2 pos;
	float rot;
	Vector2 scale;

	Matrix3 posMat;
	Matrix3 rotMat;
	Matrix3 scaleMat;

	Matrix3 localMat;

	Matrix3 globalMat;

	Transform* parent;

};

