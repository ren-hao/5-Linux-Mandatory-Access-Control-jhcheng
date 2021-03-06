# 5-Linux-Mandatory-Access-Control-jhcheng
Mini-Project #5: Linux Mandatory Access Control

# Linux Mandatory Access Control

The Linux system has two notable mandatory access control mechanisms [SELinux][1] and [AppArmor][2]. Imagine that we have the following scenario:

1. Program X is installed at /usr/local/bin/px
2. Only UserX is allowed to execute Program X
3. Program X will retrieve the source code of Program Y from the Internet and build Program Y under /var/X/
4. Program X will install Program Y under /var/Y/
5. Program X will fork a child process to execute Program Y
6. Program Y is only allowed to read/write files under /var/Y/
7. Program Y is not allowed to create or accept network connections.

Use either SELinux or AppArmor to implement least privilege security polciy for the above scenario. In other words, your policy should minimize unnecessary accesses that could be performed by Program X or Program Y.

For simplicity, you can assume that Program X and Program Y are C/C++ programs that will be compiled into ELF executables (and possibly with a bunch of .so shared libraries).

To make the grading process more manageable, please work on your policy from a fresh installed Linux, so that the TA can apply your SELinux policy or AppArmor profile on our testbed for verification.

[1]: https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/selinux_users_and_administrators_guide/index
[2]: https://wiki.ubuntu.com/AppArmor

# Install libcurl on Ubuntu

wget https://curl.haxx.se/download/curl-7.54.1.tar.gz

tar zxvf curl-7.54.1.tar.gz

cd curl-7.54.1

./configure  (if you have specific compiler, use ./configure CC=gcc-7, you can change "gcc-7" to what you want)

make

make test

sudo make install



# note

sudo aa-status

sudo aa-logprof

sudo apparmor_parser -r usr.local.bin.px/var.Y.py

sudo apparmor_parser -r var.Y.py

sudo aa-complain usr.local.bin.px/var.Y.py

sudo aa-easyprof /usr/local/bin/px ## for generate profile

reference: https://ubuntu.com/tutorials/beginning-apparmor-profile-development#1-overview
