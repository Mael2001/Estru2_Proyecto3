#pragma once
#include "Zip.h"

Zip::Zip() {
    SIGNATURE[0] = 0;
    SIGNATURE[1] = 0;
    SIGNATURE[2] = 0;
    SIGNATURE[3] = 0;
    VERSION = 0;
    BITFLAG = 0;
    COMPRESSMETHOD = 0;
    MOD_TIME = 0;
    MOD_DATE = 0;
    CRC32 = 0;
    COMPRESSED = 0;
    UNCOMPRESSED = 0;
    FILENAME_LENGTH = 0;
    EXTRA_FIELD_LENGTH = 0;
    FILENAME = new char[999];
    EXTRAFIELD = new char[99999999];
    DATA = new char[99999999];

    EXT_SIG[0] = 0;
    EXT_SIG[1] = 0;
    EXT_SIG[2] = 0;
    EXT_SIG[3] = 0;
    EXT_COMPRESS = 0;
    EXT_CRC32 = 0;
    EXT_UNCOMPRES = 0;

    CENTRAL_SIG[0] = 0;
    CENTRAL_SIG[1] = 0;
    CENTRAL_SIG[2] = 0;
    CENTRAL_SIG[3] = 0;
    CENTRAL_VER_MADE = 0;
    CENTRAL_VER = 0;
    CENTRAL_BITFLAG = 0;
    CENTRAL_COMPRESSMETHOD = 0;
    CENTRAL_MOD_TIME = 0;
    CENTRAL_MOD_DATE = 0;
    CENTRAL_CRC32 = 0;
    CENTRAL_COMPRESSED = 0;
    CENTRAL_UNCOMPRESSED = 0;
    CENTRAL_FILENAME_LENGTH = 0;
    CENTRAL_EXTRA_FIELD_LENGTH = 0;
    CENTRAL_COMMENT_LENGTH = 0;
    CENTRAL_DISK_START = 0;
    CENTRAL_INTER_ATT = 0;
    CENTRAL_EXT_ATT = 0;
    CENTRAL_HEADER_OFFSET = 0;
    CENTRAL_FILENAME = new char[999];
    CENTRAL_EXTRAFIELD = new char[9999999];
    CENTRAL_COMMENT = new char[999];

    END_SIG[0] = 0;
    END_SIG[1] = 0;
    END_SIG[2] = 0;
    END_SIG[3] = 0;
    NUM_DISK = 0;
    START_DISK = 0;
    NUM_ENTRIES_CENTRAL = 0;
    NUM_ENTRIES = 0;
    SIZE_CENTRAL = 0;
    OFFSET_CENTRAL = 0;
    ZIPFILE_COM_LENGTH = 0;
    ZIPFILE_COMENT = new char[999999];
}

