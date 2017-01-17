uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;
layout (location = 0) in vec4 vertexPosition;

void main()
{
    gl_Position = projectionMatrix*modelViewMatrix*vertexPosition;
}
