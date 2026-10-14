/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
struct Glyph { char pad[16]; unsigned char w,h; signed char x,y; unsigned char advance; };
struct State { char pad[0x14]; Glyph *glyph; void *image; float width,height,sx,sy; int p2c; float x,y; char p38[0x10]; int color; char p4c[8]; float dx,dy; char p5c[12]; int wrap; int p6c; float shadow; int p74; int flag; char p7c[0x24]; int code; };
extern int D_00624988;
extern "C" bool func_00490660(State *,float);
extern "C" void func_00490760(State *);
extern "C" void func_00491F98();
extern "C" void func_004923F8(void *,float,float,float,float);
typedef void (*Draw)(void *,int,float,float,float,float);
extern "C" int func_004924C0(int code, Draw draw, State *s) {
 float x,y,right,bottom;
 Glyph *g=s->glyph;
 int bold=s->flag!=0;
 float ox=(float)(g->x+bold);
 float oy=(float)g->y;
 float w=(float)g->w;
 float sx=s->sx;
 float bx=s->x;
 float sy=s->sy;
 x=bx+ox*sx;
 y=s->y+oy*sy;
 right=x+w*sx;
 bottom=y+((float)g->h)*sy;
 void *image=s->image;
 if(draw && image && x+s->dx<s->width && right+s->dx>0.0f && y+s->dy<s->height && bottom+s->dy>0.0f) {
  float shadow=s->shadow;
  if(shadow>0.0f) {
   int old=D_00624988;
   D_00624988=s->color;
   func_00491F98();
   draw(image,code,x+shadow,y+shadow,right+shadow,bottom+shadow);
   D_00624988=old;
   func_00491F98();
   func_004923F8(image,x,y,right,bottom);
  } else draw(image,code,x,y,right,bottom);
 }
 if(!func_00490660(s,(float)g->advance*sx) && s->wrap) {
  int c=s->code;
  if(code!=0xff63 && (unsigned)(c-0x3001)>=2 && c!=0x300c && c!=0x3083 && c!=0x3085 && c!=0x3087 && c!=0x3063 && c!=0xff0c && c!=0xff0d && c!=0x2e && c!=0x2c && c!=0x27) func_00490760(s);
 }
 s->flag=0;
 return 0;
}
