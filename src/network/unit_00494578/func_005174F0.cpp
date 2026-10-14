struct Field { int a; unsigned int w,h; int c; unsigned int period; int active; int d; unsigned char flags; };
struct Sub { char pad[0x20]; Field *fields[64]; unsigned int offsets[64]; };
struct Record { int a,count; Sub sub; };
struct Self { unsigned char id; char pad[0x1c-1]; char *src,*dst; int bitsHi,bitsLo; char p2c[0x10]; unsigned int *times; };
struct Context { char p[0x5c]; unsigned int time; };
extern Record D_0085C330[16];
extern Context *D_0064B47C;
extern "C" int func_005182D8(Self *,int,unsigned char);
extern "C" void *func_005A4724(void *,const void *,unsigned int);
extern "C" int func_005174F0(Self *self,int arg,unsigned char force,unsigned char *mask,unsigned char *out,unsigned int *used) {
    int result=0;
    unsigned char count=0;
    if(!out) return result;
    if(!used) return result;
    if(!self) return result;
    if(self->id>=16) return result;
    {
    Record *rec=D_0085C330+self->id;
    if(!rec) return result;
    {
    for(unsigned char i=0;i<rec->count;i++) {
      if(*used>=0x1ff) continue;
      Field *f=rec->sub.fields[i];
      if(!f) continue;
      int *bits; unsigned int shift;
      if(i<32) { bits=&self->bitsLo;shift=i; }
      else {bits=&self->bitsHi;shift=i>>1;}
      char *src,*dst;
      if((*bits>>shift)&1) {
        unsigned int off=rec->sub.offsets[i];
        src=self->src+off;dst=self->dst+off;
      } else {
        if(!f->active) continue;
        if(!force && self->times[i]+f->period>=D_0064B47C->time) continue;
        unsigned int off=rec->sub.offsets[i];
        src=self->src+off;dst=self->dst+off;
        if(!func_005182D8(self,arg,i)) continue;
      }
      if(0x1fe - *used<f->w*f->h+1) continue;
      *out=i;out++;
      *used+=1;
      func_005A4724(out,src,f->w*f->h);
      unsigned int size=f->w*f->h;
      count++;
      out+=size;*used+=size;
      *mask|=f->flags;
      func_005A4724(dst,src,f->w*f->h);
      self->times[i]=D_0064B47C->time;
    }
    result=count;
    }
    }
    return result;
}
