#version 450 core

layout (location = 0) in vec4 in_Position;
layout (location = 1) in vec4 in_Color;

uniform mat4 modelScaleMatrix;
uniform mat4 modelRotationMatrix;
uniform mat4 modelTranslationMatrix;

uniform mat4 cameraRotationMatrix;
uniform mat4 cameraTranslationMatrix;

uniform mat4 projectionMatrix;

out vec4 vertexColor;

void main(){
    
    vec4 scaled = modelScaleMatrix * vec4(in_Position.xyz, 1.0);
    vec4 rotated = modelRotationMatrix * scaled;
    vec4 translated = modelTranslationMatrix * rotated;

    vec4 cameraTranslated = cameraTranslationMatrix * translated;
    vec4 view = cameraRotationMatrix * cameraTranslated;

    vec4 projected = projectionMatrix * view;
    
    if (projected.w != 0){
        gl_Position = vec4(projected.x / projected.w, projected.y / projected.w, projected.z / projected.w, 1);
    }
    else{
        gl_Position = vec4(projected.xyz, 1);
    }

    vertexColor = in_Color;
}