/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj { char pad[0x24]; char *data; char pad28[0x14]; u8 *map; };
extern "C" int func_004C99B8(Obj *arg0, int key) {
    int n = key & 255;
    if ((u32)(n-1) >= 5) return 0x80004A76;
    Obj *o = arg0;
    u8 *p = o->map + n;
    int id = *p;
    if (!id) return 0x80004B76;
    key = (u16)((key & ~255) | id);
    if ((key & 0xff00) != 0x300) return 0x80004876;
    int n_2 = key & 255;
    if ((u32)(n_2-1) >= 5) return 0x80004A76;
    if (!*(int *)(o->data + n_2*16 + 0x50)) return 0x80004B76;
    *p = 0;
    int i;
    for (i=1; i<6; i++) {
        u8 *q = o->map + i;
        if (id < *q) --*q;
    }
    i = n_2+1;
    for (; i<6; i++) {
        int src = i*16+0x50;
        int dst = i*16+0x40;
        *(int *)(o->data+dst) = *(int *)(o->data+src);
        char *second = o->data+4;
        *(int *)(second+dst) = *(int *)(second+src);
        *(u16 *)(o->data+dst+8) = *(u16 *)(o->data+src+8);
        *(u16 *)(o->data+dst+10) = *(u16 *)(o->data+src+10);
        *(u16 *)(o->data+dst+12) = *(u16 *)(o->data+src+12);
        *(u8 *)(o->data+dst+14) = *(u8 *)(o->data+src+14);
        if (!*(int *)(o->data+src)) break;
    }
    if (i >= 6) {
        *(int *)(o->data+0xa0)=0;
        *(int *)(o->data+0xa4)=0;
        *(u16 *)(o->data+0xa8)=0;
        *(u16 *)(o->data+0xaa)=0;
        *(u16 *)(o->data+0xac)=0;
        *(u8 *)(o->data+0xae)=0;
    }
    return 0;
}
