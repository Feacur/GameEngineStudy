#include "ges_pch.h"
#include "OpenGLBuffer.h"

#include "GES/Debug/Instrumentor.h"
#include "GES/Debug/Code.h"

#include <glad/glad.h>

namespace GES
{
	//
	// OpenGLVertexBuffer
	//

	OpenGLVertexBuffer::OpenGLVertexBuffer(float * vertices, uint32 size)
	{
		GES_PROFILE_FUNCTION();
		// glGenBuffers(1, &m_RendererID);
		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		GES_PROFILE_FUNCTION();
		glDeleteBuffers(GL_ARRAY_BUFFER, &m_RendererID);
	}

	void OpenGLVertexBuffer::Bind() const
	{
		GES_PROFILE_FUNCTION();
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLVertexBuffer::Unbind() const
	{
		GES_PROFILE_FUNCTION();
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	//
	// OpenGLIndexBuffer
	//

	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32 * indices, uint32 count)
		: m_Count(count)
	{
		GES_PROFILE_FUNCTION();
		// glGenBuffers(1, &m_RendererID);
		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32), indices, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		GES_PROFILE_FUNCTION();
		glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &m_RendererID);
	}

	void OpenGLIndexBuffer::Bind() const
	{
		GES_PROFILE_FUNCTION();
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLIndexBuffer::Unbind() const
	{
		GES_PROFILE_FUNCTION();
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}