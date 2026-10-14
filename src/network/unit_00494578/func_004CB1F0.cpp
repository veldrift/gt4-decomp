/* compiler: ee-gcc2.96-no-strict-aliasing */
extern unsigned char D_006D0E79[];
static inline int upper(int c) { return ((*(unsigned char *)(0x006D0E79+c))&2)?c-32:c; }
extern "C" void func_004CB1F0(char *out,const char *src) {
 int i=0;
 while(i<8 && *src && *src!='.') out[i++]=upper(*src++);
 while(i<8) out[i++]=' ';
 if(*src=='.') ++src;
 for(;i<11 && *src;) out[i++]=upper(*src++);
 while(i<11) out[i++]=' ';
 out[i]=0;
}
