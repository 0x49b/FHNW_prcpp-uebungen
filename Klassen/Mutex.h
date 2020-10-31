#pragma once


struct Mutex {
	bool m_locked = false;
public:
	void lock() {
		m_locked = true;
	}
	void unlock() {
		m_locked = false;
	}
};