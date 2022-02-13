#version 330 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 ColorPosition;
layout (location = 2) in vec2 TexturePosition;

out vec3 Color;
out vec2 TextureCoordinate;

uniform float scale;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
   gl_Position = proj * view * model * vec4(Position, 1.0);

   Color = ColorPosition;

   TextureCoordinate = TexturePosition;
}