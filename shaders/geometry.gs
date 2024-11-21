#version 450 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

in vec4 worldPos[];

out vec4 vertexColour;

void main(){
    vec3 worldNormal = normalize(cross(normalize(worldPos[1].xyz - worldPos[0].xyz), normalize(worldPos[2].xyz - worldPos[0].xyz)));
    float grayscale = (dot(worldNormal, normalize(vec3(0.25, 0.75, 0.1))) + 1) / 2;
    //vertexColour = vec4(grayscale, grayscale, grayscale, 1);
    vertexColour = debugColor[0];

    vec3 normal = normalize(cross(normalize(gl_in[1].gl_Position.xyz - gl_in[0].gl_Position.xyz), normalize(gl_in[2].gl_Position.xyz - gl_in[0].gl_Position.xyz)));
    if (dot(normal, vec3(0, 0, 1)) < 0){
        if (gl_in[0].gl_Position.z > 0 || gl_in[0].gl_Position.z > 0 || gl_in[0].gl_Position.z > 0){
            for(int i = 0; i < 3; i++){
                gl_Position = gl_in[i].gl_Position;
                EmitVertex();
            }
        }
    }
    EndPrimitive();
}