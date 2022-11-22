#pragma once
template <class T>
class SmartPointer
{
	T* object;
public:
	SmartPointer(T* object = nullptr) : object{ object } {}
	~SmartPointer() { delete object; }

	SmartPointer(const SmartPointer& other) = delete;
	/*{
		object = new T;
		*object = *other.object;
	}*/

	SmartPointer(SmartPointer&& other) noexcept
		: object{ other.object }
	{
		other.object = nullptr;
	}

	SmartPointer& operator=(const SmartPointer& other) = delete;
	/*{
		if (&other == this)
			return *this;

		delete object;

		object = new T;
		*object = other.object;

		return *this;
	}*/

	SmartPointer& operator=(SmartPointer&& other) noexcept
	{
		if (&other == this)
			return *this;

		delete object;

		object = other.object;
		other.object = nullptr;

		return *this;
	}

	T& operator*() const { return *this; }
	T* operator->() const { return this; }
	bool IsNull() const { return object == nullptr; }
};

