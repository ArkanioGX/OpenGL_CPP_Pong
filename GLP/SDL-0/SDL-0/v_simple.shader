#version 330 core
in vec3 pos;
uniform vec2 objectPos;
uniform vec2 objectSize;

void main()
{
    gl_Position = vec4((pos*objectSize) + objectPos, 1.0);
}

