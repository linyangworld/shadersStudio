// rect(vec2 xy, float w, float h, float o)
// xy: vec2(x, y)
// w: width
// h: height
// o: outline thickness

#ifdef GL_ES
precision highp float;
#endif

uniform vec2 u_resolution;

float rect(vec2 xy, float w, float h, float o) {
    return step(.5-w*.5, xy.x)*(1.-step(.5+w*.5, xy.x))*step(.5-h*.5, xy.y)*(1.-step(.5+h*.5, xy.y))*
           (1.-step(.5-w*.5+o, xy.x)*(1.-step(.5+w*.5-o, xy.x))*step(.5-h*.5+o, xy.y)*(1.-step(.5+h*.5-o, xy.y)));
}

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution;    
    vec3 color = vec3(0.);
    
    color += rect(st, .8, .4, .01);
    
	gl_FragColor = vec4(color,1.);
}