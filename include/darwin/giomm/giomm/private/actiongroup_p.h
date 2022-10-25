// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GIOMM_ACTIONGROUP_P_H
#define _GIOMM_ACTIONGROUP_P_H


#include <glibmm/private/interface_p.h>
#include <gio/gio.h>

#include <glibmm/private/interface_p.h>

namespace Gio
{

class GIOMM_API ActionGroup_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = ActionGroup;
  using BaseObjectType = GActionGroup;
  using BaseClassType = GActionGroupInterface;
  using CppClassParent = Glib::Interface_Class;

  friend class ActionGroup;

  const Glib::Interface_Class& init();

  static void iface_init_function(void* g_iface, void* iface_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void action_added_callback(GActionGroup* self, const gchar* p0);
  static void action_enabled_changed_callback(GActionGroup* self, const gchar* p0, gboolean p1);
  static void action_removed_callback(GActionGroup* self, const gchar* p0);
  static void action_state_changed_callback(GActionGroup* self, const gchar* p0, GVariant* p1);

  //Callbacks (virtual functions):
  static gboolean has_action_vfunc_callback(GActionGroup* self, const gchar* action_name);
  static gchar** list_actions_vfunc_callback(GActionGroup* self);
  static gboolean get_action_enabled_vfunc_callback(GActionGroup* self, const gchar* action_name);
  static const GVariantType* get_action_parameter_type_vfunc_callback(GActionGroup* self, const gchar* action_name);
  static const GVariantType* get_action_state_type_vfunc_callback(GActionGroup* self, const gchar* action_name);
  static GVariant* get_action_state_hint_vfunc_callback(GActionGroup* self, const gchar* action_name);
  static GVariant* get_action_state_vfunc_callback(GActionGroup* self, const gchar* action_name);
  static void change_action_state_vfunc_callback(GActionGroup* self, const gchar* action_name, GVariant* value);
  static void activate_action_vfunc_callback(GActionGroup* self, const gchar* action_name, GVariant* parameter);
};


} // namespace Gio


#endif /* _GIOMM_ACTIONGROUP_P_H */

