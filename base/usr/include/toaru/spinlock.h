#pragma once

#include <syscall.h>
#include <stdatomic.h>

#ifndef spin_lock
static void spin_lock(int volatile * lock) {
	while(atomic_flag_test_and_set(lock)) {
		syscall_yield();
	}
}

static void spin_unlock(int volatile * lock) {
	atomic_flag_clear(lock);
}
#endif

