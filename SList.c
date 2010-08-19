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

/**
 * sList_new:
 * @list: a pointer to a #SList
 *
 * Init new list node
 */
static SList* sList_new(SList* list)
{
     SList *new_list;
     new_list = (SList*)malloc(sizeof(SList));

     new_list->data = NULL;
     new_list->next = NULL;

     return new_list;
}

/**
 * list_prepend:
 * @list: a pointer to a #SList
 * @data: the data for the new element
 *
 * Adds a new element on to the begin of the list.
 */
SList* list_prepend(SList* list, void* data)
{
     SList* new_list;

     new_list = sList_new(list);

     new_list->data = data;
     new_list->next = list;

     return new_list;
}

/**
 * list_append:
 * @list: a pointer to a #SList
 * @data: the data for the new element
 *
 * Adds a new element on to the end of the list.
 */
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

/**
 * list_free:
 * @list: a pointer to a #SList
 *
 * Free memory for SList
 */
SList* list_free(SList* list)
{
     while (list != NULL)
     {
	  SList* tmp = list;
          list = list->next;
	  free(tmp);
     }

     return list;
}

/**
 * list_ge_length:
 * @list: a pointer to a #SList
 *
 * Return count of elements of the SList
 */
 int list_get_length( SList* list)
{
     int length = 0;
     
     while (list)
     {
	  length++;
	  list = list->next;
     }

     return length;
}

/**
 * list_get_first:
 * @list: a pointer to a #SList
 *
 * Function return first element of the SList
 */
SList* list_get_first(SList* list)
{
     return list_get_n_list(list,0);  
}

/**
 * list_get_last:
 * @list: a pointer to a #SList
 *
 * Function return last element of the SList
 */
SList* list_get_last(SList* list)
{
   while (list->next)
	list = list->next;
   
   return list; 
}

/**
 * list_get_n_data:
 * @list: a pointer to a #SList
 * @n: the number of the element
 *
 * Return data element by index n from SList
 */
void* list_get_n_data(SList* list, int n)
{
     while ((n-- > 0) && list)
	  list = list->next;

     return list ? list->data : NULL;
}

/**
 * list_get_n_list:
 * @list: a pointer to a #SList
 * @n: the number of the element
 *
 * Return element by index n from SList
 */
SList* list_get_n_list(SList* list, int n)
{
     while ((n-- > 0) && list)
	  list = list->next;

     return list ? list : NULL;
}

/**
 * list_get_first_data:
 * @list: a pointer to a #SList
 * 
 * Return first data element from SList
 */
SList* list_get_first_data(SList* list)
{
    return list_get_n_data(list,0);
}

/**
 * list_get_first_data:
 * @list: a pointer to a #SList
 * 
 * Return last data element from SList
 */
SList* list_get_last_data(SList* list)
{
  return list_get_n_data(list, list_get_length(list)- 1);
}

/**
 * is_list_empty:
 * @list: a #SList
 *
 * Returns: 1 if SList is empty and retun 0 if SList
 */
short is_list_empty(SList* list)
{
     return list ? 1 : 0;
}

/**
 * insert_by_index:
 * @list: a pointer to a #SList
 * @index: index
 * @data:  element data
 *
 * Insert element in list by index
 */
SList* insert_by_index(SList* list, int index, void* data)
{
     
     if (index < 0)
	  return list_prepend(list, data);
     else if (index == 0)
	  return list_append(list, data);

     SList* new_list = sList_new(list);
     new_list->data = data;

     SList* prev_list = NULL;
     SList* tmp_list = NULL;
     
     if (!list)
     {
        new_list->next = NULL;
        return new_list;
     }

     prev_list = NULL;
     tmp_list = list;

     while ((index-- > 0) && tmp_list)
     {
        prev_list = tmp_list;
        tmp_list = tmp_list->next;
     }

     if (prev_list)
     {
        new_list->next = prev_list->next;
        prev_list->next = new_list;
     }
     else
     {
       new_list->next = list;
       list = new_list;
     }
  
     return list;
}

/**
 * list_get_first_data:
 * @list: a pointer to a #SList
 * @array: integer array
 * 
 * Convert list to array of integer
 */
void* list_to_int_array(SList* list, int* array)
{
     int i;
     int array_size = list_get_length(list);
   
     for (i = 0; i < array_size; i++)
     {
	  array = list_get_n_data(list,i);
	  array++;
     }
     
     return array;
}

/**
 * list_find_element:
 * @list: a pointer to a #SList
 * @data: a pointer to a void
 *
 * Find element by data
 */
SList* list_find_element(SList* list, void* data)
{
     while (list)
     {
	  if (list->data == data)
	  {
	       return list;
	  }
	  
	  list = list->next;
     }

     return NULL;
}

/**
 * list_find_index:
 * @list: a pointer to a #SList
 * @data: a pointer to a void
 *
 * Find element by index
 */
int  list_find_index(SList* list, void* data)
{
     int index = 0;
     
     while (list)
     {
	  if (list->data == data)
	  {
	       return index;
	  }

	  index++;
     }

     return -1;
}

/**
 * list_remove_element:
 * @list: a pointer to a #SList
 * @data: a pointer to a void
 *
 * Find element by data
 */
SList* list_remove_element(SList* list, void* data)
{
     SList *t;
     SList *prev;

     prev = NULL;
     t = list;

     while (t)
     {
       if (t->data == data)
       {
          if (list == t)
            list = list->next;

          t->next = NULL;
          free(t);

          break;
        }

      prev = t;
      t = t->next;
    }

  return list;
}
