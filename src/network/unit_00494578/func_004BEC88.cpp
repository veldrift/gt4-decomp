struct Obj{int a;int* status;};
extern "C" int func_004BED58(Obj*,void*,int);
inline int count(Obj* self,void* arg){if(arg){*self->status=0;}else{return 6;}return 1;}
extern "C" int func_004BEC88(Obj* self,void* arg){int total=0,error=0,n=count(self,arg);for(int i=0;i<n;i++){int result=func_004BED58(self,arg,(i&255)|0x300);if(result<0)error=1;else total+=result;}if(arg)*self->status=1;return error?int(0x80003c6bU):total;}
