// name vertex_color
// version 330 core

// VERTEX_SECTION
#if defined(VERTEX_SECTION)
layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

out vec4 v_Color;

void main()
{
	v_Color = a_Color;
	gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
}
#endif // defined(VERTEX_SECTION)

// FRAGMENT_SECTION
#if defined(FRAGMENT_SECTION)
in vec4 v_Color;

layout(location = 0) out vec4 color;

void main()
{
	color = v_Color;
}
#endif // defined(FRAGMENT_SECTION)