void Zip::unpackheader(char paquete[30]) {
    char signature[4];
    memcpy(&signature[0], &paquete[0], 1);
    memcpy(&signature[1], &paquete[1], 1);
    memcpy(&signature[2], &paquete[2], 1);
    memcpy(&signature[3], &paquete[3], 1);

    char version[2];
    memcpy(&version[0], &paquete[4], 1);
    memcpy(&version[1], &paquete[5], 1);

    char bitflag[2];
    memcpy(&bitflag[0], &paquete[6], 1);
    memcpy(&bitflag[1], &paquete[7], 1);

    char compressmethod[2];
    memcpy(&compressmethod[0], &paquete[8], 1);
    memcpy(&compressmethod[1], &paquete[9], 1);

    char mod_time[2];
    memcpy(&mod_time[0], &paquete[10], 1);
    memcpy(&mod_time[1], &paquete[11], 1);

    char mod_date[2];
    memcpy(&mod_date[0], &paquete[12], 1);
    memcpy(&mod_date[1], &paquete[13], 1);

    char crc32[4];
    memcpy(&crc32[0], &paquete[14], 1);
    memcpy(&crc32[1], &paquete[15], 1);
    memcpy(&crc32[2], &paquete[16], 1);
    memcpy(&crc32[3], &paquete[17], 1);

    char compress[4];
    memcpy(&compress[0], &paquete[18], 1);
    memcpy(&compress[1], &paquete[19], 1);
    memcpy(&compress[2], &paquete[20], 1);
    memcpy(&compress[3], &paquete[21], 1);

    char uncompress[4];
    memcpy(&uncompress[0], &paquete[22], 1);
    memcpy(&uncompress[1], &paquete[23], 1);
    memcpy(&uncompress[2], &paquete[24], 1);
    memcpy(&uncompress[3], &paquete[25], 1);

    char filename_length[2];
    memcpy(&filename_length[0], &paquete[26], 1);
    memcpy(&filename_length[1], &paquete[27], 1);

    char extrafiled_length[2];
    memcpy(&extrafiled_length[0], &paquete[28], 1);
    memcpy(&extrafiled_length[1], &paquete[29], 1);

    memcpy(SIGNATURE, &signature, 4);
    memcpy(&VERSION, &version, 2);
    memcpy(&BITFLAG, &bitflag, 2);
    memcpy(&COMPRESSMETHOD, &compressmethod, 2);
    memcpy(&MOD_TIME, &mod_time, 2);
    memcpy(&MOD_DATE, &mod_date, 2);
    memcpy(&CRC32, &crc32, 4);
    memcpy(&COMPRESSED, &compress, 4);
    memcpy(&UNCOMPRESSED, &uncompress, 4);
    memcpy(&FILENAME_LENGTH, &filename_length, 2);
    memcpy(&EXTRA_FIELD_LENGTH, &extrafiled_length, 2);
};

void Zip::unpackextheader(char paquete[16]) {
    char sig[4];
    memcpy(&sig[0], &paquete[0], 1);
    memcpy(&sig[1], &paquete[1], 1);
    memcpy(&sig[2], &paquete[2], 1);
    memcpy(&sig[3], &paquete[3], 1);

    char crc32[4];
    memcpy(&crc32[0], &paquete[4], 1);
    memcpy(&crc32[1], &paquete[5], 1);
    memcpy(&crc32[2], &paquete[6], 1);
    memcpy(&crc32[3], &paquete[7], 1);

    char compres[4];
    memcpy(&compres[0], &paquete[8], 1);
    memcpy(&compres[1], &paquete[9], 1);
    memcpy(&compres[2], &paquete[10], 1);
    memcpy(&compres[3], &paquete[11], 1);

    char uncompres[4];
    memcpy(&uncompres[0], &paquete[12], 1);
    memcpy(&uncompres[1], &paquete[13], 1);
    memcpy(&uncompres[2], &paquete[14], 1);
    memcpy(&uncompres[3], &paquete[15], 1);

    memcpy(EXT_SIG, sig, 4);
    memcpy(&EXT_CRC32, crc32, 4);
    memcpy(&EXT_COMPRESS, compres, 4);
    memcpy(&EXT_UNCOMPRES, uncompres, 4);
};

