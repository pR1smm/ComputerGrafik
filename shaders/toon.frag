#sginclude "://shaders/commonlight.vert.inc"

in vec3 viewPosition;
in vec3 viewNormal;

out vec4 fragColor;

void main()
{
    vec3 viewDirection = -normalize(viewPosition);
    vec3 normal = normalize(viewNormal); // must be normalized, since it is the result of linear interpolation

    vec3 color = vec3(0.0);
    for (int i = 0; i < sunLightCount; ++i)
    {
        float intensity = dot(-sunLights[i].viewDirection, normal);
        float steppedIntensity = floor(10.0 * intensity) / 10.0;
        vec3 ambient = sunLights[i].ambient.rgb * material.ambient.rgb;
        vec3 diffuse = sunLights[i].diffuse.rgb * material.diffuse.rgb;
        vec3 specular = sunLights[i].specular.rgb * material.specular.rgb;
        color += steppedIntensity * (ambient + diffuse + specular);
    }

    for (int i = 0; i < pointLightCount; ++i)
    {
        vec3 lightViewDirection = pointLights[i].viewPosition - viewPosition;
        float lightViewDistance = length(lightViewDirection);
        float lightAttenuation = computeLightAttenuation(lightViewDistance, pointLights[i].attenuations);
        lightViewDirection /= lightViewDistance;
        float intensity = dot(lightViewDirection, normal);
        float steppedIntensity = floor(10.0 * intensity) / 10.0;
        vec3 ambient = pointLights[i].ambient.rgb * material.ambient.rgb;
        vec3 diffuse = pointLights[i].diffuse.rgb * material.diffuse.rgb;
        vec3 specular = pointLights[i].specular.rgb * material.specular.rgb;
        color += lightAttenuation * steppedIntensity * (ambient + diffuse + specular);
    }

    for (int i = 0; i < spotLightCount; ++i)
    {
        vec3 lightViewDirection = spotLights[i].viewPosition - viewPosition;
        float lightViewDistance = length(lightViewDirection);
        lightViewDirection /= lightViewDistance;
        float clampedCosine = max(-dot(lightViewDirection, spotLights[i].viewDirection), 0.0);
        if (clampedCosine >= spotLights[i].falloffAngle)
        {
            // Fragment innerhalb Falloffradius vom Spotlicht => Wende Toon auf Fragment an
            float lightAttenuation = computeLightAttenuation(lightViewDistance, spotLights[i].attenuations);
            float falloffExponent = pow(clampedCosine, spotLights[i].falloffExponent);
            float intensity = dot(lightViewDirection, normal);
            float steppedIntensity = floor(10.0 * intensity) / 10.0;
            vec3 ambient = spotLights[i].ambient.rgb * material.ambient.rgb;
            vec3 diffuse = spotLights[i].diffuse.rgb * material.diffuse.rgb;
            vec3 specular = spotLights[i].specular.rgb * material.specular.rgb;
            color += lightAttenuation * steppedIntensity * falloffExponent * (ambient + diffuse + specular);
        }
    }

    fragColor = vec4(color + material.emission.rgb, computeMaterialAlpha());
}
