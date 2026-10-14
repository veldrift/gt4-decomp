/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Pair { s32 a,b; };
struct Entry { short delta,index; void (*fn)(void *); };
struct Model { char p0[0x4c]; void *f4c; char p50[0x64-0x50]; void (*f64)(); void *f68; void (*f6c)(); void *f70; s32 f74; char p78[0xa8-0x78]; Entry *vt; };
struct Obj { char p0[0x9c]; Pair f9c; char pa4[0xd8-0xa4]; Pair fd8; char pe0[8]; Model *fe8; char fec[0x150-0xec]; s32 f150,f154; char p158[0x164-0x158]; char f164[0x10]; s32 f174; char p178[0x18c-0x178]; char f18c[0x10]; s32 f19c; char p1a0[0x1b0-0x1a0]; s32 f1b0; char p1b4[0x1c8-0x1b4]; s32 loaded[2]; s32 f1d0,f1d4,f1d8; char p1dc[0x2a4-0x1dc]; char f2a4[0x864-0x2a4]; char f864[0x10]; char f874[0x10]; char f884[0x10]; s32 f894[2]; char p89c[8]; s32 f8a4; };
extern char D_0065B7E0[], D_0068FD88[];
struct Local { void *vt; char rest[0x58-4]; ~Local() { vt=D_0065B7E0; } };
extern "C" int func_00154C18(void *) throw();
extern "C" s32 func_00155448(void *,void *,void (*)(),void *) throw();
extern "C" s32 func_00450AD0(void *);
extern "C" char *func_00450B38(void *,s32);
extern "C" void func_00450CB8(void *,void *);
extern "C" void func_00453488(void *,s32);
extern "C" void *GT4Model__CarModel__getWheelFileName(void *,void *,s32);
extern "C" void func_004542D8(void *,s32,s32,s32,void *);
extern "C" void *GT4Model__CarModel__getTireFileName(void *,void *,s32);
extern "C" void *GT4Model__CarModel__getWingFileName(void *,void *,s32);
extern "C" void func_00459780(void *,void *);
extern "C" Model *func_004AE1F8(s32,void *);
extern "C" void free(s32) throw();
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" s32 func_0057F238(const char *,const char *) throw();
extern "C" void func_001550A0(); extern "C" void func_001550C0(); extern "C" void func_001550E0(); extern "C" void func_00155100(); extern "C" void func_00155120(); extern "C" void func_00155140();
static inline void vcall(Model *p) { Entry *e=p->vt+2; e->fn((char *)p+e->delta); }
extern "C" s32 func_00155510(Obj *self,s32 *request) {
    char path[0x40];
    char tire[0x10];
    void *data=request+1;
    s32 result=0;
    if (*request==2) {
        self->f174=0;
        func_00154C18(self->f164);
        char *lock=self->fec;
        func_00576788(lock);
        self->fe8=func_004AE1F8(0,data);
        if (self->fe8) {
            self->f150=1;
            func_00450AD0(self->f2a4);
            void *buf=(char *)self+0xa8;
            self->fd8=self->f9c;
            self->fe8->f74=0;
            self->fe8->f4c=buf;
            Model *p=self->fe8;
            p->f64=func_001550A0;
            p->f68=self;
            Model *p2=self->fe8;
            p2->f6c=func_001550C0;
            p2->f70=self;
            vcall(self->fe8);
            self->f154=1;
            result=1;
        }
        func_005767C0(lock);
    } else if (*request==4) {
        char *lock=self->fec;
        func_00576788(lock);
        result=func_00155448(self,data,func_001550E0,self);
        func_005767C0(lock);
    } else if (*request==5) {
        char *lock=self->fec;
        func_00576788(lock);
        result=func_00155448(self,data,func_00155100,self);
        func_005767C0(lock);
    } else if (*request==7) {
        if (self->f8a4) {
            func_00453488(self->f2a4,0);
            self->f19c=0;
            func_00154C18(self->f18c);
            char *lock=self->fec;
            func_00576788(lock);
            self->f19c=1;
            free(self->f8a4);
            self->f8a4=0;
            result=1;
            func_005767C0(lock);
        }
    } else if (*request==3) {
        char *lock=self->fec;
        func_00576788(lock);
        if (self->f1d0==0 && func_0057F238(self->f874,D_0068FD88)!=0) {
            GT4Model__CarModel__getWheelFileName(self->f874,path,1);
            result=func_00155448(self,path,func_001550E0,self);
        } else if (self->f1d4==0 && func_0057F238(self->f884,D_0068FD88)!=0) {
            GT4Model__CarModel__getWingFileName(self->f884,path,1);
            result=func_00155448(self,path,func_00155100,self);
        } else {
            s32 i;
            for (i=0;i<2;i++) {
                if (self->loaded[i]==0) {
                    s32 first=i==0;
                    char *name=func_00450B38(self->f2a4,first);
                    func_004542D8(self->f2a4,self->f894[i],first,0,tire);
                    if (func_0057F238(tire,name)!=0) {
                        GT4Model__CarModel__getTireFileName(tire,path,1);
                        result=func_00155448(self,path,i==0?func_00155120:func_00155140,self);
                        break;
                    }
                }
            }
            if (i==2) {
                Local l;
                func_00459780(&l,self->f864);
                func_00450CB8(self->f2a4,&l);
                self->f174=1;
                *(s32 *)((char *)self+0x188)=1;
                self->f19c=1;
                self->f1b0=1;
                self->f1d8=0;
                result=1;
            }
        }
        func_005767C0(lock);
    }
    return result;
}
