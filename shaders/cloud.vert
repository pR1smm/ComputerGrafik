#sginclude "://shaders/commonlight.vert.inc"

//Inspired from Cloud Shader of Orange Book

out float sunLightIntensities[MAX_LIGHTS];
out float pointLightIntensities[MAX_LIGHTS];
out float spotLightIntensities[MAX_LIGHTS];
out vec3 viewPosition;
out vec3 MCposition;

uniform float Scale;

void main()
{
    MCposition = vec3(vertexPosition) * Scale;
    viewPosition = eyePosition().xyz;

    for (int i = 0; i < sunLightCount; ++i)
    {
        sunLightIntensities[i] = dot(-sunLights[i].viewDirection, eyeNormalVec()) * 1.5;
    }

    for (int i = 0; i < pointLightCount; ++i)
    {
        pointLightIntensities[i] = dot(normalize(pointLights[i].viewPosition - viewPosition).xyz, eyeNormalVec()) * 1.5;
    }

    for (int i = 0; i < spotLightCount; ++i)
    {
        spotLightIntensities[i] = dot(normalize(spotLights[i].viewPosition - viewPosition).xyz, eyeNormalVec()) * 1.5;
    }

    gl_Position = vPos();
}
