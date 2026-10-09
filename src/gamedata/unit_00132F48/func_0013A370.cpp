typedef struct Rep {int len,cap,ref,sel;} Rep;typedef struct Str {char *p;} Str;
extern "C" Str *func_0021B788(void *);
extern "C" char *func_005C2560(Rep *);
extern "C" Str *func_0013A370(Str *result,void *face) {Str *source=func_0021B788((char *)face+0xA0);char *p=source->p;Rep *rep=(Rep *)(p-16);char *copy;if(rep->sel)copy=func_005C2560(rep);else{copy=p;rep->ref++;}result->p=copy;return result;}