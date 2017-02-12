// point(vec2 st)
// st: vec2(x, y)

#ifdef GL_ES
precision highp float;
#endif

uniform vec2 u_resolution;

float point(vec2 st) {
    return step(.002,length(st-.5));
}

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution;    
    vec3 color = vec3(0.);
    
    color += point(st);
    
	gl_FragColor = vec4(color,1.);
}