#version 330 core

out vec4 FragmentColor;

in vec3 Color;
in vec2 TextureCoordinate;

uniform sampler2D Texture; 

void main()
{
   FragmentColor = texture(Texture, TextureCoordinate);
}