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

#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

typedef struct _DList DList;

struct _DList
{
     void* data;
     DList* next;
     DList* prev;
};

DList* dlist_append(DList* list, void* data);

DList* dlist_prepend(DList* list, void* data);

DList* dlist_get_last(DList* list);

DList* dlist_get_first(DList* list);

uint   dlist_get_length(DList* list);

DList* dlist_free(DList* list);

short is_dlist_empty(DList* list);

DList* dlist_get_last_data(DList* list);

DList* dlist_get_first_data(DList* list);

DList* dlist_get_n_list(DList* list, uint n);

void* dlist_get_n_data(DList* list, uint n);

DList* dlist_insert_by_index(DList* list, int index, void* data);

DList* dlist_remove_element(DList* list, void* data);

int  dlist_find_index(DList* list, void* data);

DList* dlist_find_element(DList* list, void* data);
     
#endif
