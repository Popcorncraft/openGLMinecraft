#version 450 core

in vec4 vertexColour;

out vec4 fragColor;

void main(){
    fragColor = vertexColour;
}