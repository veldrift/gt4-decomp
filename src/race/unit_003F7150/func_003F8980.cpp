extern "C" int func_003F8818(void*,int);
extern "C" void func_003F88E8(void*),func_00343D78(void*,int),func_0035DF80(void*,int,int,int);
struct Pair{int low,high;void set(int a,int b){low=a;high=b;}};
extern "C" void func_003F8980(unsigned char* self,unsigned char* object,int kind){
 unsigned char* view=object+0x104;
 unsigned char* owner=*(unsigned char**)self;
 if(*(signed char*)(view+0x466)==2)return;
 switch(kind){case 3:case 4:case 6:{int mode=func_003F8818(self,1);if(!self[0xf858]&&mode==3)mode=1;func_003F88E8(self);func_00343D78(object,mode);break;}default:func_003F88E8(self);func_00343D78(object,2);break;}
 if(*(int*)(owner+0xdc)||view[0x441]||*(int*)(owner+0xf0))return;
 func_0035DF80(owner,10,view[0x440],0);
 if(!self[0xcbdc])((Pair*)(owner+0x88))->set(-1,0x157529ff);
}
