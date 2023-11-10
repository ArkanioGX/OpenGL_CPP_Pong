#version 330 core
in vec3 pos;
uniform vec3 objectPos;
uniform vec3 objectSize;

out vec4 OurColor;

void main()
{
    vec3 posT = vec3(pos);
    gl_Position = vec4((posT*objectSize) + objectPos, 1.0);

    OurColor = vec4(gl_Position);
}
