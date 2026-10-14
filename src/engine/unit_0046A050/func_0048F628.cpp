extern unsigned char* func_0048F490(void*,const void*,int*);
extern int func_0048F2E0(const void*);
extern void* malloc(int);
extern void func_00574B18(void*,void*,const void*,int);
extern void func_00574BA0(void*,int);
extern "C" void* func_0048F628(void* self,const void* name,int* allocated,int* size){
 unsigned char* source=func_0048F490(self,name,size);
 if(!source) return source;
 if(func_0048F2E0(source)){
 int length=source[4]|(source[5]<<8);
 length|=source[6]<<16;
 length|=source[7]<<24;
 length=-length;
 void* result=malloc(length);
 char decoder[0x3050];
 func_00574B18(decoder,result,source,1);
 func_00574BA0(decoder,2);
 *allocated=1;
 if(size) *size=length;
 return result;
 } else { *allocated=0;return source; }
}
