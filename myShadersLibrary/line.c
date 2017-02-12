// line(float y, float x, float o)
// y: y coordinate 
// x: x coordinate
// o: line thickness

#ifdef GL_ES
precision highp float;
#endif

uniform vec2 u_resolution;

float line(float y, float x, float o) {
    return step(x, y+o*.5)*(1.-step(x, y-o*.5));
}

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution;    
    vec3 color = vec3(0.);
    
    color += line(st.x, st.y, .01);
    
    // float x = sin(st.x*3.14);
    // float x = pow(st.x,.5);
    // float x = mod(st.x, .2);
    // float x = clamp(st.x, .3, .7);
    // color += line(x, st.y, .01);
    
	gl_FragColor = vec4(color,1.);
}