// stroke(vec2 xy, vec2 ab, vec2 cd, float o
// xy: vec2(x, y)
// ab: point 1
// cd: point 2
// o: stroke thickness

#ifdef GL_ES
precision highp float;
#endif

uniform vec2 u_resolution;

float stroke(vec2 xy, vec2 ab, vec2 cd, float o) {
    return step(xy.x*(ab.y-cd.y)/(ab.x-cd.x) + (ab.y*cd.x - cd.y*ab.x)/(cd.x-ab.x) - o*.5, xy.y)*
           (1.-step(xy.x*(ab.y-cd.y)/(ab.x-cd.x) + (ab.y*cd.x - cd.y*ab.x)/(cd.x-ab.x) + o*.5, xy.y))*
           step(ab.x, xy.x)*
           (1.-step(cd.x, xy.x));
}

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution;    
    vec3 color = vec3(0.);
    
    color += stroke(st, vec2(.2,.8),vec2(.7,.5), .01);
    
    
	gl_FragColor = vec4(color,1.);
}