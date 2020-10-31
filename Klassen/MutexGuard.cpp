#include "Mutex.h"

class MutexGuard {

	Mutex& m_mutex;

public:
	explicit MutexGuard(Mutex& m, bool locked = false) : m_mutex(m) { if (locked) lock(); }

	~MutexGuard() { unlock(); }
	MutexGuard& operator=(const MutexGuard&) = delete;

	void lock() {
		m_mutex.lock();
	}

	void unlock() {
		m_mutex.unlock();
	}

};