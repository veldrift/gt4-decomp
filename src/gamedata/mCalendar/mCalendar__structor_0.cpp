// Native object wrapper: the constructor installs its read-only data pointer.
struct RefCounter {int unknown0;virtual ~RefCounter();};
struct hObject:RefCounter {hObject() __asm__("func_0030A678");virtual ~hObject();int unknown8,unknownC;};
struct mCalendar:hObject {void* const data;mCalendar(void*) __asm__("func_00132E90");virtual ~mCalendar();};
mCalendar::mCalendar(void* value):data(value){}