void Zip::unpackcentraldir(char paquete[46]) {
    char centralsig[4];
    memcpy(&centralsig[0], &paquete[0], 1);
    memcpy(&centralsig[1], &paquete[1], 1);
    memcpy(&centralsig[2], &paquete[2], 1);
    memcpy(&centralsig[3], &paquete[3], 1);

    char central_mad[2];
    memcpy(&central_mad[0], &paquete[4], 1);
    memcpy(&central_mad[1], &paquete[5], 1);

    char central_ver[2];
    memcpy(&central_ver[0], &paquete[6], 1);
    memcpy(&central_ver[1], &paquete[7], 1);

    char central_bitflag[2];
    memcpy(&central_bitflag[0], &paquete[8], 1);
    memcpy(&central_bitflag[1], &paquete[9], 1);

    char central_method[2];
    memcpy(&central_method[0], &paquete[10], 1);
    memcpy(&central_method[1], &paquete[11], 1);

    char central_modtime[2];
    memcpy(&central_modtime[0], &paquete[12], 1);
    memcpy(&central_modtime[1], &paquete[13], 1);

    char central_moddate[2];
    memcpy(&central_moddate[0], &paquete[14], 1);
    memcpy(&central_moddate[1], &paquete[15], 1);

    char central_crc32[4];
    memcpy(&central_crc32[0], &paquete[16], 1);
    memcpy(&central_crc32[1], &paquete[17], 1);
    memcpy(&central_crc32[2], &paquete[18], 1);
    memcpy(&central_crc32[3], &paquete[19], 1);

    char central_compress[4];
    memcpy(&central_compress[0], &paquete[20], 1);
    memcpy(&central_compress[1], &paquete[21], 1);
    memcpy(&central_compress[2], &paquete[22], 1);
    memcpy(&central_compress[3], &paquete[23], 1);

    char central_uncompress[4];
    memcpy(&central_uncompress[0], &paquete[24], 1);
    memcpy(&central_uncompress[1], &paquete[25], 1);
    memcpy(&central_uncompress[2], &paquete[26], 1);
    memcpy(&central_uncompress[3], &paquete[27], 1);

    char central_filename_length[2];
    memcpy(&central_filename_length[0], &paquete[28], 1);
    memcpy(&central_filename_length[1], &paquete[29], 1);

    char central_extrafiled_length[2];
    memcpy(&central_extrafiled_length[0], &paquete[30], 1);
    memcpy(&central_extrafiled_length[1], &paquete[31], 1);

    char central_comment_length[2];
    memcpy(&central_comment_length[0], &paquete[32], 1);
    memcpy(&central_comment_length[1], &paquete[33], 1);

    char central_disks[2];
    memcpy(&central_disks[0], &paquete[34], 1);
    memcpy(&central_disks[1], &paquete[35], 1);

    char central_intatt[2];
    memcpy(&central_intatt[0], &paquete[36], 1);
    memcpy(&central_intatt[1], &paquete[37], 1);

    char central_extatt[4];
    memcpy(&central_extatt[0], &paquete[38], 1);
    memcpy(&central_extatt[1], &paquete[39], 1);
    memcpy(&central_extatt[2], &paquete[40], 1);
    memcpy(&central_extatt[3], &paquete[41], 1);

    char central_offset[4];
    memcpy(&central_offset[0], &paquete[42], 1);
    memcpy(&central_offset[1], &paquete[43], 1);
    memcpy(&central_offset[2], &paquete[44], 1);
    memcpy(&central_offset[3], &paquete[45], 1);

    memcpy(CENTRAL_SIG, centralsig, 4);
    memcpy(&CENTRAL_VER_MADE, central_mad, 2);
    memcpy(&CENTRAL_VER, central_ver, 2);
    memcpy(&CENTRAL_BITFLAG, central_bitflag, 2);
    memcpy(&CENTRAL_COMPRESSMETHOD, central_method, 2);
    memcpy(&CENTRAL_MOD_TIME, central_modtime, 2);
    memcpy(&CENTRAL_MOD_DATE, central_moddate, 2);
    memcpy(&CENTRAL_CRC32, central_crc32, 4);
    memcpy(&CENTRAL_COMPRESSED, central_compress, 4);
    memcpy(&CENTRAL_UNCOMPRESSED, central_uncompress, 4);
    memcpy(&CENTRAL_FILENAME_LENGTH, central_filename_length, 2);
    memcpy(&CENTRAL_EXTRA_FIELD_LENGTH, central_extrafiled_length, 2);
    memcpy(&CENTRAL_COMMENT_LENGTH, central_comment_length, 2);
    memcpy(&CENTRAL_DISK_START, central_disks, 2);
    memcpy(&CENTRAL_INTER_ATT, central_intatt, 2);
    memcpy(&CENTRAL_EXT_ATT, central_extatt, 4);
    memcpy(&CENTRAL_HEADER_OFFSET, central_offset, 4);
};

