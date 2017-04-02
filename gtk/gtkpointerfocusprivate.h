/* GTK - The GIMP Toolkit
 * Copyright (C) 2017 - Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _GTK_POINTER_FOCUS_PRIVATE_H_
#define _GTK_POINTER_FOCUS_PRIVATE_H_

#include <gtk/gtk.h>

typedef struct _GtkPointerFocus GtkPointerFocus;

struct _GtkPointerFocus
{
  GdkDevice *device;
  GdkEventSequence *sequence;
  GtkWindow *toplevel;
  GtkWidget *target; /* Unaffected by the implicit grab */
  GtkWidget *grab_widget;
  gdouble x, y; /* In toplevel coordinates */
};

GtkPointerFocus * gtk_pointer_focus_new  (GtkWindow        *toplevel,
                                          GtkWidget        *widget,
                                          GdkDevice        *device,
                                          GdkEventSequence *sequence,
                                          gdouble           x,
                                          gdouble           y);
void              gtk_pointer_focus_free (GtkPointerFocus *focus);

void              gtk_pointer_focus_set_coordinates (GtkPointerFocus *focus,
                                                     gdouble          x,
                                                     gdouble          y);
void              gtk_pointer_focus_set_target      (GtkPointerFocus *focus,
                                                     GtkWidget       *target);
GtkWidget *       gtk_pointer_focus_get_target      (GtkPointerFocus *focus);

void              gtk_pointer_focus_repick_target (GtkPointerFocus *focus);

#endif /* _GTK_POINTER_FOCUS_PRIVATE_H_ */
