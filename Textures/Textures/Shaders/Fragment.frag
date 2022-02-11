#version 330 core

out vec4 FragmentColor;

in vec3 Color;

void main()
{
   FragmentColor = vec4(Color, 1.0f);
}