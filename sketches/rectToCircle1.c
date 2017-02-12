
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

float circleSDF(vec2 st) {
    return length(st-.5)*4.;
}

float fill(float sdf, float w) {
    return 1.-step(w,sdf);
}


vec2 rotate(vec2 st, float angle) {
    return (mat2(cos(angle), - sin(angle),
               sin(angle),cos(angle))*(st-.5)+.5);
}

void main() {
    vec3 color = vec3(.969,.769,.262);
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    if (u_resolution.y > u_resolution.x ) {
        st.y *= u_resolution.y/u_resolution.x;
        st.y -= (u_resolution.y*.5-u_resolution.x*.5)/u_resolution.x;
    } else {
        st.x *= u_resolution.x/u_resolution.y;
        st.x -= (u_resolution.x*.5-u_resolution.y*.5)/u_resolution.y;
    }
 
    float sdf_r = rectSDF(rotate(st, sin(u_time)*3.14),vec2(cos(u_time)));
    float sdf_c = circleSDF(st);
    float sdf = mix(sdf_r, sdf_c , cos(u_time)*.9);
    color += fill(sdf,.8);

    gl_FragColor = vec4(color,1.0);
}