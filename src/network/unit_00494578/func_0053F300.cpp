extern const char* func_0053F398(const char*,int);
extern int func_0057F260(const char*);
extern int func_00594470(const char*,const char*,int);
extern "C" int func_0053F300(char* text,int* length,const char* suffix){
 const char* tail=func_0053F398(text,*length);
 int count=func_0057F260(suffix);
 if(func_00594470(suffix,tail,count)==0){
 *length=*length-count-1;
 text[*length]=0;
 return 1;
 }
 return 0;
}
