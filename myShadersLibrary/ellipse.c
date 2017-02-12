// ellipse(vec2 st, float d, float o) 
// st: vec2(x, y)
// d: diameter
// o: outline thinkness

#ifdef GL_ES
precision highp float;
#endif

uniform vec2 u_resolution;

float ellipse (vec2 st, float d, float o) {
    return (1.-step(d, length(st-.5) * 2.))*
           step(d-o*2.,length(st-.5)*2.);
}

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution;    
    vec3 color = vec3(0.);
    
    color += ellipse(st, .5, 0.01);
    
	gl_FragColor = vec4(color,1.);
}