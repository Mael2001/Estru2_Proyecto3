#ifndef MYZIP_H
#define MYZIP_H
#include "Zip.h"
#include "string"
#include "list"
#include "iostream"
#include "sstream"
#include "iterator"
#include <QStringList>

class myZip {
private:
    ifstream file_zip;
    ifstream verificando;
    inline bool estaFinal(int pos) {
        verificando.seekg(pos);
        char signature[5];
        verificando.read(signature, 4);
        signature[4] = 0;
        uint8_t num;
        uint8_t num1;

        memcpy(&num, &signature[2], 1);
        memcpy(&num1, &signature[3], 1);
        //cout << "NUM1: " << (int)num << endl << "NUM2: " << (int)num1 << endl;
        if ((int)num == 1)
        {
            return 1;
        }
        return 0;
    };
    inline void ReadHeader(string filename) {
        file_zip.seekg(0, ios_base::beg);
        while (true)
        {
            Zip clase;
            if (estaFinal(file_zip.tellg()))
            {
                file_zip.read((char*)central_dir, sizeof(central_dir));
                clase.unpackcentraldir(central_dir);
                file_zip.read(clase.CENTRAL_FILENAME, clase.getCentral_FILELENGTH());
                file_zip.read(clase.CENTRAL_EXTRAFIELD, clase.getCentral_EXTRALENGTH());
                file_zip.read(clase.CENTRAL_COMMENT, clase.getCentral_COMLENGTH());
                clase.CENTRAL_FILENAME[clase.getCentral_FILELENGTH()] = 0;
                clase.CENTRAL_EXTRAFIELD[clase.getCentral_EXTRALENGTH()] = 0;
                clase.CENTRAL_COMMENT[clase.getCentral_COMLENGTH()] = 0;
                clase.print_central();

                file_zip.read((char*)end_cen_dir, sizeof(end_cen_dir));
                clase.unpackEndCentralDir(end_cen_dir);
                file_zip.read(clase.ZIPFILE_COMENT, clase.getEnd_COMLENGTH());
                clase.ZIPFILE_COMENT[clase.getEnd_COMLENGTH()] = 0;
                clase.print_endCentral();
                break;
            }
            else {
                file_zip.read((char*)file_header, sizeof(file_header));
                clase.unpackheader(file_header);
                file_zip.read(clase.FILENAME, clase.getfilenamelength());
                file_zip.read(clase.EXTRAFIELD, clase.getextrafieldlength());
                file_zip.read(clase.DATA, clase.getcompressedsize());
                clase.EXTRAFIELD[clase.getextrafieldlength()] = 0;
                clase.FILENAME[clase.getfilenamelength()] = 0;
                clase.DATA[clase.getcompressedsize()] = 0;
                List<<clase.FILENAME;
                Uncompressed.push_back(clase.getuncompressed());
                Compressed.push_back(clase.getcompressedsize());
                Listings.push_back(clase.FILENAME);
                Mod_Date.push_back(clase.getModdate());
                Mod_time.push_back(clase.getModtime());
                uint8_t recio = (clase.getbitflag() >> 3) & 1U;
                clase.print();
                if (recio)
                {
                    file_zip.read((char*)ext_header, sizeof(ext_header));
                    clase.unpackextheader(ext_header);
                    clase.print_ext();
                }
            }
        }

    };

public:
    char file_header[30];
    char ext_header[16];
    char central_dir[46];
    char end_cen_dir[22];
    QStringList List;
    list<string> Listings;
    list<uint16_t>Mod_time;
    list<uint16_t>Mod_Date;
    list<uint64_t>Uncompressed;
    list<uint64_t>Compressed;
    inline void OpenZIP(const char* filename) {
        file_zip.open(filename, ifstream::in | ifstream::binary);
        verificando.open(filename, ifstream::in | ifstream::binary);
        if (file_zip.is_open())
        {
            ReadHeader(filename);
        }
        else {
            cout << "Archivo No Encontrado" << endl;
        }
    };
};
#endif // MYZIP_H