void Zip::unpackEndCentralDir(char paquete[22]) {
    char endsig[4];
    memcpy(&endsig[0], &paquete[0], 1);
    memcpy(&endsig[1], &paquete[1], 1);
    memcpy(&endsig[2], &paquete[2], 1);
    memcpy(&endsig[3], &paquete[3], 1);

    char no_disk[2];
    memcpy(&no_disk[0], &paquete[4], 1);
    memcpy(&no_disk[1], &paquete[5], 1);

    char s_disk[2];
    memcpy(&s_disk[0], &paquete[6], 1);
    memcpy(&s_disk[1], &paquete[7], 1);

    char no_entries_central[2];
    memcpy(&no_entries_central[0], &paquete[8], 1);
    memcpy(&no_entries_central[1], &paquete[9], 1);

    char no_entries[2];
    memcpy(&no_entries[0], &paquete[10], 1);
    memcpy(&no_entries[1], &paquete[11], 1);

    char size_central[4];
    memcpy(&size_central[0], &paquete[12], 1);
    memcpy(&size_central[1], &paquete[13], 1);
    memcpy(&size_central[2], &paquete[14], 1);
    memcpy(&size_central[3], &paquete[15], 1);

    char offset_central[4];
    memcpy(&offset_central[0], &paquete[16], 1);
    memcpy(&offset_central[1], &paquete[17], 1);
    memcpy(&offset_central[2], &paquete[18], 1);
    memcpy(&offset_central[3], &paquete[19], 1);

    char zip_comlen[2];
    memcpy(&zip_comlen[0], &paquete[20], 1);
    memcpy(&zip_comlen[1], &paquete[21], 1);

    memcpy(END_SIG, endsig, 4);
    memcpy(&NUM_DISK, no_disk, 2);
    memcpy(&START_DISK, s_disk, 2);
    memcpy(&NUM_ENTRIES_CENTRAL, no_entries_central, 2);
    memcpy(&NUM_ENTRIES, no_entries, 2);
    memcpy(&SIZE_CENTRAL, size_central, 4);
    memcpy(&OFFSET_CENTRAL, offset_central, 4);
    memcpy(&ZIPFILE_COM_LENGTH, zip_comlen, 2);
};

void Zip::print() {
    char sig[5];
    sig[4] = '\0';
    memcpy(sig, SIGNATURE, 4);

    uint8_t num;
    uint8_t num1;

    memcpy(&num, &sig[2], 1);
    memcpy(&num1, &sig[3], 1);

    sig[2] = 0;
    /*File modification time	stored in standard MS - DOS format :
    Bits 00 - 04 : seconds divided by 2
        Bits 05 - 10 : minute
        Bits 11 - 15 : hour
        File modification date	stored in standard MS - DOS format :
    Bits 00 - 04 : day
        Bits 05 - 08 : month
        Bits 09 - 15: years from 1980
        */
    uint8_t segundos = 0;
    uint8_t minuto = 0;
    uint8_t hora = 0;



    for (size_t i = 0; i < 5; i++)
    {
        uint8_t recio = (MOD_TIME >> i) & 1U;
        if (recio)
        {
            segundos ^= 1UL << i;
        }
    }

    for (size_t i = 5; i < 10; i++)
    {
        uint8_t recio = (MOD_TIME >> i) & 1U;
        if (recio)
        {
            minuto ^= 1UL << i - 5;
        }
    }
    for (size_t i = 11; i < 16; i++)
    {
        uint8_t recio = (MOD_TIME >> i) & 1U;
        if (recio)
        {
            hora ^= 1UL << i - 11;
        }
    }

    uint8_t dia = 0;
    uint8_t mes = 0;
    uint8_t ano = 0;

    for (size_t i = 0; i < 5; i++)
    {
        uint8_t recio = (MOD_DATE >> i) & 1U;
        if (recio)
        {
            dia ^= 1UL << i;
        }
    }

    for (size_t i = 5; i < 9; i++)
    {
        uint8_t recio = (MOD_DATE >> i) & 1U;
        if (recio)
        {
            mes ^= 1UL << i - 5;
        }
    }
    for (size_t i = 9; i < 16; i++)
    {
        uint8_t recio = (MOD_DATE >> i) & 1U;
        if (recio)
        {
            ano ^= 1UL << i - 9;
        }
    }

    cout << "*************************" << endl;
    cout << "*******FILE*HEADER*******" << endl;
    cout << "FILENAME: " << FILENAME << endl;
    cout << "SIGNATURE: " << sig << (int)num << (int)num1 << endl;
    cout << "VERSION: " << VERSION << endl;
    cout << "BITFLAG: " << BITFLAG << endl;
    cout << "COMPRESSION METHOD: " << COMPRESSMETHOD << endl;
    cout << "MOD TIME: " << MOD_TIME << endl;
    cout << "SEGUNDO: " << (int)segundos / 2 << ", MINUTOS: " << (int)minuto << ", HORA: " << (int)hora << endl;
    cout << "MOD DATE: " << MOD_DATE << endl;
    cout << "DIA: " << (int)dia << ", MES: " << (int)mes << ", ANO: " << (int)ano + 1980 << endl;
    cout << "CRC32: " << CRC32 << endl;
    cout << "COMPRESSED SIZE: " << COMPRESSED << endl;
    cout << "UNCOMPRESSED SIZE: " << UNCOMPRESSED << endl;
    cout << "FILENAME LENGTH: " << FILENAME_LENGTH << endl;
    cout << "EXTRA FIELD LENGTH: " << EXTRA_FIELD_LENGTH << endl;
    cout << "EXTRA FIELD: " << endl;
    if (EXTRA_FIELD_LENGTH != 0) cout << EXTRAFIELD << endl;
    cout << "DATA: " << DATA << endl;
    cout << "*************************" << endl;

    delete DATA;
    delete FILENAME;
    delete EXTRAFIELD;
};

