/* -*- Mode: C; indent-tabs-mode: ni; c-basic-offset: 8 -*- */

/*
 * This file is part of The Croco Library
 *
 * Copyright (C) 2002-2003 Dodji Seketeli <dodji@seketeli.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2.1 of the GNU Lesser General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */

/*
 *$Id$
 */

#ifndef __CR_STYLESHEET_H__
#define __CR_STYLESHEET_H__

#include "cr-utils.h"
#include "cr-statement.h"

/**
 *@file
 *The declaration of the #CRStyleSheet class.
 */

/**
 *An abstraction of a css stylesheet as defined
 *by the css2 spec in chapter 4.
 */
struct _CRStyleSheet
{
	/**The css statements list*/
	CRStatement *statements ;
} ;


CRStyleSheet *
cr_stylesheet_new (CRStatement *a_stmts) ;

void
cr_stylesheet_dump (CRStyleSheet *a_this, FILE *a_fp) ;

void
cr_stylesheet_destroy (CRStyleSheet *a_this) ;

#endif /*__CR_STYLESHEET_H__*/
