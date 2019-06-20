/* vim: set backspace=2 ts=4 softtabstop=4 sw=4 cinoptions=>4 expandtab autoindent smartindent: */
/* xkb-cairo.h
 * Copyright (C) 2008 Alexander Iliev <sasoiliev@mamul.org>
 *
 * Parts of this program comes from the XfKC tool:
 * Copyright (C) 2006 Gauvain Pocentek <gauvainpocentek@gmail.com>
 *
 * A part of this file comes from the gnome keyboard capplet (control-center):
 * Copyright (C) 2003 Sergey V. Oudaltsov <svu@users.sourceforge.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _XKB_CAIRO_H_
#define _XKB_CAIRO_H_

#include <glib.h>
#include <glib/gprintf.h>
#include <gdk/gdk.h>
#include <cairo/cairo.h>
#include <librsvg/rsvg.h>
#include <pango/pangocairo.h>

void        xkb_cairo_draw_flag     (cairo_t *cr,
                                     const gchar *flag_name,
                                     gint panel_size,
                                     gint actual_width,
                                     gint actual_height,
                                     gint width,
                                     gint height,
                                     gint variant_markers_count,
                                     //gint textsize,
                                     const gchar *font_str,
                                     GdkColor fgcolor);

void        xkb_cairo_draw_label    (cairo_t *cr,
                                     const gchar *group_name,
                                     const gint panel_size,
                                     const gint actual_width,
                                     const gint actual_height,
                                     const gint width,
                                     const gint height,
                                     const gint variant_markers_count,
                                     //const gint textsize,
                                     const gchar *font_str,
                                     const GdkColor fgcolor);

#endif

