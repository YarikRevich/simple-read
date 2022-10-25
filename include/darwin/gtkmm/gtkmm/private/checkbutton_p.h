// Generated by gmmproc 2.66.4 -- DO NOT MODIFY!
#ifndef _GTKMM_CHECKBUTTON_P_H
#define _GTKMM_CHECKBUTTON_P_H


#include <gtkmm/private/togglebutton_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class GTKMM_API CheckButton_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = CheckButton;
  using BaseObjectType = GtkCheckButton;
  using BaseClassType = GtkCheckButtonClass;
  using CppClassParent = Gtk::ToggleButton_Class;
  using BaseClassParent = GtkToggleButtonClass;

  friend class CheckButton;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static void draw_indicator_vfunc_callback(GtkCheckButton* self, cairo_t* cr);
};


} // namespace Gtk


#endif /* _GTKMM_CHECKBUTTON_P_H */

