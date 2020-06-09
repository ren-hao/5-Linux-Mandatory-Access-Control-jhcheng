# vim:syntax=apparmor
# AppArmor policy for py
# ###Jen Hao, Cheng###
# ###COPYRIGHT###
# ###COMMENT###

#include <tunables/global>

# No template variables specified

"/var/Y/py" {
  #include <abstractions/base>

  /var/Y/* rw,
  deny network inet,
  deny network inet6,
  deny network raw,
  deny network,
}
