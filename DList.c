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

#include "DList.h"

static inline DList* dlist_init();

/**
 * dlist_init:
 *
 * Init new list node
 */
static inline DList* dlist_init()
{
     DList* dlist_new = (DList*)(malloc(sizeof(DList)));

     dlist_new->prev = NULL;
     dlist_new->next = NULL;
     dlist_new->data = NULL;

     return dlist_new;
}

/**
 * dlist_append:
 * @list: a pointer to a #DList
 * @data: a pointer to a #void
 *
 * Append new item in list
 */
DList* dlist_append(DList* list, void* data)
{
     DList* new_list;
     DList* last;
     
     new_list = dlist_init();
     new_list->data = data;

     if (list)
     {
	  last = dlist_get_last(list);
	  last->next = new_list;
	  new_list->prev = last;

	  return list;
     }

     else
         return new_list;
}


/**
 * dlist_prepend:
 * @list: a pointer to a #DList
 * @data: a pointer to a #void
 *
 * Prepend new item in list
 */
DList* dlist_prepend(DList* list, void* data)
{
     DList* new_list;

     new_list = dlist_init();
     new_list->data = data;

     if (list)
     {
	  if(list->prev)
	  {
	       list->prev->next = new_list;
	       new_list->prev = list->prev;
	  }

	  list->prev = new_list;
	  new_list->next = list;
     }
     
     return new_list;
}


/**
 * dlist_get_last:
 * @list: a pointer to a #DList
 *
 * Get last item from the list
 */
DList* dlist_get_last(DList* list)
{
     if (list)
     {
	while(list->next)
	     list = list->next;

     }
     
     return list;
}


/**
 * dlist_get_first:
 * @list: a pointer to a #DList
 *
 * Get first item from the list
 */
DList* dlist_get_first(DList* list)
{
     if (list)
     {
	  while (list->prev)
	       list = list->prev;
     }

     return list;
}

/**
 * dlist_get_length:
 * @list: a pointer to a #DList
 *
 * Get count of DList items
 */
uint dlist_get_length(DList* list)
{
     uint length = 0;

     if (list)
     {
	  while(list)
	  {
	       length++;
	       list = list->next;
	  }
     }
     else
	  return 0;

     return length;
}

/**
 * dlist_free:
 * @list: a pointer to a #DList
 *
 * Free DList
 */
DList* dlist_free(DList* list)
{
     while (list != NULL)
     {
	  DList* tmp = list;
          list = list->next;
	  free(tmp);
     }

     return list;
}


/**
 * dlist_get_n_data:
 * @list: a pointer to a #DList
 * @n: the number of the element
 *
 * Return data element by index n from DList
 */
void* dlist_get_n_data(DList* list, uint n)
{
     while ((n-- > 0) && list)
	  list = list->next;

     return list ? list->data : NULL;
}

/**
 * dlist_get_n_list:
 * @list: a pointer to a #DList
 * @n: the number of the element
 *
 * Return element by index n from DList
 */
DList* dlist_get_n_list(DList* list, uint n)
{
    while ((n-- > 0) && list)
	  list = list->next;

     return list ? list : NULL;
}

/**
 * dlist_get_first_data:
 * @list: a pointer to a #DList
 * 
 * Return first data element from DList
 */
DList* dlist_get_first_data(DList* list)
{
    return dlist_get_n_data(list,0);
}

/**
 * dlist_get_first_data:
 * @list: a pointer to a #DList
 * 
 * Return last data element from DList
 */
DList* dlist_get_last_data(DList* list)
{
  return dlist_get_n_data(list, dlist_get_length(list)- 1);
}

/**
 * is_dlist_empty:
 * @list: a #DList
 *
 * Returns: 1 if SList is empty and retun 0 if DList
 */
short is_dlist_empty(DList* list)
{
     return list ? 1 : 0;
}


/**
 * dlist_insert_by_index:
 * @list: a pointer to a #DList
 * @index: index
 * @data:  element data
 *
 * Insert element in DList by index
 */
DList* dlist_insert_by_index(DList* list, int index, void* data)
{
     DList *new_list;
     DList *tmp_list;
  
     if (index < 0)
	  return dlist_append (list, data);
     else if (index == 0)
	  return dlist_prepend (list, data);
  
     tmp_list =  dlist_get_n_list(list, index);

     if (!tmp_list)
	  return dlist_append (list, data);
  
     new_list = dlist_init();
     new_list->data = data;
  
     if (tmp_list->prev)
     {
	  tmp_list->prev->next = new_list;
	  new_list->prev = tmp_list->prev;
     }

     new_list->next = tmp_list;
     tmp_list->prev = new_list;
  
     if (tmp_list == list)
	  return new_list;
     else
	  return list;
}

/**
 * dlist_remove_element:
 * @list: a pointer to a #DList
 * @data: a pointer to a void
 *
 * Remove data element from list
 */
DList* dlist_remove_element(DList* list, void* data)
{
    DList *tmp;
  
    tmp = list;
    while (tmp)
    {
        if (tmp->data != data)
	     tmp = tmp->next;
        else
	{
	     if (tmp->prev)
		  tmp->prev->next = tmp->next;
	     if (tmp->next)
		  tmp->next->prev = tmp->prev;
	  
	     if (list == tmp)
		  list = list->next;
	  
	     free (tmp);
	  
	  break;
	}
    }
  return list;
}

/**
 * dlist_find_index:
 * @list: a pointer to a #DList
 * @data: a pointer to a void
 *
 * Find element by index
 */
int  dlist_find_index(DList* list, void* data)
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
 * dlist_find_element:
 * @list: a pointer to a #DList
 * @data: a pointer to a void
 *
 * Find element by data
 */
DList* dlist_find_element(DList* list, void* data)
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
