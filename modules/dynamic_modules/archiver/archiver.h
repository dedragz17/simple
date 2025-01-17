
/* 
    Copyright (c) 2016-2018 Azeez Adewale <azeezadewale98@gmail.com> 
    MIT License Copyright (c) 2018 simple 

*/

/* 
 * File:   archiver.h
 * Author: thecarisma
 *
 * Created on February 11, 2018, 3:27 PM
 */

#ifndef ARCHIVER_H
#define ARCHIVER_H

#ifdef __cplusplus
extern "C" {
#endif
    
typedef struct zip_t ZIP_T ;

struct buffer_t {
    char *data;
    size_t size;
};

void zip_ZIP_DEFAULT_COMPRESSION_LEVEL(void *pointer);
void open_zip_file(void *pointer);
void open_zip_entry_file(void *pointer);
void write_zip_entry_file(void *pointer);
void fwrite_zip_entry_file(void *pointer);
void read_zip_entry_file(void *pointer);
void fread_zip_entry_file(void *pointer);
void close_zip_entry_file(void *pointer);
void extract_zip_file(void *pointer);
void close_zip_file(void *pointer);
void total_zip_file_count(void *pointer);
void zip_entry_by_index(void *pointer);
void extract_zip_entry(void *pointer);
void zip_entry_stat_info(void *pointer);
void zip_entry_name_by_index(void *pointer);


#ifdef __cplusplus
}
#endif

#endif /* ARCHIVER_H */

