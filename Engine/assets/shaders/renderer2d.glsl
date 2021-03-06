// name: renderer2d
// version: 330 core

// section: VERTEX_SECTION
#if defined(VERTEX_SECTION)
layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec2 a_TexCoord;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

out vec2 v_TexCoord;

void main()
{
	v_TexCoord = a_TexCoord;
	gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
}
#endif // defined(VERTEX_SECTION)

// section: FRAGMENT_SECTION
#if defined(FRAGMENT_SECTION)
in vec2 v_TexCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

layout(location = 0) out vec4 color;

void main()
{
	color = texture(u_Texture, v_TexCoord) * u_Color;
}
#endif // defined(FRAGMENT_SECTION)
