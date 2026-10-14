struct TextureState{unsigned long regs[5];};
struct Resource{int address,size;TextureState*state;int active,owned;};
struct Self{char unknown0[0x88];char*data;int unknown8C;int rows,columns;};
extern "C" int func_0049B220(int,int,int,int*);
extern "C" void func_00107B98(Resource*);
extern "C" int func_00107B58(Resource*,int);
extern "C" unsigned char func_004A07F8();
extern "C" void func_004A4F48(unsigned,int,int,int,int,int,int,const void*);
extern "C" void func_004A50C0(unsigned,int,int,int,int,int,int,const void*);
extern "C" void func_004A2038(int);
extern "C" void func_004A4910();
extern "C" void func_00107DF8(Resource*);
extern "C" void pgluTexReset(TextureState*);
extern "C" void pgluTexImage(TextureState*,int,unsigned,unsigned,int);
extern "C" void func_0049AF00(TextureState*,int,int);
extern "C" void func_0049B148(TextureState*,int,unsigned,unsigned);
extern "C" void func_0049AFD0(TextureState*,unsigned,unsigned);
extern "C" void func_001FE5B0(Self*self,Resource*resource){int width;int size=func_0049B220(0,128,128,&width);func_00107B98(resource);if(func_00107B58(resource,size)<0)return;
unsigned address=resource->address;char*source=self->data+(self->columns*self->rows/4)*12;
int x,y;
if(func_004A07F8()){
 for(y=0;y<128;y+=16){for(x=0;x<self->columns;x+=16,source+=1024){if(x>=0){if(x<128)func_004A4F48(address,0,width,y,x,16,16,source);}}}
 func_004A2038(1);func_004A4910();
}else{
 for(y=112;y>=0;y-=16){for(x=0;x<self->columns;x+=16,source+=1024){if(x>=0){if(x<128)func_004A50C0(address,0,width,0,0,128,128,source);}}}
 func_004A4910();
}
func_00107DF8(resource);TextureState*state=resource->state;pgluTexReset(state);pgluTexImage(state,0,address,0,width);func_0049AF00(state,128,128);func_0049B148(state,0,0,127);func_0049B148(state,1,0,127);func_0049AFD0(state,4,1);func_0049AFD0(state,5,1);
}