void Zip::print_ext() {
    char sig[3];
    memcpy(sig, EXT_SIG, 2);
    sig[2] = 0;
    uint8_t num;
    memcpy(&num, &EXT_SIG[2], 1);
    uint8_t num1;
    memcpy(&num1, &EXT_SIG[3], 1);
    cout << "*************************" << endl;
    cout << "*******EXTD*HEADER*******" << endl;
    cout << "SIGNATURE: " << sig << (int)num << (int)num1 << endl;
    cout << "CRC32: " << EXT_CRC32 << endl;
    cout << "COMPRESSED SIZE: " << EXT_COMPRESS << endl;
    cout << "UNCOMPRESSED SIZE: " << EXT_UNCOMPRES << endl;
    cout << "*************************" << endl;
    cout << "*************************" << endl;
};

void Zip::print_central() {
    char sig[3];
    memcpy(sig, CENTRAL_SIG, 2);
    sig[2] = 0;
    uint8_t num;
    memcpy(&num, &CENTRAL_SIG[2], 1);
    uint8_t num1;
    memcpy(&num1, &CENTRAL_SIG[3], 1);

    uint8_t segundos = 0;
    uint8_t minuto = 0;
    uint8_t hora = 0;

    for (size_t i = 0; i < 5; i++)
    {
        uint8_t recio = (CENTRAL_MOD_TIME >> i) & 1U;
        if (recio)
        {
            segundos ^= 1UL << i;
        }
    }

    for (size_t i = 5; i < 10; i++)
    {
        uint8_t recio = (CENTRAL_MOD_TIME >> i) & 1U;
        if (recio)
        {
            minuto ^= 1UL << i - 5;
        }
    }
    for (size_t i = 11; i < 16; i++)
    {
        uint8_t recio = (CENTRAL_MOD_TIME >> i) & 1U;
        if (recio)
        {
            hora ^= 1UL << i - 11;
        }
    }

    uint8_t dia = 0;
    uint8_t mes = 0;
    uint8_t ano = 0;

    for (size_t i = 0; i < 5; i++)
    {
        uint8_t recio = (CENTRAL_MOD_DATE >> i) & 1U;
        if (recio)
        {
            dia ^= 1UL << i;
        }
    }

    for (size_t i = 5; i < 9; i++)
    {
        uint8_t recio = (CENTRAL_MOD_DATE >> i) & 1U;
        if (recio)
        {
            mes ^= 1UL << i - 5;
        }
    }
    for (size_t i = 9; i < 16; i++)
    {
        uint8_t recio = (CENTRAL_MOD_DATE >> i) & 1U;
        if (recio)
        {
            ano ^= 1UL << i - 9;
        }
    }

    cout << "*************************" << endl;
    cout << "*******CENTRAL*DIR*******" << endl;
    cout << "FILENAME: " << CENTRAL_FILENAME << endl;
    cout << "SIGNATURE: " << sig << (int)num << (int)num1 << endl;
    cout << "CENTRAL VERSION MADE: " << CENTRAL_VER_MADE << endl;
    cout << "CENTRAL VERSION: " << CENTRAL_VER << endl;
    cout << "CENTRAL BITFLAG: " << CENTRAL_BITFLAG << endl;
    cout << "CENTRAL COMPRESSION METHOD: " << CENTRAL_COMPRESSMETHOD << endl;
    cout << "CENTRAL MOD TIME: " << CENTRAL_MOD_TIME << endl;
    cout << "SEGUNDO: " << (int)segundos / 2 << ", MINUTOS: " << (int)minuto << ", HORA: " << (int)hora << endl;
    cout << "CENTRAL MOD DATE: " << CENTRAL_MOD_DATE << endl;
    cout << "DIA: " << (int)dia << ", MES: " << (int)mes << ", ANO: " << (int)ano + 1980 << endl;
    cout << "CENTRAL CRC32: " << CRC32 << endl;
    cout << "CENTRAL COMPRESSED SIZE: " << CENTRAL_COMPRESSED << endl;
    cout << "CENTRAL UNCOMPRESSED SIZE: " << CENTRAL_UNCOMPRESSED << endl;
    cout << "CENTRAL FILENAME LENGTH: " << CENTRAL_FILENAME_LENGTH << endl;
    cout << "CENTRAL EXTRA FIELD LENGTH: " << CENTRAL_EXTRA_FIELD_LENGTH << endl;
    cout << "CENTRAL EXTRA FIELD: " << CENTRAL_EXTRAFIELD << endl;
    cout << "CENTRAL COMMENT LENGTH: " << CENTRAL_COMMENT_LENGTH << endl;
    cout << "CENTRAL COMMENT: " << CENTRAL_COMMENT << endl;
    cout << "CENTRAL DISK START: " << CENTRAL_DISK_START << endl;
    cout << "CENTRAL INTERNAL ATTRIBUTE: " << CENTRAL_INTER_ATT << endl;
    cout << "CENTRAL EXTERNAL ATTRIBUTE: " << CENTRAL_EXT_ATT << endl;
    cout << "CENTRAL FILE HEADER OFFSET: " << CENTRAL_HEADER_OFFSET << endl;
    cout << "*************************" << endl;
    cout << "*************************" << endl;
};

