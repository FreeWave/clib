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

#include "SList.h"

#include <stdlib.h>
#include <stdio.h>

static SList* sList_new(SList* list);

static SList* sList_new(SList* list)
{
     SList *new_list;
     new_list = (SList*)malloc(sizeof(SList));

     new_list->data = NULL;
     new_list->next = NULL;

     return new_list;
}

SList* list_prepend(SList* list, void* data)
{
     SList* new_list;

     new_list = sList_new(list);

     new_list->data = data;
     new_list->next = list;

     return new_list;
}

SList* list_append(SList* list, void* data)
{
     SList* new_list;

     new_list = sList_new(list);

     new_list->data = data;
     new_list->next = NULL;

     if (list)
     {
	  SList* last = list_get_last(list);
	  last->next = new_list;
	  
	  return list;
     }

     return new_list;
}

void list_free(SList* list)
{
     while (list->next)
     {
	  free(list);
	  list = list->next;
     }
}

int list_get_length( SList* list)
{
     int length = 0;

     if (!list)
	  return length;
     
     while (list)
     {
	  length++;
	  list = list->next;
     }

     return length;
}

SList* list_get_first(SList* list)
{
     return list_get_n_list(list,0);  
}

SList* list_get_last(SList* list)
{
   while (list->next)
	list = list->next;
   
   return list; 
}

void* list_get_n_data(SList* list, int n)
{
     while ((n-- > 0) && list)
	  list = list->next;

     return list ? list->data : NULL;
}

SList* list_get_n_list(SList* list, int n)
{
     while ((n-- > 0) && list)
	  list = list->next;

     return list ? list : NULL;
}

SList* list_get_first_data(SList* list)
{
    return list_get_n_data(list,0);
}

SList* list_get_last_data(SList* list)
{
  return list_get_n_data(list, list_get_length(list)- 1);
}


