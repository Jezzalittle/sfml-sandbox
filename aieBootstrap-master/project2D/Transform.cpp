  #include "Transform.h"



Transform::Transform()
{
	rot = 0.0f;
	scale = Vector2(1, 1);
	parent = nullptr;
}



void Transform::UpdateTransforms()
{
	posMat.setTraslate(pos.x, pos.y);
	rotMat.setRotateZ(rot);
	scaleMat.setScaleXYZ(scale.x, scale.y,1);

	localMat = posMat * rotMat * scaleMat;

	if (parent == nullptr)
	{
		globalMat = localMat;
	}
	else
	{
		globalMat = parent->globalMat * localMat;
	}

}

Matrix3 Transform::GetLocalMatrix() const
{
	return localMat;
}

void Transform::Translate( Vector2& a_pos)
{
	pos += a_pos;
	UpdateTransforms();
}

void Transform::Scale(Vector2& a_scale)
{
	scale += a_scale;
	UpdateTransforms();
}

void Transform::Rotate(float angle)
{
	rot += angle;
	UpdateTransforms();
}

void Transform::SetPosition(const Vector2& a_pos)
{
	pos = a_pos;

	posMat.setTraslate(a_pos.x, a_pos.y);
	UpdateTransforms();
}

void Transform::SetScale(const Vector2& a_scale)
{
	scale = a_scale;
	scaleMat.setScaleXYZ(a_scale.x, a_scale.y, 1);

	UpdateTransforms();
}

void Transform::SetRotation(float angle)
{
	rot = angle;
	rotMat.setRotateZ(angle);
	UpdateTransforms();
}

Vector2 Transform::GetPosition() const
{
	return pos;
}

Vector2 Transform::GetScale() const
{
	return scale;
}

float Transform::GetRotation() 
{
	return rot;
}

Matrix3 Transform::getglobalMat() const
{
	if (parent != nullptr)
	{
		return parent->getglobalMat() * localMat;
	}
	else
	{
		return localMat;
	}
}

void Transform::setParent(Transform * a_parent)
{
	parent = a_parent;
}

Transform * Transform::getParent()
{
	return parent;
}
