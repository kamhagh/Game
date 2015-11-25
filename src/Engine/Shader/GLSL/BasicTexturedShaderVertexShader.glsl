#version 430

in layout(location = 0) vec3 vertexPosition;
in layout(location = 1) vec2 vertexTexture;

out vec3 theColor;
out vec2 theTexture;

void main(){
	
	gl_Position = vec4(vertexPosition,1.0);
	theTexture = vertexTexture;

};