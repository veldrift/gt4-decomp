extern "C" void* func_005A48D8(void*,int,unsigned int);
extern "C" int func_0052F8E0(void*);
extern "C" unsigned char* D_0064B47C;
extern "C" int func_00533650(unsigned char* self){
 if(!self)return 23;
 func_005A48D8(self,0,0x13c);
 *(int*)(self+4)=64;
 *(int*)(self+8)=0;
 unsigned char* manager=D_0064B47C;
 *(int*)(self+0xa4)=0;
 int count=*(int*)(manager+0x6c);
 *(int*)(self+0xac)=0;
 ++count;
 *(int*)(self+0xb4)=0;
 *(int*)(self+0x138)=count;
 *(int*)(self+0xbc)=0;
 *(int*)(self+0xc4)=0;
 *(int*)(self+0xc8)=0;
 func_0052F8E0(self+0xcc);
 *(int*)self=1;
 return 0;
}
