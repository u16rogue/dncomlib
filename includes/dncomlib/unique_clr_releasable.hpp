#pragma once

namespace dcl
{
	// TODO: implement sfinae to check if class has a Release method
	template <typename T>
	class unique_clr_releasable
	{
	public:
		unique_clr_releasable(unique_clr_releasable &) = delete;
		unique_clr_releasable(const unique_clr_releasable &) = delete;

		unique_clr_releasable() = default;

		~unique_clr_releasable()
		{
			remove();
		}

		unique_clr_releasable(T * instance_)
			: instance(instance_)
		{
		}

		unique_clr_releasable(unique_clr_releasable && other)
		{
			remove();
			this->instance = other.instance;
			other.instance = nullptr;
		}

		auto remove() -> void
		{
			if (this->instance)
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
			this->instance = rhs;
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
		T * instance;
	};
}