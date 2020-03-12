#include <klib.h>
#include <amdev.h>

uint32_t uptime() {
  _DEV_TIMER_UPTIME_t uptime;
  _io_read(_DEV_TIMER, _DEVREG_TIMER_UPTIME, &uptime, sizeof(uptime));
  return uptime.lo;
}

void get_timeofday(void *rtc) {
  _io_read(_DEV_TIMER, _DEVREG_TIMER_DATE, rtc, sizeof(_DEV_TIMER_DATE_t));
}

int read_key() {
  _DEV_INPUT_KBD_t key;
  _io_read(_DEV_INPUT, _DEVREG_INPUT_KBD, &key, sizeof(_DEV_INPUT_KBD_t));
  int ret = key.keycode;
  if (key.keydown) ret |= 0x8000;
  return ret;
}

void draw_rect(uint32_t *pixels, int x, int y, int w, int h) {
  _DEV_VIDEO_FBCTRL_t ctl = (_DEV_VIDEO_FBCTRL_t) {
    .pixels = pixels,
    .x = x, .y = y, .w = w, .h = h,
    .sync = 0,
  };
  _io_write(_DEV_VIDEO, _DEVREG_VIDEO_FBCTRL, &ctl, sizeof(ctl));
}

void draw_sync() {
  _DEV_VIDEO_FBCTRL_t ctl;
  ctl.pixels = NULL;
  ctl.x = ctl.y = ctl.w = ctl.h = 0;
  ctl.sync = 1;
  _io_write(_DEV_VIDEO, _DEVREG_VIDEO_FBCTRL, &ctl, sizeof(ctl));
}

int screen_width() {
  _DEV_VIDEO_INFO_t info;
  _io_read(_DEV_VIDEO, _DEVREG_VIDEO_INFO, &info, sizeof(info));
  return info.width;
}

int screen_height() {
  _DEV_VIDEO_INFO_t info;
  _io_read(_DEV_VIDEO, _DEVREG_VIDEO_INFO, &info, sizeof(info));
  return info.height;
}

int printf(const char *fmt, ...) {
	int count=0;
	va_list argptr;
	va_start(argptr,fmt);
	for(;fmt[count]!='\0';)
	{
		if (fmt[count]!='%')
		{   _putc(fmt[count]);
			count++;
		}
		else
		{   
		//	char next=fmt[count+1];
			if (fmt[count+1]=='s')
			{   
				char* s=va_arg(argptr,char*);
//				count = concat_s(out,s,count);
				
				for(int i=0;s[i]!='\0';i++)
					_putc(s[i]);
				count = count+2;
			}
			else 
			{	char geshi[4];
				int g;
				geshi[0]='\0';
				for (g=count+1;fmt[g]!='d'&&fmt[g]!='u'&&fmt[g]!='x';g++)
					geshi[g-count-1]=fmt[g];
				geshi[g-count-1]='\0';
				//char next=fmt[g];
				int num = va_arg(argptr,int);
      		//	count = concat_d(out,count,num);
				
				int s;
				char str[200];
				int c=0;
				//10 d
			//	if (fmt[g]=='d')
				while(num/10!=0)
				{
					s = num%10;
					str[c] = s+'0';
					num = num/10;
					c++;
				}
				s = num%10;
				str[c] = s+'0';
				c++;
				str[c]='\0';
				
				//16 x
		/*		else if (fmt[g]=='x')
				{
					while(num/16!=0)
					{
						s= num%16;
						if (s<=9)
							str[c]=s+'0';
						else
							str[c]=s-10+'a';
						num = num/16;
						c++;
					}
					s = num%16;
					if (s<=9)
						str[c]=s+'0';
					else
						str[c]=s-10+'a';
					c++;
					str[c]='\0';
				}
				*/
				int len = strlen(str);
				for (int i=0;i<len/2;i++)
				{
					char temp = str[i];
					str[i] = str[len-1-i];
					str[len-1-i] = temp;
				}
				
				
				if (strlen(geshi)==2)
				{	for (int i=geshi[1]-'0'-strlen(str);i>0;i--)
						_putc(geshi[0]);
					for (int j=0;str[j]!='\0';j++)
						_putc(str[j]);
				}
				else if (strlen(geshi)==0)
					for (int j=0;str[j]!='\0';j++)
							_putc(str[j]);
				

				count =count+strlen(geshi)+2;;
			}
		}
	}
      va_end(argptr);	
	  _putc('\0');
	  return 0;

}


