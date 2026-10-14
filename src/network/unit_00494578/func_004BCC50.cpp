/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
struct Fs { char pad[0x24]; char *tbl; };
struct Rec { u16 h0,h2; u8 bytes[6]; u16 hA,hC; u8 len1,len2; u8 tail[4]; u16 h14; u16 pad16; u8 *p18,*p1c; };
struct Ent { u32 p; char pad[6]; u16 a,b; char pad2[2]; };
extern "C" void func_004BC868(u8 *,const u16 *,int) throw();
extern "C" short func_004BC8A0(Rec *) throw();
extern "C" u8 *func_004C0508(char *,int,u16);
static inline u32 destination(u32 base,u32 off,u32 count) { base+=off; base+=count*6; base+=6; return base; }
extern "C" void func_004BCC50(Fs *fs,Rec *rec,u16 id) {
    char *tbl=fs->tbl;
    u32 off=rec->h0*20;
    u32 dst;
    if ((id&0xff00)==0x200) {
        Ent *e=(Ent *)((u32)tbl+((id&255)*16+0x40));
        dst=destination(e->p,off,e->a);
    } else {
        Ent *e=(Ent *)((u32)tbl+((id&255)*16+0x50));
        dst=destination(e->p,off,e->a+e->b);
    }
    u8 *out=(u8 *)dst;
    rec->h2=0;
    u16 *h=&rec->h2;
    u16 *h14=&rec->h14;
    u8 *cursor;
    func_004BC868(out,h,1);
    out[2]=rec->bytes[0]; out[3]=rec->bytes[1]; out[4]=rec->bytes[2];
    out[5]=rec->bytes[3]; out[6]=rec->bytes[4]; out[7]=rec->bytes[5];
    func_004BC868(out+8,&rec->hA,1);
    func_004BC868(out+10,&rec->hC,1);
    out[12]=rec->len1; out[13]=rec->len2;
    out[14]=rec->tail[3]; out[15]=rec->tail[2]; out[16]=rec->tail[1]; out[17]=rec->tail[0];
    func_004BC868(out+18,h14,1);
    *h=func_004BC8A0(rec);
    u8 *d;
    int i;
    if (rec->p18) {
        d=func_004C0508(tbl,id,*h14);
        cursor=rec->p18;
        if (d) for(i=0;i<rec->len1;i++) { u8 value=*cursor; cursor++; *d=value; d++; }
    }
    if (rec->p1c) {
        cursor=rec->p1c;
        d=func_004C0508(tbl,id,rec->h14);
        if(d) {
            d+=rec->len1;
            for(i=0;i<rec->len2;i++) { u8 value=*cursor; cursor++; *d=value; d++; }
        }
    }
    return func_004BC868(out,h,1);
}
