#sginclude "://shaders/commonlight.vert.inc"

in vec2 textureCoords;


out vec3 viewPosition;
out vec3 viewNormal;
out vec2 texCoords;


void main()
{

    viewPosition = eyePosition().xyz;
    viewNormal = eyeNormalVec().xyz;

    gl_Position = projectionMatrix * modelViewMatrix * vertexPosition;

    texCoords=textureCoords;
}
