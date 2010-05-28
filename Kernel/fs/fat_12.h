/* 
 * File:   fat.h
 * Author: bdallen
 *
 * Created on May 28, 2010, 2:01 PM
 */

#ifndef _FAT_H
#define	_FAT_H

    #include <types.h>

    #define FORM_INT(a,b) ((b<<8)|a)
    #define FORM_LONG(a,b,c,d) ((d<<24)|(c<<16)|(b<<8)|a)
    #define MAX_FILE 10
    #define MAX_DIR 10

    #define BYTE1(a) (a&0xff)
    #define BYTE2(a) ((a>>8)&0xff)
    #define BYTE3(a) ((a>>16)&0xff)
    #define BYTE4(a) ((a>>24)&0xff)

    //Attributes in Root Directory

    #define ATTR_READ_ONLY 0x01
    #define ATTR_HIDDEN 0x02
    #define ATTR_SYSTEM 0x04
    #define ATTR_VOLUME_ID 0x08
    #define ATTR_DIRECTORY 0x10
    #define ATTR_ARCHIVE 0x20
    #define ATTR_LONG_NAME 0xf
    #define ATTR_LONG_NAME_MASK 0x3F

    //Start Sector Values

    #define BOOT_SEC 0
    #define FAT1_SEC 1
    #define FAT2_SEC 10
    #define ROOT_SEC 19
    #define DATA_SEC 33
    #define MAX_BLOCK 2849
    #define MAX_SECTOR 2880

    //Number of Entries

    #define DIR_ENTRIES 16


    // FAT Entry Values

    #define UNUSED 0
    #define RESERVED1 0xff0
    #define RESERVED2 0xff6
    #define BADCLUSTER 0xff7
    #define EOF1 0xFF8
    #define EOF2 0xFFF
    #define EOF(in) (in >= EOF1 && in <= EOF2)

    //Root Directory Dir[0] values

    #define FREE                0xE5
    #define REST_FREE           0x0
    #define KANJI               0x05

    //Error

    #define E_DISK		-1
    #define E_FS_NEXISTS 	-2
    #define E_FS_EXISTS         -3
    #define E_FS_FNAME    	-4
    #define E_FS_SPACE          -5
    #define E_FS_BUSY           -6
    #define E_NOT_LONG          -7
    #define E_FS_BADREQ         -8

    #define O_RDONLY            1
    #define O_RDWR              2

    #define MAX_FS_REQ          50

    //TYPES Of Requests

    #define OPEN		1
    #define CLOSE		2
    #define READ		3
    #define WRITE		4
    #define CREATEFIL           5
    #define OPENDIR		6
    #define CREATEDIR           7
    #define CLOSEDIR            8
    #define READDIR		9
    #define REMOVE		10
    #define RENAME		11

    #define LOAD 		12


    struct boot_sector
    {
         char jumpBoot[3];
         char SysName[8];
         int charsPerSector;
         char SectorsPerCluster;
         int ReservedSectors;
         char FATcount;
         int MaxRootEntries;
         int TotalSectors1;
         char MediaDescriptor;
         int SectorsPerFAT;
         int SectorsPerTrack;
         int HeadCount;
         long HiddenSectors;
         long TotalSectors2;
         char DriveNumber;
         char Reserved1;
         char ExtBootSignature;
         long VolumeSerial;
         char VolumeLabel[11];
         char Reserved2[8];
    };
    struct dir_entry
     {
          char Filename[8];
          char Extension[3];
          char Attributes;
          char NTRes;
          char CrtTimeTenth;
          int CrtTime;
          int CrtDate;
          int LstAccDate;
          int FstClusHI;
          int WrtTime;
          int WrtDate;
          int FstClusLO;
          long FileSize;
     };

    typedef struct
    {
        char name[256];
        char attribute;
        DATE crt_dt;
        TIME crt_time;
        DATE acc_dt;
        long clu;
        long size;
        DATE mod_dt;
        TIME mod_time;
    } DIRENT;

    struct long_dir_entry
    {
        char LDIR_Ord;
        unsigned char LDIR_Name1[10];
        char LDIR_Attr;
        char LDIR_Type;
        char LDIR_Chksum;
        unsigned char LDIR_Name2[12];
        int  LDIR_FstClusLO;
        unsigned char LDIR_Name3[4];
    };

    struct sector
    {
        int base;
        int length;
    };

    struct file_des
    {
        int avl;
        char fname[256];
        int mode;
        int sec_offset;
        int offset;
        unsigned char buffer[512];
        long length;
        long tot_offset;
        struct dir_entry rs;
        int root_sec;
        int root_in;
    };



#endif	/* _FAT_H */

