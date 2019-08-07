#pragma once
#include <stdexcept>

template<typename T>
class ServiceLocator
{
public:
	
	static T* GetService() {
		if (service == nullptr)
		{
			throw(std::runtime_error("Service was Null"));
		}
		return service;
	}

	static void SetService(T* p_service) {
		service = p_service;
	}

private:
	/*inline*/ static T* service /*= nullptr*/;
	static_assert(!std::is_pointer<T>::value, "Service must not be a pointer");
};
template <class T> T* ServiceLocator<T>::service = nullptr;