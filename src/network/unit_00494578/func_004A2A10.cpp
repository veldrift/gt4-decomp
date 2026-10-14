/* compiler: ee-gcc2.96-nogcse */
#include "spr.h"
struct Scratch { char pad[7]; char mode; char pad8[0x2b8]; char alt; char flag; };
extern "C" int func_004A2B58(float,float,float,float);
extern "C" int func_004A2A10(int type) {
    Scratch *s=(Scratch *)spr_base();
    int alt=s->alt;
    float x=0.0f, y=0.0f;
    int four=4;
    int mode=3;
    s->flag=0;
    if(alt) mode=four;
    float h=0.5f;
    switch(type) {
    case 0: case 5: case 6: case 7: case 8: default:
        h=1.0f; s->mode=0; break;
    case 1:
        y=mode==3 ? 0.0f : 0.5f; s->mode=1; break;
    case 2:
        y=mode==3 ? 0.5f : 0.0f; s->mode=1; break;
    case 3: s->mode=1; break;
    case 4: y=0.5f; s->mode=1; break;
    case 9:
        y=mode==3 ? 0.0f : 0.5f; s->mode=0; s->flag=1; break;
    }
    return func_004A2B58(x,y,1.0f,h);
}
