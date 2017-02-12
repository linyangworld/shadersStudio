#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

float rectSDF(vec2 st, vec2 s) {
    st = st*2.-1.;
    return max( abs(st.x/s.x),
                abs(st.y/s.y));
}

float fill(float sdf, float w) {
    return 1.-step(w,sdf);
}


void main() {
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    st.x *= u_resolution.x/u_resolution.y;
    vec3 color = vec3(.0); 
    
	color += fill(rectSDF(st,vec2 (0.8)), .5);
    

    gl_FragColor = vec4(color,1.0);
}
