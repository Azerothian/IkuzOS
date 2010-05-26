#define WHITE_SPACE 0x07
#define VIDEO_MEMORY 0xb8000

char *videoMemory = (char*) VIDEO_MEMORY;

void clrscr()
{
    int i;
    for(i=0;i < (80*25*2);i+=2)
    {
        videoMemory[i]=' ';
        videoMemory[i+1]=WHITE_SPACE;
    }
}

void printxy(char *message, unsigned int x, unsigned int y)
{
    unsigned int i=0;
    i=(y*80*2)+x;
    while(*message!=0)
    {
        if(*message=='\n')
        {
            y++;
            i=(y*80*2);
        } else {
            videoMemory[i++]=*message;            
            videoMemory[i++]=WHITE_SPACE;
        }
        *message++;
    }
}

void _kernel_main()
{
    clrscr();
    printxy("IkuzOS - Starting Environment", 0, 0);
}
