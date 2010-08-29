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

#include <stdio.h>
#include <stdlib.h>

#include "SList.h"
#include "DList.h"

int main (int argc, char *argv[])
{
     DList* list = NULL;
     list = dlist_append(list, (void*)"ASD");
     list = dlist_append(list, (void*)"DSA");
     list = dlist_prepend(list, (void*)"ASDD");

     list = dlist_insert_by_index(list,0, (void*)"DDD");

     list = dlist_remove_element(list, (void*)"DSA");
     
     printf("%d", dlist_get_length(list)); 

     return 0;
}
