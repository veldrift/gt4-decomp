typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
struct Obj { char pad[0x9c]; u16 count; };
struct Info { int *items; int out[3]; u32 count; };
extern "C" int func_00528160(Obj *,u32,u16,const unsigned char **) throw();
extern "C" int func_00528600(Obj *o,Info *p,u16 index) {
    const unsigned char *data=0;
    u16 n=0xfffe;
    u32 i=0;
    u32 ordinal=0;
    for(;i<o->count;i++) {
        if(p->items[i]) {
            if(index==i) { n=ordinal; break; }
            ordinal++;
        }
    }
    int ret=func_00528160(o,p->count,n,&data);
    if(ret) return ret;
    for(ordinal=0;ordinal<3;ordinal++) {
        if((s8)data[ordinal]==-1) p->out[ordinal]=0;
        else {
            s8 k=0;
            for(u32 i=0;i<o->count;i++) {
                if(p->items[i]) {
                    if(k==(s8)data[ordinal]) { p->out[ordinal]=p->items[i]; break; }
                    k++;
                }
            }
        }
    }
    return 0;
}
