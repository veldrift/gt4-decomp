/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk24 { int a,b,c; unsigned short d,e,f,g; int h; };
extern char SDDRV__VoiceSystem__master_[];
extern "C" float func_0055C5F0(void *, float);
extern "C" Blk24 *func_0055CE60(void *, int);
extern "C" void func_0055CC10(void *, int, Blk24 *);
extern "C" void func_00460ED8() {
    func_0055C5F0(SDDRV__VoiceSystem__master_,60.0f);
    int i=0;
    int color=0x1fffff;
    do {
        Blk24 b=*func_0055CE60(SDDRV__VoiceSystem__master_,i);
        b.c=4;
        b.d=0xfff;
        b.e=0xfff;
        b.g=0;
        b.f=0;
        b.b=0;
        b.a=1;
        b.h=color;
        color-=0x20000;
        func_0055CC10(SDDRV__VoiceSystem__master_,i,&b);
        ++i;
    } while(i<2);
}
