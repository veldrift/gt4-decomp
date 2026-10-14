/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct V4 { f32 x; f32 y; f32 z; f32 w; };
extern V4 D_006DE918;
extern V4 D_006DE928;
extern V4 D_006DE938;
extern char D_006DE948[], D_006DE998[], D_006DE9E0[], D_006DEA18[], D_006DEA50[], D_006DEAB8[];
extern char D_00618430[];

extern "C" void func_001043C0(void *, void *);
extern "C" void func_00104420(void *, s32);
extern "C" void func_00104538(void *);
extern "C" void func_00104568(void *, s32);
extern "C" void func_00104630(void *, void *, s32);
extern "C" void func_001046E0(void *, s32) throw();
extern "C" void func_001049A0(void *);
extern "C" void func_001049F8(void *, s32);
extern "C" void func_00104D28(void *);
extern "C" void func_00104D60(void *, s32);

static inline void vec(V4 *const p, float a, float b, float c, float d) {
 p->x=a; p->y=b; p->z=c; p->w=d;
}
extern "C" void func_00104F80(s32 init, s32 prio) {
 if(prio==65535 && init==1) vec(&D_006DE918,0,0,0,1);
 if(prio==65535 && init==1) vec(&D_006DE928,0.8f,0.8f,0.8f,1);
 if(prio==65535 && init==1) vec(&D_006DE938,1,1,1,1);
 if(prio==65535 && init==1) func_00104630(D_00618430,&D_006DE918,1);
 if(prio==65535 && init==1) func_001049A0(D_006DE948);
 if(prio==65535 && init==1) func_001043C0(D_006DE998,&D_006DE918);
 if(prio==65535 && init==1) func_00104D28(D_006DE9E0);
 if(prio==65535 && init==1) func_00104538(D_006DEA18);
 if(prio==65535 && init==1) func_00104630(D_006DEA50,&D_006DE928,0);
 if(prio==65535 && init==1) func_001043C0(D_006DEAB8,&D_006DE928);
 if(prio==65535 && init==0) func_00104420(D_006DEAB8,2);
 if(prio==65535 && init==0) func_001046E0(D_006DEA50,2);
 if(prio==65535 && init==0) func_00104568(D_006DEA18,2);
 if(prio==65535 && init==0) func_00104D60(D_006DE9E0,2);
 if(prio==65535 && init==0) func_00104420(D_006DE998,2);
 if(prio==65535 && init==0) func_001049F8(D_006DE948,2);
 if(prio==65535 && init==0) func_001046E0(D_00618430,2);
}
