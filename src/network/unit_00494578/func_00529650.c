typedef unsigned char u8;
typedef unsigned short u16;
struct B { int kind; char pad4[0x70]; u16 refs; char pad76[0x16]; int a8c,a90; char pad94[0x404]; int a498; };
struct O { u8 bytes[4]; };
struct E { void *p; unsigned n; };
struct Q { struct E e[8]; unsigned size; int count; };
union H { struct {u8 a,b; u16 length;} f; struct {u16 flags,length;} w; };
extern void func_0052AA88(void *,struct B*,u16,int,struct O*);
extern int func_0052AB68(void *,void *,struct Q*,unsigned,int);
static inline void init(struct Q *q) { q->count=0; q->size=0; }
static inline void add(struct Q *q,void *p,const u16 *length) {
    unsigned n;
    q->e[q->count].p=p;
    n=*length;
    q->e[q->count].n=n;
    q->size+=n;
    q->count++;
}
extern void func_00529650(void *a,struct B*b) {
    struct O o;
    struct Q q;
    union H h;
    if(a && b) {
        int kind=b->kind;
        b->a8c=0; b->a90=0; b->a498=0;
        if(kind==13 || kind==4) {
            b->kind=6;
            func_0052AA88(a,b,0x4000,0,&o);
            h.f.a=o.bytes[0];h.f.b=o.bytes[1];
            h.w.flags &= 0xf800;
            if(h.w.flags & 0x6000) h.w.length=4; else h.w.length=2;
            init(&q);
            add(&q,&o,&h.w.length);
            if(func_0052AB68(a,(char *)b+0x14,&q,0x2000,0)) b->refs--;
        } else b->kind=5;
    }
}
