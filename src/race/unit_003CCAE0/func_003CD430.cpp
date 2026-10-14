struct Owner;struct Car;struct Header{char opaque[0x9680];int modes[0];};struct Database;
struct Control{float values[4];char opaque[32];};
struct Channel{float value;char opaque[0x174];};
struct Group{Channel channels[6];int size() const{return sizeof(channels)/sizeof(channels[0]);}};
struct Metric{float value;char opaque[0x9C];};
struct Self{Owner*owner;char opaque4[0x2C0];Control controls[0];};
extern "C" Car*func_0034C190(Owner*,int);
extern "C" void func_0040C090(Control*,Car*,int,float);
extern "C" int func_003CF5C8(Self*,int,Car*,int,int);
extern "C" Database*Pitmen__getMotion(Self*);
extern "C" int func_00429AD8(Database*,int,int,float*);
extern "C" void func_003D0DF0(Self*,int,int,Owner*);
extern "C" void func_003CB990(Header*,int,Self*,Owner*);
inline void set(Channel*channel,float value){channel->value=value;}
inline float scaleValue(const Self*self,int variant){int offset=variant*sizeof(Metric);const char*base=(const char*)self;const char*metric=base+offset;return *(const float*)(metric+0x78AC);}
extern "C" void func_003CD430(Self*self,int variant,Owner*owner){Car*car=func_0034C190(owner,variant);Header*header=(Header*)((char*)self+4);int mode=header->modes[variant];Group*group=((Group*)((char*)self+0x3E4))+variant;float scale=scaleValue(self,variant);
 if((unsigned)(mode-2)<3)func_0040C090(&self->controls[variant],car,1,scale);else func_0040C090(&self->controls[variant],car,0,scale);
 int i;if(mode==0){for(i=0;i<group->size();++i)set(&group->channels[i],0.0f);}
 else{i=0;char*source=(char*)self+0x38C4;Channel*channel=group->channels;for(;i<6;++i,source+=0xAA4,++channel){int key=func_003CF5C8(self,i,car,mode,variant);float value=0;Database*database=Pitmen__getMotion(self);func_00429AD8(database,*(int*)source,key,&value);channel->value=value;}
 for(i=0;i<=mode;++i)func_003D0DF0(self,variant,i,owner);
 }
 func_003CB990(header,variant,self,owner);
}
