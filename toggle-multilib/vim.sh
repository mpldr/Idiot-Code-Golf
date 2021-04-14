#!/bin/sh

grep '^\[multilib]' /etc/pacman.conf >/dev/null && sudo vim /etc/pacman.conf '+%s/^\(\[multilib]\)\n\(.*\)/#\1\r#\2' +x || sudo vim /etc/pacman.conf '+%s/^#\(\[multilib\]\)\n#\(.*\)/\1\r\2' +x
