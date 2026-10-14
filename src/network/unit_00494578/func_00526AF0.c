/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Token { char data[6]; };
struct Entry { int x; int p,q; char pad[0x20]; unsigned short tag; char tail[0x16]; };
struct S { char pad[0x84]; struct Entry *entries; };
void func_00527710(struct S *,int,int,int);
int func_00526AF0(struct S *s,int unused,struct Token *src) {
    struct Token t=*src;
    unsigned short index=*(unsigned short *)(t.data+2);
    unsigned short tag=*(unsigned short *)(t.data+4);
    struct Entry *e=(struct Entry *)(index*0x44+(int)s->entries);
    if(e->tag!=tag) return 0;
    if(e->p!=0) {
        func_00527710(s,e->p,1,0xD2F3);
        return 0;
    }
    if(e->q!=0) func_00527710(s,e->q,1,0xD2F3);
    return 0;
}
