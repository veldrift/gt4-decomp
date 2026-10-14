extern void func_00526040(void*,int*,unsigned short*);
inline unsigned short sentinel(){return 0xfffe;}
extern "C" int func_00523D48(void* input,unsigned short* out) {
 unsigned short value=sentinel();
 int pos=0;
 if(!out)return 2;
 *out=-2;
 if(!input)return 2;
 func_00526040(input,&pos,&value);
 *out=value;
 return 0;
}
