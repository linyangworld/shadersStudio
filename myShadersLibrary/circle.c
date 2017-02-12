#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform float u_time;

float circle(vec2 st) {
    return length(st-.5)*4.;
}

float fill(float sdf, float w) {
    return 1.-step(w,sdf);
}


void main() {
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    st.x *= u_resolution.x/u_resolution.y;
    vec3 color = vec3(.0); 
    
	color += fill(circle(st), 0.716);
    
    gl_FragColor = vec4(color,1.0);
}
