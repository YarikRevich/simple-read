// Generated by gmmproc 2.66.4 -- DO NOT MODIFY!
#ifndef _GTKMM_TREEVIEWCOLUMN_P_H
#define _GTKMM_TREEVIEWCOLUMN_P_H


#include <gtkmm/private/object_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class GTKMM_API TreeViewColumn_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TreeViewColumn;
  using BaseObjectType = GtkTreeViewColumn;
  using BaseClassType = GtkTreeViewColumnClass;
  using CppClassParent = Object_Class;
  using BaseClassParent = GObjectClass;

  friend class TreeViewColumn;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void clicked_callback(GtkTreeViewColumn* self);

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_TREEVIEWCOLUMN_P_H */

