/***************************************************************************
 *   Copyright (C) 2010 by Kuleshov Alexander (shk)                        *
 *   <kuleshovmail@gmail.com>                                              *
 *   <http://github.com/FreeWave/clib>                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef SLIST_H
#define SLIST_H

typedef struct _SList SList;

struct _SList
{
     void* data;
     SList* next;
};

SList* list_prepend(SList* list, void* data);

SList* list_get_first(SList* list);

int list_get_length( SList* list);

void list_free(SList* list);

SList* list_get_first(SList* list);

SList* list_get_last(SList* list);

void* list_get_n_data(SList* list, int n);

SList* list_get_n_list(SList* list, int n);

SList* list_get_first_data(SList* list);

SList* list_get_last_data(SList* list);

SList* list_append(SList* list, void* data);

SList* insert_by_index(SList* list, int index, void* data);

short is_list_empty(SList* list);

void* list_to_int_array(SList* list, int* array);

SList* list_find_element(SList* list, void* data);

int   list_find_index(SList* list, void* data);

SList* list_remove_element(SList* list, void* data);

#endif
