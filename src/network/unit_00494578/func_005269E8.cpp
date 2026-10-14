struct Token { char data[6]; };
struct Entry { int type,p,q; char pad[0x38]; };
struct S { char pad[0x84]; Entry *entries; };
extern "C" int func_00523D48(void *,unsigned short *) throw();
extern "C" void func_00527710(S *,int,int,int);
extern "C" int func_005269E8(S *s,int unused,Token *src) {
    Token t;
    unsigned short index;
    func_00523D48(s,&index);
    Entry *base=s->entries;
    if(((Entry *)(index*0x44+(int)base))->type!=7) return 0;
    t=*src;
    Entry *e=(Entry *)(*(unsigned short *)(t.data+2)*0x44+(int)base);
    if(e->p==0 && e->q==0) return 0;
    e=(Entry *)(*(unsigned short *)(t.data+4)*0x44+(int)base);
    if(e->p!=0) {
        func_00527710(s,e->p,1,0xD2F3);
        return 0;
    }
    if(e->q!=0) func_00527710(s,e->q,1,0xD2F3);
    return 0;
}
