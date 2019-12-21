#include "ges_pch.h"
#include "Renderer.h"

#include "Orthographic2dCamera.h"

#include "RendererAPI.h"
#include "Shader.h"
#include "Texture.h"
#include "VertexArray.h"

namespace GES
{
	struct Data
	{
		glm::mat4 ViewProjectionMatrix;
	};

	static Scope<Data> s_Data = CreateScope<Data>();
	static Scope<RendererAPI> s_RendererAPI = RendererAPI::Create();
	
	void Renderer::SetClearColor()
	{
		s_RendererAPI->SetClearColor();
	}

	void Renderer::Clear()
	{
		s_RendererAPI->Clear();
	}
	
	void Renderer::Init()
	{
		s_RendererAPI->Init();
	}
	
	void Renderer::Shutdown()
	{
	}

	void Renderer::OnWindowResize(uint32 width, uint32 height)
	{
		s_RendererAPI->SetViewport(0, 0, width, height);
	}

	void Renderer::BeginScene(Orthographic2dCamera const & camera)
	{
		s_Data->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::Submit(Ref<Shader> const & shader, Ref<VertexArray> const & vertexArray, glm::mat4 const & transform)
	{
		shader->Bind();
		shader->UploadUniformMat4("u_ViewProjectionMatrix", s_Data->ViewProjectionMatrix);
		shader->UploadUniformMat4("u_Transform", transform);

		vertexArray->Bind();
		s_RendererAPI->DrawIndexed(vertexArray);
	}

	void Renderer::Submit(Ref<Shader> const & shader, Ref<VertexArray> const & vertexArray, glm::mat4 const & transform, Ref<Texture> const & texture)
	{
		texture->Bind(0u);

		shader->Bind();
		shader->UploadUniformMat4("u_ViewProjectionMatrix", s_Data->ViewProjectionMatrix);
		shader->UploadUniformMat4("u_Transform", transform);
		shader->UploadUniformInt32("u_Texture", (int32)texture->GetSlot());

		vertexArray->Bind();
		s_RendererAPI->DrawIndexed(vertexArray);
	}

	void Renderer::EndScene()
	{
	}
}
