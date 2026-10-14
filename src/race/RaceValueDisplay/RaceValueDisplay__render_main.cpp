/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Image { char pad[0x20]; unsigned long bits; };
struct Texture { char pad[0x18]; Image *image; };
struct Self { unsigned char active,fx,fy,pad3; short x,y,dx,dy; float alpha; char pad10[8]; int color,secondary; Texture *tex; float cached,pulse; char pad2c[0x18]; signed char tx,ty; char suffix[0x22]; char font[0x20]; char *text; float minimum,gap; };
extern char D_00623838[];
extern char D_006A1460[];
extern "C" {
void func_003AEF18(Texture*,float,float,unsigned,unsigned);
int func_003AFD78(int,int,int);
int func_003AFEC8(int,float);
void func_0044D920(void*,void*);
void func_0044D988(void*);
float func_0044DC30(void*);
void func_0044DDF8(void*,float,float,float);
void func_0044DE80(void*,unsigned);
float func_0044DFC8(void*,void*);
void func_0044E030(void*,void*);
void func_004AA1D8(float,float,float,float);
}
extern "C" void RaceValueDisplay__render_main(Self *s) {
 float width,y;
 float one=1.0f;
 float scale;
 float zero=0.0f;
 float *pulse=&s->pulse;
 int initialColor=func_003AFEC8(s->color,s->alpha * *pulse);
 void *o=D_00623838;
 func_0044DE80(o,initialColor);
 func_0044D920(o,s->font);
 scale=one / func_0044DC30(o);
 char *text=s->text;
 width=func_0044DFC8(o,text);
 int x=func_003AFD78(s->x,(int)width,s->fx);
 y=(float)s->y;
 func_0044DDF8(o,(float)x,y,zero);
 func_0044E030(o,text);
 __asm__("max.s %0, %0, %1":"+f"(width):"f"(s->minimum));
 width+=s->gap;
 width=(float)func_003AFD78(s->x,(int)width,s->fx);
 if(s->tex) {
  func_0044D988(o);
  float factor=*pulse;
  float alpha=s->alpha;
  func_004AA1D8(one,one,one,alpha*factor);
  func_003AEF18(s->tex,width+(float)(s->dx+s->tx),(float)(s->y+s->dy+s->ty),1,1);
  width-=(float)(int)(((s->tex->image->bits>>14)&1023)+1);
 }
 func_0044D920(o,D_006A1460);
 char *suffix;
 if(s->cached==zero) {
 suffix=s->suffix;
 s->cached=func_0044DFC8(o,suffix)*scale;
 } else suffix=s->suffix;
 int color=s->secondary;
 if(color==0) color=s->color;
 func_0044DE80(o,func_003AFEC8(color,s->alpha * *pulse));
 func_0044DDF8(o,width-s->cached,y,0.0f);
 func_0044E030(o,suffix);
 func_0044D988(o);
}
