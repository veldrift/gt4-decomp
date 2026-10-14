/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry { int a,b; short c,d,e; char f,pad; };
struct Data { char pad[0x50]; Entry entries[6]; };
struct Obj { char pad[0x24]; Data *data; char pad2[0x14]; u8 *map; };
extern "C" {
int func_004BED58(Obj *, int, int) throw();
void *func_004C4070(void *, const void *, unsigned) throw();
int func_004C9B80(int, int, void *, const void *, int);
}
static inline u32 get(const u8 *p) { return (p[0]<<24)|p[3]|((p[2]<<8)|(p[1]<<16)); }
extern "C" int func_004C9790(Obj *o, const u8 *p, int n) {
    if(n < 13) return 0x80004475;
    u32 th=(p[4]<<24)|p[7];
    u32 tl=(p[6]<<8)|(p[5]<<16);
    u32 type=th|tl;
    u32 ah=(p[0]<<24)|p[3];
    u32 al=(p[2]<<8)|(p[1]<<16);
    u32 a=ah|al;
    u32 bh=(p[8]<<24)|p[11];
    u32 bl=(p[10]<<8)|(p[9]<<16);
    u32 b=bh|bl;
    if(type < 3) return 0x80004875;
    if(type != 3) return 0x80004875;
    Entry tmp;
    int result=func_004C9B80(1,a,&tmp,p,b);
    if(result < 0) return result;
    Data *d=o->data;
    int i;
    for(i=1; i<6; i++) { if(d->entries[i].a == 0) break; }
    if(i==6) return 0x80004575;
    unsigned short handle=i|0x300;
    func_004C4070(&d->entries[i],&tmp,16);
    if(func_004BED58(o,0,handle)) {
        o->data->entries[i].a=0;
        o->data->entries[i].b=0;
        o->data->entries[i].c=0;
        o->data->entries[i].d=0;
        o->data->entries[i].e=0;
        o->data->entries[i].f=0;
        return 0x80004975;
    }
    u8 *map=o->map;
    for(int j=1;j<6;j++) { if(map[j]==0) { map[j]=i; return j|0x300; } }
    return 0x80004575;
}
