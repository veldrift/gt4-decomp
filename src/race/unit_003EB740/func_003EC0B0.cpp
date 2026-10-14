struct Object;struct Owner;struct Context{int enabled;char unknown4[0x28-4];};struct Font{char unknown[0x1c];float width,height,scaleX,scaleY;};extern Font*PDISTD__global_font_manager;
extern "C" {void func_004AB040(int);void func_004A29A8(int);void func_004A1638(int);void func_00490700(Font*,int,int,int,int);void func_004A3040(float,float,float,float);void func_004A2980(unsigned);void func_004A3230(int);void func_004A53F8();void func_004A2808(int,float);void func_00472DE8(Context*);void RaceEntryCar__update(int);void func_004A7454();void func_004A5A90(float,float,float,float,float,float);void func_004735A0(Context*);void func_004735C8(Context*);void func_00475CA0(Object*,Context*,unsigned);void func_004A5400();}
inline int rounded(float f){return (int)f;}
extern "C" void func_003EC0B0(Owner*,Object*object,unsigned color,int special){
 Context context;func_004AB040(5);func_004AB040(4);func_004AB040(3);func_004A29A8(0);func_004AB040(8);func_004A1638(6);
 Font*scaleFont=PDISTD__global_font_manager;*(float*)((char*)scaleFont+0x28)=1.0f;*(float*)((char*)scaleFont+0x24)=1.0f;func_00490700(PDISTD__global_font_manager,0,0,640,480);
 Font*font=PDISTD__global_font_manager;float savedWidth=font->width,savedHeight=font->height;font->width=640.0f;font->height=480.0f;int width=rounded(savedWidth),height=rounded(savedHeight);
 func_004A3040(0,0,0,0);func_004A2980(0xff000000);func_004A3230(1);func_004A2980(0xffffffff);func_004A53F8();func_004A2808(68,1);func_00472DE8(&context);RaceEntryCar__update(1);func_004A7454();func_004A5A90(0,640,480,0,-1,1);RaceEntryCar__update(0);func_004A7454();
 if(special)func_004735A0(&context);func_00475CA0(object,&context,color);if(special)func_004735C8(&context);func_004A5400();func_004AB040(5);func_004AB040(4);func_004AB040(3);func_004A29A8(1);Font*restore=PDISTD__global_font_manager;restore->width=(float)width;restore->height=(float)height;
}
