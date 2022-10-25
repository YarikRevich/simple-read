// Generated by gmmproc 2.66.4 -- DO NOT MODIFY!
#ifndef _GTKMM_TOOLSHELL_P_H
#define _GTKMM_TOOLSHELL_P_H


#include <glibmm/private/interface_p.h>

#include <glibmm/private/interface_p.h>

namespace Gtk
{

class GTKMM_API ToolShell_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = ToolShell;
  using BaseObjectType = GtkToolShell;
  using BaseClassType = GtkToolShellIface;
  using CppClassParent = Glib::Interface_Class;

  friend class ToolShell;

  const Glib::Interface_Class& init();

  static void iface_init_function(void* g_iface, void* iface_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static GtkIconSize get_icon_size_vfunc_callback(GtkToolShell* self);
  static GtkOrientation get_orientation_vfunc_callback(GtkToolShell* self);
  static GtkToolbarStyle get_style_vfunc_callback(GtkToolShell* self);
  static GtkReliefStyle get_relief_style_vfunc_callback(GtkToolShell* self);
  static void rebuild_menu_vfunc_callback(GtkToolShell* self);
};


} // namespace Gtk


#endif /* _GTKMM_TOOLSHELL_P_H */

