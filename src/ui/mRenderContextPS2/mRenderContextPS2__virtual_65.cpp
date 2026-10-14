/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z,w; Vec() {} Vec(float a,float b,float c,float d) {x=a;y=b;z=c;w=d;} };
struct Buf { int a,b,tex; char pad[0x34]; };
struct Entry { short delta,index; void (*fn)(void *); };
struct Entry3 { short delta,index; void (*fn)(void *,Vec *,Vec *); };
struct Entry1 { short delta,index; void (*fn)(void *,int); };
struct Obj { int a; char *vt; char pad[0x40]; char *vt48; };
struct Camera { float a,b,n,f; };
struct Tex { char pad[0x18]; int tex; };
extern "C" {
void func_00105708(void *); void func_00107328(void *);
void func_00107AE8(void *); void func_00107B00(void *,int);
void func_00107BE8(void *,void *); void func_001FE5B0(void *,void *);
float func_00201FA0(void *); Vec *func_0021A760(void *);
Camera *func_0021A798(void *); Obj *func_0021A7C8(void *);
void func_0022A910(void *,void *); void *func_002314E8(void *);
void func_0049CE68(int); void func_004A1638(int); void func_004A26F0(int);
void func_004A2808(int,float); void func_004A2930(int,int,int,int);
void func_004A29A8(int); void func_004A3230(int); void func_004A4550(int,int);
void RaceEntryCar__update(int); void func_004A53F8(); void func_004A5400();
void pglPushAttrib(int); void func_004A5688();
void func_004A59B8(float,float,float,float,float,float,float);
void func_004A7454(); void func_004AA4A0(); void func_004AB040(int);
float func_0057D380(float);
extern char D_00618E40[],D_006184D0[];
struct Global { char pad[0xf8]; char buf[0x40]; };
extern Global D_0061850C;
}
extern "C" void mRenderContextPS2__virtual_65(Obj *self,Obj *o) {
 Vec zero(0.0f,0.0f,0.0f,0.0f);
 Vec v; Vec *p=&v;
 Vec *q=func_0021A760(o);
 p->x=q->x;p->y=q->y;p->z=q->z;p->w=q->w;
 v.y=v.x=0.0f;
 func_0022A910(p,func_002314E8(self));
 Entry3 *e3=(Entry3 *)(self->vt+0x1f8);
 e3->fn((char *)self+e3->delta,&zero,p);
 Entry *e;
 func_004AA4A0();pglPushAttrib(0x887);func_004AB040(8);
 func_004A1638(5);func_004A26F0(3);func_004A1638(100);
 func_004A4550(1,0);func_004A2930(1,1,1,0);func_004AB040(4);
 Global *g=&D_0061850C;func_00105708(g->buf);func_004A1638(5);func_004A29A8(1);func_004A3230(2);
 Buf b;func_00107AE8(&b);
 Obj *r=func_0021A7C8(o);
 if(r) {
  Entry *t=(Entry *)(r->vt+0x80);
  Tex *tex=((Tex *(*)(void *))t->fn)((char *)r+t->delta);
  func_00107BE8(&b,tex);func_0049CE68(tex->tex);
 } else {func_001FE5B0(D_00618E40,&b);func_0049CE68(b.tex);}
 Camera *c=func_0021A798(o);RaceEntryCar__update(1);func_004A53F8();func_004A7454();
 float n=c->n;float f=c->f;
 float h=v.w*0.5f;float x=v.x+v.z*0.5f;float y=v.y+h;
 func_004A59B8(-x,640.0f-x,y-480.0f,y,n,f,h/func_0057D380(func_00201FA0(c)*0.5f*3.14159265f/180.0f));
 func_00107328(D_006184D0);RaceEntryCar__update(0);func_004A53F8();func_004A7454();
 Entry *e18=(Entry *)(o->vt48+0x18);e18->fn((char *)o+e18->delta);
 func_004A53F8();
 Entry1 *e1=(Entry1 *)(o->vt48+0x10);e1->fn((char *)o+e1->delta,0);
 Entry *e20=(Entry *)(o->vt48+0x20);e20->fn((char *)o+e20->delta);
 Entry1 *e28=(Entry1 *)(o->vt48+0x28);e28->fn((char *)o+e28->delta,0);
 func_004A5400();RaceEntryCar__update(0);func_004A5400();RaceEntryCar__update(1);func_004A5400();func_0049CE68(0);
 func_00105708(D_006184D0+0x134);func_004A1638(6);func_004A2808(0x44,1.0f);
 func_004AB040(5);func_004AB040(4);func_004AB040(100);func_004A29A8(0);func_004A5688();
 func_004A2930(1,1,1,0);func_00107B00(&b,2);
}
