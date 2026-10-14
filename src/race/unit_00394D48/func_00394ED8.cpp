/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long u64;
struct Spec { char pad[0xb0]; };
struct Rec { char pad[0x14]; unsigned char valid; char tail[0xb]; };
struct Block { int a,b,flag; };
struct Obj { char *base; void *course; char pad[0x14]; Block block; char tail[0x88]; int section; };
extern char RaceCourse__model_arena_[];
extern int D_006214D0, D_006214D4;
extern "C" void func_00446F90(Spec *);
extern "C" int SPEC_DATABASE__RaceSpec__setCourse(Spec *,u64);
extern "C" char *func_004638D8(void *,int);
extern "C" bool func_00447F48(u64,Rec *);
extern "C" unsigned char func_00447FD0(Rec *);
extern "C" void func_003D5920(Block *,int,char *,int);
extern "C" int func_003D59F8(Block *);
extern "C" int func_00447730(Spec *);
extern "C" void *func_003978F8(u64,char *,int);
extern "C" void func_00396298(void *);
extern "C" unsigned short RaceCourse__getSectionCount(Obj *);
extern "C" void func_00446FC8(Spec *,int);
extern "C" void func_00394ED8(Obj *o,u64 id) {
    Spec spec;
    Rec rec;
    int size;
    char *base;
    if(o->course == 0) {
        func_00446F90(&spec);
        size=0xbc8000;
        SPEC_DATABASE__RaceSpec__setCourse(&spec,id);
        base=func_004638D8(RaceCourse__model_arena_,0);
        o->base=base;
        if(func_00447F48(id,&rec)) {
            if(rec.valid) {
                if(func_00447FD0(&rec)==2) {
                    Block *p=&o->block;
                    func_003D5920(p,D_006214D4,base,0x100000);
                    p->flag=0;
                } else {
                    Block *p=&o->block;
                    func_003D5920(p,D_006214D0,base,0x100000);
                    p->flag=1;
                }
                base+=0x100000;
                size=0xac8000;
            } else {
                func_003D59F8(&o->block);
            }
        }
        void *c=func_003978F8((u64)(unsigned int)func_00447730(&spec),base,size);
        o->course=c;
        func_00396298(c);
        if(o->section >= RaceCourse__getSectionCount(o)) o->section=-1;
        func_00446FC8(&spec,2);
    }
}
