#version 450 core

layout (location = 0) in vec4 in_Position;

uniform mat4 modelScaleMatrix;
uniform mat4 modelRotationMatrix;
uniform mat4 modelTranslationMatrix;

uniform mat4 cameraRotationMatrix;
uniform mat4 cameraTranslationMatrix;

uniform mat4 projectionMatrix;

out vec4 worldPos;

void main(){
    
    vec4 scaled = modelScaleMatrix * in_Position;
    vec4 rotated = modelRotationMatrix * scaled;
    vec4 translated = modelTranslationMatrix * rotated;

    worldPos = translated;

    vec4 cameraTranslated = cameraTranslationMatrix * translated;
    vec4 view = cameraRotationMatrix * cameraTranslated;

    vec4 projected = projectionMatrix * view;
    
    if (projected.w != 0){
        gl_Position = vec4(projected.x / projected.w, projected.y / projected.w, projected.z / projected.w, 1);
    }
    else{
        gl_Position = vec4(projected.xyz, 1);
    }
}
