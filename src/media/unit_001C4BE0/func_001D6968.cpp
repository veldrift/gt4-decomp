/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Tex { int v[16]; };
struct Obj { char pad[8]; void *other; char fields[0x2c]; void *renderer; void *data; };
extern "C" {
void func_00105280(void *,int);
int func_001052E0(void *,int,int,int);
void *func_00105378(void *,void *);
void func_001054A0(void *,int);
void func_001056A0(void *);
void func_00105728(void *);
int func_00105818(void *);
void func_001D60A0(void *,void *,void *,float) throw();
void func_001D61D8(void *) throw();
void func_001D68B8(void *,void *,float,float) throw();
void func_00452008(void *,void *,int,void *,float);
void func_004523E8(float,float,float,float);
void func_004567F0(int);
void func_00459780(void *,void *);
void func_004A1638(int);
void func_004A2808(int,float);
void func_004A2980(int);
void func_004A3078(int);
void func_004A3230(int);
void func_004A4550(int,int);
void func_004A53F8();
void func_004A5400();
void func_004A6498(int,int,int,int,int,int,int,int);
void func_004A7698(void *);
void func_004AA1D8(float,float,float,float);
void func_004AB040(int);
}
extern int D_006956B8[];
extern char D_006956D8[],D_0065B7E0[];
extern "C" void func_001D6968(Obj *self,void *unused,Tex *tex,int index,float x,float alpha) {
 Tex small;
 int offset=index*4;
 int base=(int)self+12;
 float opacity=*(float *)(offset+base+0x180)*alpha;
 if(opacity<0.0078125f) return;
 int width=tex->v[2]/2;
 func_001052E0(&small,0,width,func_00105818(tex)/2);
 func_001054A0(&small,tex->v[10]);
 func_001056A0(&small);
 func_004A3078(0);func_004A3230(1);func_004567F0(0);
 {
 float matrix[16]; float vec[4]; int render[24];
 for(int i=0;i<6;i++) {
 int i64=index*64;
 func_004A2980(0x01000000 << (7-i));
 float fi=(float)(i+10);
 int o=offset+0x170;
 float f=*(float *)(base+o);
 float scale=fi*0.0625f*f;
 func_004A53F8();
 func_001D68B8(vec,(char *)self+i64+0x7c,scale,x+(float)D_006956B8[i]*0.125f);
 func_001D60A0(matrix,vec,D_006956D8,1.0f);
 func_004A7698(matrix);func_001D61D8(self);
 int *pr=render;
 func_00459780(pr,self->data);
 func_004523E8(0,0,0,0.9921875f);
 func_00452008(self->renderer,pr,1,self->other,0);
 pr[0]=(int)D_0065B7E0;
 func_004A5400();
 }
 }
 func_004A4550(1,0);func_004AB040(5);func_004AB040(4);func_004A1638(6);
 func_004A2980(0xffffff);func_004A2808(0x44,1.0f);func_004A4550(3,1);func_004A4550(2,1);
 Tex copy;
 func_00105378(&copy,tex);func_001054A0(&copy,0);func_001056A0(&copy);
 func_004AA1D8(0,0,0,opacity);func_00105728(&small);
 int width2=copy.v[2];
 func_004A6498(0,0,width2,func_00105818(&copy),0,0,small.v[4]+small.v[6],small.v[5]+small.v[7]);
 func_001056A0(tex);func_004567F0(1);func_00105280(&copy,2);func_00105280(&small,2);
}
