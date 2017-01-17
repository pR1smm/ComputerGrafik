#sginclude "://shaders/commonlightmatdefs.inc"
#sginclude "://shaders/commonlightmodels.inc"

uniform float hasTexture=0.0f;
uniform sampler2D textureMap;

in vec2 texCoords;
in vec3 viewPosition;
in vec3 viewNormal;

out vec4 fragColor;

void main()
{


    if(hasTexture > 0.5)
    {
        vec4 textureFrag = texture(textureMap, texCoords);
        vec3 color = phong(viewPosition, -normalize(viewPosition), normalize(viewNormal), (textureFrag.rgb));
        fragColor = vec4((color + textureFrag.rgb), computeMaterialAlpha() + textureFrag.a);
    }
//    fragColor = vec4(texCoords.x,texCoords.y,0.,1.);
}