int vsprintf(char *out, const char *fmt, va_list ap) {
  return 0;
}

int sprintf(char *out, const char *fmt, ...) {
	int count=0;
	va_list argptr;
	va_start(argptr,fmt);
	for(;fmt[count]!='\0';)
	{
		if (fmt[count]!='%')
		{   char temp[2];
			temp[0]=fmt[count];
			temp[1]='\0';
			if (count==0)
				strcpy(out,temp);
			else
			    strcat(out,temp);
			count++;
		}
		else
		{
			char next = fmt[count+1];
			if (next=='s')
			{   
//				char* s=va_arg(argptr,char*);
//				count = concat_s(out,s,count);
				
				if (count==0)
					strcpy(out,va_arg(argptr,char*));
				else
					strcat(out,va_arg(argptr,char*));
				count = count+2;
			}
			else if(next=='d')
			{
				int num = va_arg(argptr,int);
      		//	count = concat_d(out,count,num);
				
				int s;
				char str[200];
				int c=0;
				while(num/10!=0)
				{
					s = num%10;
					str[c] = s+'0';
					num = num/10;
					c++;
				}
				s = num%10;
				str[c] = s+'0';
				c++;
				str[c]='\0';
				int len = strlen(str);
				for (int i=0;i<len/2;i++)
				{
					char temp = str[i];
					str[i] = str[len-1-i];
					str[len-1-i] = temp;
				}
				if (count==0)
					strcpy(out,str);
				else
					strcat(out,str);
				count = count+2;
				
			}
		}
	}
      va_end(argptr);	
	  return 0;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  return 0;
}


size_t strlen(const char *s) {
	size_t count;
    for (count=0;s[count]!='\0';count++);	
    return count;

//	return 0;
}

char *strcpy(char* dst,const char* src) {
  int size_src = strlen(src);
  int i;
  for (i=0; i<=size_src;i++)
	  dst[i]=src[i];
  return dst;
  
//	return NULL;
}

char* strncpy(char* dst, const char* src, size_t n) {
  int len_src = strlen(src);
  for(int i=0;i<n && i<=len_src;i++)
	  dst[i] = src[i];
  return dst;

//	 return NULL;
}

char* strcat(char* dst, const char* src) {
	int len_dst = strlen(dst);
    int len_src = strlen(src);
    for(int i=0;i<=len_src;i++)
		dst[i+len_dst] = src[i];
	return dst;	
	
//	  return NULL;
}

int strcmp(const char* s1, const char* s2) {
	int len_s1 = strlen(s1);
	int len_s2 = strlen(s2);
	int i;
	for (i=0;i<len_s1 && i<len_s2;i++)
	{
		if (s1[i]<s2[i])
			return -1;
		else if (s1[i]>s2[i])
			return 1;
	}
	if (i==len_s1 && i==len_s2)
		return 0;
	else
	{
		if (i==len_s1)
			return -1;
		else if (i==len_s2)
			return 1;
	}
	
	  return 0;
}

int strncmp(const char* s1, const char* s2, size_t n) {
  return 0;
}

void* memset(void* v,int c,size_t n) {
	char* t = (char*)v;
    for(int i=0;i<n;i++)
	    t[i] = c;
    return v;	
	
//	  return NULL;
}

void* memcpy(void* out, const void* in, size_t n) {
	char* t = (char*)out;
	char* p = (char*)in;
	for(size_t i=0;i<n;i++)
		t[i] = p[i];
	return out;

	// return NULL;
}

int memcmp(const void* s1, const void* s2, size_t n){
	char* t = (char*)s1;
	char* p = (char*)s2;
	for (int i=0;i<n;i++)
	{
		if (t[i]<p[i])
			return -1;
		else if (t[i]>p[i])
			return 1;
	}
	return 0;
	
	//  return 0;
}