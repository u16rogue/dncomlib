#pragma once

namespace dcl
{
	// TODO: implement sfinae to check if class has a Release method
	template <typename T>
	class unique_releasable
	{
	public:
		unique_releasable(unique_releasable &) = delete;
		unique_releasable(const unique_releasable &) = delete;

		unique_releasable() = default;

		~unique_releasable()
		{
			remove();
		}

		unique_releasable(T * instance_)
			: instance(instance_)
		{
		}

		unique_releasable(unique_releasable && other)
		{
			remove();
			instance = other.instance;
			other.instance = nullptr;
		}

		auto remove() -> void
		{
			if (instance)
				instance->Release();

			instance = nullptr;
		}

		auto operator ->() -> T *
		{
			return instance;
		}

		auto operator =(T * rhs) -> void
		{
			remove();
			instance = rhs;
		}

		auto operator =(unique_releasable<T> && rhs) -> void
		{
			remove();
			instance = rhs.instance;
			rhs.instance = nullptr;
		}

		operator bool() const noexcept
		{
			return instance != nullptr;
		}

		auto ppinstance() -> T **
		{
			return &instance;
		}

	private:
		T * instance { nullptr };
	};
}