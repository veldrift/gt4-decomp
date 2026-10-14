/* compiler: ee-gcc2.96-as2004 */
typedef unsigned long long U64 __attribute__((aligned(4)));
struct Result { int a[4]; };
struct Entry { unsigned char state; char pad[3]; U64 key; char padc[16]; void (*callback)(int,Result*,int); };
struct API { char pad[0x7c]; void (*get)(Result *,U64); };
struct Alloc { char pad[0x14]; unsigned int (*release)(void); };
extern Entry D_00868848[256];
extern API *D_0064B4B0;
extern Alloc *D_0064B4A8;
extern int D_0064B4EC;
extern "C" int func_00535780(unsigned int) throw();
extern "C" void *func_005A48D8(void*,int,unsigned int);
extern "C" int func_00536308(void) {
    Entry *p=D_00868848;
    unsigned int i=0;
    do {
        if((unsigned char)(p->state-1)<2) { p->state=4; }
        if(p->state==4) {
            Result r;
            D_0064B4B0->get(&r,p->key);
            if(p->callback) { p->callback(14,&r,0); p->callback=0; }
            p->state=0;
        }
        i++;
        p++;
    } while(i<256);
    if(D_0064B4EC) {
        int r=func_00535780(D_0064B4A8->release());
        if(r) return r;
        D_0064B4EC=0;
    }
    func_005A48D8(D_00868848,0,0x2000);
    return 0;
}
