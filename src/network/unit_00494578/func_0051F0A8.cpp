typedef unsigned char u8;
struct Bytes { u8 a,b,c,d; };
struct Obj { char pad[0x84]; volatile int handle; char pad88[0x10]; int (*fn)(int,u8,u8,u8,u8,int,void *); };
extern "C" int func_0051F0A8(Obj *p, int, volatile Bytes *buf, int size) {
    if (p->fn) {
        u8 a=buf->a, b=buf->b, c=buf->c, d=buf->d;
        p->fn(p->handle,a,b,c,d,size-4,(char *)buf+4);
    }
    return 0;
}
