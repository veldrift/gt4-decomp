/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Image { char pad[0x20]; unsigned long bits; };
struct Texture { char pad[0x18]; Image *image; };
struct Obj { int a,mode; };
struct Display {
 unsigned char a,flags; short p2,x,y,dx,dy; float alpha;
 char pad10[8]; unsigned color, color2; Texture *texture; float width, fade;
 char pad2c[0x18]; signed char tx,ty; char text[0x22]; int count,total;
};
extern "C" {
extern Obj D_00623838;
extern char D_006A1460[],D_006A1468[],D_006A1488[];
unsigned func_003AFEC8(unsigned,float);
void func_0044DE80(Obj*,unsigned);
void func_0044D920(Obj*,char*);
void func_0057DA20(char*,char*,...);
float RaceDisplayUtil__wideOffset(int);
void func_0044DDF8(Obj*,float,float,float);
void func_0044E088(Obj*,const char*,...);
float func_0044DC30(Obj*);
float func_0044DFC8(Obj*,char*);
void func_0044D988(Obj*);
void func_004AA1D8(float,float,float,float);
void func_003AEF18(Texture*,float,float,unsigned,unsigned);
void func_0044E030(Obj*,char*);
}
static inline float maxf(float a,float b) { float r; __asm__("max.s %0, %1, %2":"=f"(r):"f"(a),"f"(b)); return r; }
extern "C" void RaceCountDisplay__render_main(Display *d) {
 char buf[32];
 float *fade=&d->fade;
 func_0044DE80(&D_00623838,func_003AFEC8(d->color,d->alpha * *fade));
 D_00623838.mode=2;
 func_0044D920(&D_00623838,D_006A1460);
 int count=d->count;
 if(count>99999999) { d->count=99999999; count=99999999; }
 int total=d->total;
 if(total>99999999) { d->total=99999999; total=99999999; }
 if(total<=0) func_0057DA20(buf,D_006A1468,count,total);
 else func_0057DA20(buf,D_006A1488,count,total);
 Obj *o=&D_00623838;
 float width=(float)d->x;
 float x=width+RaceDisplayUtil__wideOffset(d->flags);
 float y=(float)d->y;
 func_0044DDF8(o,x,y,0.0f);
 func_0044E088(o,buf);
 float scale=1.0f / func_0044DC30(o);
 width=maxf(func_0044DFC8(o,buf)*scale,90.0f)+10.0f;
 if(d->texture) {
 func_0044D988(o);
 float opacity = *fade;
 float alpha = d->alpha;
 func_004AA1D8(1.0f,1.0f,1.0f,alpha * opacity);
 func_003AEF18(d->texture,(x-(float)(int)width)+(float)d->dx+(float)d->tx,(float)(d->y+d->dy+d->ty),1,1);
 width+=(float)(int)(((d->texture->image->bits >> 14)&0x3ff)+1);
 }
 func_0044D920(o,D_006A1460);
 if(d->width==0.0f) d->width=func_0044DFC8(o,d->text)*scale;
 unsigned c=d->color2;
 if(c==0) c=d->color;
 func_0044DE80(o,func_003AFEC8(c,d->alpha * *fade));
 func_0044DDF8(o,(x-width)-d->width,y,0.0f);
 func_0044E030(o,d->text);
 o->mode=0;
 func_0044D988(o);
}
