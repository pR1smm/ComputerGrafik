#sginclude "://shaders/commonlightmatdefs.inc"

in float sunLightIntensities[MAX_LIGHTS];
in float pointLightIntensities[MAX_LIGHTS];
in float spotLightIntensities[MAX_LIGHTS];

in vec3 viewPosition;
in vec3 MCposition;
out vec4 fragColor;

uniform vec3 SkyColor=vec3(0.0, 0.0, 0.8);
uniform vec3 CloudColor=vec3(0.8, 0.8, 0.8);

void main()
{
    vec2  noisevec  = noise2(MCposition);
    float intensity = (noisevec[0] + noisevec[1] + 0.03125)*.6;
    vec3 color = vec3(0.0);

    for (int i = 0; i < sunLightCount; ++i)
    {
        color += mix(SkyColor, CloudColor, intensity) * 1.5 * sunLightIntensities[i];
    }

    for (int i = 0; i < pointLightCount; ++i)
    {
        color += mix(SkyColor, CloudColor, intensity) * 1.5 * pointLightIntensities[i];
    }

    for (int i = 0; i < spotLightCount; ++i)
    {
        vec3 lightViewDirection = normalize(spotLights[i].viewPosition - viewPosition);
        float clampedCosine = max(-dot(lightViewDirection, spotLights[i].viewDirection), 0.0);
        if (clampedCosine >= spotLights[i].falloffAngle)
        {
            color += mix(SkyColor, CloudColor, intensity) * 1.5 * spotLightIntensities[i];
        }
    }

    fragColor = vec4(color,0.5);
}
