/* vim: set backspace=2 ts=4 softtabstop=4 sw=4 cinoptions=>4 expandtab autoindent smartindent: */
/* xkb-config.h
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

#ifndef _XKB_CONFIG_H_
#define _XKB_CONFIG_H_

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <glib.h>
#include <glib/gstdio.h>
#include <gdk/gdk.h>
#include <libxklavier/xklavier.h>

typedef enum
{
    GROUP_POLICY_GLOBAL     = 0,
    GROUP_POLICY_PER_WINDOW     = 1,
    GROUP_POLICY_PER_APPLICATION    = 2
} t_group_policy;

typedef void        (*XkbCallback)                  (gint current_group,
                                                     gboolean groups_changed,
                                                     gpointer user_data);

gboolean          xkb_config_initialize                   (t_group_policy group_policy,
                                                           XkbCallback callback,
                                                           gpointer data);
void              xkb_config_finalize                     (void);
void              xkb_config_set_group_policy             (t_group_policy group_policy);
gint              xkb_config_get_group_count              (void);
const gchar*      xkb_config_get_group_name               (gint group);
const gchar*      xkb_config_get_variant                  (gint group);
gboolean          xkb_config_set_group                    (gint group);
gboolean          xkb_config_next_group                   (void);
gboolean          xkb_config_prev_group                   (void);
gint              xkb_config_variant_index_for_group      (gint group);

void              xkb_config_window_changed               (guint new_window_id,
                                                           guint application_id);
void              xkb_config_application_closed           (guint application_id);
void              xkb_config_window_closed                (guint window_id);
GdkPixbuf*        xkb_config_get_tooltip_pixbuf           (gint group);
gchar*            xkb_config_get_pretty_layout_name       (gint group);
gint              xkb_config_get_current_group            (void);

/* TODO: remove this function - xkl structures should not be used outside xkb-config */
XklConfigRegistry*
                  xkb_config_get_xkl_registry             (void);

#ifdef DEBUG

#define XKB_DEBUG(...) \
    do { g_fprintf (stderr, "[[ XFCE XKB PLUGIN ]]: "__VA_ARGS__); g_fprintf (stderr, "\n"); } while (0)

#define XKB_DEBUG_KBD(kbd, msg) g_printf("DUMPING KEYBOARD SETTINGS [[[%s]]] {%d}: ", msg, kbd);\
    if (kbd) { \
        g_printf ("\n\
          model: %s [%d]\n\
          layouts: %s [%d]\n\
          variants: %s [%d]\n\
          options: %s [%d]\n", \
                kbd->model, kbd->model, \
                kbd->layouts, kbd->layouts, \
                kbd->variants, kbd->variants, \
                kbd->options, kbd->options); \
    } else { \
        g_printf("NULL\n"); \
    }

#define XKB_DEBUG_CONFIG_REC(crec, msg) g_printf("DUMPING CONFIG REC [[[%s]]] {%d}: ", msg, (int) crec);\
    if (crec) { \
        g_printf ("\n\
            model: %s [%d]\n\
            layouts: %s [%d]\n\
            variants: %s [%d]\n", \
                crec->model, (int) crec->model, \
                g_strjoinv (",", crec->layouts), (int) crec->layouts, \
                g_strjoinv (",", crec->variants), (int) crec->variants); \
    } else { \
        g_printf ("NULL\n"); \
    }

#define XKB_DEBUG_GROUP_NAMES(groupnames, i, count) \
    for (i = 0; i < count; i++) {\
        if (groupnames && groupnames[i]) { \
            XKB_DEBUG("group : %s", groupnames[i]); \
        } \
    }

#else

#define XKB_DEBUG(...)
#define XKB_DEBUG_KBD(kbd, msg)
#define XKB_DEBUG_CONFIG_REC(crec, msg)
#define XKB_DEBUG_GROUP_NAMES(groupnames, i, count)

#endif

#endif

