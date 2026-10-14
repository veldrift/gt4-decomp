struct S { int pad,capacity,position,mode; unsigned char *cursor; int remain,read,err,failed; };
extern "C" void func_0046E8E0(S*);
extern "C" int func_0046EA08(S *self) {
 if(self->failed) return 0;
 if(self->mode!=7){func_0046E8E0(self);self->mode=7;}
 if(!self->remain){self->err=1;self->failed=1;return 0;}
 int value=*self->cursor<<8;
 func_0046E8E0(self);
 if(!self->remain){self->err=1;self->failed=1;return 0;}
 value|=*self->cursor;
 func_0046E8E0(self);
 self->read=1;
 return value;
}
