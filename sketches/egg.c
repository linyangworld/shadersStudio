// Author: Lin Yang
// Title: egg

#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;


float circleSDF(vec2 st) {
    return length(st-.5)*6.;
}

float fill(float sdf, float w) {
    return 1.-step(w,sdf);
}


void main() {
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    vec3 color = vec3(.969,.769,.262);
    if (u_resolution.y > u_resolution.x ) {
        st.y *= u_resolution.y/u_resolution.x;
        st.y -= (u_resolution.y*.5-u_resolution.x*.5)/u_resolution.x;
    } else {
        st.x *= u_resolution.x/u_resolution.y;
        st.x -= (u_resolution.x*.5-u_resolution.y*.5)/u_resolution.y;
    } 
 
    st.x += cos(u_time+st.y*8.)*.035;
    st.y += cos(u_time+st.y*2.)*.01;
    
    float c = circleSDF(st);
    color += fill(c,1.);

    gl_FragColor = vec4(color,1.0);
}