/* -*- Mode: C; indent-tabs-mode:nil; c-basic-offset: 8-*- */

/*
 *This file is part of The Croco Library
 *
 *The Croco Library is free software; 
 *you can redistribute it and/or modify it under the terms of 
 *the GNU General Public License as 
 *published by the Free Software Foundation; either version 2, 
 *or (at your option) any later version.
 *
 *GNU The Croco Library is distributed in the hope 
 *that it will be useful, but WITHOUT ANY WARRANTY; 
 *without even the implied warranty of 
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *See the GNU General Public License for more details.
 *
 *You should have received a copy of the 
 *GNU General Public License along with The Croco Library; 
 *see the file COPYING. If not, write to 
 *the Free Software Foundation, Inc., 
 *59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *Copyright 2002-2003 Dodji Seketeli <dodji@seketeli.org>
 */

#ifndef __CR_BOX_H__
#define __CR_BOX_H__

#include "cr-style.h"

/*
 *$Id$
 */

G_BEGIN_DECLS

/**
 *@file 
 *the declaration of the #CRBox class.
 */
enum CRBoxContentType
{
	NO_CONTENT_TYPE,
	TEXT_CONTENT_TYPE,
	IMAGE_CONTENT_TYPE
} ;

typedef struct _CRImageContentDesc CRImageContentDesc ;
struct _CRImageContentDesc
{
	guchar *img_buf ;
	gulong *len ;
	guchar *img_path ;
} ;

typedef struct _CRBoxContent CRBoxContent ;
struct _CRBoxContent
{
	enum CRBoxContentType type ;
	union 
	{
		guchar *text ;
		CRImageContentDesc *img_desc ;
	} kind ;
} ;

typedef struct _CRBoxEdge CRBoxEdge ;

/**
 *An internal data structure
 *used by #CRBox.
 *An edge is an rectangular area
 *defined by the coordinates of the it top left corner,
 *its width and height.
 */
struct _CRBoxEdge
{
	gulong x, y, width, height ;
} ;


enum CRBoxType
{
        BOX_TYPE_BLOCK,
        BOX_TYPE_ANONYMOUS_BLOCK,
        BOX_TYPE_INLINE,
        BOX_TYPE_ANONYMOUS_INLINE,
        BOX_TYPE_COMPACT,
        BOX_TYPE_RUN_IN
} ;

typedef struct _CRBox CRBox ;
/**
 *The CRBox class.
 *Abstracts the css2 box as defined in the
 *css2 spec in chapter 8.
 *It is actually a tree of boxes, each being "generated"
 *by an xml document tree node.
 */
struct _CRBox
{
        enum CRBoxType type ;

	/**
	 *The inner edge, or content edge.
	 *Is the one that immediately wraps
	 *the content of the box.
	 *The content of the box may be
	 *a text, an image, or a set of boxes.
	 *If the content is a set of boxes, then
	 *this set is inevitably the set of children
	 *boxes of this current box.
	 */
	CRBoxEdge inner_edge ;

	/**
	 *The padding edge.
	 *It includes the inner_edge plus a
	 *a surrounding area called "padding".
	 *When the padding is inexistent, the
	 *padding edge equals the inner or content edge.
	 */
	CRBoxEdge padding_edge ;

	/**
	 *The border edge.
	 *It includes the padding edge plus
	 *a surrounding area called "border".
	 *If the border is inexistant, the
	 *border edge equals the padding edge.
	 *
	 */
	CRBoxEdge border_edge ;

	/**
	 *The outer edge aka margin edge.
	 *It includes the border edge plus
	 *a surrounding area called "margin".
	 *If the border is inexistant, the outer
	 *edge equals the border_edge.
	 */
	CRBoxEdge outer_edge ;

	/**
	 *The values of all the preceding
	 *edges are infered from the value
	 *of the 'style' field.
	 */

	/**
	 *The content (text or image) of this
	 *box
	 */
	CRBoxContent content ;

	/**
	 *if TRUE, it means that this box has
	 *a simple content. Simple content means
	 *either a text or image content.
	 *Normally, to be logic, if this is
	 *set to TRUE, the children pointer should
	 *be NULL ... see what I mean ?
	 */
	gboolean as_simple_content ;

	/**
	 *The value infered from what has been found
	 *in the css stylesheet.
	 *
	 */
	CRStyle *style ;

	/**the containing box*/
	CRBox *parent ;

	/**the next box in the flow*/
	CRBox *next ;

	/**the previous box in the flow*/
	CRBox *prev ;

	/**the children (contained) boxes*/
	CRBox *children ;
};


CRBox *
cr_box_new (void) ;

enum CRStatus
cr_box_insert_sibling (CRBox *a_prev,
                       CRBox *a_next,
                       CRBox *a_to_insert) ;

enum CRStatus
cr_box_append_child (CRBox *a_this, CRBox *a_to_append) ;


void
cr_box_destroy (CRBox *a_this) ;


G_END_DECLS

#endif /*__CR_BOX_H__*/

