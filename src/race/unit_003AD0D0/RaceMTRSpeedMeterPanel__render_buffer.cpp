/* compiler: ee-gcc2.96-no-strict-aliasing */
struct TexData {char pad[0x20];unsigned long bits;};
struct Tex {char pad[0x18];TexData *data;};
struct Self {char pad[0x18];Tex *tex,*tex2;int speed;char pad24[8];int tw,th,flag;};
struct Buffer {int id,flags;};
struct Font {int unk,flags;float x,y;char pad10[8];float sx,sy;};
extern Font D_00623838;extern char D_006A1460[],D_006A1430[],D_006A1438[];
extern "C" void func_001055C0(void*),func_00105460(void*,int,int),func_001056A0(void*);
extern "C" int func_00105528(void*);
extern "C" void pglPushAttrib(int),func_004A2980(int),func_004A3078(int),func_004A3230(int),func_004A5688(),func_004AA168(unsigned),func_004A1638(int),func_004AB040(int),func_004A29A8(int),func_004A2808(int,float),RaceEntryCar__update(int),func_004A53F8(),func_004A7454(),func_004A5400();
extern "C" void func_004A5A90(float,float,float,float,float,float),func_004AA1D8(float,float,float,float),func_003AF4F8(Tex*,float,float,float,float,int,int),func_004A2750(int,float),func_004A27C8(int);
extern "C" void func_0044E390(Font*,float,float),func_0044D9B8(Font*,const char*),func_0044D950(Font*),func_0044D988(Font*),func_0044DE80(Font*,unsigned),func_0044E088(Font*,const char*,...);
extern "C" int func_0044E3B0(Font*,int,int);
extern "C" float func_0044DFC8(Font*,const char*);
extern "C" unsigned func_003AFEC8(unsigned,float);
extern char D_006A1420[],D_006A17F0[];
extern "C" void RaceMTRSpeedMeterPanel__init_texset(Self*);
extern "C" int func_0044E3F8(Font*);
extern "C" unsigned RaceDisplayUtil__getScaledColor(unsigned,float,float);
extern "C" void RaceMTRSpeedMeterPanel__render_buffer(Self *self,Buffer *buf) {
 Font *font=&D_00623838;float one=1.0f;
 pglPushAttrib(1);RaceMTRSpeedMeterPanel__init_texset(self);
 float sx=font->sx;float sy=font->sy;
 func_0044E390(font,one,one);func_0044D9B8(font,D_006A1420);
 if(self->tw==0){self->tw=(int)func_0044DFC8(font,D_006A1430);self->th=func_0044E3F8(font);}
 int h=self->th+3;
 unsigned long bits=self->tex->data->bits;
 int texH=(int)(((bits>>34)&0x3FF)+1),texW=(int)(((bits>>14)&0x3FF)+1);
 int w=texW+self->tw;
 if(h<texH)h=texH;
 if(buf->id==-1){func_00105460(buf,w,h);buf->flags=0;func_00105528(buf);}
 func_001056A0(buf);func_004A2980(-1);func_004A3078(0);func_004A3230(1);
 float fw=(float)w;
 func_004AA168(0x80FFFFFF);func_004A1638(6);func_004A1638(4);func_004AB040(15);func_004AB040(5);func_004A29A8(0);
 float fh=(float)h;
 func_004A2750(6,0.0f);func_004A27C8(0);func_004A2808(0x44,0.0f);RaceEntryCar__update(1);func_004A53F8();func_004A7454();
 func_004A5A90(0.0f,fw,fh,0.0f,-1.0f,1.0f);RaceEntryCar__update(0);func_004A53F8();func_004A7454();
 float x=(float)(w-texW),y=(float)(h-texH);
 func_003AF4F8(self->tex,x,y,fw,fh,0,0);
 float lit=self->flag?1.0f:0.0f;
 func_004AA168(RaceDisplayUtil__getScaledColor(0x800000FF,lit,1.0f));
 func_003AF4F8(self->tex2,x,y,fw,fh,0,0);
 func_0044E3B0(&D_00623838,w,h);func_0044D950(&D_00623838);func_0044DE80(&D_00623838,0x80E3B896);
 D_00623838.flags=4;D_00623838.y=D_00623838.x=0.0f;
 func_0044E088(&D_00623838,D_006A17F0,self->speed<0?-self->speed:self->speed);
 D_00623838.flags=0;func_0044D988(&D_00623838);
 func_004AB040(4);func_004A5400();RaceEntryCar__update(1);func_004A5400();RaceEntryCar__update(0);
 func_0044E390(&D_00623838,sx,sy);func_004A5688();
}
