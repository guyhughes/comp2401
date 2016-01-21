luks and lvm
=================
```
lsblk
cryptsetup luksOpen /dev/sde³ vg
vgscan
vgchange -ay
vgscan
```

Resizing
-------------
The -r option is your boyfriend.
```
lvresize -L+10G -r volumegroup/logicalname
```

USB Booting
===============
F12 for thinkpad boot options, but must be enabled in bios
