/* -*- Mode: C; indent-tabs-mode:nil; c-basic-offset: 8-*- */

/*
 * This file is part of The Croco Library
 *
 * Copyright (C) 2002-2003 Dodji Seketeli <dodji@seketeli.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2.1 of the 
 * GNU Lesser General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the 
 * GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */

#ifndef __CR_LAY_ENG_H__
#define __CR_LAY_ENG_H__

#include <libxml/tree.h>
#include "cr-utils.h"
#include "cr-cascade.h"
#include "cr-box.h"

/**
 *@file
 *the declaration of the #CRLayEng class.
 */

G_BEGIN_DECLS

typedef struct _CRLayEngPriv CRLayEngPriv ;

/**
 *The abstraction of the Layout engine of libcroco.
 */
typedef struct
{
	CRLayEngPriv *priv ;
} CRLayEng ;


CRLayEng *
cr_lay_eng_new (void) ;

enum CRStatus
cr_lay_eng_build_box_tree (CRLayEng *a_this,
                           xmlDoc *a_xml_doc,
                           CRCascade *a_cascade,
                           CRBox **a_box_tree) ;
void
cr_lay_eng_destroy (CRLayEng *a_this) ;

G_END_DECLS

#endif /*__CR_LAYOUT_ENG_H__*/
