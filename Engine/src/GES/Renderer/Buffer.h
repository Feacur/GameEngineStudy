#pragma once
#include "GES/Core/Code.h"

#if !defined(GES_BYPASS_VENDOR_HEADERS)
	#include <string>
#endif

namespace GES
{
	enum class ShaderDataType
	{
		None = 0,
		Float1,
		Float2,
		Float3,
		Float4,
		Mat3,
		Mat4,
		Int1,
		Int2,
		Int3,
		Int4,
		Bool,
	};

	static u32 ShaderDataTypeComponentCount(ShaderDataType type)
	{
		switch(type)
		{
			case ShaderDataType::Float1: return 1;
			case ShaderDataType::Float2: return 2;
			case ShaderDataType::Float3: return 3;
			case ShaderDataType::Float4: return 4;
			case ShaderDataType::Mat3:   return 3 * 3;
			case ShaderDataType::Mat4:   return 4 * 4;
			case ShaderDataType::Int1:   return 1;
			case ShaderDataType::Int2:   return 2;
			case ShaderDataType::Int3:   return 3;
			case ShaderDataType::Int4:   return 4;
			case ShaderDataType::Bool:   return 1;
		}
		// GES_CORE_ASSERT(false, "unsupported ShaderDataType '{0}'", (s32)type);
		return 0;
	}

	static u32 ShaderDataTypeSingleSize(ShaderDataType type)
	{
		switch(type)
		{
			case ShaderDataType::Float1: return sizeof(r32);
			case ShaderDataType::Float2: return sizeof(r32);
			case ShaderDataType::Float3: return sizeof(r32);
			case ShaderDataType::Float4: return sizeof(r32);
			case ShaderDataType::Mat3:   return sizeof(r32);
			case ShaderDataType::Mat4:   return sizeof(r32);
			case ShaderDataType::Int1:   return sizeof(s32);
			case ShaderDataType::Int2:   return sizeof(s32);
			case ShaderDataType::Int3:   return sizeof(s32);
			case ShaderDataType::Int4:   return sizeof(s32);
			case ShaderDataType::Bool:   return sizeof(s8);
		}
		// GES_CORE_ASSERT(false, "unsupported ShaderDataType '{0}'", (s32)type);
		return 0;
	}

	static u32 ShaderDataTypeSize(ShaderDataType type)
	{
		return ShaderDataTypeSingleSize(type) * ShaderDataTypeComponentCount(type);
	}

	struct BufferElement
	{
		ShaderDataType Type;
		std::string Name;
		bool Normalized;

		BufferElement(ShaderDataType type, std::string name, bool normalized = false)
			: Type(type), Name(name), Normalized(normalized) {}
		
		u32 GetSize() const { return ShaderDataTypeSize(Type); }
		u32 GetComponentCount() const { return ShaderDataTypeComponentCount(Type); }
	};

	class BufferLayout
	{
	public:
		BufferLayout() = default;

		BufferLayout(std::initializer_list<BufferElement> const & elements)
			: m_Elements(elements) {}

	public:
		inline std::vector<BufferElement> const & GetElements() const { return m_Elements; }

		std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
		std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
		std::vector<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }
		std::vector<BufferElement>::const_iterator end() const { return m_Elements.end(); }

	private:
		std::vector<BufferElement> m_Elements;
	};

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

	public:
		static Ref<VertexBuffer> Create(r32 * vertices, u32 count);

	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetLayout(BufferLayout const & layout) = 0;
		virtual BufferLayout const & GetLayout() const = 0;
	};
	
	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

	public:
		static Ref<IndexBuffer> Create(u32 * indices, u32 count);

	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		
		virtual u32 GetCount() const = 0;
	};
}