void Zip::print_endCentral() {
    char sig[3];
    memcpy(sig, END_SIG, 2);
    sig[2] = 0;
    uint8_t num;
    memcpy(&num, &END_SIG[2], 1);
    uint8_t num1;
    memcpy(&num1, &END_SIG[3], 1);

    cout << "**************************" << endl;
    cout << "*******END*CEN*DIR********" << endl;
    cout << "SIGNATURE: " << sig << (int)num << (int)num1 << endl;
    cout << "NUMBER OF DISKS: " << NUM_DISK << endl;
    cout << "START DISK: " << START_DISK << endl;
    cout << "NUMBER OF ENTRIES IN CENTRAL DIR: " << NUM_ENTRIES_CENTRAL << endl;
    cout << "TOTAL NUMBER OF ENTRIES: " << NUM_ENTRIES << endl;
    cout << "SIZE OF CENTRAL DIR: " << SIZE_CENTRAL << endl;
    cout << "OFFSET OF CENTRAL DIR: " << OFFSET_CENTRAL << endl;
    cout << "ZIPFILE COMMENT LENGTH: " << ZIPFILE_COM_LENGTH << endl;
    cout << "ZIPFILE COMMENT: " << ZIPFILE_COMENT << endl;
    cout << "**************************" << endl;
    cout << "**************************" << endl;
};
