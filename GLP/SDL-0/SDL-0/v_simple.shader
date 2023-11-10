#version 330 core
in vec3 pos;
uniform vec3 objectPos;
uniform vec3 objectSize;

void main()
{
    vec3 posT = vec3(pos);
    posT.x *= 0.75;
    gl_Position = vec4((posT*objectSize) + objectPos, 1.0);
}

