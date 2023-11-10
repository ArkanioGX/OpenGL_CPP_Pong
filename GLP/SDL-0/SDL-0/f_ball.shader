#version 330 core
out vec4 FragColor;
in vec4 OurColor;

void main()
{
    FragColor = vec4(OurColor.xyz/2+0.5,1.0);
}
