/* Lib Aldaron --- Copyright (c) 2016 Jeron A. Lau */
/* This file must be distributed with the GNU LESSER GENERAL PUBLIC LICENSE. */
/* DO NOT REMOVE THIS NOTICE */

#ifndef LA_FILE
#define LA_FILE

#include <stdint.h>
#include <la_buffer.h>
#include <la_list.h>

enum {
	FILE_TYPE_NONE,
	FILE_TYPE_DIR,
	FILE_TYPE_FILE,
	FILE_TYPE_UNKNOWN,
} la_file_type_t;

const char* la_file_basename(char* base, const char* filename);
const char* la_file_append(const char* filename, const void* data, uint32_t size);
const char* la_file_truncate(const char* filename);
uint8_t la_file_exist(const char* path);
const char* la_file_load(la_buffer_t* load, const char* file_name);
const char* la_file_mkdir(const char* path);
la_list_t* la_file_ls(const char* dirname, uint8_t recursive);
const char* la_file_resloc(const char* prg_folder, const char* rname);
void la_file_rm(const char* filename);
char la_file_savezip(const char* package_name, const char* file_name,
	void *data, uint64_t data_size);
char* la_file_compress(const char* folder);
const char* la_file_loadzip(la_buffer_t* rtn, la_buffer_t* data,
	const char* file_name);

#endif
