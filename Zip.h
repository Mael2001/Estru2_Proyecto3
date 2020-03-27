#ifndef ZIP_H
#define ZIP_H
#include <iostream>
#include <fstream>
#include <inttypes.h>
#include <limits>
#include <stdio.h>
#include <stdint.h>
#include <cstring>
#include <iomanip>

using namespace std;

class Zip {
private:
    char SIGNATURE[4];
    uint16_t VERSION;
    uint16_t BITFLAG;
    uint16_t COMPRESSMETHOD;
    uint16_t MOD_TIME;
    uint16_t MOD_DATE;
    uint64_t CRC32;
    uint64_t COMPRESSED;
    uint64_t UNCOMPRESSED;
    uint16_t FILENAME_LENGTH;
    uint16_t EXTRA_FIELD_LENGTH;

    char EXT_SIG[4];
    uint64_t EXT_CRC32;
    uint64_t EXT_COMPRESS;
    uint64_t EXT_UNCOMPRES;

    char CENTRAL_SIG[4];
    uint16_t CENTRAL_VER_MADE;
    uint16_t CENTRAL_VER;
    uint16_t CENTRAL_BITFLAG;
    uint16_t CENTRAL_COMPRESSMETHOD;
    uint16_t CENTRAL_MOD_TIME;
    uint16_t CENTRAL_MOD_DATE;
    uint64_t CENTRAL_CRC32;
    uint64_t CENTRAL_COMPRESSED;
    uint64_t CENTRAL_UNCOMPRESSED;
    uint16_t CENTRAL_FILENAME_LENGTH;
    uint16_t CENTRAL_EXTRA_FIELD_LENGTH;
    uint16_t CENTRAL_COMMENT_LENGTH;
    uint16_t CENTRAL_DISK_START;
    uint16_t CENTRAL_INTER_ATT;
    uint64_t CENTRAL_EXT_ATT;
    uint64_t CENTRAL_HEADER_OFFSET;

    char END_SIG[4];
    uint16_t NUM_DISK;
    uint16_t START_DISK;
    uint16_t NUM_ENTRIES_CENTRAL;
    uint16_t NUM_ENTRIES;
    uint64_t SIZE_CENTRAL;
    uint64_t OFFSET_CENTRAL;
    uint16_t ZIPFILE_COM_LENGTH;
public:
    char* FILENAME;
    char* EXTRAFIELD;
    char* DATA;

    char* CENTRAL_FILENAME;
    char* CENTRAL_EXTRAFIELD;
    char* CENTRAL_COMMENT;

    char* ZIPFILE_COMENT;

    Zip();
    inline uint16_t getModtime(){
        return MOD_TIME;
    }
    inline uint16_t getModdate(){
        return MOD_DATE;
    }
    inline uint16_t getbitflag() {
        return BITFLAG;
    }
    inline uint16_t getfilenamelength() {
        return FILENAME_LENGTH;
    }
    inline uint16_t getextrafieldlength() {
        return EXTRA_FIELD_LENGTH;
    }
    inline uint64_t getcompressedsize() {
        return COMPRESSED;
    }
    inline uint64_t getuncompressed(){
        return UNCOMPRESSED;
    }

    inline uint16_t getCentral_FILELENGTH() {
        return CENTRAL_FILENAME_LENGTH;
    }
    inline uint16_t getCentral_EXTRALENGTH() {
        return CENTRAL_EXTRA_FIELD_LENGTH;
    }
    inline uint16_t getCentral_COMLENGTH() {
        return CENTRAL_COMMENT_LENGTH;
    }

    inline uint16_t getEnd_COMLENGTH() {
        return ZIPFILE_COM_LENGTH;
    }

    void unpackheader(char paquete[30]);
    void unpackextheader(char paquete[16]);
    void unpackcentraldir(char paquete[46]);
    void unpackEndCentralDir(char paquete[22]);
    void print();
    void print_ext();
    void print_central();
    void print_endCentral();
};
#endif ZIP_H
