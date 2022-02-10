#version 330 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 ColorPosition;

out vec3 Color;

uniform float scale;

void main()
{
   gl_Position = vec4(Position.x + Position.x * scale, Position.y + Position.y * scale, Position.z + Position.z * scale, 1.0);

   Color = ColorPosition;
}