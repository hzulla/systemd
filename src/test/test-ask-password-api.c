/* SPDX-License-Identifier: LGPL-2.1+ */
/***
  This file is part of systemd.

  Copyright 2016 Zbigniew Jędrzejewski-Szmek
***/

#include "alloc-util.h"
#include "ask-password-api.h"
#include "log.h"

static void ask_password(void) {
        int r;
        _cleanup_free_ char *ret;

        r = ask_password_tty(-1, "hello?", "da key", 0, 0, NULL, &ret);
        assert(r >= 0);

        log_info("Got %s", ret);
}

int main(int argc, char **argv) {
        log_parse_environment();

        ask_password();
}
