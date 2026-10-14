/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void free(void *) throw();
extern "C" char *func_00575E60(int, int);
extern "C" char *func_005CDD50(char *, int, char *);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void *func_005A48D8(void *, int, unsigned);
struct Self { char pad[0x50]; char *data; };
extern "C" int func_001CCEC8(Self *, void *, char *, int, int) throw();
struct Vec { int allocator; char *start; char *finish; char *eos; char spare[16]; char *tmp; char zero;
 Vec() { start=0; finish=0; eos=0; char *p=func_00575E60(0x40,0xCC0); eos=p+0xCC0; start=p; finish=p; tmp=p; zero=0; finish=func_005CDD50(p,0xCC0,&zero); }
 ~Vec() { if (start) free(start); }
};
extern "C" int func_001D0F38(Self *self, void *arg1, int arg2, int arg3) {
 Vec v;
 if (self->data) func_005A4724(v.start,self->data,0xC88);
 else func_005A48D8(v.start,0,0xC88);
 if (func_001CCEC8(self,arg1,v.start,v.finish-v.start,arg3)==0) return 1;
 return 0;
}
